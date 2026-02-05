
#include <iostream>
#include "Polynome.hpp"

Polynome :: Polynome(unsigned int _degre , const double * _coef )
: degre(_degre) , coef(nullptr)
{
    coef = new double [degre + 1]
    for ( size_t i = 0 ; i<= degre ; i++){
        coef[i] = _coef[i];
    }
}

Polynome :: Polynome( const Polynome & src)
: degre(src.degre)
{
    coef = new double [ degre + 1];
    for ( size_t i = 0 ; i<= degre ; i++){
        coef[i] = src.coef[i];
    }
}

Polynome :: ~Polynome()
{
    delete [] coef ;
}
 Polynome:: Polynome deriver() const
{
    const double val[1] = {0}
    if(degre== 0){
        return Polynome(0 , val);
    }
    // Fonction à terminer 
}

Polynome:: operator = (const polynome & p )
{
    degre = p.degre;
    delete [] coef;
    for ( size_t i = 1 ; i <= degre ; i++){
        coef[i] = p.coef[i];
    }
}

bool operator (const Polynome & p)
{
    if( degre > p.degre){
        return false;
       }
    if( degre < p.degre){
        return false;
       }
    if( degre == p.degre){
        return true;
       }
       
    for ( size_t i = 0 ; i< degre ; i++){
        coef[i] = p.coef[i];
       }

       // A VÉRIFIER 
} 

Polynome operateur( const polynome & p1 , const polynome & p2 )
{
    const double big = (p1.degre >= p2.degre ) ? p1 : p2;
    const double small = ( p1.degre < p2.degre) ? p1 : p2;
    double res = big;
    res += small;

}
