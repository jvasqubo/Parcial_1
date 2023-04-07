#include <iostream>
#include "GestionInformacion.h"

using namespace std;

int main()
{
    char* Informacion;
    int* Posiciones;
    int* tamano;
    char*** Matriz;
    Informacion = Open_File();
    Posiciones = Positions_Signs(Informacion,Count_Subjects(Informacion));
    tamano = Size_Subcategory(Posiciones,Count_Subjects(Informacion));
    /*cout<<Informacion<<endl;
    cout<<Count_Subjects(Informacion)<<endl;
    cout<<"******************"<<endl;
    Matriz = Reserve_Matix_Group(Posiciones,Count_Subjects(Informacion));*/
}

