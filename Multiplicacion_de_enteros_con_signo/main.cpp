#include <iostream>
#include <math.h>

using namespace std;

void presentacion_nBits_asignacion(int unsigned &refn_count)
{
    cout<<"OPERACION: MULTIPLICACION (Alg. de Booth)\n";
    cout<<"-------------------------\n\n";

    cout<<"Con cuantos bits desea trabajar?: ";
    cin>>refn_count;
    cout<<"\nPor lo visto, usted a escogido un ancho de bits de \""<<refn_count<<"\"\n";
    cout<<"por lo que su rango sera:\n\n";
    cout<<-(pow(2,refn_count-1))<<" hasta "<<pow(2,refn_count-1)-1<<endl;
}

void multiplicando_multiplicador_asignacion(int &refM, int &refQ)
{
    cout<<"Ingrese el Multiplicando: ";
    cin>>refM;
    cout<<"Ahora ingrese su multiplicador: ";
    cin>>refQ;
}

void printbits(int num, int unsigned n)
{
    const unsigned MASCARA = 1 << (n-1);

    for (unsigned i = 1; i <= n; i++ )
    {
        cout << ( num & MASCARA ? '1' : '0' );
        num <<= 1; // desplaza el valor a la izquierda por 1
    }
}

int obtener_LSB(int num)
{
    if(num%2==0)
    {
        return 0;
    }
    return 1;
}

int obtener_MSB(int num, int n_count)
{
    if(num>pow(2,n_count-1)-1)
    {
        return 1;
    }
    return 0;
}

int Cambiar_signo(int M)
{
    M=~M;
    M+=1;
    return M;
}

void shift_Arithmetic(int &refA, int &refQ, short &refQ_1, int n_count)
{
    refQ_1 = obtener_LSB(refQ);
    refQ >>= 1;
    if(obtener_LSB(refA)==1)
    {
        refQ+=pow(2,n_count-1);
    }


    int MSB_A=obtener_MSB(refA,n_count);

    if(MSB_A==1)
    {
        refA >>= 1;
        refA+=pow(2,n_count-1);
    }
    else if(MSB_A==0)
    {
        refA >>= 1;
    }
}

//estudiar los genros teatrales;
void AlgoritmoBooth(int &M, int &Q, int n_count)
{
    int A = 0 << n_count;
    int n=n_count;
    short Q_1=0;
    short Q0;
    cout<<"\t  A    Q    Q-1     M"<<endl;
    while(n!=0)
    {
        cout<<"\t";
        printbits(A,n_count);
        cout<<"  ";
        printbits(Q,n_count);
        cout<<"   "<<Q_1<<"    ";
        printbits(M,n_count);
        cout<<endl;
        Q0=obtener_LSB(Q);

        if(Q0==1 && Q_1==0)
        {
            A+=Cambiar_signo(M);

        }
        if(Q0==0 && Q_1==1)
        {
            A+=M;
        }
        cout<<"\t";
        printbits(A,n_count);
        cout<<"  ";
        printbits(Q,n_count);
        cout<<"   "<<Q_1<<"    ";
        printbits(M,n_count);
        cout<<endl;

        shift_Arithmetic(A,Q,Q_1,n_count);
        n--;

    }
    cout<<"res:    ";
    printbits(A,n_count);
    cout<<"  ";
    printbits(Q,n_count);
    cout<<"   "<<Q_1<<"    ";
    printbits(M,n_count);
    cout<<endl;
}

int main()
{
    int M, Q;
    int unsigned n_count;
    presentacion_nBits_asignacion(n_count);
    multiplicando_multiplicador_asignacion(M,Q);
    cout<<"Multiplicando en bits: ";printbits(M,n_count);
    cout<<"\nMultiplicador en bits: ";printbits(Q,n_count);
    cout<<endl;
    AlgoritmoBooth(M,Q,n_count);

}
