#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    char *descricao
}tEncontro;

void menuprincipal(){

    system("cls");
    printf("1. Manter amigo\n");
    printf("2. Manter local\n");
    printf("3. Manter categoria\n");
    printf("4. Manter encontro\n");
    printf("5. Relatórios\n");
    printf("6. Sair\n");

}

int main(){

    system("cls");
    printf("Bom dia querido usuario!");
    sleep(3);
    
    while(op != 7){
        printf("Digite uma opcao")

    }
    return 0
}


