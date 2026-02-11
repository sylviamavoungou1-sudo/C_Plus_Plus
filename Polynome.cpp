#include <iostream>
#include <cmath>
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


Polynome operator- ( const Polynome & p1 , const Polynome & p2 )

{
    double* temporelle = new double[p2.degre +1];
    for( size_t i = 0 ; i<= p2.degre ; i++){
        temporelle[i] = - 1 *(p2.coef[i]);
    }
    Polynome polysoustraction(p2.degre , temporelle);
    delete[] temporelle;
    const Polynome& big = (p1.degre >= polysoustraction.degre ) ? p1 : polysoustraction;
    const Polynome& small = ( p1.degre < polysoustraction.degre) ? p1 : polysoustraction;
    Polynome res(big);
    for ( size_t i = 0 ; i<= small.degre ; i++){
        res.coef[i] += small.coef[i] ;
    }
    return res ; 
}





std::ostream& operator<< (std::ostream& os , const Polynome & p ){
     bool premier_monome = true;
     for(size_t i = p.degre; i > 0; i--){

        double mon_coef = p.coef[i];

        if(mon_coef != 0){ // Ignorer les coefficients nuls
            if(!premier_monome){  // Si ce n'est pas le premier monome
                if(mon_coef > 0)
                    os << '+';
                else
                    os << '-';
            }
            else {  // Si c'est le premier monome
                if(mon_coef < 0)
                    os << '-';
                premier_monome = false;
            }

            // Si le coefficient est +1, on n'affiche pas le 1, juste "x"
            if(mon_coef == 1){
                os << "x"; // Affiche juste 'x'
            }
            // Si le coefficient est -1, on affiche "-x"
            else if(mon_coef == -1){
                os << "-x"; // Affiche '-x'
            }
            else {
                os << mon_coef;  // Affichage normal du coefficient
                // Si ce n'est pas un terme constant (i > 0), on affiche "x^i"
                if(i > 0) {
                    os << "x";
                    if(i > 1) {
                        os << "^" << i; // Afficher x^i si le degré est supérieur à 1
                    }
                }
            }
        }
    }

  if(p.coef[0] != 0 || premier_monome == false) { // Si le terme constant est non nul
        if(!premier_monome) {
            os << (p.coef[0] > 0 ? "+" : "-");
        }
        os << p.coef[0]; // Affichage du terme constant
    }

     return os;

      }
        
double Polynome :: operator() (double x)
{
    double res = 0;
    for ( size_t i =0 ; i<= degre ; ++i) 
    res += coef [i] * pow(x , i);

    return res ;
}




