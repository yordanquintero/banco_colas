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


void insertar_cola(nodo *&,nodo *&,int);
void Mostrarcola();
bool cola_vacia(nodo *);

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



int main(){
    int suma=0;
    int n,num;
   printf("ingrese la cantidad de numeros para agregar: ");
   scanf("%d",&n);
   for(int i=0;i<n;i++){
    printf("ingrese un numero: ");
    fflush(stdin);
    scanf("%d",&num);
    insertar_cola(frente,fin,num);
    suma=suma+num;


   }
printf("la suma es: %d\n",suma);
printf("su promedio es: %d",suma/n);

    return 0;
}
