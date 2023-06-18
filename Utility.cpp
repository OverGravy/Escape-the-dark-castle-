#include "Utility.h"

using namespace std;
//a queata funzione passo un vettore e una stringa e lui lo scompone secondo quello ce desidero e che inserisco all'interno di ch

size_t Split(const string &txt, vector<string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    // divide
    while( pos != string::npos ) { //npos si riferisce alla fine della stringa "posizione finale"
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;
        pos = txt.find( ch, initialPos );
    }

    //aggiunge la parte finale
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}

//Questa funzione considera del file solo la perte interessante per o noi ovvero la linea con le statistiche giuste
fstream& GotoLine(fstream& file, unsigned int num){
	cout << std::ios::beg;
    file.seekg(std::ios::beg);  //ios::beg si riferisci all'inizio dl file
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

