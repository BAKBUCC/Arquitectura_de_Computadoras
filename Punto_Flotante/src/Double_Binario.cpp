#include "Double_Binario.h"

//PARTEEE 2

Double_Binario::Double_Binario()
{
    //ctor
}

double Double_Binario::retornar_Significando_en_deci(bitset <52> Significando)
{
    double decimal=0;
    for(int i=1; i<23; i++)
    {
        if(Significando.test(i)==true)
        {
            decimal+=pow(2,-i);
        }
    }
    return 1+decimal;
}

int Double_Binario::retornar_exp_en_deci(bitset <11> exp_biased)
{
    int exp=0;
    for(int i=0; i<11; i++)
    {
        if(exp_biased.test(i)==true)
        {
            exp+=pow(2,i);
        }
    }
    exp-=(pow(2,(11-1))-1);
    return exp;
}

int Double_Binario::retornar_signo(bitset <1> signo)
{
    if(signo.any()==true)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

double Double_Binario::Valor_real(bitset <1> signo, bitset <11> exp_biased, bitset <52> Significando)
{
    double numero = retornar_Significando_en_deci(Significando);
    int exp = retornar_exp_en_deci(exp_biased);
    int pos_o_nega=retornar_signo(signo);
    return pos_o_nega*(numero*pow(2,exp));
}

void Double_Binario::activacion_signo(bitset <1> &signo, double n)
{
    if(n>=0)
    {
        signo.reset();
    }
    else
    {
        signo.set();
    }
}


void Double_Binario::activacion_exp(bitset <11> &exp_biased, int v_exp_int)
{
    int exp= v_exp_int + (pow(2,11-1)-1);
    int *i = new int;
    for(*i=0; *i<11; (*i)++)
    {
        if(exp%2==1)
        {
            exp_biased.set(*i);
        }
        else
        {
            exp_biased.reset(*i);
        }
        exp/=2;
    }
    delete i;
}

void Double_Binario::activacion_Significando(bitset <52> &Significando, double parte_decimal, int parte_entera, int &v_exp_int)
{
    int *i=new int;
    for(*i=0; *i<52 && parte_entera>1; (*i)++)
    {
        if(parte_entera%2==1)
        {
            Significando.set(51);
            Significando >>= 1;
        }
        else
        {
            Significando.reset(51);
        }
        parte_entera/=2;
    }

    Significando <<= 2;

    v_exp_int=*i;

    double m;
    for(int j=*i ; j<52; j++)
    {
        parte_decimal = modf(parte_decimal*2, &m);
        if(m>0)
        {
            Significando.set(51-j);
        }
        else
        {
            Significando.reset(51-j);
        }
    }
    delete i;
}

void Double_Binario::Punto_Flotante(double n)
{
    activacion_signo(signo,n);

    if(n<0)
    {
        n=-n;
    }

    double parte_decimal, parte_entera;
    parte_decimal = modf(n, &parte_entera);

    parte_int=int(parte_entera);

    activacion_Significando(Significando,parte_decimal,parte_int,v_exp_int);

    activacion_exp(exp_biased,v_exp_int);

    cout<<signo<<" "<<exp_biased<<" "<<Significando<<endl;

    cout<<"\ncomprobación de su valor"<<endl;
    cout<<"------------------------"<<endl;

    cout<<Valor_real(signo,exp_biased,Significando)<<endl;
}

