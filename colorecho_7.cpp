#include <iostream>
#include <windows.h> // void nastav_barvu(WORD attr)
#include <sstream> // istringstream iss
using namespace std;

/*
pouziti:
colorecho 0-15 P¯Ìliö ûluùouËk˝ k˘Ú ˙pÏl Ô·belskÈ Ûdy. (123) äçéÿ¡⁄…Õ

verze 7 - neni potreba delat uvozovky mezi vicero slovama,
pridana cerna barva, pro tisk prazdnyho radku 
a uz umi tiskout jak obycejny text tak hacky carky
*/

// funkce pro nastaveni barvy
void nastav_barvu(WORD attr){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),attr);
}

struct paleta { const char* name; WORD attr; };		        
paleta barva[]={
{ "0: Black", 0 },
{ "1: Blue", FOREGROUND_BLUE },
{ "2: Green", FOREGROUND_GREEN },
{ "3: Cyan", FOREGROUND_GREEN | FOREGROUND_BLUE },
{ "4: Red", FOREGROUND_RED },
{ "5: Magenta", FOREGROUND_RED | FOREGROUND_BLUE },
{ "6: Yellow", FOREGROUND_RED | FOREGROUND_GREEN },
{ "7: White",FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE }, // micha RGB
{ "8: Bright Black (Gray)", FOREGROUND_INTENSITY },
{ "9: Bright Blue", FOREGROUND_INTENSITY | FOREGROUND_BLUE },
{ "10: Bright Green", FOREGROUND_INTENSITY | FOREGROUND_GREEN },
{ "11: Bright Cyan", FOREGROUND_INTENSITY | FOREGROUND_GREEN  | FOREGROUND_BLUE },
{ "12: Bright Red", FOREGROUND_INTENSITY | FOREGROUND_RED },
{ "13: Bright Magenta", FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE },
{ "14: Bright Yellow", FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN },
{ "15: Bright White", FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE },
{ "16: puvodni barva konzole", FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE },
};

int b, bb, n=5000;
string t="";

// funkce napoveda
void napoveda() {
for (int aa = 0; aa <= 15; aa++ ){
cout<<"colorecho "<<aa;
nastav_barvu(barva[aa].attr);
cout<<" "<<'"'<<"zde nejaky text"<<'"'<<endl;
nastav_barvu(barva[16].attr); // vrati default barvu konzole
}
}

int main(int argc, char* argv[]){
if (argc < 3 ) { // mene nez 3 argv[0][1][2]
napoveda();
Sleep(n);
exit(1);
}

istringstream iss(argv[1]);
if (iss >> b){ // prevedeni string argv[1] na int
if (( b < 0 ) || ( b > 15 )){
napoveda();
Sleep(n);
exit(1);	
}

// nastaveni globalni locale podle systemu (poradilo AI)
// klicove pro spravnou konverzi a diakritiku
locale::global(locale("")); // bez tototo i FUNGUJE (ale radeji ponechano)

// nastaveni C knihoven na systemove locale (poradilo AI)
setlocale(LC_ALL, ""); // bez tohoto NEfunguje

// spojeni argumentu argv[2] az argv[argc] to jednono retezce
// rozdeleno mezi sebou mezerama
for (int bb = 2; bb <= argc - 1; bb++ ){
t += argv[bb];
if (bb < argc - 1 ){ // za poslednim davat nezeru nebude
t += " ";
}
}

// tisk vysledku pokud by obsahovalo UTF-8 tak ho pouzije
nastav_barvu(barva[b].attr);
// t = "P¯Ìliö ûluùouËk˝ k˘Ú ˙pÏl Ô·belskÈ Ûdy. (123) äçéÿ¡⁄…Õ";
cout<<t<<endl;
nastav_barvu(barva[16].attr); // vrati default barvu konzole

// pokud se argv[1] neprevedl na int
}else{
napoveda();
Sleep(n);
exit(1);
}

return 0;
}

