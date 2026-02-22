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
      cout << "___________Etat des emplacements___________" << endl;

      cout << " " << endl;

      for (size_t i = 0; i < 10; i++)
      {
         cout << "Emplacement [" << i << "] : ";
         if (emplacements[i] == nullptr)
         {
            cout << "Vide" << endl;
         }
         else
            cout << *(emplacements[i]) << endl;
      }

      cout << "1.saisir un Polynome" << endl;
      cout << "2.Addition" << endl;
      cout << "3.Soustraction " << endl;
      cout << "4.Derivation " << endl;
      cout << "5.Multiplication par un reel " << endl;
      cout << "votre choix >> ";
      cin >> choix;

      switch (choix)
      {
      case 1:
      {
         cout << "Dans quel emplacement voulez vous saisir ? ";
         unsigned int emp = 0;
         cin >> emp;
         if (emp >= 10)
         {
            cout << "emplacement invalide " << endl; // limiter la saisie de l'utilisateur entre 0 et 9

            break;
         }
         cout << "Quel est le degre de votre Polynome ? ";
         unsigned int d = 0;
         cin >> d;
         cout << " Quels sont les coefficients de votre Polynome ? " << endl;

         double *donne_coef = new double[d + 1];

         for (size_t i = 0; i <= d; i++)
         {
            cout << "Coefficient x^" << i << ":" << endl;
            cin >> donne_coef[i];
         }

         delete emplacements[emp]; // s'il existe un polynome dans l'emplacement choisi on le supprime

         emplacements[emp] = new Polynome(d, donne_coef);

         delete[] donne_coef; // IMPORTANT

         break;
      }
      case 2:
      {
         unsigned int emp1 = 0;
         unsigned int emp2 = 0;
         unsigned int empResultat = 0;

         cout << "_________ADDITION__________" << endl;
         cout << " " << endl;
         cout << "Donnez l'emplacement du premier polynome a additionner >> ";
         cin >> emp1;
         cout << "Donnez l'emplacement du deuxième polynome a additionner >> ";
         cin >> emp2;

         if (emp1 >= 10 || emp2 >= 10 || emplacements[emp1] == nullptr || emplacements[emp2] == nullptr) // controle de la saisie de l'utilisateur
         {
            cout << "Operation impossible , selectionez un emplacement existant et contenant un polynome" << endl;

            break;
         }
         do
         {
            cout << "Dans quel emplacement voulez-vous stocker votre calcul >> ";
            cin >> empResultat;
         } while (empResultat >= 10); // controle de la saisie de l'utilisateur dans le cas où l'emplacement > 10

         delete emplacements[empResultat];                                                        // S'il existe un polynome à cette emplacement on le supprime
         emplacements[empResultat] = new Polynome((*emplacements[emp1]) + (*emplacements[emp2])); // emplacement reserver pour stocker le nouveau polynome

         break;
      }
      case 3:
      {
         unsigned int emp1 = 0;
         unsigned int emp2 = 0;
         unsigned int empResultat = 0;

         cout << "__________Soustraire___________" << endl;
         cout << " " << endl;

         cout << "Donnez l'emplacement du premier polynome a soustraire >> ";
         cin >> emp1;
         cout << "Donnez l'emplacement du deuxième polynome a soustraire >> ";
         cin >> emp2;
         if (emp1 >= 10 || emp2 >= 10 || emplacements[emp1] == nullptr || emplacements[emp2] == nullptr)
         {
            cout << "Operation impossible , selectionez un emplacement existant et contenant un polynome" << endl; // Gestion des cas où il ne contient rien dans l'emplacement des polynome à soustraire

            break;
         }
         do
         {
            cout << "Dans quel emplacement voulez-vous stocker votre calcul >> ";
            cin >> empResultat;
         } while (empResultat >= 10);

         delete emplacements[empResultat];
         emplacements[empResultat] = new Polynome((*emplacements[emp1]) - (*emplacements[emp2]));

         break;
      }
      case 4:
      {
         unsigned int emp1 = 0;
         unsigned int empResultat = 0;

         cout << " ______DERIVER_____" << endl;
         cout << " " << endl;

         do
         {
            cout << " Donner l'emplacement du Polynome que vous voulez dériver >> ";
            cin >> emp1;
         } while (emp1 >= 10 || emplacements[emp1] == nullptr);

         do
         {
            cout << " Dans quel emplacement voulez-vous stocker votre calcul  >> ";
            cin >> empResultat;
         } while (empResultat >= 10);

         delete emplacements[empResultat];
         emplacements[empResultat] = new Polynome((*emplacements[emp1]).deriver());

         break;
      }
      case 5:
      {
         unsigned int emp1 = 0;
         double reel = 0;
         unsigned int empResultat = 0;

         cout << " _______MULTIPLICATION______" << endl;
         cout << " " << endl;

         do
         {
            cout << "Donnez l'emplacement du Polynome que vous voulez multiplier >> ";
            cin >> emp1;
         } while (emp1 >= 10 || emplacements[emp1] == nullptr);

         cout << "Donnez le reel avec lequel vous voulez multiplier votre Polynome >> ";
         cin >> reel;

         do
         {
            cout << " Dans quel emplacement voulez-vous stocker votre calcul  >> ";
            cin >> empResultat;
         } while (empResultat >= 10);

         delete emplacements[empResultat];
         emplacements[empResultat] = new Polynome((*emplacements[emp1]) * reel);
         break;
      }
      }

   } while (choix != 0);

   for (size_t i = 0; i < 10; i++)
   {
      delete emplacements[i]; // important pour eviter les fuites de mémoire
   }
   return 0;
}
