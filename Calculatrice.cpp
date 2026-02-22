#include <iostream>
#include "Polynome.hpp"
using namespace std;

int main()
{

   int choix = 0;
   Polynome *emplacements[10];     
   for (size_t i = 0; i < 10; i++)
   {
      emplacements[i] = nullptr;  
   }

   do
   {
      for (size_t i = 0; i < 10; i++)
      {
         cout << "Emplacement [" << i << "] : ";
         if (emplacements[i] == nullptr)
         {
            cout << "aucun polynome" << endl;
         }
         else
            cout << *(emplacements[i]) << endl;
      }

      cout << "1.saisir" << endl;
      cout << "2.Addition" << endl;
      cout << "3.Soustraction " << endl;
      cout << "4.Derivage" << endl;
      cout << "votre choix >> ";
      cin >> choix;

      switch (choix)
      {
      case 1:
      {
         cout << "Dans quel emplacement voulez vous saisir ? ";
         unsigned int emp = 0;
         cin >> emp;
         cout << "Quel est le degre de votre Polynome ?";
         unsigned int d = 0;
         cin >> d;
         cout << " Quels sont les coefficients de votre Polynome ? " << endl;
         double *donne_coef = new double[d + 1];
         for (size_t i = 0; i <= d; i++)
         {
            cout << "Coefficient x^" << i << ":" << endl;
            cin >> donne_coef[i];
         }
         
         emplacements[emp] = new Polynome(d, donne_coef);

         delete[] donne_coef; // IMPORTANT
         break;
      }
      case 2:
      {
         unsigned int emp1 = 0;
         unsigned int emp2 = 0;
         unsigned int empResultat = 0;
         do{
         cout << "Donnez l'emplacement du premier polynome à additionner";
         cin >> emp1;
         cout << "Donnez l'emplacement du deuxième polynome à additionner";
         cin >> emp2;
         }while( emplacements[emp1] ==nullptr || emplacements[emp2] ==nullptr);
         cout << "Dans quel emplacement voulez-vous stocker votre calcul ";
         cin >> empResultat;
         emplacements[empResultat] = new Polynome((*emplacements[emp1]) + (*emplacements[emp2]));   // emplacement reserver pour stocker le nouveau polynome
         break;
      }
      case 3:
      {
         unsigned int emp1 = 0;
         unsigned int emp2 = 0;
         unsigned int empResultat = 0;
         do{
         cout << "Donnez l'emplacement du premier polynome à soustraire";
         cin >> emp1;
         cout << "Donnez l'emplacement du deuxième polynome à soustraire";
         cin >> emp2;
         }while( emplacements[emp1] ==nullptr || emplacements[emp2] ==nullptr);
         cout << "Dans quel emplacement voulez-vous stocker votre calcul ";
         cin >> empResultat;

         emplacements[empResultat] = new Polynome((*emplacements[emp1]) - (*emplacements[emp2]));
         break;
      }
      case 4:
      {
         unsigned int emp1 = 0;
         unsigned int empResultat = 0;
         do{
         cout << " Donner l'emplacement du Polynome que vous voulez dériver";
         cin >> emp1;
         }while(emplacements[emp1] ==nullptr );
         cout << " Dans quel emplacement voulez-vous stocker votre calcul";
         cin >> empResultat;
         emplacements[empResultat] = new Polynome((*emplacements[emp1]).deriver());
         break;
      }
      }

   } while (choix != 0);

   for(size_t i = 0 ; i<10 ; i++){
      delete emplacements[i];       // important pour eviter les fuites de mémoire
   }

   return 0;
}