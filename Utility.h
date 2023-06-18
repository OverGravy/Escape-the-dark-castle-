#ifndef __UTILITY__
#define __UTILITY__

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>

using namespace std;

//Questa funzione serve a dividere le parole a inserirle come elementi nel vettore
size_t Split(const string &txt, vector<string> &strs, char ch);

//Questa funzione considera del file solo la perte interessante per o noi ovvero la linea con le statistiche giuste
fstream& GotoLine(fstream& file, unsigned int num);

#endif
