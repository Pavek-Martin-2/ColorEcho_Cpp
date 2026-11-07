#include <iostream>
#include <windows.h> // void nastav_barvu(WORD attr)
#include <sstream> // istringstream iss
using namespace std;

// colorecho_5 1-15 "nejaky text"

// funkce pro nastaveni barvy
void nastav_barvu(WORD attr){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),attr);
}

struct paleta { const char* name; WORD attr; };		        
paleta barva[]={
{ "0: Black", 0 }, // vynechano, kdyby nekomu chybela cerna muze si ji vratit
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
{ "16: puvodni barva konzole", FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE }, // vynechano
};

int b, n = 5000;
string t;

// funkce napoveda
void napoveda() {
for (int aa = 1; aa <= 15; aa++ ){ // aa = 0;  i z cernou
cout<<"colorecho "<<aa;
nastav_barvu(barva[aa].attr);
cout<<" "<<'"'<<"zde nejaky text"<<'"'<<endl;
nastav_barvu(barva[16].attr); // vrati default barvu konzole
}
}

int main(int argc, char* argv[]) {
// argumenty, prvni argument volba barvy
// druhej argumet je zobrazovanej text
if (argc != 3) { // pokud nejsou prave 2 argumenty
napoveda();
Sleep(n);
exit(1);
}

istringstream iss(argv[1]);
if (iss >> b){ // prevedeno string argv[1] na int
// kontrola jesti bylo zadano cislo 1-15
if (( b < 1 ) || ( b > 15 )) {	// b < 0  pro cernou
napoveda();
//cout<<endl<<"zadej barvu 1-15 "<<endl;
Sleep(n);
exit(1);	
}

// tady uz tisknout barevne argv[2]
nastav_barvu(barva[b].attr);
t = argv[2];
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

