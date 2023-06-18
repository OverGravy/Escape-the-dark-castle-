#include "Chapter.h"

using namespace std;
//funzione che non serve a nulla in realtà
void Chapter::Print(const string & msg){
            cout << msg << endl;
}
//costruttore
Chapter::Chapter(const int & l){

	fstream ChapterFileCombo; 
	fstream ChapterFileText;
	fstream ChapterFileDamage;
	string stream; 

	line=l;
	
	try{
        ChapterFileCombo.open("./Files/Cards/ChapterCombo.txt");
    }
    catch(const exception& e){
        cerr << "!!  " << e.what() << "  !!" << endl;
        exit(1);
    }
	     
	GotoLine(ChapterFileCombo, line); // serve per scorrere fino alla linea desiderata
	getline(ChapterFileCombo,stream); // considera solo la line che ci interessa
	Split(stream,WinCombo,' '); //divide quello che leggo
	
	ChapterFileCombo.close();
	
	try{
        ChapterFileText.open("./Files/Cards/ChapterText.txt");
    }
    catch(const exception& e){
        cerr << "!!  " << e.what() << "  !!" << endl;
        exit(1);
    }
    
    GotoLine(ChapterFileText,line);
    getline(ChapterFileText,stream);
	Chapter_text = stream;
	
	ChapterFileText.close();
	
	try{
        ChapterFileDamage.open("./Files/Cards/ChapterDamage.txt");
    }
    catch(const exception& e){
        cerr << "!!  " << e.what() << "  !!" << endl;
        exit(1);
    }
    
    GotoLine(ChapterFileDamage,line);
    getline(ChapterFileDamage,stream);
    stringstream tmp(stream);
    tmp >> damage;
    
	ChapterFileDamage.close();
}
//getter
int Chapter::Get_Line(){
	return line;
}

string Chapter::Get_Text(){
	return Chapter_text;
}

string Chapter::Get_Combo(const int & position){
	return WinCombo[position];
}

int Chapter::Get_Combo_lenght(){
	return WinCombo.size();
}

int Chapter::Get_damage(){
	return damage;
}

vector<string> Chapter::Get_Vector(){
	return WinCombo;
}

//setter
void Chapter::Add_WinCombo(const string & pl_Combo){
	WinCombo.push_back(pl_Combo);
}

void Chapter::Delete_position_Combo(const int & position){
	//qui definisco un iteratore che e punta al valore che voglio cancellare 
	vector<string>::iterator it = WinCombo.begin() + position;
	WinCombo.erase(it);
}

bool Chapter::Is_combo_empty(){
	return WinCombo.empty();
}
