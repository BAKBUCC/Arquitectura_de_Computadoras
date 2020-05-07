#ifndef FLOAT_BINARIO_H
#define FLOAT_BINARIO_H

#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;


class Float_Binario
{
    public:
        Float_Binario();
        void Punto_Flotante(float );
        void Conversor_F_to_D(float);
    private:
        int v_exp_int, parte_int;
        bitset <1> signo;
        bitset <23> Significando;
        bitset <8> exp_biased;
        float retornar_Significando_en_deci(bitset <23> );
        int retornar_exp_en_deci(bitset <8> );
        int retornar_signo(bitset <1> );
        float Valor_real(bitset <1> , bitset <8> , bitset <23> );
        void activacion_signo(bitset <1> &, float );
        void activacion_exp(bitset <8> &, int );
        void activacion_Significando(bitset <23> &, float, int , int &);
};

#endif // FLOAT_BINARIO_H
