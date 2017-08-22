//TALLER ESTRUCTURA DE DATOS 2
//DESARROLLADORES: JULIANA MEDINA,JUAN MANUEL CARDONA,FABIAN ANDRES CUARTAS
//21 DE AGOSTO DE 2017
//EL SIGUIENTE PROGRAMA TIENE COMO FINALIDAD MOSTRAR 
//LAS DIFERENTES OPERACIONES QUE SE PUEDEN HACER CON LAS FUNCIONES BASICAS DE C++ 
//EN EL OBSERVAMOS UN MENU DE SEIS PUNTOS.

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
void gotoxy(int x,int y);//PROTOTIPO FUNCION DE POSICIONAMIENTO
void llenar();
void n_estudiantes();
void menu();//PROTOTIPO DE LA FUNCION
void punto1();//PROTOTIPO DE CADA PUNTO DEL MENU
void UnoAlCien();
void ParesAlCincuenta();
void ImparesAlCincuenta();
void punto2();//PROTOTIPO DE CADA PUNTO DEL MENU
void producto();
int factorial();
void fibonacci();
void punto3();//PROTOTIPO DE CADA PUNTO DEL MENU
void Arraydecimal();
void punto4();//PROTOTIPO DE CADA PUNTO DEL MENU
void punto5();//PROTOTIPO DE CADA PUNTO DEL MENU
void punto6();//PROTOTIPO DE CADA PUNTO DEL MENU

struct competidor{
	char nombre[30];
	int edad;
	char sexo;
	char club[20];
	char categoria[8];
}b;
struct promedio{
	float nota1,nota2,nota3;
};

struct alumno{
	int n; 
	char nombre[30];
	char sexo;
	int edad;
	promedio p;
}alumnos[100],a;
int i,r=0,num,j,y=1,f,c,vertical[3],horizontal[3],total,opc=0,bandera=1,r2,t,m[3][3];
char caso,vocal;
int main () 
{
	menu();
	return 0;
}
void gotoxy(int x,int y){  
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void llenar(){
	srand(time(NULL));
	printf("MATRIZ NUMEROS ALEATORIOS\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			t=1+rand()%((50+1)-1);
			m[i][j]=t;
			printf("%d \t",m[i][j]);
		}
		printf("\n");
	}
}
void n_estudiantes(){
	int n,i,pos_M=0,pos_Me;
	float may_prom=0,men_prom=5,prom_alumnos[100];
	printf("ingrese la cantidad de alumnos\n");
	scanf("%d",&n);
	fflush(stdin);
	for (i=0;i<n;i++){
		printf("Nombre:\n");
		gets(alumnos[i].nombre);
		printf("sexo: M/F\n");
		scanf("%c",&alumnos[i].sexo);
		printf("Edad:\n");
		scanf("%d",&alumnos[i].edad);
		printf("Nota 1:\n");
		scanf("%f",&alumnos[i].p.nota1);
		printf("Nota 2:\n");
		scanf("%f",&alumnos[i].p.nota2);
		printf("Nota 3:\n");
		scanf("%f",&alumnos[i].p.nota3);
		prom_alumnos[i]=(alumnos[i].p.nota1+alumnos[i].p.nota2+alumnos[i].p.nota3)/3;
		
		if(prom_alumnos[i]>may_prom){
			may_prom = prom_alumnos[i];
			pos_M=i;
		}
		if(prom_alumnos[i]<men_prom){
			men_prom = prom_alumnos[i];
			pos_Me=i;
		}
		fflush(stdin);
	}
	printf("\n Nombre: %s, Sexo: %c, Edad: %d a;os, Mejor Promedio Notas: %1.f \n",alumnos[pos_M].nombre,alumnos[pos_M].sexo,alumnos[pos_M].edad,may_prom);
	printf("\n Nombre: %s, Sexo: %c, Edad: %d a;os, Menor Promedio Notas: %1.f \n",alumnos[pos_Me].nombre,alumnos[pos_Me].sexo,alumnos[pos_Me].edad,men_prom);
	
}

void menu(){
	while (bandera!=0){
		printf("MENU \n\n");
		printf("1. Ciclo While \n");
		printf("2. Ciclo For \n");
		printf("3. Array \n");
		printf("4. Switch \n");
		printf("5. Matrices \n");
		printf("6. Estructuras \n\n");
		printf("0. SALIR \n \n");
		printf("Seleccione una opcion \n \n");
		scanf("%d",&opc);
		system("cls");
		switch(opc){
		case 1:
			punto1();
			break;
		case 2:
			punto2();
			break;
		case 3:
			punto3();
			break;
		case 4:
			punto4();
			break;
		case 5:
			punto5();
			break;
		case 6:
			punto6();
			break;
		case 0:
			printf("SALIR");
			bandera=0;
			break;
		default:
			system("cls");
			printf("opcion invalida \n");
			Sleep(1000);
			system("cls");
			break;
			
			
		}
	}
}

//FUNCION DE EJERCICIOS POR MEDIO DE UN CICLO WHILE

void punto1 (){
	
	printf(" a. suma de numeros del 1 al 100 \n ");
	printf("b. suma de numeros pares del 1 al 50 \n ");
	printf("c. suma de numeros impares del 1 al 50 \n\n ");
	printf("Seleccione una opcion \n\n ");
	scanf("%s",&caso);
	switch(caso){
	case 'a':
		UnoAlCien();
		system("pause");
		system("cls");
		
		break;
	case 'b':
		ParesAlCincuenta();
		system("pause");
		system("cls");
		break;
	case 'c':
		ImparesAlCincuenta();
		system("pause");
		system("cls");
		break;
	}
	
}
void UnoAlCien(){
	i=1;
	while(i<=100){
		r=r+i;
		i++;
	}	
	printf("el resultado es %d\n",r);
	r=0;
}
void ParesAlCincuenta(){
	
	i=1;
	while(i<=50){
		if(i%2==0){
			r=r+i;
			
		}
		i++;
	}
	printf("el resultado es %d\n",r);	
	r=0;
}
void ImparesAlCincuenta(){
	i=1;
	while(i<=50){
		if(i%2==1){
			r=r+i;
			
		}
		i++;
	}
	printf("el resultado es %d\n",r);	
	r=0;
}
//FUNCION DE EJERCICIOS POR MEDIO DE UN CICLO FOR
void producto(){
	printf("ingrese un numero \n\n");
	scanf("%d",&num);
	for(i=1;i<=20;i++){
		r=num*i;
		printf("%d * %d = %d \n",num,i,r);
	}	
	
}
int factorial(int num){
	r=1;
	for(i=1;i<=num;i++){
		r=r*i;
	}
	return r;
}
void fibonacci(){
	printf("ingrese el numero hasta donde quiere hacer el calculo fibonacci \n\n");
	scanf("%d",&num);
	printf("\n");
	for(i=1;i<=num;i++){
		j=r+y;
		r=y;
		y=j;
		printf("%d \n",r);	
	}
}
void punto2(){
	
	printf(" a. Imprimir tabla de multiplicar de un numero del l al 20 \n ");
	printf("b. Solucionar el factorial de un numero \n ");
	printf("c. solucionar el numero de fibonacci \n\n ");
	printf("Seleccione una opcion \n \n");
	scanf("%s",&caso);
	switch(caso){
	case 'a':
		producto();
		system("pause");
		system("cls");
		break;
	case 'b':
		printf("ingrese un numero \n\n");
		scanf("%d",&num);
		printf("el resultado es %d\n",factorial(num));
		system("pause");
		system("cls");
		break;
	case 'c':
		fibonacci();
		system("pause");
		system("cls");
		break;
	}
}

//FUNCION DE EJERCICIOS DE TIPO ARRAY 
void Arraydecimal(){
	float a[4];
	a[0]=32.583;
	a[1]=11.239;
	a[2]=45.781;
	a[3]=22.237;
	for(i=0;i<=3;i++){
		printf("(%d) %.3f\n",i,a[i]);
	}
}
int ArrayUnoyCero(int f,int c){
	int x[f][c];
	for ( i=0;i<f;i++){
		for( j=0;j<c;j++){
			if (i==j){
				x[i][j]=1;	
			}else{
				if(i!=j){
					x[i][j]=0;
				}
			}
		}
	}
	for(i=0;i<f;i++){
		for(j=0;j<c;j++){
			printf("(%d,%d): %d\t ",i,j,x[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<f;i++){
		for(j=0;j<c;j++){
			printf("%d\t ",x[i][j]);
		}
		printf("\n");
	}
}
void punto3(){
	printf(" a. array de numeros decimales \n ");
	printf("b. array de m*n de valores 1 y 0  \n ");
	printf("c. array de 4*4 : en la columna 1 numeros ingresados \n    columna 2:val. elevados al cuadrado \n    columna 3: val. elevados al cubo \n    columna 4:val. elevados a la cuarta \n\n ");
	printf("seleccione una opcion\n\n");
	scanf("%s",&caso);
	switch(caso){
	case 'a':
		Arraydecimal();
		system("pause");
		system("cls");
		break;
	case 'b':{
		printf("Ingrese No. de filas :\n ");
		scanf("%d",&f);
		printf("Ingrese No. de columnas :\n ");
		scanf("%d",&c);
		ArrayUnoyCero(f,c);
		system("pause");
		system("cls");
	}
		break;
	case 'c':
		int x[4][4];
		printf("ingrese los valores de la primer columna \n ");
		for ( i=0;i<4;i++){
			for( j=0;j<4;j+=4){
				scanf("%d",&x[i][j]);
			}
		}
		for ( i=0;i<4;i++){
			for( j=0;j<4;j++){
				if(j!=0){
					x[i][j]=x[i][0]*x[i][0];
				}
				if(j!=0 && j!=1){
					x[i][j]=x[i][0]*x[i][0]*x[i][0];
				}
				if(j!=0 && j!=1 && j!=2){
					x[i][j]=x[i][0]*x[i][0]*x[i][0]*x[i][0];
				}
			}
		}
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				printf("(%d,%d): %d\t ",i,j,x[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				printf("%d\t ",x[i][j]);
			}
			printf("\n");
		}
		system("pause");
		system("cls");
		break;
	}
}

//FUNCION DE EJERCICIOS DE TIPO SWITCH

void punto4(){
	printf(" a. consulta de MES del sistema \n ");
	printf("b. codigo ascii de una vocal  \n ");
	printf("c. codigo ascii del 0 al 9 \n\n ");
	printf("seleccione una opcion\n\n");
	scanf("%s",&caso);
	switch(caso){
	case 'a':{
		char meses[][20]= {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"}; 
		time_t t; 
		struct tm *ahora; 
		time(&t); 
		ahora = localtime(&t); 
		printf("Mes: %s\n ", meses[ahora->tm_mon]); 
		system("pause");
		system("cls");
	}
		break;
	case 'b':
		printf("Escriba una vocal para ver su codigo ASCII \n");
		fflush(stdin);
		scanf("%c",&vocal);
		switch(vocal){
		case 'a': printf("alt 97\n");
		break;
		case 'e': printf("alt 101\n");
		break;
		case 'i': printf("alt 106\n");
		break;
		case 'o': printf("alt 111\n");
		break;
		case 'u': printf("alt 117\n");
		break;
		case 'A': printf("alt 65\n");
		break;
		case 'E': printf("alt 69\n");
		break;
		case 'I': printf("alt 73\n");
		break;
		case 'O': printf("alt 79\n");
		break;
		case 'U': printf("alt 85\n");
		break;
		default: printf("Usted ha ingresado una opción incorrecta");
		}
		system("pause");
		system("cls");
		break;
	case 'c':
		printf("Escriba un numero para ver su codigo ASCII \n");
		scanf("%d",&num);
		switch(num)
		{
		case 0: printf("alt 48\n");
		break;
		case 1: printf("alt 49\n");
		break;
		case 2: printf("alt 50\n");
		break;
		case 3: printf("alt 51\n");
		break;
		case 4: printf("alt 52\n");
		break;
		case 5: printf("alt 53\n");
		break;
		case 6: printf("alt 54\n");
		break;
		case 7: printf("alt 55\n");
		break;
		case 8: printf("alt 56\n");
		break;
		case 9: printf("alt 57\n");
		break;
		default: printf("Usted ha ingresado una opción incorrecta");
		}
		system("pause");
		system("cls");
		break;
	}
}

//FUNCION DE EJERCICIOS DE MATRICES

void punto5(){
	printf(" a. Matriz 3*3	con suma de sus posiciones \n ");
	printf("b. Matriz de 3*3 llena por el sistema \n ");
	printf("c. Matriz de 3*3 llena por el sistema con numeros primos \n\n ");
	printf("seleccione una opcion\n\n");
	scanf("%s",&caso);
	system("cls");
	
	switch(caso){
		int x[3][3];
	case 'a':
		for (i=0;i<=2;i++){
			for (j=0;j<=2;j++){
				printf("Posicion: %d ,%d  ",i,j);
				scanf("%d",&x[i][j]);
			}
		}
		for (i=0;i<=2;i++){
			r=0;
			for (j=0;j<=2;j++){
				r+=x[i][j];
				
			}
			vertical[i]=r;
		}
		
		for (j=0;j<=2;j++){
			r=0;
			for (i=0;i<=2;i++){
				r+=x[i][j];
				
			}
			horizontal[j]=r;
		}
		gotoxy(5,10);printf("MATRIZ \n\n\n");
		
		for (i=0;i<=2;i++){
			for (j=0;j<=2;j++){
				
				printf("%d\t",x[i][j]);
			}
			printf("\n");
		}
		gotoxy(25,10); printf("suma de posiciones: \n");
		gotoxy(25,11); printf("FILAS: \n");
		i=13;
		for (f=0;f<=2;f++){
			gotoxy(25,i);printf("%d",vertical[f]);
			i++;
		}
		
		i=0;
		for (f=0;f<=2;f++){
			gotoxy(i,18);printf("%d \t<--COLUMNAS",horizontal[f]);
			i+=8;
		}
		r=0;
		for (j=0;j<=2;j++){
			for (i=0;i<=2;i++){
				r+=x[i][j];
				
			}
		}
		printf("\n\n la suma total es: %d ",r);
		break;
	case 'b':
		llenar();
		break;
	case 'c':
		printf("\n\n\t"); //Generamos la matriz....
		
		srand(time(0));
		
		for(i=0;i<=2;i++){
			for(j=0;j<=2;j++){
				r=0;
				t=1+rand()%((50+1)-1);
				
				m[i][j]=t;
				
				printf(" %d ",m[i][j]);
				
				for(c=2;(c<m[i][j])&& !r ;c++)
					
				{
					
					r=m[i][j]%c;
					
					if(f==0) 
						
						r=1;
					
				}
				
				if(!r) 
					
					r2++;
				
			}
			
			printf("\n\t");
			
		}
		break;
	}
	
	system("pause");
	system("cls");
}

//FUNCION DE EJERCICIOS DE STRUCT

void punto6(){
	printf(" a. nota de n estudiantes en un array de estructura \n ");
	printf("b. estructura  competencia  \n ");
	printf("c. estructura anidada estudiantes y promedio \n ");
	printf("d. estructura anidada de N estudiantes y promedio \n\n ");
	printf("seleccione una opcion\n\n");
	scanf("%s",&caso);
	fflush(stdin);
	system("cls");
	switch(caso){
	case 'a':{
		float aux;
		printf("ingrese la cantidad de alumnos:\n");
		scanf("%d",&num);
		fflush(stdin);
		float resultado[num],mayor[num];
		for (i=0;i<num;i++){
			printf("Nombre :\n");
			scanf("%s",&alumnos[i].nombre);
			printf(".:Notas:.\n\n");
			printf("Nota 1 :\n");
			scanf("%f",&alumnos[i].p.nota1);
			printf("Nota 2 :\n");
			scanf("%f",&alumnos[i].p.nota2);
			printf("Nota 3 :\n");
			scanf("%f",&alumnos[i].p.nota3);
			resultado[i]=(alumnos[i].p.nota1+alumnos[i].p.nota2+alumnos[i].p.nota3)/3;
			mayor[i]=resultado[i];
		}
		for (i=0;i<num;i++){
			printf("ALUMNO: %s \n PROMEDIO: %1.f\n",alumnos[i].nombre,resultado[i]);
			
		}
		printf("\n PROMEDIO DE MAYOR A MENOR \n");
		for(i=0;i<num;i++){
			for(j=1;j<num;j++){
				if(mayor[i]>mayor[j]){
					aux=mayor[i];
					mayor[i]=mayor[j];
					mayor[j]=aux;
				}
			}
		}
		for(i<num;i>=0;i--){
			printf("%1.f\n",mayor[i]);
		}
		system("pause");
		system("cls");
	}
		break;
	case 'b':
		printf("Nombre: \n");
		gets(b.nombre);
		printf("Edad: \n");\
			scanf("%d",&b.edad);
		fflush(stdin);
		printf("Sexo: M/F  \n");
		scanf("%c",&b.sexo);
		fflush(stdin);
		printf("Club: \n");
		gets(b.club);
		if (b.edad<=15){
			strcpy(b.categoria,"Infantil");
		}else{
			if(b.edad<=30){
				strcpy(b.categoria,"Joven");
			}else{
				if(b.edad>30){
					strcpy(b.categoria,"Mayor");
				}
			}
		}
		printf("\n Nombre: %s \n Edad: %d a?os \n Sexo: %c \n Club: %s \n Categoria: %s\n",b.nombre,b.edad,b.sexo,b.club,b.categoria);
		system("pause");
		system("cls");
		break;
	case 'c':{
		float resultado;
		printf("Nombre:\n");
		gets(a.nombre);
		printf("sexo: M/F\n");
		scanf("%c",&a.sexo);
		printf("Edad:\n");
		scanf("%d",&a.edad);
		printf("Nota 1:\n");
		scanf("%f",&a.p.nota1);
		printf("Nota 2:\n");
		scanf("%f",&a.p.nota2);
		printf("Nota 3:\n");
		scanf("%f",&a.p.nota3);
		
		resultado=(a.p.nota1+a.p.nota2+a.p.nota3)/3;
		
		printf("\n Nombre: %s, Sexo: %c, Edad: %d a;os, Promedio Notas: %1.f \n",a.nombre,a.sexo,a.edad,resultado);
		system("pause");
		system("cls");
	}
		break;
	case 'd':
		n_estudiantes();
		
		system("pause");
		system("cls");
		break;
	}
}
