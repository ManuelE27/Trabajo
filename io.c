/**
*************************************************************
* @file directorio.c
* @brief Lista los archivos del directorio actual
*
* @author Gaspar Fernández <blakeyed@totaki.com>
* @web    http://totaki.com/poesiabinaria
* @version
* @date 18 sep 2011
*************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#include <sys/stat.h>
#include <unistd.h>
#include <"fileutil.h">


//Declaración de funciones 

void error(const char *s);
int procesoArchivo(char *archivo);

int is_regular_file(const char *path);



int main(int argc, char *argv[])
{
if (argc != 2) 
    {
      error("Ingrese un argumento\n");
    }
  /* Con un puntero a DIR abriremos el directorio */
  DIR *dir;
  /* en *ent habrá información sobre el archivo que se está "sacando" a cada momento */
  struct dirent *ent;

  /* Empezaremos a leer en el directorio actual */
  dir = opendir (argv[1]);

  /* Miramos que no haya error */
  if (dir == NULL){ 
    error("No puedo abrir el directorio");
	}
char *buf[1000000];
unsigned char tipo;
int i=0;
int aux=0;
int tot=0;

  while ((ent = readdir (dir)) != NULL) //comienzo a leer todo el directorio guardando cada archivo en ent
    {

tipo=ent->d_type; //Me retorna el tipo de archivo que es ent y este se guarda en tipo 
if(tipo==DT_REG){ //comprueba si es archivo


//concatenar dirección 

  FILE*f;
                f=fopen(ent->d_name,"r");
                buf[i]=(char *)malloc(sizeof(char) *strlen(ent->d_name)); //Abre un espacio en memoria

		strcat(buf[i],argv[1]); 	//Concatena la direccion
		strcat(buf[i],"/");  	//Concatena la barra "/"
		strcat(buf[i],ent->d_name);	//Concatena el nombre del directorio

            //    printf("dirección cada archivo: %s\n",buf[i]);  //dirección completa de cada archivo 
/*
strcpy(ent->d_name,buf[i]);   //copio la direccion comppleta en el nombre de cada archivo 
printf("%s\n",ent->d_name);
*/



			int reci=0;
	  	
			reci=procesoArchivo(ent->d_name);
			
			 //cantidad de bites de un solo archivo
			tot=tot+reci;//suma de bites de todos los archivos 
	






	i++;  //cantidad de archivos   
   }//CIERRO IF ARCHIVO
 	}//cierro while
printf("Estudiante_1:201622375\nEstudiante_2: 201629898\nTotal archivos: %d\nTotal bytes: %d\n",i,tot);
//printf("%d",buf);
  closedir (dir);

  return EXIT_SUCCESS;

} //cierro main







void error(const char *s)
{
  /* perror() devuelve la cadena S y el error (en cadena de caracteres) que tenga errno */
  perror (s);
  exit(EXIT_FAILURE);
}






int procesoArchivo(char *archivo){
 

 FILE *fich;
  long ftam;

  fich=fopen(archivo, "r"); //Fich archivo por archivo

long cont=0;
int c;
char q;

/*
while (q=fgetc(fich)!=EOF){ //lectura intensiva 
	//char h=fgetc(fich);
	cont++;//cantidad de caracteres en un archivo 	



	}//cierro while
*/



    do  
    {  
        cont++;  
    } while (q=fgetc(fich)!=EOF);  




//fclose(fich);

return cont;

}// cierro proceso archivo




int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}








