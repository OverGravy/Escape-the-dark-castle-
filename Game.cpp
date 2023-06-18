#include "Game.h"

//vigor = vigore [pugno]
//wisdom = sagezza [stealla]
//cunning = astuzia [occhio]

using namespace std;

Game::Game(){
	
}

Game::~Game(){
	
}

//funzione che inizializza il gioco
void Game::Init(){
	system("mode con COLS=700"); //serve per il full screen
	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE); // serve per il full screen
	SendMessage(GetConsoleWindow(),WM_SYSKEYDOWN,VK_RETURN,0x20000000);
	Print_Title(); 
 	Chose_Player_Number(); 
    Chose_Hero(); 			
	Create_Castle();
	
}

//Funzione per far scegliere il numero di giocatori
void Game::Chose_Player_Number(){ 
	bool flag =false;
	
    cout << "In qunati si desidera giocare?  " ;
    cin >> N_Player;	
    
    do{
    	if((N_Player < 0) || (N_Player > 4)){ 
    		cout << endl << "Il numero di giocatori inserito e' non valido, riprovare min 1 max 4 giocatori: ";
    		cin >> N_Player;
		}else flag=true;
	}while(flag == false);   
}

void Game::Chose_Hero(){ // si occupa della scelta dell'eroe
    bool flag;
    int answer;
    string Player_name;
    stringstream tmp;
    
    for (int i = 0; i < N_Player; i++){
        //implementa la possibilità di strivere il ruolo
        flag=false;
        system("cls");
        while (flag!=true){ 
	    	//Qui serve un delay
	        cout << "Il giocatore "<< i + 1 << " sceglie il suo ruolo ..."<<endl<<endl;
	        cout << "1)" << endl;
	        Print_Character("Smith");
			cout << endl << endl;
			cout << "2)" << endl;
	        Print_Character("Taylor");
	        cout << endl << endl;
	        cout << "3)" << endl;
	        Print_Character("Cook");
	        cout << endl << endl;
	        cout << "4)" << endl;
			Print_Character("Abbot");
			cout << endl << endl;
	        cout << "Chi scegli per questa avventura: ";
			cin >> answer;
	        cout << endl;
	        switch (answer){
		        case 1:{ // Selezione SMITH
		            cout << "Giocatore " << i + 1 << " hai scelto SMITH" << endl << endl;
		            cout << "Come ti chiami avventuriero: ";
		            cin >> Player_name;
		            cout << endl;
		            Hero Smith(1,Player_name,"Smith");
		            Smith.Set_Role("Smith");
		            Crew.push_back(Smith); 
				    flag=true; 
				    break;}
		        case 2:{ // Selezione TAYLOR
		            cout << "Giocatore " << i + 1 << " hai scelto TAYLOR" << endl << endl;
					cout << "Come ti chiami avventuriero: ";
		            cin >> Player_name;
		            cout << endl;
					Hero Taylor(2,Player_name,"Taylor");
					Crew.push_back(Taylor);    
		            flag=true;
					break;}
		        case 3:{ // Selezione COOK
		        	cout << "Giocatore " << i+1 << " hai scelto COOK" << endl<<endl;
		    		cout << "Come ti chiami avventuriero: ";
		            cin >> Player_name;
		            cout << endl;
		          	Hero Cook(3,Player_name,"Cook");
		          	Crew.push_back(Cook); 
		        	flag=true;
					break;}
		        case 4:{ // Selezione ABBOT
		        	cout << "Giocatore " << i+1 << " hai scelto ABBOT" << endl<<endl;
		          	cout << "Come ti chiami avventuriero: ";
		            cin >> Player_name;
		            cout << endl;
		          	Hero Abbot(4,Player_name,"Abbot");
		          	Crew.push_back(Abbot);    
		        	flag=true;
					break;}
		        default:{//caso in cui si inserisca un numero sbagliato 
		            cout << "Il valore inserito non corrisponde ad alcun Ruolo disponibile, premi invio per riprovare . . . ";
		            getch();
					flag=false;
		            break;}
	         }
	         system("cls");
	    }
    }
}
//Questa funzione come la precedente poteva venire meglio grazie a stoi o a un convertitore stringa intero puiù esay

void Game::Create_Castle(){ // si occupa della creazione della partita
	srand(time(NULL));

	if(N_Player == 1) N_Card=5; //8 
	else if(N_Player == 2)N_Card=6;	//10
	else if(N_Player == 3)N_Card=6; //14
	else if(N_Player == 4) N_Card=7; //16
	
	for(int i=0;i<N_Card;i++){ 
		int rnum; //il numero a caso da cercare nel file
		rnum=rand()%10+1; //randomizzo 10+
		Chapter Carta(rnum);// lo passo al costruttore 
		Castle.push_back(Carta);//inserisco la carta appena creata
	} 
	Chapter First(11); // è una linea inutilizzata
	Castle.push_front(First); // inserisco la prima carta introduttiva 
}

void Game::Match(){ //gestisce lo svolgimento della partita
	
	srand(time(NULL)); // per avere ogni volta una randomizzazione diversa
	int rnum; //numero randomico 
	string result; // risultato ottenuto dal lancio dei dadi personaggio
	vector<string> PlayerCombo; //vettore dei risultati dei lanci dei dadi personaggio
	bool Life_flag,Score_flag; //flag per la vittoria/perdita
	
	system("cls");
	Print_Card(Castle[0].Get_Line());//scrivo la prima carta
	cout << endl << endl << Castle[0].Get_Text(); // scrivo il testo della carta
	cout << endl << endl <<"L'avventura comincia, premi un tasto qualsiasi . . .";
	getch();
	Castle.pop_front();//escludo la prima carta proprio come un mazzo
	
	Played_Card=0;
	
	while(Castle.size() > 0){ //scorro tutte le carte del mazzo
	
		//i casi sono 2 o mi trovo davanti una carta mostro oppure una carta buona 
		if(Castle[1].Get_Combo(0)!="0"){ // caso in cui sia un mostro 
			Played_Card++;
			system("cls");// cancello tutto prima di scrivere il testo e la win combo

			for(int j=0;j<N_Player;j++){ //inserisco il vettore wincombo più la relativa parte aggiunta dai giocatori
				rnum = rand()%6;
				result=Crew[j].Get_Dice_Face(rnum);
				if(result == "ss"){ // potrei avere dei doppi quindi devo aggiungere il risultato unico 
					Castle[1].Add_WinCombo("saggezza"); 
					Castle[1].Add_WinCombo("saggezza");
				}else if(result == "aa"){
					Castle[1].Add_WinCombo("astuzia");
					Castle[1].Add_WinCombo("astuzia");
				}else if(result == "vv"){
					Castle[1].Add_WinCombo("vigore");
					Castle[1].Add_WinCombo("vigore");
				}else{
					Castle[1].Add_WinCombo(result); // i caso in cui non è un doppio	
				}
			}
			
			Life_flag = false; 
			Score_flag =false;
			
			while(Life_flag==false && Score_flag==false){ // entro nel combattimento sto fino a fine vite o ad aver battuto il mostro
				PlayerCombo.clear(); // ripulisco il vettore del lancio dei dadi ad ogni combattimeto
				system("cls");
				
				Print_Card(Castle[1].Get_Line());// stampo la carta
				cout << endl << endl << Castle[1].Get_Text(); // scrivo il testo della carta
				cout << endl << endl << endl;
				Print_Vector(Castle[1].Get_Vector()); // stampo ciò che rimane nel vettore WinCombo
				cout << "       DANNO--> ("  << Castle[1].Get_damage() << ")"; // scrivo il danno del mostro
			
				cout << endl << endl << "Inizia il combattimento ... " ; 
				getch(); // serve per aspettare un input qualsiasi 
				//aggiunta dadi
				for(int j=0;j<N_Player;j++){ //combattimento, genero un vettore con i risultati dei vari giocatori
					cout << endl << endl << Crew[j].Get_Name() << " e' il tuo turno di combattere . . . ";
					getch();
					rnum = rand()%6; // sorteggio un numero per la faccia del dado
					
					for(int h=0;h<N_Player;h++){ //imposto tutti i dubble a false prima di lanciare pechè se facessero dubble non perdono punti vita
						Crew[h].Set_Dubble(false);	
					}
					
					result = Crew[j].Get_Dice_Face(rnum);
					//controllo doppi
					if(result == "ss"){ // se ottengo un doppio devo farlo valer come un doppio aggiungendo 2 risultati
							PlayerCombo.push_back("saggezza"); // esiste un modo più carino per farlo
							PlayerCombo.push_back("saggezza");
							Crew[j].Set_Dubble(true);	
					}else if(result == "aa"){
							PlayerCombo.push_back("astuzia");
							PlayerCombo.push_back("astuzia");
							Crew[j].Set_Dubble(true);		
					}else if(result == "vv"){
							PlayerCombo.push_back("vigore");
							PlayerCombo.push_back("vigore");
							Crew[j].Set_Dubble(true);	
					}else{
						PlayerCombo.push_back(result);
					}
					cout << "  Il risultato e'... " << "["<<result<<"]";
				}
				
			  	//rimuovo i dadi uguali
				for (int j=0;j<PlayerCombo.size();j++){ // controllo con la win combo cosa ho levato
					for(int k=0;k<Castle[1].Get_Combo_lenght();k++){
						if(PlayerCombo[j] == Castle[1].Get_Combo(k)){
							Castle[1].Delete_position_Combo(k); // rimuovo quelli uguali 
							break; // devo uscire appena levo qualcosa perchè quel dado vale solo per uno, break esce dal for sopra
						}
					}
				}
				
				//controlli su punteggio e vita
				if(Castle[1].Is_combo_empty()){ // controllo se ho battuto il mostro
					Score_flag = true;
					cout << endl << endl << "Congratulazioni avete battuto questo nemico";
					for(int j=0;j<N_Player;j++){
						cout << endl << endl << "A " << Crew[j].Get_Name() << " rimangono: ["<< Crew[j].Get_HP() <<"] punti vita";
					}
				}else{ // in caso non abbia battuto il mostro riscrivo la combinazione rimanente diminuiamo i punti vita 
					cout <<endl <<endl << "Non e' ancora finita . . .  ";
					Print_Vector(Castle[1].Get_Vector()); // stampo ciò che rimane nel vettore WinCombo
					//distribuzione danni solo nel caso non lo abbiamo battuto
					for (int j=0;j<N_Player;j++){ // Qui distribuisco i danni e determino se qualcuno è morto 
						if(Crew[j].Get_Dubble() == false){
							Crew[j].Decrease_HP(Castle[1].Get_damage());
							if(Crew[j].Get_HP()==0 || Crew[j].Get_HP()<0){
								Print_GameOver(Crew[j].Get_Name());
								Life_flag=true;	
							} else{ // nel caso in cui non sia successo nulla scrivo solo quanti punti rimangomo
							cout << endl << endl << "A " << Crew[j].Get_Name() << " rimangono: ["<< Crew[j].Get_HP() <<"] punti vita";
							}	 
						}else{
						cout << endl << endl << Crew[j].Get_Name() << " non hai subito danni, hai ottento un doppio, ti rimangono: [" << Crew[j].Get_HP() <<"]";
						}
					}
				}
				// nel caso in cui il mostro non è stato battuto o è morto qualcuno oppure i giocatori hanno solo perso punti vita	
				getch();
				system("cls");
				cout << endl;
	    	}	
		}
		
		// caso in cui la ca sia un carta buona
		if(Castle[1].Get_Combo(0)=="0"){ 
		    Played_Card++;
			system("cls");// cancello tutto prima di scrivere il testo e la win combo 
			Print_Card(Castle[1].Get_Line());	
			cout << endl << endl << Castle[1].Get_Text()<< endl << endl; // scrivo il testo della carta
			for(int j=0;j<N_Player;j++){
				cout << Crew[j].Get_Name() << " hai ricevuto [2] punti vita . . ."<<endl<<endl;
				Crew[j].Add_HP(2);  
			}
			cout << endl << endl <<"L'avventura continua, premi un tasto qualsiasi . . .";
			getch();
		}
		
		if(Life_flag==true){ // il gicoco conclude solo con la fine dei punti vita di uno dei giocatori perciò controllo se è successo
			break;	
		}
		
		Castle.pop_front(); //estraggo la carta appena giocata	
    }
    //fine del gioco 
    if(Life_flag == false){ // se finiscono le carte e sono ancora vivi
    	Print_Win();
    	Print_Close();
	}
    
}

void Game::Show_Score(){ //Scivo il punteggio
	cout << "-------------------------------------------------------------------------------"<<endl << endl;
	cout << "PUNTEGGIO:                                                                  ";
	cout<< endl << endl <<  "Congratulazioni avete raggiunto la carta numero [" << Played_Card << "]";
	for (int i=0;i<N_Player;i++){
		if(Crew[i].Get_HP()>0){
			cout << endl << endl << Crew[i].Get_Name() << "e' rimasto con [" << Crew[i].Get_HP() << "]";
		}else{
			cout << endl << endl << Crew[i].Get_Name() << "e' morto R.I.P";
		}
	}
	cout <<endl << endl << "-------------------------------------------------------------------------------";
}

void Game::Close(){ //la chiusura
	Print_Close();
	Show_Score();
	cout << endl << endl << "Grazie per aver giocato <3";
	getch();
}

//questa funzionbe serviva a scopo di test
void Game::Show_Every_Card(){ // mostra tutto ciò che è contenuto nel
	for(int i=0;i<N_Card;i++){
		cout << endl << Castle[i].Get_Text();
		for (int j=0;j<Castle[i].Get_Combo_lenght();j++){
			cout << "[" << Castle[i].Get_Combo(j) <<"] ";
		}
		cout << " " << Castle[i].Get_damage() << endl << endl;
	}
}
