#include <cmath>
#include "Polynome.hpp"

Polynome ::Polynome(unsigned int _degre, const double *_coef)
    : degre(_degre), coef(nullptr)
{
    coef = new double[degre + 1];
    for (size_t i = 0; i <= degre; i++)
    {
        coef[i] = _coef[i];
    }
}

Polynome ::Polynome(const Polynome &src)
    : degre(src.degre), coef(src.coef)
{
    coef = new double[degre + 1];
    for (size_t i = 0; i <= degre; i++)
    {
        coef[i] = src.coef[i];
    }
}

Polynome ::~Polynome()
{
    delete[] coef;
}
Polynome Polynome::deriver() const
{
    const double val[1] = {0};
    if (degre == 0)
    {
        return Polynome(0, val);
    }
    double *p = new double[degre];
    for (size_t i = 1; i <= degre; i++)
    {
        p[i - 1] = coef[i] * i;
    }
    Polynome res(degre - 1, p);
    delete[] p;
    return res;
}

Polynome Polynome::operator=(const Polynome &p)
{
    if (coef != p.coef)  
    {
        delete[] coef;                   // libèreration de l'ancien tableau
        degre = p.degre;
        coef = new double[degre + 1];    
        for (size_t i = 0; i <= degre; i++)
            coef[i] = p.coef[i];         // on copie tout les coefficient
    }
    return *this;                        // retour du polynome

}

bool operator==(const Polynome &p1, const Polynome &p2)
{
    if (p1.degre != p2.degre)
    {
        return false;
    }

    for (size_t i = 0; i <= p1.degre; i++)
    {
        if (p1.coef[i] != p2.coef[i])
            return false;
    }
    return true;
}

Polynome operator+(const Polynome &p1, const Polynome &p2)
{
    const Polynome big = (p1.degre >= p2.degre) ? p1 : p2;
    const Polynome small = (p1.degre < p2.degre) ? p1 : p2;
    Polynome res(big);
    for (size_t i = 0; i <= small.degre; i++)
    {
        res.coef[i] += small.coef[i];
    }
    return res;
}

Polynome operator-(const Polynome &p1, const Polynome &p2)

{
    double *temporelle = new double[p2.degre + 1]; // création dynamique d'un tableau de degre p2
    for (size_t i = 0; i <= p2.degre; i++)
    {
        temporelle[i] = -1 * (p2.coef[i]); // on stocke l'opposer de p2 dans le tableau
    }
    Polynome polysoustraction(p2.degre, temporelle);                                    // Creation d'un polynome correspondant a l'opposer de p2
    delete[] temporelle;                                                                // important
    const Polynome &big = (p1.degre >= polysoustraction.degre) ? p1 : polysoustraction; // On determine le plus grand et le plus petit polynome
    const Polynome &small = (p1.degre < polysoustraction.degre) ? p1 : polysoustraction;
    Polynome res(big); // on copie le plus grand polynome dans res
    for (size_t i = 0; i <= small.degre; i++)
    {
        res.coef[i] += small.coef[i]; // On additionne les deux polynomes
    }
    return res;
}


Polynome operator*(const Polynome& p, double reel)
{
    Polynome res(p); // on copie  p dans res 

    for (unsigned int i = 0; i <= p.degre; i++)
    {
        res[i] *= reel;   // multiplication de res par reel
    }

    return res;
}

std::ostream &operator<<(std::ostream &os, const Polynome &p)
{
    bool premier_monome = true; // booléens pour connaitre si c'est le premier monome

    for (int i = p.degre; i >= 0; i--)
    {
        double mon_coef = p.coef[i];

        if (mon_coef != 0)
        {
            // Gestion des signes
            if (mon_coef > 0 && !premier_monome)
                os << '+';
            else if (mon_coef < 0)
                os << '-';

            if ((mon_coef != 1 && mon_coef != -1) || i == 0) // gestion de coefficient= 1 || -1 et des degre= 0
                os << std::abs(mon_coef);                    // on met la valeur absolu pour la condition contenu dans notre if

            if (i > 1)
                os << "x^" << i;
            else if (i == 1)
                os << "x";

            premier_monome = false;
        }
    }

    return os;
}

double Polynome ::operator()(double x)
{
    double res = 0;
    for (size_t i = 0; i <= degre; ++i)
        res += coef[i] * pow(x, i);

    return res;
}