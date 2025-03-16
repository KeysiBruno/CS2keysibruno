#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator)
{
    if(denominator == 0)
    {
        cout<<"Denominator cant be 0, lets change it to another number."<<endl;
       _denominator = 1+rand()%10;
    }
    else
    {
        _denominator = denominator;
    }
    _numerator = numerator;
    simplify();
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    Fraction Fsum;
    Fsum._numerator = (this->_numerator*frac._denominator)+(this->_denominator*frac._numerator);
    Fsum._denominator = this->_denominator*frac._denominator;

    Fsum.simplify();

    return Fsum;
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    Fraction Fsub;
    Fsub._numerator = (this->_numerator*frac._denominator)-(this->_denominator*frac._numerator);
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
    if(b==0) return a;
    return gcd(b, a%b);
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    bool band = false;

    Fraction x = frac;
    Fraction y = *this;

    x.simplify();
    y.simplify();

      if(x._numerator==y._numerator && x._denominator==y._denominator)
      {
         band = true;
      }
    return band;
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    os << frac._numerator << "/" << frac._denominator;
    return os;
}