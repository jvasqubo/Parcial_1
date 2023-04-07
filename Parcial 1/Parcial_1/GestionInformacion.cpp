#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

char* Open_File ()
{
    std::ifstream archivo("Plan de Estudios1.txt", std::ios::in | std::ios::ate);
    int tamano = archivo.tellg();
    archivo.seekg(0);
    char* contenido = new char[tamano];
    archivo.read(contenido, tamano);
    return contenido;
}

int Count_Chars(char Arreglo[])
{
    int Count = 0;
    while (Arreglo[Count] != '\0')
    {
        Count++;
    }
    return Count;
}

int Count_Subjects ( char Arreglo[])
{
    int Longitud = Count_Chars(Arreglo);
    int Count=0;
    for ( int i=0;i<Longitud;i++)
    {
        if (Arreglo[i]=='.') Count++;
    }
    return Count;
}

int* Positions_Signs ( char Arreglo[], int Subjects)
{
    int Longitud = Count_Chars(Arreglo);
    int* Posiciones = new int [Subjects*4];
    int Contador=0;
    for (int i=0; i<Longitud; i++)
    {
        if (Arreglo[i]=='.' || Arreglo[i]==',')
        {
            Posiciones[Contador]=i;
            Contador++;
        }
    }
    return Posiciones;
}

int* Size_Subcategory (int Posiciones[], int Subjects)
{
    int* Size = new int [Subjects*4];
    int contador = 0;
    for (int i=0; i<Subjects*4; i++)
    {
        if (i==0)
        {
            Size[contador]=Posiciones[i];
            cout<<contador<<','<<Size[contador]<<endl;
            contador++;
        }
        else
        {
            Size[contador]=Posiciones[i]-Posiciones[i-1];
            cout<<contador<<','<<Size[contador]<<endl;
            contador++;
        }
    }
    return Size;
}

char*** Reserve_Matix_Group(int Posiciones[], int Subjects)
{
    char*** Matrix_Group= new char**[Subjects];
    int contador=0;
    for (int i=0; i<Subjects; i++)
    {
        Matrix_Group[i]=new char*[5];
    }
    for (int i=0; i<Subjects; i++)
    {
        for (int j=0;j<5;j++)
        {
            if (contador==0)
            {
                Matrix_Group[i][j]= new char[Posiciones[0]+1];
                cout<<Posiciones[0]+1<<endl;
                contador++;
            }
            else if (j == 3)
            {
                Matrix_Group[i][j]= new char[2];
            }
            else
            {
                Matrix_Group[i][j]= new char[Posiciones[contador]-Posiciones[contador-1]];
                cout<<"******************"<<endl;
                cout<<contador<<","<<Posiciones[contador]-Posiciones[contador-1]<<endl;
                contador++;
            }
        }
    }
    return Matrix_Group;
}
