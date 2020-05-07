#ifndef DOUBLE_BINARIO_H
#define DOUBLE_BINARIO_H

#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

class Double_Binario
{
    public:
        Double_Binario();
        void Punto_Flotante(double );
        double Valor_real(bitset <1> , bitset <11> , bitset <52> );
    private:
        int v_exp_int, parte_int;
        bitset <1> signo;
        bitset <52> Significando;
        bitset <11> exp_biased;
        double retornar_Significando_en_deci(bitset <52> );
        int retornar_exp_en_deci(bitset <11> );
        int retornar_signo(bitset <1> );
        void activacion_signo(bitset <1> &, double );
        void activacion_exp(bitset <11> &, int );
        void activacion_Significando(bitset <52> &, double, int , int &);

};

#endif // DOUBLE_BINARIO_H
