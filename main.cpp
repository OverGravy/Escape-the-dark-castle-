#include <iostream>
#include "Game.h"

using namespace std;

//Nel main richiamer� solo le funzioni di getsione del gioco poich� usero una classe game che gestisce tutta la partita

int main(){
    Game g1; // creo una classe game dentro la quale organizzer� il gioco
    g1.Init(); //Faccio scegiere ai giocatori i ruoli da loro desiderati, li inizializzo e inizializzo il castello
    g1.Match(); //Svolgo la partita, faccio combattere ogni giocatore a turno fino alla fine
    g1.Close(); //Concludo con la chiusura
}
