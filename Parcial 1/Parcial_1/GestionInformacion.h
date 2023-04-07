#ifndef GESTIONINFORMACION_H
#define GESTIONINFORMACION_H
#include <fstream>

char* Open_File ();
int Count_Chars(char Arreglo[]);
int Count_Subjects ( char Arreglo[]);
int* Positions_Signs ( char Arreglo[], int Subjects);
int* Size_Subcategory (int Posiciones[], int Subjects);
char*** Reserve_Matix_Group(int Posiciones[], int Subjects);

#endif // GESTIONINFORMACION_H
