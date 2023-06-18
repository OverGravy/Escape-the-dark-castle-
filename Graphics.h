#ifndef __GRAPHICS__
#define __GRAPHICS__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <conio.h>

using namespace std;

void Print_Title(); // questa funzione stampa il titolo

void Print_Card(const int & line); //Questa funzione stampa la carta che desidero 

void Print_Character(const string & file); //Stampa la crta personaggio //la variabile file è un numero da 1-4

void Print_Vector(const vector<string> & v); //Conoscendo la faccia faccio stampare il simbolo 

void Print_GameOver(const string & name); //stampa qualcosa per la morte di uno dei giocatori 

void Print_Win(); // Stampa la vittoria

void Print_Close(); // stampa qualcosa in fase di chiusura

#endif
