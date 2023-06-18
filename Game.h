#ifndef __GAME__
#define __GAME__

#include <iostream> 
#include <fstream> //per lo stream di file
#include <string> //per le stringhe
#include <vector> //per i vettori
#include <deque> // per la queue castle che sono una coda
#include <algorithm> //per il random shuffle
#include <ctime> //per il time del random
#include <conio.h> //per il getch e il press any key to ocntinue
#include <stdlib.h> //per irpulire la console
#include <windows.h> // per il full screen
#include <sstream> // per convertire string to int

#include "Hero.h" //sottoclasse che definisce il tipo eroe
#include "Chapter.h" //sottocalsse che descrive il tipo Capitolo
#include "Graphics.h" //libreria contente funzioni di stampa.

using namespace std;

class Game{
private:
    int N_Player; //numero di giocatori
    int N_Card; //numero di carte
    int Played_Card; //carte giocate
    
    deque<Chapter> Castle; //coda delle carte capitolo
    vector<Hero> Crew; //vettore degli eroi selezionati
    
    //funnzioni interne alle classe e usate solo internamente non sono metodi esterni
    
    void Chose_Player_Number();//serve per definire il numero di giocarori 
    void Chose_Hero();  //funzione per scegliere l'eroe
    void Create_Castle(); //funzione per creare il castello
	void Show_Score(); //Mostro il punteggio 
	
	//funzioni per il testing 
	void Show_Every_Card(); //MOstr ogni carta e il relativo contenuto
	
public:
    Game();
    
    ~Game();

    void Init(); //inizializzazione game
	
	void Match(); // svolge la partita
	
	void Close(); //conclude la partita

};

#endif

