#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;


struct nodo{
int dato;
nodo *siguiente;
};

typedef struct nodo *puntero;

nodo *frente=NULL;
nodo *fin=NULL;

int a;


struct clientes{
int id;
char nombre[50];
int documento;
char tipo_transaccion[20];

}clientes[50],*pclientes=clientes;

void ingresar_cliente();
void menu();
void menut();
void reti();
void depo();
void consultaa();
void mostrarcliente();
void insertar_cola(nodo *&,nodo *&,int);
bool cola_vacia(nodo *);
void Mostrarcola();
int Desencolar();
void tiempo_total();
void actualizaccionn();
void pagoss();
void eliminarCliente();

int numclientes=0;
float tiempo=0;


char ret[20]="Retiro";
char dep[20]="Deposito";
char consu[20]="Consulta";
char actua[20]="Actualizacion";
char pag[20]="pagos";

float retiro=4;
float deposito=2;
float consulta=3.5;
float actualizacion=5;
float pagos=2;

int main(){

menu();

    return 0;
}


void menu(){
int opc;

do{
          system("cls");
printf("\t\tMENU\n\n");
printf("\t1. crear cliente\n\n");
printf("\t2. mostrar cliente\n\n");
printf("\t3. total tiempo\n\n");
printf("\t4. mostrar cola\n\n");
printf("\t5. desencolar\n\n");
printf("\t ingrese una opcion: ");
scanf("%d",&opc);
switch(opc){
case 1:ingresar_cliente();
    break;
case 2:mostrarcliente();
    break;
case 3:tiempo_total();
    break;
case 4:Mostrarcola();
    break;
case 5:Desencolar();
    break;
}

}while(opc!=0);

}



void ingresar_cliente(){
    system("cls");
(clientes+numclientes)->id = numclientes;
printf("\n\n\t\tingrese los datos\n");
printf("\n\n\t\tnombre: ");
fflush(stdin);
fgets((pclientes+numclientes)->nombre,30,stdin);
printf("\n\n\t\tdocumento: ");
scanf("%d",&(pclientes+numclientes)->documento);
insertar_cola(frente,fin,(pclientes+numclientes)->documento);





 int opc;

    system("cls");
printf("\ttipo de transaccion\n\n");
printf("\t1. retiro\n\n");
printf("\t2. Deposito\n\n");
printf("\t3. consulta\n\n");
printf("\t4. actualizacion\n\n");
printf("\t5. pagos\n\n");
printf("\t ingrese una opcion: ");
scanf("%d",&opc);
switch(opc){
case 1:reti();
    break;
case 2:depo();
    break;
case 3:consultaa();
    break;
case 4:actualizaccionn();
    break;
case 5:pagoss();
    break;
    }

numclientes++;

}

void insertar_cola(nodo *&frente,nodo *&fin,int n){
nodo *nuevo_nodo=new nodo();

nuevo_nodo->dato=n;
nuevo_nodo->siguiente=NULL;
if(cola_vacia(frente)){
    frente=nuevo_nodo;
}else{
    fin->siguiente=nuevo_nodo;

    }
fin=nuevo_nodo;
}

bool cola_vacia(nodo *frente){

if(frente==NULL){
    return true;
}else{
    return false;
    }
}

void Mostrarcola(){
puntero p_aux;
p_aux=frente;
while(p_aux!=NULL){
    printf("\n\t");
    printf("%d",p_aux->dato);
    p_aux=p_aux->siguiente;
    }
    printf("\n");
    system("pause");

}

int Desencolar(){
puntero p_aux;
p_aux=frente;
frente=(frente)->siguiente;
delete(p_aux);
eliminarCliente();
}

void mostrarcliente(){
    system("cls");
    printf("\t\tclientes\n");
for(int i=0;i<numclientes;i++){
printf("\t\tnombre: %s",(pclientes+i)->nombre);
printf("\t\tdocumento: %d\n",(pclientes+i)->documento);
printf("\t\ttipo de transaccion: %s\n\n",(pclientes+i)->tipo_transaccion);
}

system("pause");
}


void reti(){
strcpy((pclientes+numclientes)->tipo_transaccion,ret);
tiempo=tiempo+retiro;
printf("\t\ttardara 4 minutos\n");
system("pause");

}
void depo(){
strcpy((pclientes+numclientes)->tipo_transaccion,dep);
tiempo=tiempo+deposito;
printf("\t\ttardara 2 minutos\n");
system("pause");

}
void consultaa(){
strcpy((pclientes+numclientes)->tipo_transaccion,consu);
tiempo=tiempo+consulta;
printf("\t\ttardara 3,5 minutos\n");
system("pause");

}

void actualizaccionn(){

strcpy((pclientes+numclientes)->tipo_transaccion,actua);
tiempo=tiempo+actualizacion;
printf("\t\ttardara 5 minutos\n");
system("pause");

}

void pagoss(){

strcpy((pclientes+numclientes)->tipo_transaccion,pag);
tiempo=tiempo+pagos;
printf("\t\ttardara 2 minutos\n");
system("pause");



}



void tiempo_total(){
    system("cls");
printf("\t\tel tiempo total es %.1f minutos\n",tiempo);
system("pause");

}

void eliminarCliente(){
	int idCliente=0;
	if(idCliente < numclientes){
		for(int i=idCliente; i<numclientes; i++){
			(clientes+i+1)->id = (clientes+i)->id;
			strcpy((clientes+i)->nombre,(clientes+i+1)->nombre);
			(clientes+i)->documento=(clientes+i+1)->documento;
			strcpy((clientes+i)->tipo_transaccion,(clientes+i+1)->tipo_transaccion);
		}
	}
	numclientes--;
}
