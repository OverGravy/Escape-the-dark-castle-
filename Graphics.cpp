#include "Graphics.h"

using namespace std;

void Print_Title(){ //stampa titolo
	string line;
	fstream Title;
	Title.open("./Files/Screen/Title.txt");
	if(Title.is_open()){
		while(getline(Title,line)){
			cout << line << endl;
		}
	}else{
		cout << endl << endl << "Il file Title.txt non si e' aperto correttamente . . .";
	}
	Title.close();
}

void Print_Card(const int & line){ // Stampo carta
	string stream,location,l;
	stringstream tmp; // serve per la conversione di un numero in una stringa
    tmp << line; //converto in stringa
	location = "./Files/Cards/Image/"+tmp.str()+ ".txt"; 
	fstream Card;
	Card.open(location.c_str());
	
	if(Card.is_open()){ // se la carta si apre correttamente allora stampa la grafica della carta
		while(getline(Card,stream)){
			cout << stream << endl;	//scrive linea per linea 
		}	
		}else{
			cout << endl << endl << "Il file " << line <<".txt non si e' aperto correttamente . . .";
		}
		Card.close();
}		

void Print_Vector(const vector<string> & v){ // stampo un vettore
		vector<string>::const_iterator it;
		for (it = v.begin();it!=v.end();it++){
			cout << "[" << *it << "] ";
		}
}

void Print_Character(const string & file){ // stampo un personaggio 
	string location,stream;
	location = "./Files/Character/Image/" + file +".txt";
	fstream Card;
	Card.open(location.c_str());
	
	if(Card.is_open()){
		while(getline(Card,stream)){
			cout << stream << endl;	//scrive linea per linea 
	}	
	}else{
		cout << endl << endl << "Il file " << file <<".txt non si e' aperto correttamente . . .";
	}
	Card.close();
}

void Print_GameOver(const string & name){
	string line;
	fstream GameOver;
	GameOver.open("./Files/Screen/GameOver.txt");
	system("cls");
	if(GameOver.is_open()){
		while(getline(GameOver,line)){
			cout << line << endl;
		}
	}else{
		cout << "Il file GameOver.txt non si e' aperto correttamente . . ."<< endl;
	}
	GameOver.close();
	
	cout << endl << endl << name << " e' morto R.I.P";	
}

void Print_Win(){
    string line;
	fstream Win;
	Win.open("./Files/Screen/Win.txt");
	system("cls");
	if(Win.is_open()){
		while(getline(Win,line)){
			cout << line << endl;
		}
	}else{
		cout << "Il file Win.txt non si e' aperto correttamente . . ."<< endl;
	}
	Win.close();
	cout << endl << endl << "Congratulazioni siete riusciti a scappare dal Castello, nessuno è morto. . .";		
	getch();
}

void Print_Close(){
	string line;
	fstream Close;
	Close.open("./Files/Screen/Title.txt");
	system("cls");
	if(Close.is_open()){
		while(getline(Close,line)){
			cout << line << endl;
		}
	}else{
		cout << "Il file Title.txt non si e' aperto correttamente . . ."<< endl;
	}
	Close.close();			
}
