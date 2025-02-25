#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator)
{
    _numerator = numerator;
    while(denominator != 0)
    {
        _denominator = denominator;
    } 
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    Fraction Fsum;
    Fsum._numerator = (this->_numerator*frac._denominator)+(this->_denominator*frac._denominator);
    Fsum._denominator = this->_denominator*frac._denominator;

    Fsum.simplify();

    return Fraction(Fsum._numerator, Fsum._denominator);
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    Fraction Fsub;
    Fsub._numerator = (this->_numerator*frac._denominator)-(this->_denominator*frac._denominator);
    Fsub._denominator = this->_denominator*frac._denominator;

    Fsub.simplify();

    return Fraction(Fsub._numerator, Fsub._denominator);
}

fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    Fraction Fprod;
    Fprod._numerator = this->_numerator*frac._numerator;
    Fprod._denominator = this->_denominator*frac._denominator;

    Fprod.simplify();

    return Fraction(Fprod._numerator, Fprod._denominator);
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{
    Fraction Fdiv;
    Fdiv._numerator = this->_numerator*frac._denominator;
    Fdiv._denominator = this->_denominator*frac._numerator;

    Fdiv.simplify();

    return Fraction(Fdiv._numerator, Fdiv._denominator);
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    frac.simplify();
    return Fraction(frac._numerator, frac._denominator);
}

void fractions::Fraction::simplify()
{ 
   int aux = gcd(_numerator, _denominator);
   _numerator=_numerator/aux;
   _denominator=_denominator/aux;
}

int fractions::Fraction::gcd(int a, int b)
{
    int num_ref;
    int gdc;

    (a>b)? : num_ref=a, num_ref=b;

    for(int i=1; i<num_ref; i++)
    {
       if(a%i==0 && b%i==0)
       {
           gdc = i;
       }
    }

    return gdc;
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    bool band = false;
      if(frac._numerator==this->_numerator && frac._denominator==this->_denominator)
      {
         band = true;
      }
    return band;
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    return os;
}