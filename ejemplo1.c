#include <stdio.h>
#include <string.h>

struct Direccion {
    char callePrincipal[50];
    int numeroCasa;
    char calleSecundaria[50];
};

typedef struct  {
    char nombre[50];
    struct Direccion direccion;    
    int edad;
} Alumno;


typedef float NUMEROFLOTANTE;

void mostrarAlumno( Alumno *a);

int main(void) {

    NUMEROFLOTANTE test = 1.0;
    Alumno a1;
    strcpy(a1.nombre, "Jose");
    strcpy(a1.direccion.callePrincipal, "Av. Siempre viva");
    a1.direccion.numeroCasa = 123;
    strcpy(a1.direccion.calleSecundaria, "Av. Florida");
    a1.edad = 20;
    
    mostrarAlumno(&a1);
   
   
    return 0;
}

void mostrarAlumno(Alumno *a){

    printf("Nombre: %s\n", a -> nombre);
    printf("Edad: %d", a -> edad);
    printf("Calle principal: %s\n", a -> direccion.callePrincipal);
    printf("Numero de Casa: %d\n", a -> direccion.numeroCasa);
    printf("Calle secundaria: %s\n", a -> direccion.calleSecundaria);
}