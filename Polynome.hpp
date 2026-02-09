#ifndef POLYNOME_HPP
#define POLYNOME_HPP

class Polynome
{
    private :
    unsigned int degre;
    double * coef;

    public:

    Polynome( unsigned int  ,const double * );
    Polynome() = delete ;
    Polynome(const Polynome & src);
    ~Polynome() ;
    inline const double getDegree(){ return degre; };
    Polynome deriver() const ;
    Polynome operator = (const Polynome & p );
    friend bool operator== (const Polynome & p1, const Polynome & p2);
    friend Polynome operator+ ( const Polynome & p1 , const Polynome & p2 );

};


#endif