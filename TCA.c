#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include <ctype.h>

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

//declaracao de funcoes//

void limpamemoria();                            //limpa memoria alocada
bool validasubmenu(char a);                     //valida operadores de submenu
void verifica_alocacao(void *v);                //verifica se alocacao dinamica deu certo
bool valido(char a);                            //valida operador do menu principal
bool validarEmail(char *email);                 //valida o email do amigo
bool valide_data(int dias, int mes, int ano);   //valida datas
void criaamigo();                               //cria amigos
void menuprincipal();                           //explode o menu principal
void orienta();                                 //puxa uma verificacao pos menu principal
void excluiamigo();                             //exclui amigos
void editaamigo();                              //edita dados dos amigos
void excluiamigo();                             //lista negra
void switchamigo(int op);                       //switchcase do menu amigo
void menuamigo();                               //invoca as opcoes de acao para com um amigo
void menueditaamigo(int opAmigo);               //"o que deseja fazer com este amigo?"
void switchprincipal(int op)                    //invoca as funoces manter ou relatorios com um SC.

int main(){

    system("cls");
    printf("Bom dia querido usuario!");
    Sleep(2000);
    menuprincipal(); 
    limpamemoria();
    printf("Obrigado por trabalhar com nossos produtos!");  

    return 0;
}

void editaamigo(){
    int opAmigo = 0, ver = 1;
    char opIn = 'a', str[100];

    system("cls");
    printf("Digite 1 para pesquisar seu amigo pelo nome\n");
    printf("Digite 2 para exibir a lista de amigos\n");
    
    while(opIn != '1' && opIn != '2')
    {
        scanf("%c", &opIn);
        if(opIn != '1' && opIn != '2')
        {
            printf("Operador invalido! Digite novamente: ");
        }

    }

    if(opIn == '1'){

        system("cls");
        printf("Qual o nome do seu amigo?(atente-se a letras maiusculas): ");
        gets(str);
        while(ver != 0){
            for(int i = 0; i < Numamigo; i++){
                ver = strcmp(Listaamigo[i].nome, nome);
                if(result != 0){
                    continue;
                } else {
                    return result;
                }
            }
            if(ver == 0){
                printf("Amigo nao encontrado! Digite novamente: ");
            } else {
                printf("Amigo encontrado!");
                Sleep(1000);
                system("cls");  
            }
        }
        menueditaamigo(i);
    }
    
    printf("Qual amigo deseja editar?: ");
    while(opAmigo < 1 || opAmigo > Numamigo)
    {
        scanf(" %d", &opAmigo);
        if (opAmigo < 1 || opAmigo > Numamigo)
        {
            printf("Amigo inválido! Digite novamente: \n");

        }
    }
    menueditaamigo(opAmigo);
    scanf("%d", )

}

void menueditaamigo(int opAmigo){

    printf("Digite 1 para alterar o nome (%s)", Listaamigo[opAmigo].nome);
    printf("Digite 2 para alterar o apelido (%s)", Listaamigo[opAmigo].apelido);
    printf("Digite 3 para alterar o numero de telefone (%s)", Listaamigo[opAmigo].telefone);
    printf("Digite 4 para alterar o email (%s)", Listaamigo[opAmigo].email);
    printf("Digite 5 para alterar a data de nasicemnto (%d/%d/%d)", Listaamigo[opAmigo].nascimento.dia, Listaamigo[opAmigo].nascimento.mes, Listaamigo[opAmigo].nascimento.ano);

}

void excluiamigo() {
    int opAmigo = 0;
    printf("Qual o numero do amigo que deseja excluir? (de 1 a %d): ", Numamigo);
    
    while(opAmigo < 1 || opAmigo > Numamigo)
    {
        scanf(" %d", &opAmigo);
        if (opAmigo < 1 || opAmigo >= Numamigo)
        {
            printf("Amigo inválido! Digite novamente: \n");

        }

    }
    opAmigo--;//equivalencia, o amigo 1 na real eh o Listaamigoo[0], portanto, op-1
     
    free(Listaamigo[opAmigo].nome);
    free(Listaamigo[opAmigo].apelido);
    free(Listaamigo[opAmigo].email);
    free(Listaamigo[opAmigo].telefone);

    if(opAmigo < Numamigo){
        for (int i = opAmigo; i < Numamigo - 1; i++) 
        {//a posicao entao ucupada pelo amigo prestes a ser excluido, passa agora a ser ocupada
        //pelos dados do proximo amigo da lista, e assim sucessecivamente ateh o utimo da lista ser realocado.
        Listaamigo[i] = Listaamigo[i + 1];
        }
    }
    
    Numamigo--;
    Listaamigo = (tAmigo *)realloc(Listaamigo, Numamigo * sizeof(tAmigo));//realloca a Lista para o novo tamanho de Numamigo
    verifica_alocacao(Listaamigo);
    printf("Amigo excluído com sucesso!\n");
}

void limpamemoria(){

    for(int i = 0; i < Numamigo; i++){
        free(Listaamigo[Numamigo].nome);
        free(Listaamigo[Numamigo].apelido);
        free(Listaamigo[Numamigo].email);
        free(Listaamigo[Numamigo].telefone);
    }
    free(Listaamigo);

}

bool validasubmenu(char a){
    
    if(a != '1' && a != '2' && a != '3' && a != '4'){
        return false;
    } else {
        return true;
    }

}

void verifica_alocacao(void *v){
    if(!v){
        printf("ERRO AO ALOCAR MEMORIA!!!");
        exit(1);
    }
}

bool valido(char a){
    if(a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6'){// char suspender
        return false;
    }else{
        return true;
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

    system("cls");
    printf("Voce tem %d amigos no momento\n", Numamigo);

    if (Numamigo == 0) {
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

    printf("Qual eh a data de nascimento de %s? (dd mm aaaa): ", Listaamigo[Numamigo].nome);
    while(ver == false){
        scanf("%d%d%d", &Listaamigo[Numamigo].nascimento.dia, &Listaamigo[Numamigo].nascimento.mes, &Listaamigo[Numamigo].nascimento.ano);
        ver = valide_data(Listaamigo[Numamigo].nascimento.dia, Listaamigo[Numamigo].nascimento.mes, Listaamigo[Numamigo].nascimento.ano);
        if(ver == false){
            printf("Data invalida! Digite novamente: ");
        }
    }
    
    Numamigo++;
    menuamigo();
}

void switchamigo(int op){

    switch (op)
    {
        case '1':
            criaamigo();
            break;
        case '2':
            editaamigo();
            break;
        case '3':
            excluiamigo();
            break;  
        case '4':
            menuprincipal();
            break;      
    }
}

void menuamigo(){
    char op;
    bool ver = false;

    system("cls");
    printf("Menu amigo\nDigite:\n");
    printf("1 para criar um amigo\n");
    printf("2 para editar um amigo\n");
    printf("3 para excluir um amigo\n");
    printf("4 para voltar\n");
    printf("O que deseja fazer?: ");
    while(ver == false){
        scanf(" %c", &op);
        ver = validasubmenu(op);
        if(ver == false){
            printf("Operador invalido! Digite novamente: ");
        }
    }
    
    switchamigo(op);

}

void switchprincipal(int op){

    switch (op)
    {
        case '6':
            printf("Obrigado por trabalhar con nossos produtos!");
            exit(1);
        case '1':
            menuamigo();
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
    orienta();

}

void orienta(){

    bool ver = false;
    char op = 0;
    
    while(ver == false){
        
        scanf(" %c", &op);
        ver = valido(op);
        if(ver == false){
            printf("Operador invalido! Digite novamente: ");
        }
    }
    switchprincipal(op); 
}