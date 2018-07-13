/*********************************************************************************
*                           GNU GENERAL PUBLIC LICENSE                           *
*                            Version 3, 29 June 2007                             *
*          Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>  *
*           author:Antonino Fortunato email: antoninofortunato.pc@gmail.com      *
*********************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//DICHIARAZIONE FUNZIONI 
void scrivi_wl(string stringa);


const char alfabeto[62] = 
{
	'A', 'B', 'C', 'D', 'E', 'F', 'G',       //elementi su cui vengono effettuate le combinazioni
	'H', 'I', 'J', 'K', 'L', 'M', 'N',       //se si desidera ampliare la lista  aggiungere gli altri caratteri
	'O', 'P', 'Q', 'R', 'S', 'T', 'U',       //ricordando di modificare il numero degli elementi 
	'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 
	'c', 'd', 'e', 'f', 'g', 'h', 'i', 
	'j', 'k', 'l', 'm', 'n', 'o', 'p', 
	'q', 'r', 's', 't', 'u', 'v', 'w', 
	'x', 'y', 'z', '0', '1', '2', '3', 
	'4', '5', '6', '7', '8', '9', 
};

void Genera(unsigned int length, string r)
{
	if(length == 0) 
	{
		std::cout << r << "\n"; 
	        scrivi_wl(r);
		return;
	}

	for(unsigned int i = 0; i < 62; i++) // itera tutti gli elementi
	{
		std::string word= r + alfabeto[i];
		Genera(length-1, word);
	}
}


void scrivi_wl (string stringa)
{
	ofstream wordlist("\wordlist.txt", ios::app);
	wordlist<<stringa;
	wordlist<< "\n";
}


void start()
{
	 int scelta=0;
	 int stringlength;
	 
	 cout<<"\n\nScegli una delle seguenti opzioni:\n 1)Genera una nuova Wordlist\n 2)Continua la generazione di una Wordlist gia' esistente\n\n";
	 cout<<"Inserisci l'opzione scelta e premi invio:\n";
	 cin>>scelta;
	 
	 if (scelta==1)
	 { 
	
	        cout<< "Inserire il numero di caratteri da cui avviare il generatore (es. 3 = aaa, aab...): ";
	        cin>> stringlength;
	        ofstream wordlist("\wordlist.txt"); //crea una nuova wordlist    
	        	
	        	while(1)
                        {
			  Genera(stringlength, "");
			  stringlength++;
	         	}
	     }
   
   
    if (scelta==2)
    {
        cout<<"La wordlist.txt verrà ampliata, se il file non esiste verrà creato\n";
	    cout<<"Inserire il numero di caratteri da cui avviare il generatore (es. 3 = aaa, aab...): ";
	    cin>> stringlength;
		
    	   while(1)
            {
	       Genera(stringlength, "");
	       stringlength++;
	    }
    	
    } else {
		
           cout<<"\n\nHai inserito un valore errato il programma verrà arrestato\n";
	   system("pause");
		
	   }

}

int main()
{
	    cerr << "\n\t\t\t Wordlist Generator \n\n"; 
	    cout<<"Questo programma genera/amplia  una wordlist nella cartella corrente in cui si trova.\nIl file creato/ampliato e' wordlist.txt.\n";
	    cout<<"Quando si ritiene di aver raggiunto un numero sufficiente di elementi e'\nsufficiente interrompere il programma.\n";
	    start();

	return 0;
}






