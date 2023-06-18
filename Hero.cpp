#include "Hero.h"

//Questa è una possibilità per il costruttore, potrei far leggere questi dati da un file di testo considerando di passare il valore di riga o qualcosa che faccia riferimento a dove devo leggere
Hero::Hero(const int & line, const string & n,const string & r){
	name=n + " the " + r;
	role = r.c_str();
	fstream CharacterFile;
	try{
         CharacterFile.open("./Files/Character/CharacterCard.txt");
    }
    catch(const exception& e){
        cerr << "!!  " << e.what() << "  !!" << endl;
        exit(1);
    }
     GotoLine(CharacterFile, line); // serve per scorrere fino alla linea desiderata
     string stream;
     getline(CharacterFile,stream);
	 Split(stream,Dice,' '); // creo il dado personaggio
     CharacterFile.close();
   
}
  
Hero::Hero(const Hero & cp){
	name=cp.name;
	Dice=cp.Dice;
}

Hero::~Hero(){
	
}

//getter

string Hero::Get_Dice_Face(const int & position)const{
	return Dice[position];
}

string Hero::Get_Name()const{
	return name;
}

int Hero::Get_HP(){
	return HP;
}

string Hero::Get_Role()const{
	return role;
}

bool Hero::Get_Dubble()const{
	return dubble;
}

//setter
void Hero::Add_HP(const int & p) {
	HP=HP+p;
}

void Hero::Decrease_HP(const int & p) {
	HP=HP-p;
}

void Hero::Set_Dubble(const bool & result) {
	dubble=result;
}

void Hero::Set_Role(const string & r){
	role=r;
}


