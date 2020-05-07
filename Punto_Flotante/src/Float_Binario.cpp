#include "Float_Binario.h"
#include "Double_Binario.h"

//PARTEEE 1

Float_Binario::Float_Binario()
{

}

float Float_Binario::retornar_Significando_en_deci(bitset <23> Significando)
{
    float decimal=0;
    for(int i=1; i<23; i++)
    {
        if(Significando.test(i)==true)
        {
            decimal+=pow(2,-i);
        }
    }
    return 1+decimal;
}

int Float_Binario::retornar_exp_en_deci(bitset <8> exp_biased)
{
    int exp=0;
    for(int i=0; i<8; i++)
    {
        if(exp_biased.test(i)==true)
        {
            exp+=pow(2,i);
        }
    }
    exp-=(pow(2,(8-1))-1);
    return exp;
}

int Float_Binario::retornar_signo(bitset <1> signo)
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

float Float_Binario::Valor_real(bitset <1> signo, bitset <8> exp_biased, bitset <23> Significando)
{
    float numero = retornar_Significando_en_deci(Significando);
    int exp = retornar_exp_en_deci(exp_biased);
    int pos_o_nega=retornar_signo(signo);
    return pos_o_nega*(numero*pow(2,exp));
}

void Float_Binario::activacion_signo(bitset <1> &signo, float n)
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


void Float_Binario::activacion_exp(bitset <8> &exp_biased, int v_exp_int)
{
    int exp= v_exp_int + (pow(2,8-1)-1);
    int *i = new int;
    for(*i=0; *i<8; (*i)++)
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

void Float_Binario::activacion_Significando(bitset <23> &Significando, float parte_decimal, int parte_entera, int &v_exp_int)
{
    int *i=new int;
    for(*i=0; *i<23 && parte_entera>1; (*i)++)
    {
        if(parte_entera%2==1)
        {
            Significando.set(22);
            Significando >>= 1;
        }
        else
        {
            Significando.reset(22);
        }
        parte_entera/=2;
    }

    Significando <<= 2;

    v_exp_int=*i;

    float m;
    for(int j=*i ; j<23; j++)
    {
        parte_decimal = modf(parte_decimal*2, &m);
        if(m>0)
        {
            Significando.set(22-j);
        }
        else
        {
            Significando.reset(22-j);
        }
    }
    delete i;
}

void Float_Binario::Punto_Flotante(float n)
{
    activacion_signo(signo,n);

    if(n<0)
    {
        n=-n;
    }

    float parte_decimal, parte_entera;
    parte_decimal = modf(n, &parte_entera);

    parte_int=int(parte_entera);

    activacion_Significando(Significando,parte_decimal,parte_int,v_exp_int);

    activacion_exp(exp_biased,v_exp_int);

    cout<<signo<<" "<<exp_biased<<" "<<Significando<<endl;

    cout<<"\ncomprobación de su valor"<<endl;
    cout<<"------------------------"<<endl;

    cout<<Valor_real(signo,exp_biased,Significando)<<endl;
}

//PARTEEE 3

void Float_Binario::Conversor_F_to_D(float n)
{
    bitset <52> Significando_52;
    bitset <11> exp_biased_11;
    Punto_Flotante(n);
    Double_Binario doble;
    double m;
    m=n;
    cout<<"\n\n"<<endl;
    doble.Punto_Flotante(m);
}
