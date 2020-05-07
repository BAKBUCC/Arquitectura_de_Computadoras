#include "Float_Binario.h"
#include "Double_Binario.h"

int main()
{
    float n;
    cout<<"coloque su float: ";
    cin>>n;

    cout<<n<<endl;

    cout<<"FLOAT\n";
    cout<<"-----\n";
    Float_Binario flotante;
    flotante.Punto_Flotante(n);

    double m;
    cout<<"\n\ncoloque su double: ";
    cin>>m;

    cout<<m<<endl;
    cout<<"\nDOUBLE\n";
    cout<<"------\n";
    Double_Binario doble;
    doble.Punto_Flotante(m);

    float a;
    cout<<"\n\ncoloque su float para convertirlo a double en binario: ";
    cin>>a;

    cout<<a<<endl;

    cout<<"\n\nFLOAT to DOUBLE (Respectivamente)\n";
    cout<<"------\n";
    flotante.Conversor_F_to_D(a);

    return 0;
}
