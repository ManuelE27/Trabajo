
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#include <sys/stat.h>
#include <unistd.h>
#include <"fileutil.h">



//DeclaraciÃ³n de funciones 

void error(const char *s);
int procesoArchivo(char *archivo);
int is_regular_file(const char *path);



int main(int argc, char *argv[])
{
if (argc != 2) 
    {
      error("Ingrese un argumento\n");
    }

  DIR *dir;

  struct dirent *ent;

  /* Empezaremos a leer en el directorio actual */
  dir = opendir (argv[1]);

  /* Miramos que no haya error */
  if (dir == NULL){ 
    error("No puedo abrir el directorio");
	}

unsigned char tipo;
int i=0;
int aux=0;
int tot=0;



//primer while solo para contar la cantidad de archivos 
  while ((ent = readdir (dir)) != NULL) //comienzo a leer todo el directorio guardando cada archivo en ent
    {

tipo=ent->d_type;
						 //Me retorna el tipo de archivo que es ent y este se guarda en tipo 
if(tipo==DT_REG){ //comprueba si es archivo
FILE*f;
f=fopen(ent->d_name,"r");
i++;  //cantidad de archivos 

  
   }//CIERRO IF ARCHIVO
 	}//cierro while
 	  closedir (dir);

 	
 	
 	
 	
 	
 	
 	
 	
 	
 	//parte dos
 	
 	 dir = opendir (argv[1]);

  /* Miramos que no haya error */
  if (dir == NULL){ 
    error("No puedo abrir el directorio");
	}
/*char *lis[1000000];
unsigned char tipo;
int i=0;
int aux=0;
int tot=0;*/
int rec;
int a=0;
int b=0;
//int pype[2];
//pipe(pype);
int ret;
int arch=i/2;

int n=0;

int pid = fork(); //ABRO DOS PROCESOS





char *buf[1000000];


if (pid==0){

//close(pype[0]); //cierro lado de lectura

 a=3;
}
else{
//close(pype[1]); //cierro lado de escritura


 a=2;
}


  while ((ent = readdir (dir)) != NULL ) //b<i/2 or a>i/2 padre leera la primer mitad mientras su contador aumenta +1 por cada iteración, a leera la segunda mitad mientras su contador baja -1 por cada iteración
    {


tipo=ent->d_type;
						 //Me retorna el tipo de archivo que es ent y este se guarda en tipo 
if(tipo==DT_REG){ //comprueba si es archivo


//concatenar  

  FILE*f;
  
  
                f=fopen(ent->d_name,"r");


if(a%2==0)
{
                buf[i]=(char *)malloc(sizeof(char) *strlen(ent->d_name)); //Abre un espacio en memoria

	//strcpy(lis[i],argv[1]);
		strcat(buf[i],argv[1]); 	//Concatena la direccion
		//strcpy(lis[i],"/");
		strcat(buf[i],"/");  	//Concatena la barra "/"
		//strcpy(lis[narch],dir->d_name);
		strcat(buf[i],ent->d_name);	//Concatena el nombre del directorio
			int reci=0;
	  	
			reci=procesoArchivo(ent->d_name);
				tot=tot+reci;//suma de bites de todos los archivos 
if (pid==0){
//write(pype[1],tot);
}
//}//if comprobacion padre hiho a b 
else {


}
}
a++;


}//CIERRO IF ARCHIVO
   }//cierra el while
 	
 	  closedir (dir);

 	
 	
 	
 	
 	
 	
 
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
printf("Estudiante_1:201622375\nTotal archivos: %d\nTotal bytes: %d PID:  %d\n",i,tot,pid);
//printf("%d",buf);
  //closedir (dir);

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
//int pid;

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








