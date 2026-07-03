#include <stdio.h>
#include <string.h>

typedef struct  {
    char callePrincipal[50];
    int numeroCasa;
    char calleSecundaria[50];
}Direccion;

typedef struct  {
    char nombre[50];
    Direccion direccion;    
    int edad;
} Alumno;

/*Funciones prototipos*/
typedef float NUMEROFLOTANTE;

void mostrarAlumno( Alumno *a);

void saveFile(Alumno *a, int size);

void readFile();

void readFileCSV();

int main(void) {
     
    NUMEROFLOTANTE test = 1.0;
    Alumno estudiantes[2];
    int size =  sizeof(estudiantes) / sizeof(estudiantes[0]);
    strcpy(estudiantes[0].nombre, "Jose");
    strcpy(estudiantes[0].direccion.callePrincipal, "Av. Siempre viva");
    estudiantes[0].direccion.numeroCasa = 123;
    strcpy(estudiantes[0].direccion.calleSecundaria, "Av. Florida");
    estudiantes[0].edad = 20;

    strcpy(estudiantes[1].nombre, "Maria");
    strcpy(estudiantes[1].direccion.callePrincipal, "Calle Central");
    estudiantes[1].direccion.numeroCasa = 456;
    strcpy(estudiantes[1].direccion.calleSecundaria, "Av. Amazonas");
    estudiantes[1].edad = 22;

   
            //mostrarAlumno(estudiantes);
            saveFile(estudiantes, size);
            readFile();

   
   
    return 0;
}

void mostrarAlumno(Alumno *a){
for (int i = 0; i < 2; i++)
{
    /* code */
    printf("\n");
      printf("Nombre: %s\n", a[i].nombre);
    printf("Edad: %d", a[i].edad);
    printf("Calle principal: %s\n", a[i].direccion.callePrincipal);
    printf("Numero de Casa: %d\n", a[i].direccion.numeroCasa);
    printf("Calle secundaria: %s\n", a[i].direccion.calleSecundaria);
}
 
}

/*Guardo los datos en formato CSV
@Param -> Recibe un dato de tipo alumno
@Param -> El tamanio del arreglo
*/
void saveFile(Alumno *a, int size ) {
  
    FILE *File = fopen("Alumno.csv", "w");
    
if (File == NULL)
{
    puts("Archivo no encontrado");
    return;
}


    for (int i = 0; i < size; i++)
    { 
          // fprintf(File, "Nombre: %s\n", a[i].nombre);
           //fprintf(File, "Edad: %d\n", a[i].edad);
        fprintf(File, "%s;%d;%s;%d;%s\n", 
                a[i].nombre,
                a[i].edad,
                a[i].direccion.callePrincipal, 
                a[i].direccion.numeroCasa, 
                a[i].direccion.calleSecundaria);
        //fprintf(File, "-------------------------\n");
    }

    fclose(File);
    printf("\n[Datos guardados en Alumno.csv con exito]\n");
}

void readFile(){

    char linea[100];
   FILE *file = fopen("Alumno.txt", "r");
   if (file == NULL)
   {
    puts("El archivo no se encontro");
    return;
   }

   while (fgets(linea, sizeof(linea), file) != NULL)
   {
      printf("%s", linea);
   }

   fclose(file);

   
}

void readFileCSV(){
    FILE *File = ("Alumno.csv", "r");
    if (File == NULL)
    {
        puts("No se encontro el archivo");
        return;
    }
   
    Alumno alumno;
    fscanf(File,"%49[^;];%49[^;];%49[^;];%d;%d", 
        alumno.nombre,
        alumno.direccion.callePrincipal,
        alumno.direccion.calleSecundaria,
        alumno.direccion.numeroCasa,
        alumno.edad
    );


    fclose(File);
    
}