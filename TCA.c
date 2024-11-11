#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>

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

void limpamemoria(){

    for(int i = 0; i < Numamigo; i++){
        free(Listaamigo[Numamigo].nome);
        free(Listaamigo[Numamigo].apelido);
        free(Listaamigo[Numamigo].email);
        free(Listaamigo[Numamigo].telefone);
    }
    free(Listaamigo);

}

void verifica_alocacao(void *v){
    if(!v){
        printf("ERRO AO ALOCAR MEMORIA!!!");
        exit(1);
    }
}

int valido(int a){
    if(a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6'){// char suspender
        return 0;
    }else{
        return 1;
    }
}

bool validarEmail(char *email){
    int countA = 0, countB = 0;
    
    for(int i = 0; email[i] != '\0'; i++){
        if(email[i] == '@'){
            countA++;
        } else if(email[i] == '.'){
            countB++;
        }
    }

    if(countA != 1 || countB < 1){
        return false;
    } else {
        return true;
    }

}

bool valide_data(int dias, int mes, int ano)
{
    if (mes > 12 || mes <= 0)
    {
        return false;
    }
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        if (dias <= 0 || dias > 31)
        {
            return false;
        }
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dias <= 0 || dias > 30)
        {
            return false;
        }
    }
    if (ano % 4 == 0 && mes == 2)
    {
        if (dias <= 0 || dias > 29)
        {
            return false;
        }
    }
    else if (mes == 2)
    {
        if (dias <= 0 || dias > 28)
        {
            return false;
        }
    }
    return true;
}

void criaamigo(){

    //int i, j, k;
    char str[100];
    bool ver = false;
    
    printf("Voce tem %d amigos no momento\n", Numamigo);

    if (Numamigo == 0) {f
        Listaamigo = (tAmigo *)malloc(sizeof(tAmigo));
        verifica_alocacao(Listaamigo);
    } else{
        
        Listaamigo = (tAmigo *)realloc(Listaamigo, (Numamigo + 1) * sizeof(tAmigo));
        verifica_alocacao(Listaamigo);
    }
    printf("Qual o nome do seu %d amigo?: ", Numamigo + 1);
    fflush(stdin);
    gets(str);
    fflush(stdin);
    Listaamigo[Numamigo].nome = (char*) malloc ((strlen(str)+1) * sizeof(char));
    strcpy(Listaamigo[Numamigo].nome, str);
    puts(Listaamigo[Numamigo].nome);

    printf("Qual eh o apelido de %s?: ", Listaamigo[Numamigo].nome);
    fflush(stdin);
    gets(str);
    fflush(stdin);
    Listaamigo[Numamigo].apelido = (char*) malloc ((strlen(str)+1) * sizeof(char));
    strcpy(Listaamigo[Numamigo].apelido, str);
    puts(Listaamigo[Numamigo].apelido);

    printf("Qual eh o telefone do seu amigo?: "); 
    fflush(stdin);
    gets(str);
    fflush(stdin);
    Listaamigo[Numamigo].telefone = (char*) malloc ((strlen(str)+1) * sizeof(char));
    strcpy(Listaamigo[Numamigo].telefone, str);
    puts(Listaamigo[Numamigo].telefone);

    printf("Qual o email de %s?: ", Listaamigo[Numamigo].nome);
    while(ver == false){
        fflush(stdin);
        gets(str);
        fflush(stdin);
        ver = validarEmail(str);
        if(ver == true){
            Listaamigo[Numamigo].email = (char*) malloc ((strlen(str)+1) * sizeof(char));
            strcpy(Listaamigo[Numamigo].email, str);
        } else {
            printf("Email invalido! O email deve conter 1 '@' e ao menos 1 '.'\n");
            printf("Digite novamente: ");
        }
        
    }
    ver = false;

    printf("Qual eh a data de nascimento de %s? (dd mm ): " Listaamigo[Numamigo].nome);
    while(ver == false){
        scanf("%d%d%d", &Listaamigo[Numamigo].nascimento.dia, &Listaamigo[Numamigo].nascimento.mes, &Listaamigo[Numamigo].nascimento.ano);
        ver == valide_data(Listaamigo[Numamigo].nascimento.dia, Listaamigo[Numamigo].nascimento.mes, Listaamigo[Numamigo].nascimento.ano);
        if(ver == false){
            printf("Data invalida! Digite novamente: ");
        }
    }
    
    Numamigo++;

}

void switchprincipal(int op){

    switch (op)
    {
        case '6':
            printf("Obrigado por trabalhar con nossos produtos!");
            exit(1);
        case '1':
            criaamigo();
            break;
        
    }
}

void menuprincipal(){

    system("cls");
    printf("***MENU PRINCIPAL***\n\n");
    printf("Digite:\n");
    printf("1. para manter amigo\n");
    printf("2. para manter local\n");
    printf("3. para manter categoria\n");
    printf("4. para manter encontro\n");
    printf("5. para Relatorios\n");
    printf("6. para Sair\n");
    printf("O que deseja fazer?: ");

}

void orienta(){

    int ver = 0;
    char op = 0;
    
    while(ver == 0){
        
        scanf(" %c", &op);
        ver = valido(op);
        if(ver == 0){
            printf("Operador invalido! Digite novamente: ");
        }
    }
    switchprincipal(op); 
}

int main(){

    system("cls");
    printf("Bom dia querido usuario!");
    Sleep(2000);
    menuprincipal(); 
    orienta(); 
    limpamemoria();
    printf("Obrigado por trabalhar com nossos produtos!");  

    return 0;
}