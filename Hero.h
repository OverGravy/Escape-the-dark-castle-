#ifndef __HERO__
#define __HERO__

#include <string>
#include <iostream>
#include <vector>
#include <conio.h>
#include "Utility.h"


using namespace std;

//Questa classe descrive una carta eroe

class Hero{
private:
	int HP=10; //punti vita Health point
	string name; //nome dell eroe + giocatore // ruolo 
 	vector<string> Dice; // vettre dado
	bool dubble; 
	string role; // ruolo
public:
	//setter
	void Decrease_HP(const int & p);
	void Add_HP(const int & p);
	void Set_Dubble(const bool & result);
	void Set_Role(const string & r);
	//getter
    string Get_Dice_Face(const int & position)const; // per farmi restituire una fccia del dado nello specifico
	string Get_Name()const;
	int Get_HP();
	bool Get_Dubble()const;
	string Get_Role()const;
	//costruttori/distruttori
	Hero(const int & line, const string & n, const string & r); //ricevo la line a cui leggere le statistiche del personaggio e il nome del giocatore 
    Hero(const Hero& cp); // copy costructor
   ~Hero();
	
};

#endif
