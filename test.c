#include <stdio.h>

struct  Fecha
{
    int dia;
    int mes;
    int anio;
};

struct Persona
{
    char nombre[50];
    struct Fecha nacimiento;
    
};




int main(void){
     struct  Persona p;

     p.nacimiento.mes = 12;
     
     
    return 0;
}
