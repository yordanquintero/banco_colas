#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

struct nodo{

int nro;
struct nodo *sgte;
};

typedef struct nodo *puntero;


 puntero delante;
    puntero atras;

    void Cola();
    void Encolar(int);
    int Desencolar();
    bool Colavacia();
    void Mostrarcola();
    void Vaciarcola();
    void menup();






void Cola(){
     delante=NULL;
      atras=NULL;

}
bool Colavacia(){
if(delante==NULL){
    return true;
}else{
return false;
    }

}

void Encolar(int x){
puntero p_aux;

p_aux=new(struct nodo);
p_aux->nro=x;
p_aux->sgte=NULL;

if(delante==NULL){
    delante=p_aux;
}else{
    atras->sgte=p_aux;

}
atras=p_aux;
}
int Desencolar(){
int n;
puntero p_aux;
p_aux=delante;
n=p_aux->nro;
delante=(delante)->sgte;
delete(p_aux);
return n;

}

void Mostrarcola(){
puntero p_aux;
p_aux=delante;
while(p_aux!=NULL){
    printf("\n\t");
    printf("%d",p_aux->nro);
    p_aux=p_aux->sgte;
    }
    printf("\n");

}

void Vaciarcola(){
puntero p_aux,r_aux;
p_aux=delante;
while(p_aux!=NULL){
    r_aux=p_aux;
    p_aux=p_aux->sgte;
    delete(r_aux);
    delante=NULL;
    atras=NULL;

}
}

void menuc (){

    int x;
    int op=0;
do{

    printf("\n\n\t__________________________________________________\n");
    printf("\t|                IMPLEMENTACION DE UNA COLA       |\n");
    printf("\t|_________________________________________________|\n");
    printf("\n\t|                                                 |\n");
    printf("\t|  1.ENCOLAR                                      |\n");
    printf("\t|  2.DESENCOLAR                                   |\n");
    printf("\t|  3.MOSTRAR COLA                                 |\n");
    printf("\t|  4.VACIAR COLA                                  |\n");
    printf("\t|  5. SALIR                                       |\n");
    printf("\t|_________________________________________________|\n");
    printf("\t ingrese una opcion: ");

    scanf("%d",&op);
    switch(op){
        case 1: printf("\n\t INGRESE NUMERO A ENCOLAR: ");
                scanf("%d",&x);
                Encolar(x);
                printf("\n\n\t agregado numero %d",x);
                printf("\n\n\t");
                break;
        case 2:
            if(Colavacia()==true){
                printf("\n\n\t cola vacia...");
            }else{
                x=Desencolar();
                printf("\n\n\t eliminado numero %d",x);
                printf("\n\n\t");
            }
            break;
        case 3:
            printf("\n\t MOSTRANDO COLA");
            if(Colavacia()!=true){
                Mostrarcola();
            }else{
            printf("\n\n\tcola vacia...!");
            printf("\n\n");
            }
                break;
        case 4:
            Vaciarcola();
            printf("\n\n\t\tcola eliminada...");
            printf("\n\n");
            break;
        case 5:menup();

        default:
            printf("\n\n");
            printf("\n\n\tIngrese una opcion valida...!!");
    }
       system("pause"); system("cls");
}while(op!=6);


}

int main(){
system("color b0");
menup();

return 0;
}

// codigo de pilas


int p=0;
int con[50];


struct nodo2{
int nro;
struct nodo *sgte;
};

typedef struct nodo *puntero;

puntero cima;
    void Pila();
    void Apilar(int);
    int Desapilar();
    void Cima();
    bool Pilavacia();
    void Mostrarpila();
    void Destruirpila();
    void imprimirinverso();




void Pila(){
    cima=NULL;
}

bool Pilavacia(){
    if(cima==NULL){
    	return true;
	}
    else{
    	return false;
	}
}

void Apilar(int x){

puntero p_aux;
p_aux=new(struct nodo);
p_aux->nro=x;
con[p]=p_aux->nro;
p_aux->sgte=cima;
cima=p_aux;
p++;

}

void Cima(){
int x;
if(cima==NULL){
    printf("\n\n\tpila vacia...!");

}else{
    x=cima->nro;
    printf("\n\tla cima es: %d\n",x);

    }
}

int Desapilar(){
int x;
puntero p_aux;
if(cima==NULL){
    printf("\n\n\tpila vacia...!!");
}else{
    p_aux=cima;
    x=p_aux->nro;
    cima=cima->sgte;
    delete(p_aux);
    }
return x;
}

void Mostrarpila(){
puntero p_aux;
p_aux=cima;
while(p_aux!=NULL){
    printf("\t%d\n",p_aux->nro);

    p_aux=p_aux->sgte;

    }

}

void Destruirpila(){
puntero p_aux;

while(cima!=NULL){
    p_aux=cima;
    cima=cima->sgte;
    delete(p_aux);

    }

}

void menupila(){

Pila();
int x;
int op;

do{
printf("\t|------------------------------------------|\n");
printf("\t|        IMPLEMENTACION DE UNA PILA        |\n");
printf("\t|------------------------------------------|\n");
printf("\t|                                          |\n");
printf("\t|  1. APILAR                               |\n");
printf("\t|  2. DESAPILAR                            |\n");
printf("\t|  3. MOSTRAR PILA                         |\n");
printf("\t|  4. DESTRUIR PILA                        |\n");
printf("\t|  5. MOSTRAR CIMA                         |\n");
printf("\t|  6. IMPRIMIR INVERSO                     |\n");
printf("\t|  7. SALIR                                |\n");
printf("\t|------------------------------------------|\n");
printf("\t ingrese una opcion: ");

    scanf("%d",&op);
    switch(op){
     case 1:
	 printf("\n\t INGRESE NUMERO A APILAR: ");
     scanf("%d",&x);
     Apilar(x);
     printf("\n\n\t\tNumero %d apilado...\n\n",x);
        break;
     case 2:
        if(Pilavacia()==true){
            printf("\n\n\tpila vacia...");
        }else{

        x=Desapilar();
        printf("\n\n\tnumero %d desapilado\n",x);

        }
            break;
     case 3:
        printf("\n\n\t MOSTRANDO PILA\n\n");
        if(Pilavacia()!=true){
            Mostrarpila();
        }else{
            printf("\n\n\t pila vacia..!\n");
        }   break;

     case 4:
        Destruirpila();
        printf("\n\n\tpila eliminada...\n\n");
        break;
     case 5:
        Cima();
        break;
     case 6: printf("\n\n\t MOSTRANDO PILA INVERSA\n\n");
        imprimirinverso();
        break;
    case 7: menup();
    }

    printf("\n\n");
    system("pause"); system("cls");
}while(op!=0);


}


 void imprimirinverso(){//imprimiendo pila de forma invertida

for(int i=0;i<p;i++){
            printf("\t%d\n",con[i]);
        }
 }

 void menup(){
    int opc=0;
do{
    system("cls");
    printf("\t\t---------------------------\n");
    printf("\t\t|    MENU PRINCIPAL       |\n");
    printf("\t\t|   1. pilas              |\n");
    printf("\t\t|   2. colas              |\n");
    printf("\t\t|   3. salir              |\n");
    printf("\t\t---------------------------\n");
     printf("\t\tingrese una opcion: ");
    scanf("%d",&opc);
    system("cls");
    switch(opc){
    case 1:menupila();
                break;
    case 2:menuc();
            break;
    case 3:exit(0);

    }

}while(opc!=0);

}
