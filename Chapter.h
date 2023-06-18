#ifndef __CHAPTHER__
#define __CHAPTHER__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Utility.h"

//Questa classe descrive una carta castello

using namespace std;

class Chapter{
    private:
    	int line; //linea da cui leggere nel relativo fil di testo
    	int damage; //danno della carta
        vector<string> WinCombo; //vettore della vincita
        string Chapter_text; //testo della carta
    public:
    	//getter
        int Get_Line();
        string Get_Combo(const int & position);
        string Get_Text();
        int Get_Combo_lenght();
        int Get_damage();
        vector<string> Get_Vector();
    	//setter
        void Set_WinCombo(int p_number,vector<string> W_combo); // per impostare la combinazione vicente sulla carta
        void Set_Damage(int d); //set della proprieta danno 
        void Set_Text(string stream); //Set della proprietà testo
        void Print(const string & msg); // Questa funzione no so ancora quanto sia utile, potrebbe capitare di vole stampare a video qualcosa durante il game attraverso la carta capitolo è possibile
        void Add_WinCombo(const string & pl_Combo); // aggiunge la parte di combo dei giocatori 
        void Delete_position_Combo(const int & position); 
        
        bool Is_combo_empty(); // controllo se è vuoto il vettore WinCombo
        
        //costruttore
		Chapter(const int & l);
};

#endif
