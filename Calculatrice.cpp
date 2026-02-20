#include <iostream>
#include "Polynome.hpp"
using namespace std;

int main()
{
 Polynome* emplacements[10];
 //Polynome * emplacement = new Polynome[10]; quand on connait la taille du tableau on utilise le C
   for(size_t i = 0 ; i< 10 ; i++){ 
	emplacements[i] = nullptr;
   }
   for(size_t i = 0 ; i<10 ; i++){
	if (emplacements[i] == nullptr){
		cout<< "Emplacement ["<< i+1 << "]"<< ": aucun polynome"<< endl;
   }
   else
   		cout<< * (emplacements[i])<< endl;
}

int choix;
cout<< "1.saisir"<< endl;
cout<< "2.Addition"<< endl;
cout<< "3.Soustraction "<< endl;
cout<< "4.Derivage"<< endl;
cout<< "5.Affichage"<< endl;
cout<< "votre choix >> ";
cin>> choix;




}