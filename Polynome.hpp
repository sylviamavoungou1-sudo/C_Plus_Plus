#ifndef POLYNOME_HPP
#define POLYNOME_HPP

class Polynome
{
    private :
    unsigned int degre;
    double * coef;

    public:

    Polynome( unsigned int & ,const double * &);
    Polynome = delete ;
    Polynome(const polynome & src);
    ~Polynome() ;
    inline const double getDegree(){ return degre; };
    Polynome deriver() const ;
    Polynome operator = (const polynome & p );
    friend bool operator (const Polynome & p);
    friend Polynome operateur( const polynome & p1 , const polynome & p2 );

};


#endif