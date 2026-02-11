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
    inline double & operator [] (size_t i)
{
    if(i<= degre)
    return coef[i];
    else
    throw std::runtime_error("erreur");
}

inline const double & operator[] (size_t i)const
{
     if(i<= degre)
    return coef[i];
    else
    throw std::runtime_error("erreur");
}
    double operator() (double x);
    friend bool operator== (const Polynome & p1, const Polynome & p2);
    friend Polynome operator+ ( const Polynome & p1 , const Polynome & p2 );
     friend Polynome operator- ( const Polynome & p1 , const Polynome & p2 );
    friend std ::ostream& operator<< (std::ostream& os , const Polynome & p );
};


#endif