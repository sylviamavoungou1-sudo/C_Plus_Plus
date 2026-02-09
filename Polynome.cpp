#include <iostream>
#include <c.math>
#include "Polynome.hpp"

Polynome :: Polynome(unsigned int _degre , const double * _coef )
: degre(_degre) , coef(nullptr)
{
    coef = new double [degre + 1];
    for ( size_t i = 0 ; i<= degre ; i++){
        coef[i] = _coef[i];
    }
}

Polynome :: Polynome( const Polynome & src)
: degre(src.degre), coef(src.coef)
{
    coef = new double [degre+1];
    for ( size_t i = 0 ; i<= degre ; i++){
        coef[i] = src.coef[i];
    }
}

Polynome :: ~Polynome()
{
    delete [] coef ;
}
 Polynome Polynome:: deriver() const
{
    const double val[1] = {0};
    if(degre== 0){
        return Polynome(0 , val);
    }
    double * p = new double [degre];
    for (size_t i = 1 ; i<= degre ; i++){
        p[i-1] = coef[i] * i;
    }
    Polynome res(degre-1 , p);
    delete [] p;
    return res ;
}

Polynome Polynome:: operator = (const Polynome & p )
{
    degre = p.degre;
    delete [] coef;
    for ( size_t i = 1 ; i <= degre ; i++){
        coef[i] = p.coef[i];
    }
    return Polynome(degre , coef);
}

bool operator== (const Polynome & p1, const Polynome & p2)
{
    if( p1.degre != p2.degre){
        return false;
       }
 
    for ( size_t i = 0 ; i<= p1.degre ; i++){
        if (p1.coef[i] != p2.coef[i])
            return false;
       }
        return true;
} 

Polynome operator+ ( const Polynome & p1 , const Polynome & p2 )
{
    const Polynome big = (p1.degre >= p2.degre ) ? p1 : p2;
    const Polynome small = ( p1.degre < p2.degre) ? p1 : p2;
    Polynome res(big);
    for ( size_t i = 0 ; i<= small.degre ; i++){
        res.coef[i] += small.coef[i] ;
    }
    return res ; 
}
ostream & operator<< (ostream & os , const Polynome & p ){
    for(size_t i = p.degre + 1 ; i>0 ; i--){
        os<< '+'<<p.coef[i-1]<<"x^"<< i-1;
    return os;
    }
}


double Polynome :: operator() (double x)
{
    double res = 0;
    for ( size_t i =0 ; i<= degre ; ++i) 
    res += coef [i] * pow(x , i);

    return res ;
}