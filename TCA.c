#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct
{ // g) horario

    int hora;
    int minuto;
} tHoraio;
typedef struct
{ // f) data

    int ano;
    int mes;
    int dia;
} tData;
typedef struct
{ // c) Endereco

    char *rua;
    int numero;
    char *bairro;
    char *cidade;
    char estado;
} tEndereco;
typedef struct
{ // d) Categoria

    char *categoria;
} tCategoria;
typedef struct
{ // a) Amigo

    char *nome;
    tData nascimento;
    char *apelido;
    char *email;
    char *telefone;
} tAmigo;
typedef struct
{ // b) Local

    char *NOM_encontro;
    tEndereco endereco;
} tLocal;
typedef struct
{ // e) Encontro

    tData data;
    tHoraio horario;
    tAmigo *amigos;
    tCategoria *categoria;
    char *descricao;
} tEncontro;

tEncontro *Listaencontro = NULL;
tAmigo *Listaamigo = NULL;
tLocal *Listalocal = NULL;
tCategoria *Listacategoria = NULL;

int Numencontro = 0, Numamigo = 0, Numcategoria = 0, Numlocal = 0;

//                                            // declaracao de funcoes
void firula();                                // mensagem bonitinha bem homossexual
void limpamemoria();                          // limpa memoria alocada
bool validasubmenu(char a);                   // valida operadores de submenu
void verifica_alocacao(void *v);              // verifica se alocacao dinamica deu certo
bool valido(char a);                          // valida operador do menu principal
bool validarEmail(char *email);               // valida o email do amigo
bool valide_data(int dias, int mes, int ano); // valida datas
void criaamigo();                             // cria amigos
void menuprincipal();                         // explode o menu principal
void orienta();                               // puxa uma verificacao pos menu principal
void orientaexcluiamigo();                    // exclui amigos
void editaamigo();                            // edita dados dos amigos
void excluiamigo();                           // lista negra
void switchamigo(int op);                     // switchcase do menu amigo
void menuamigo();                             // invoca as opcoes de acao para com um amigo
void menueditaamigo(int opAmigo);             // "o que deseja fazer com este amigo?"
void switchprincipal(int op);                 // invoca as funoces manter ou relatorios com um SC.
void exibeamigo(bool prolongar);              // printa os amigos e suas informacoes
void alteraramigo(char editor, int amigo);    // factualmente muda os dados do amigo
bool validanome(char nome[]);                 // cheks if theres a friend w that name
void menurelatorios();                        // puxa as opcoes de relatorios
void switchrelatorios(char op);               // invoca as funcoes de relatorio
void orientarelatorios();                     // escaneia o operador e invoca o switch
int buscaamigonome();                         // strcomparezao
void ERRO(int opErro);                        // mensagem de erro

int main()
{
    firula();
    limpamemoria();

    return 0;
}

void firula(){

    char word[] = "Hello, world!";

    system("cls");
    for(int i = 0; word[i] != '\0'; i++)
    {
        printf("%c", word[i]);
        Sleep(100);
    }
    Sleep(1500);
    system("cls");
    printf("Bom dia querido usuario!");
    Sleep(2500);
    menuprincipal();
}

void orientarelatorios(){

    char op = 'a';

    while (op != '1' && op != '2' && op != '3' && op != '4' && op != '5')
    {
        scanf(" %c", &op);
        if (op != '1' && op != '2' && op != '3' && op != '4' && op != '5')
        {
            printf("Operador invalido! Digite novamente: ");
        }
    }

    switchrelatorios(op);

}

void switchrelatorios(char op)
{

    switch (op)
    {
    case '5':
        menuprincipal();
        break;
    case '1':
        exibeamigo(true);
        break;
    }
}

void menurelatorios()
{
    system("cls");
    printf("***MENU DE RELATORIOS***\n\n");
    printf("Digite 1 para exibir o relatorio de amigos\n");
    printf("Digite 2 para exibir o relatorio de locais\n");
    printf("Digite 3 para exibir o relatorio de categorias\n");
    printf("Digite 4 para exibir o relatorio de encontros\n");
    printf("Digite 5 para voltar\n: ");
    orientarelatorios();

}

void exibeamigo(bool prolongar)
{

    system("cls");
    if (prolongar == false)
    {
        printf("AMIGOS:\n\n"); 
        for (int i = 0; i < Numamigo; i++)
        {
            printf("%d° amigo: %s;\n", i + 1, Listaamigo[i].nome);
        }
    }

    else if (prolongar == true)
    {
        printf("AMIGOS:\n\n");
        for (int i = 0; i < Numamigo; i++)
        {
            printf("Amigo %d: \n", i + 1);
            printf("Nome: %s\n", Listaamigo[i].nome);
            printf("Apelido: %s\n", Listaamigo[i].apelido);
            printf("Email: %s\n", Listaamigo[i].email);
            printf("Telefone: %s\n", Listaamigo[i].telefone);
            printf("Nascimento: (%d/%d/%d)\n\n", Listaamigo[i].nascimento.dia, Listaamigo[i].nascimento.mes, Listaamigo[i].nascimento.ano);
        }
    }
    
    Sleep(1000);
    printf("Pressione ENTER para continuar: ");
    while(getchar() != '\n');
    getchar();
    menuprincipal();
}

void editaamigo()
{
    int opAmigo = 0, ver = 1, i;
    char opIn = 'a', str[100], editor;

    system("cls");
    printf("Digite 1 para pesquisar seu amigo pelo nome\n");
    printf("Digite 2 para exibir a lista de amigos\n");
    printf("Digite 3 para voltar\n:");

    while (opIn != '1' && opIn != '2' && opIn != '3')
    {
        scanf(" %c", &opIn);
        if (opIn != '1' && opIn != '2' && opIn != '3')
        {
            printf("Operador invalido! Digite novamente: ");
        }
    }

    if (opIn == '1')
    {

        menueditaamigo(buscaamigonome);
        while (editor != '1' && editor != '2' && editor != '3' && editor != '4' && editor != '5')
        {
            scanf("%c", &editor);
            if (editor != '1' && editor != '2' && editor != '3' && editor != '4' && editor != '5')
            {
                printf("Operador invalido! Digite novamente: ");
            }
        }
        alteraramigo(editor, opAmigo);
    }

    if (opIn == '2')
    {
        printf("Qual amigo deseja editar?: \n");
        exibeamigo(false);
        while (opAmigo < 1 || opAmigo > Numamigo)
        {
            scanf(" %d", &opAmigo);
            if (opAmigo < 1 || opAmigo > Numamigo)
            {
                printf("Amigo inválido! Digite novamente: \n");
            }
        }
        opAmigo--;
        menueditaamigo(opAmigo);
        while (editor != '1' && editor != '2' && editor != '3' && editor != '4' && editor != '5')
        {
            scanf("%c", &editor);
            if (editor != '1' && editor != '2' && editor != '3' && editor != '4' && editor != '5')
            {
                printf("Operador invalido! Digite novamente: ");
            }
        }
        alteraramigo(editor, opAmigo);
    }

    if (opIn == '3')
    {
        menuamigo();
    }
}

void alteraramigo(char editor, int amigo)
{

    char str[100];
    bool ver = false;

    switch (editor)
    {
    case '1':
        printf("Qual o novo nome de %s?", Listaamigo[amigo].nome);
        fflush(stdin);
        gets(str);
        fflush(stdin);
        Listaamigo[Numamigo].nome = (char *)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(Listaamigo[Numamigo].nome, str);

    case '2':
        printf("Qual o novo apelido de %s?", Listaamigo[amigo].nome);
        fflush(stdin);
        gets(str);
        fflush(stdin);
        Listaamigo[Numamigo].apelido = (char *)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(Listaamigo[Numamigo].apelido, str);

    case '3':
        printf("Qual o novo numero de telefone de %s?", Listaamigo[amigo].nome);
        fflush(stdin);
        gets(str);
        fflush(stdin);
        Listaamigo[Numamigo].telefone = (char *)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(Listaamigo[Numamigo].telefone, str);

    case '4':
        printf("Qual o novo email de %s?", Listaamigo[amigo].nome);
        fflush(stdin);
        gets(str);
        fflush(stdin);
        Listaamigo[Numamigo].email = (char *)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(Listaamigo[Numamigo].email, str);
        while (ver == false)
        {
            fflush(stdin);
            gets(str);
            fflush(stdin);
            ver = validarEmail(str);
            if (ver == true)
            {
                Listaamigo[Numamigo].email = (char *)malloc((strlen(str) + 1) * sizeof(char));
                strcpy(Listaamigo[Numamigo].email, str);
            }
            else
            {
                printf("Email invalido! O email deve conter 1 '@' e ao menos 1 '.'\n");
                printf("Digite novamente: ");
            }
        }
        ver = false;

    case '5':
        printf("Qual eh a data de nascimento de %s? (dd mm aaaa): ", Listaamigo[Numamigo].nome);
        while (ver == false)
        {
            scanf("%d%d%d", &Listaamigo[Numamigo].nascimento.dia, &Listaamigo[Numamigo].nascimento.mes, &Listaamigo[Numamigo].nascimento.ano);
            ver = valide_data(Listaamigo[Numamigo].nascimento.dia, Listaamigo[Numamigo].nascimento.mes, Listaamigo[Numamigo].nascimento.ano);
            if (ver == false)
            {
                printf("Data invalida! Digite novamente: ");
            }
        }
    }

    printf("Amigo Editado com sucesso!");
    Sleep(1500);
    menuamigo();
}

void menueditaamigo(int opAmigo)
{
    system("cls");
    printf("Digite 1 para alterar o nome (%s)\n", Listaamigo[opAmigo].nome);
    printf("Digite 2 para alterar o apelido (%s)\n", Listaamigo[opAmigo].apelido);
    printf("Digite 3 para alterar o numero de telefone (%s)\n", Listaamigo[opAmigo].telefone);
    printf("Digite 4 para alterar o email (%s)\n", Listaamigo[opAmigo].email);
    printf("Digite 5 para alterar a data de nasicemnto (%d/%d/%d)\n", Listaamigo[opAmigo].nascimento.dia, Listaamigo[opAmigo].nascimento.mes, Listaamigo[opAmigo].nascimento.ano);
}

void excluiamigo()
{

}

void orientaexcluiamigo()
{

    char opIn, str[100];
    int opAmigo = 0, i, ver = 0;

    system("cls");
    printf("Digite 1 para pesquisar seu amigo pelo nome\n");
    printf("Digite 2 para exibir a lista de amigos\n");
    printf("Digite 3 para voltar\n:");

    while (opIn != '1' && opIn != '2')
    {
        scanf(" %c", &opIn);
        if (opIn != '1' && opIn != '2')
        {
            printf("Operador invalido! Digite novamente: ");
        }
    }

    if (opIn == '1')
    {

        opAmigo = buscaamigonome();

        free(Listaamigo[opAmigo].nome);
        free(Listaamigo[opAmigo].apelido);
        free(Listaamigo[opAmigo].email);
        free(Listaamigo[opAmigo].telefone);

        if (opAmigo < Numamigo)
        {
            for (i = opAmigo; i < Numamigo - 1; i++)
            {
                Listaamigo[i] = Listaamigo[i + 1];
            }
        }

        Numamigo--;
        Listaamigo = (tAmigo *)realloc(Listaamigo, Numamigo * sizeof(tAmigo)); // realloca a Lista para o novo tamanho de Numamigo
        verifica_alocacao(Listaamigo);
        printf("Amigo excluído com sucesso!\n");
        menuamigo();
    }

    if (opIn == '2')
    {

        printf("Qual o numero do amigo que deseja excluir? (de 1 a %d): ", Numamigo);

        while (opAmigo < 1 || opAmigo > Numamigo)
        {
            scanf(" %d", &opAmigo);
            if (opAmigo < 1 || opAmigo >= Numamigo)
            {
                printf("Amigo inválido! Digite novamente: \n");
            }
        }
        opAmigo--;

        free(Listaamigo[opAmigo].nome);
        free(Listaamigo[opAmigo].apelido);
        free(Listaamigo[opAmigo].email);
        free(Listaamigo[opAmigo].telefone);

        if (opAmigo < Numamigo)
        {
            for (i = opAmigo; i < Numamigo - 1; i++)
            {
                Listaamigo[i] = Listaamigo[i + 1];
            }
        }

        Numamigo--;
        Listaamigo = (tAmigo *)realloc(Listaamigo, Numamigo * sizeof(tAmigo));
        verifica_alocacao(Listaamigo);
        printf("Amigo excluído com sucesso!\n");
        menuamigo();
    }

    menuamigo();
}

void limpamemoria()
{
    char word[] = "Obrigado por trabalhar com nossos produtos!";

    for (int i = 0; i < Numamigo; i++)
    {
        free(Listaamigo[Numamigo].nome);
        free(Listaamigo[Numamigo].apelido);
        free(Listaamigo[Numamigo].email);
        free(Listaamigo[Numamigo].telefone);
    }
    free(Listaamigo);
    
    system("cls");
    for(int i = 0; word[i] != '\0'; i++)
    {
        printf("%c", word[i]);
        Sleep(80);
    }
}

bool validasubmenu(char a)
{

    if (a != '1' && a != '2' && a != '3' && a != '4')
    {
        return false;
    }
    else
    {
        return true;
    }
}

void verifica_alocacao(void *v)
{
    if (!v)
    {
        printf("ERRO AO ALOCAR MEMORIA!!!");
        exit(1);
    }
}

bool valido(char a)
{
    if (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6')
    { // char suspender
        return false;
    }
    else
    {
        return true;
    }
}

bool validarEmail(char *email)
{
    int countA = 0, countB = 0;

    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
        {
            countA++;
        }
        else if (email[i] == '.')
        {
            countB++;
        }
    }

    if (countA != 1 || countB < 1)
    {
        return false;
    }
    else
    {
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

void criaamigo()
{

    // int i, j, k;
    char str[100];
    bool ver = false;

    system("cls");
    printf("Voce tem %d amigos no momento\n", Numamigo);

    if (Numamigo == 0)
    {
        Listaamigo = (tAmigo *)malloc(sizeof(tAmigo));
        verifica_alocacao(Listaamigo);
    }
    else
    {

        Listaamigo = (tAmigo *)realloc(Listaamigo, (Numamigo + 1) * sizeof(tAmigo));
        verifica_alocacao(Listaamigo);
    }

    while (ver == false)
    {

        printf("Qual o nome do seu %d amigo?: ", Numamigo + 1);
        fflush(stdin);
        gets(str);
        fflush(stdin);
        ver = validanome(str);
        if (ver == false)
        {
            printf("\nJa existe um amigo com este nome!");
            printf("\nAdicione um sobrenome para diferencia-lo.");
            printf("\nDigite novamente: ");
        }
        else
        {
            Listaamigo[Numamigo].nome = (char *)malloc((strlen(str) + 1) * sizeof(char));
            verifica_alocacao(Listaamigo[Numamigo].nome);
            strcpy(Listaamigo[Numamigo].nome, str);
        }
    }
    ver = false;

    printf("Qual eh o apelido de %s?: ", Listaamigo[Numamigo].nome);
    fflush(stdin);
    gets(str);
    fflush(stdin);
    Listaamigo[Numamigo].apelido = (char *)malloc((strlen(str) + 1) * sizeof(char));
    verifica_alocacao(Listaamigo[Numamigo].apelido);
    strcpy(Listaamigo[Numamigo].apelido, str);

    printf("Qual eh o telefone do seu amigo?: ");
    fflush(stdin);
    gets(str);
    fflush(stdin);
    Listaamigo[Numamigo].telefone = (char *)malloc((strlen(str) + 1) * sizeof(char));
    verifica_alocacao(Listaamigo[Numamigo].telefone);
    strcpy(Listaamigo[Numamigo].telefone, str);

    printf("Qual o email de %s?: ", Listaamigo[Numamigo].nome);
    while (ver == false)
    {

        fflush(stdin);
        gets(str);
        fflush(stdin);
        ver = validarEmail(str);
        if (ver == true)
        {
            Listaamigo[Numamigo].email = (char *)malloc((strlen(str) + 1) * sizeof(char));
            verifica_alocacao(Listaamigo[Numamigo].email);
            strcpy(Listaamigo[Numamigo].email, str);
        }
        else
        {
            printf("Email invalido! O email deve conter 1 '@' e ao menos 1 '.'\n");
            printf("Digite novamente: ");
        }
    }
    ver = false;

    printf("Qual eh a data de nascimento de %s? (dd mm aaaa): ", Listaamigo[Numamigo].nome);
    while (ver == false)
    {
        scanf("%d%d%d", &Listaamigo[Numamigo].nascimento.dia, &Listaamigo[Numamigo].nascimento.mes, &Listaamigo[Numamigo].nascimento.ano);
        ver = valide_data(Listaamigo[Numamigo].nascimento.dia, Listaamigo[Numamigo].nascimento.mes, Listaamigo[Numamigo].nascimento.ano);
        if (ver == false)
        {
            printf("Data invalida! Digite novamente: ");
        }
    }

    Numamigo++;
    printf("Amigo adicionado com sucesso!");
    menuamigo();
}

void switchamigo(int op)
{

    switch (op)
    {
    case '1':
        criaamigo();
        break;
    case '2':
        if(Numamigo == 0)
        {
            printf("Nao ha amigos para serem editados!");
            Sleep(2500);
            menuamigo();
        } 
        else 
        {
            editaamigo();
            break;
        }
        
    case '3':
        if(Numamigo == 0)
        {
            printf("Nao ha amigos para serem excluidos!");
            Sleep(2500);
            menuamigo();
        } 
        else
        {
            orientaexcluiamigo();
            break;
        }
        
    case '4':
        menuprincipal();
        break;
    }
}

void menuamigo()
{
    char op;
    bool ver = false;

    system("cls");
    printf("Menu amigo\nDigite:\n");
    printf("1 para criar um amigo\n");
    printf("2 para editar um amigo\n");
    printf("3 para excluir um amigo\n");
    printf("4 para voltar\n");
    printf("O que deseja fazer?: ");
    while (ver == false)
    {
        scanf(" %c", &op);
        ver = validasubmenu(op);
        if (ver == false)
        {
            printf("Operador invalido! Digite novamente: ");
        }
    }

    switchamigo(op);
}

void switchprincipal(int op)
{

    switch (op)
    {
    case '6':
        limpamemoria();
        exit(1);

    case '5':
        menurelatorios();
        break;

    case '1':
        menuamigo();
        break;
    }
}

void menuprincipal()
{

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

void orienta()
{

    bool ver = false;
    char op = 0;

    while (ver == false)
    {

        scanf(" %c", &op);
        ver = valido(op);
        if (ver == false)
        {
            printf("Operador invalido! Digite novamente: ");
        }
    }
    switchprincipal(op);
}

bool validanome(char nome[])
{

    for (int i = 0; i < Numamigo; i++)
    {
        int ver = strcmp(nome, Listaamigo[i].nome);
        if (ver != 0)
        {
            return false;
        }
    }

    return true;
}

int buscaamigonome()
{
    int ver = 0, i;
    char str[100];

    while (ver != 0)
        {
            system("cls");
            printf("Qual o nome do seu amigo?(atente-se a letras maiusculas): ");
            gets(str);
            printf("Buscando");
            for (i = 0; i < 3; i++)
            {
                Sleep(400);
                printf(".");
            }
            system("cls");
            for (i = 0; i < Numamigo; i++)
            {
                ver = strcmp(Listaamigo[i].nome, str);
                if (ver == 0)
                {
                    printf("Amigo encontrado!");
                    Sleep(1000);
                    system("cls");
                    break;
                }
                
            }
            if (ver != 0)
            {
                ERRO(3);
                Sleep(2000);
            }
        }
        return i;
}

void ERRO(int opErro)
{

    switch(opErro)
    {
        case 1:
            printf("Operador invalido! Digite novamente: ");
            break;
        case 2: 
            printf("Amigo invalido! Digite novamente: ");
            break;
        case 3:
            printf("Amigo nao encontrado!");
            break;
        case 4:
            printf("Erro ao alocar memoria!");
            break;
        case 5:
            printf("Nao existem amigos para serem editados!");
            break;
        case 6: 
            printf("Nao existem amigos para serem excluidos!");
            break;
    }
}