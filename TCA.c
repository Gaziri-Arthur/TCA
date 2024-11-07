#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

typedef struct{//g) horario
    
    int hora;
    int minuto;
}tHoraio;
typedef struct{//f) data

    int ano;
    int mes;
    int dia;
}tData;
typedef struct{//c) Endereco

    char *rua;
    int numero;
    char *bairro;
    char *cidade;
    char estado;
}tEndereco;
typedef struct{//d) Categoria

    char *categoria;
}tCategoria;
typedef struct {//a) Amigo

    char *nome;
    tData nascimento;
    char *apelido;
    char *email;
    char *telefone;
}tAmigo;
typedef struct {//b) Local

    char *NOM_encontro;
    tEndereco endereco;
}tLocal;
typedef struct{//e) Encontro
    
    tData data;
    tHoraio horario;
    tAmigo *amigos;
    tCategoria *categoria;
    char *descricao;
}tEncontro;

tEncontro *Listaencontro = NULL;
tAmigo *Listaamigo = NULL;
tLocal *Listalocal = NULL;
tCategoria *Listacategoria = NULL;

int Numencontro = 0, Numamigo = 0, Numcategoria = 0, Numlocal = 0;


int valido(int a){
    if(a < 1 || a > 6){
        return 0;
    }else{
        return 1;
    }

}

void switchprincipal(int op){

    switch (op){
        case 6:
            exit(1);
        
    }
}

void menuprincipal(){

    int op = 0, ver = 0;

    system("cls");
    printf("Digite:\n");
    printf("1. para manter amigo\n");
    printf("2. para manter local\n");
    printf("3. para manter categoria\n");
    printf("4. para manter encontro\n");
    printf("5. para Relatórios\n");
    printf("6. para Sair\n");
    printf("O que deseja fazer?: ");
    while(ver == 0){
        scanf("%d", &op);
        ver = valido(op);
        if(ver == 0){
            printf("Valor invalido! Digite novamente: ");
        }
    }
    switchprincipal(op);
    

}

int main(){

    system("cls");
    printf("Bom dia querido usuario!");
    Sleep(3000);
    menuprincipal();    

    return 0;
}