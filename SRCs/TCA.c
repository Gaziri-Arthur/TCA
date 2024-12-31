#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include <ctype.h>
#define CLS printf("\033[2J\033[1;1H");
#define GTS        \
    fflush(stdin); \
    gets(str);     \
    fflush(stdin);

typedef struct
{

    int hora;
    int minuto;
} tHoraio;
typedef struct
{

    int ano;
    int mes;
    int dia;
} tData;
typedef struct
{

    char *numero;
    char *logradouro;
    char *bairro;
    char *cidade;
    char *estado;

} tEndereco;
typedef struct
{

    char *categoria;
    int id;
} tCategoria;
typedef struct
{

    tData nascimento;
    int id;
    char *nome;
    char *apelido;
    char *email;
    char *telefone;

} tAmigo;
typedef struct
{

    int id;
    tEndereco endereco;
    char *nomelocal;

} tLocal;
typedef struct
{

    tData data;
    tHoraio horario;
    tAmigo **amigos;
    tCategoria **categoria;
    tLocal *local;
    int Namigos;
    char *descricao;
    char *nome;

} tEncontro;

tEncontro *Listaencontro = NULL;
tAmigo *Listaamigo = NULL;
tLocal *Listalocal = NULL;
tCategoria *Listacategoria = NULL;

int Numencontro = 0, Numamigo = 0, Numcategoria = 0, Numlocal = 0;

//                            // inicio meio e fim
void start();                 // "fractal trunk"
void menuprincipal();         // explode o menu principal
void orienta();               // puxa uma verificacao pos menu principal
void switchprincipal(int op); // invoca as funoces manter ou relatorios com um SC.
void limpamemoria();          // limpa memoria alocada
void end();                   // finalização do programa
//
void menuamigo();                          // invoca as opcoes de acao para com um amigo
void switchamigo(char op);                 // switchcase do menu amigo
void criaamigo();                          // cria amigos
void orientaexcluiamigo();                 // orienta a exlusao de amigos
void editaamigo();                         // edita dados dos amigos
void excluiamigo(int opAmigo);             // lista negra
void menueditaamigo(int opAmigo);          // "o que deseja fazer com este amigo?"
void alteraramigo(char editor, int amigo); // factualmente muda os dados do amigo
bool validanome(char *nome);               // cheks if theres a friend w that name
bool validaemail(char *email);             // validates emails and checks for doubles
bool validanumero(char *num);              // checks for doubles
int buscaxnome(int op);                    // buscapelonome
//
void menucategoria();          // invoca o menu categoria
void switchcategoria(char op); // invoca as opcoes de acao para com uma categoria
void criacategoria();          // cria categorias
void editacategoria();         // orienta a edicao de categoria
void alteracategoria(int cat); // edita categorias
void orientaexcluicat();       // orienta a exclusao de categorias
void excluicat(int opCat);     // exclui categorias
//
void criaencontro(); // cria encontros
bool validanomenc(char *str);
//
void menulocal();                        // invoca o menu local
void switchlocal(char op);               // invoca as opcoes de acao para com um local
void crialocal();                        // cria locais
void orientaeditalocal();                // orienta a edicao de locais
void editalocal(char editor, int local); // edita locais
void orientaexcluilocal();               // orienta a exclusao de locais
void excluilocal(int opLocal);           // exclui locais
void menueditalocal(int opLocal);        // "o que deseja fazer com este local?"
//
void menurelatorios();                     // puxa as opcoes de relatorios
void switchrelatorios(char op);            // invoca as funcoes de relatorio
void exibeamigo(bool prolongar, bool rel); // printa os amigos e suas informacoes
void exibecategoria(bool rel);             // printa as categorias
void exibelocal(bool prolongar, bool rel); // printa os locais e suas informacoes
//
void verifica_alocacao(void *v);              // verifica se alocacao dinamica deu certo
char valida16();                              // valida operador do menu principal
char valida14();                              // valida operadoeres 1 a 4
bool valide_data(int dias, int mes, int ano); // valida datas
bool validasimnao();                          // valida sim e nao
char valida15();                              // valida 1 a 5
char valida13();                              // valida 1 a 3
char valida12();                              // valida 1 a 2
void ERRO(int opErro);                        // mensagem de erro
void adviser(int opex);                       // Pergunta se o usuario quer prossegiuir com a ma ideia

int main()
{
    start();
}

bool validanomenc(char *str)
{
    for (int i = 0; i < Numencontro; i++)
    {
        (strcmp(str, Listalocal[i].nome) == 0) ? return false : continue;
    }
    return true;
}

criaencontro()
{
    char str[100];
    CLS

        printf("**CRIACAO DE ENCONTROS***\n\n");
    printf("Você tem %d encontros no momento\n\n", Numencontro);
    printf("Qual será o nome de seu encontro?: ");
    do
    {
        GTS if (validanomenc(str))
        {
            Listalocal[Numlocal].nome = (char *)malloc((strlen(str) + 1) * sizeof(char));
            strcpy(Listalocal[Numlocal].nome, str);
            break;
        }
        else
        {
            printf("Já há um encontro com este nome!\n");
            printf("Escolha outro nome: ");
        }
    } while (!validanomenc(str));

    CLS
        printf("Seu encontro precisa de um local.\n");
    printf("Digite 1 para adicionar um local existente.\nDigite 2 para adicionar um novo local");
    char op = valida12();
    if (op == 1)
    {
        exibelocal(true, false);
        Printf("Digite um operador de 1 a %d para escolher o local parq seu encontro", Numlocal);
        do
        {
            scanf(" %d", &op);
            if (op < 1 || op > Numlocal)
            {
                ERRO(1);
            }
        } while (op < 1 || op > Numlocal);
        Listaencontro[Numencontro].local = &Listalocal[op - 1];
    }
    else
    {
        crialocal();
    }
}

void adviser(int opex)
{
    CLS
        ERRO(0);
    bool maideia = validasimnao();
    if (maideia)
    {
        if (opex == 1)
        {
            orientaexcluiamigo();
        }
        else if (opex == 2)
        {
            orientaexcluilocal();
        }
        else if (opex == 3)
        {
            orientaexcluicat();
        }
        else
        {
            // orientaexcluiencontro();
        }
    }
    else
    {
        menuprincipal();
    }
}

void excluilocal(int opLocal)
{
    free(Listalocal[opLocal].endereco.bairro);
    free(Listalocal[opLocal].endereco.cidade);
    free(Listalocal[opLocal].endereco.estado);
    free(Listalocal[opLocal].endereco.logradouro);
    free(Listalocal[opLocal].endereco.numero);
    free(Listalocal[opLocal].nomelocal);

    for (int i = opLocal; i < Numlocal - 1; i++)
        if (opLocal < Numlocal)
        {
            Listalocal[i] = Listalocal[i + 1];
            for (int i = opLocal; i < Numlocal - 1; i++)
            {
                Listalocal[i] = Listalocal[i + 1];
            }
        }

    Numlocal--;
    Listalocal = (tLocal *)realloc(Listalocal, Numlocal * sizeof(tLocal));
    verifica_alocacao(Listalocal);
    printf("Local excluido com sucesso!\n");
    Sleep(2000);
    menulocal();
}
/******  4da5208b-52fa-488d-a21d-1764659f68c0  *******/

void orientaexcluilocal()
{
    int opLocal;

    CLS
        printf("Digite 1 para pesquisar seu local pelo nome\n");
    printf("Digite 2 para exibir a lista de locais\n");
    printf("Digite 3 para voltar\nDigite a opcao:");

    char opIn = valida13();

    if (opIn == '1')
    {
        opLocal = buscaxnome(2);
        excluilocal(opLocal);
    }
    else if (opIn == '2')
    {
        printf("Qual o numero do local que deseja excluir?: ");
        exibelocal(false, false);

        while (opLocal < 1 || opLocal > Numlocal)
        {
            scanf(" %d", &opLocal);
            if (opLocal < 1 || opLocal >= Numlocal)
            {
                ERRO(19);
            }
        }
        opLocal--;
        excluilocal(opLocal);
    }
    else
    {
        return;
    }
}

void editalocal(char editor, int local)
{

    char str[100];
    CLS

        switch (editor)
    {
    case '1':
        printf("Qual o novo nome de %s?: ", Listalocal[local].nomelocal);
        GTS
            Listalocal[local]
                .nomelocal = (char *)malloc((strlen(str) + 1) * sizeof(char));
        verifica_alocacao(Listalocal[local].nomelocal);
        strcpy(Listalocal[local].nomelocal, str);
        break;

    case '2':
        printf("Qual o novo estado para seu encontro?: ");
        GTS
            Listalocal[local]
                .endereco.estado = (char *)malloc((strlen(str) + 1) * sizeof(char));
        verifica_alocacao(Listalocal[local].endereco.estado);
        strcpy(Listalocal[local].endereco.estado, str);
        printf("Qual a nova cidade para seu encontro?: ");
        GTS
            Listalocal[local]
                .endereco.cidade = (char *)malloc((strlen(str) + 1) * sizeof(char));
        verifica_alocacao(Listalocal[local].endereco.cidade);
        strcpy(Listalocal[local].endereco.cidade, str);
        printf("Qual o novo bairro para seu encontro?: ");
        GTS
            Listalocal[local]
                .endereco.bairro = (char *)malloc((strlen(str) + 1) * sizeof(char));
        verifica_alocacao(Listalocal[local].endereco.bairro);
        strcpy(Listalocal[local].endereco.bairro, str);
        printf("Qual o novo logradouro para seu encontro?: ");
        GTS
            Listalocal[local]
                .endereco.logradouro = (char *)malloc((strlen(str) + 1) * sizeof(char));
        verifica_alocacao(Listalocal[local].endereco.logradouro);
        strcpy(Listalocal[local].endereco.logradouro, str);
        printf("Qual o novo numero para seu encontro?: ");
        GTS
            Listalocal[local]
                .endereco.numero = (char *)malloc((strlen(str) + 1) * sizeof(char));
        verifica_alocacao(Listalocal[local].endereco.numero);
        strcpy(Listalocal[local].endereco.numero, str);
        break;

    case '3':
        printf("Qual o novo numero para seu encontro?: ");
        GTS
            Listalocal[local]
                .endereco.numero = (char *)malloc((strlen(str) + 1) * sizeof(char));
        verifica_alocacao(Listalocal[local].endereco.numero);
        strcpy(Listalocal[local].endereco.numero, str);
        break;
    }
    CLS
        printf("Local Editado com sucesso!");
    Sleep(1500);
    menulocal();
}

void menueditalocal(int opLocal)
{

    CLS
        printf("Digite 1 para alterar o nome (%s)\n", Listalocal[opLocal].nomelocal);
    printf("Digite 2 para alterar a endereco %s, %s, %s, %s, %s\n", Listalocal[opLocal].endereco.estado, Listalocal[opLocal].endereco.cidade, Listalocal[opLocal].endereco.bairro, Listalocal[opLocal].endereco.logradouro, Listalocal[opLocal].endereco.numero);
    printf("Digite 3 para alterar o numero (%s)\n", Listalocal[opLocal].endereco.numero);
}

char valida12()
{
    char opIn;
    do
    {
        scanf(" %c", &opIn);
        if (opIn != '1' && opIn != '2')
        {
            ERRO(1);
        }
    } while (opIn != '1' && opIn != '2');

    return opIn;
}
char valida13()
{
    char opIn;
    do
    {
        scanf(" %c", &opIn);
        if (opIn != '1' && opIn != '2' && opIn != '3')
        {
            ERRO(1);
        }
    } while (opIn != '1' && opIn != '2' && opIn != '3');

    return opIn;
}

char valida14()
{
    char opIn;
    do
    {
        scanf(" %c", &opIn);
        if (opIn != '1' && opIn != '2' && opIn != '3' && opIn != '4')
        {
            ERRO(1);
        }
    } while (opIn != '1' && opIn != '2' && opIn != '3' && opIn != '4');

    return opIn;
}

char valida15()
{
    char op;
    do
    {
        scanf(" %c", &op);
        if (op != '1' && op != '2' && op != '3' && op != '4' && op != '5')
        {
            ERRO(1);
        }
    } while (op != '1' && op != '2' && op != '3' && op != '4' && op != '5');

    return op;
}
void exibelocal(bool prolongar, bool rel)
{
    CLS

        if (!prolongar)
    {
        printf("LOCAIS:\n\n");
        for (int i = 0; i < Numlocal; i++)
        {
            printf("%d Local: %s\n", i + 1, Listalocal[i].nomelocal);
        }
    }

    else if (prolongar)
    {
        printf("LOCAIS:\n\n");
        for (int i = 0; i < Numlocal; i++)
        {
            printf("\nLocal %d: \n", i + 1);
            printf("Nome: %s\n", Listalocal[i].nomelocal);
            printf("Endereco: %s, %s, %s, %s, %s\n", Listalocal[i].endereco.logradouro, Listalocal[i].endereco.numero, Listalocal[i].endereco.bairro, Listalocal[i].endereco.cidade, Listalocal[i].endereco.estado);
        }
    }

    if (rel)
    {
        Sleep(1000);
        printf("Pressione ENTER para voltar: ");
        while (getchar() != '\n')
            ;
        getchar();
        menurelatorios();
    }
    else
    {
        return;
    }
}

void orientaeditalocal()
{
    int opLocal = 0;
    char editor;

    CLS
        printf("Digite 1 para pesquisar seu local pelo nome\n");
    printf("Digite 2 para exibir a lista de locais\n");
    printf("Digite 3 para voltar\nDigite a opcao: ");
    char opIn = valida13();

    if (opIn == '1')
    {
        opLocal = buscaxnome(2);
        menueditalocal(opLocal);
        printf("\n\nDigite para alterar: ");
        editor = valida13();
        editalocal(editor, opLocal);
    }
    else if (opIn == '2')
    {
        exibelocal(false, false);
        printf("Qual o numero do local que deseja editar?: ");
        while (opLocal < 1 || opLocal > Numlocal)
        {
            scanf(" %d", &opLocal);
            if (opLocal < 1 || opLocal > Numlocal)
            {
                ERRO(19);
            }
        }
        opLocal--;
        menueditalocal(opLocal);
        printf("\n\nDigite para alterar: ");
        editor = valida13();
        editalocal(editor, opLocal);
    }
    else
    {
        return;
    }
}

void crialocal()
{
    char str[100];

    CLS
        printf("Voce tem %d locais no momento\n\n", Numlocal);

    (Numlocal == 0) ? (Listalocal = (tLocal *)malloc(1 * sizeof(tLocal))) : (Listalocal = (tLocal *)realloc(Listalocal, (Numlocal + 1) * sizeof(tLocal)));
    verifica_alocacao(Listalocal);

    printf("Em qual estado sera seu encontro?: ");
    GTS
        Listalocal[Numlocal]
            .endereco.estado = (char *)malloc((strlen(str) + 1) * sizeof(char));
    verifica_alocacao(Listalocal[Numlocal].endereco.estado);
    strcpy(Listalocal[Numlocal].endereco.estado, str);

    printf("Em qual cidade sera seu encontro?: ");
    GTS
        Listalocal[Numlocal]
            .endereco.cidade = (char *)malloc((strlen(str) + 1) * sizeof(char));
    verifica_alocacao(Listalocal[Numlocal].endereco.cidade);
    strcpy(Listalocal[Numlocal].endereco.cidade, str);

    printf("Em qual bairro sera seu encontro?: ");
    GTS
        Listalocal[Numlocal]
            .endereco.bairro = (char *)malloc((strlen(str) + 1) * sizeof(char));
    verifica_alocacao(Listalocal[Numlocal].endereco.bairro);
    strcpy(Listalocal[Numlocal].endereco.bairro, str);

    printf("Qual o logradouro ser seu encontro?: ");
    GTS
        Listalocal[Numlocal]
            .endereco.logradouro = (char *)malloc((strlen(str) + 1) * sizeof(char));
    verifica_alocacao(Listalocal[Numlocal].endereco.logradouro);
    strcpy(Listalocal[Numlocal].endereco.logradouro, str);

    printf("Qual o numero para seu encontro?: ");
    GTS
        Listalocal[Numlocal]
            .endereco.numero = (char *)malloc((strlen(str) + 1) * sizeof(char));
    verifica_alocacao(Listalocal[Numlocal].endereco.numero);
    strcpy(Listalocal[Numlocal].endereco.numero, str);

    printf("Qual o nome do seu local?: ");
    GTS
        Listalocal[Numlocal]
            .nomelocal = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(Listalocal[Numlocal].nomelocal, str);

    Numlocal++;
    CLS
        printf("Local criado com sucesso!");
    Sleep(1000);
}

void switchlocal(char op)
{
    switch (op)
    {
    case '1':
        crialocal();
        break;
    case '2':
        if (Numlocal < 1)
        {
            ERRO(21);
        }
        else
        {
            orientaeditalocal();
        }
        break;
    case '3':
        if (Numlocal < 1)
        {
            ERRO(22);
        }
        else if (Numlocal < 2)
        {
            adviser(2);
        }
        else
        {
            orientaexcluilocal();
        }

        break;
    case '4':
        menuprincipal();
    }
    return;
}

void menulocal()
{

    CLS
        printf("***MENU LOCAL***\n\nDigite:\n");
    printf("1. para criar um local\n");
    printf("2. para editar um local\n");
    printf("3. para excluir um local\n");
    printf("4. para voltar\n");
    printf("\nO que deseja fazer?: ");
    char op = valida14();
    switchlocal(op);
    return;
}

void excluicat(int opCat)
{

    if (opCat < Numcategoria)
    {
        for (int i = opCat; i < Numcategoria - 1; i++)
        {
            Listacategoria[i] = Listacategoria[i + 1];
        }
    }

    Numcategoria--;
    Listacategoria = (tCategoria *)realloc(Listacategoria, Numcategoria * sizeof(tCategoria));
    verifica_alocacao(Listacategoria);
    printf("Categoria excluida com sucesso!\n");
    Sleep(2000);
    menucategoria();
}

void orientaexcluicat()
{
    int opCat = 0;

    CLS
        printf("Digite 1 para pesquisar sua categoria pelo nome\n");
    printf("Digite 2 para exibir a lista de categorias\n");
    printf("Digite 3 para voltar\nDigite a opcao:");

    char opIn = valida13();

    if (opIn == '1')
    {
        int i = buscaxnome(3);
        excluicat(i);
    }
    else if (opIn == '2')
    {
        CLS
            printf("Qual categoria deseja excluir?: \n");
        exibecategoria(false);
        printf("\n: ");
        while (opCat < 1 || opCat > Numcategoria)
        {
            scanf(" %d", &opCat);
            if (opCat < 1 || opCat > Numcategoria)
            {
                ERRO(8);
            }
        }
        opCat--;
        excluicat(opCat);
    }
    else
    {
        menucategoria();
    }
}

void alteracategoria(int cat)
{
    char str[100];

    printf("Qual novo nome deseja para sua categoria?: ");
    GTS
        Listacategoria[cat]
            .categoria = (char *)malloc((strlen(str) + 1) * sizeof(char));
    verifica_alocacao(Listacategoria[cat].categoria);
    strcpy(Listacategoria[cat].categoria, str);
    printf("Categoria alterada com sucesso!");
    Sleep(2000);
    menucategoria();
}

void exibecategoria(bool rel)
{

    CLS

        printf("CATEGORIAS:\n\n");
    for (int i = 0; i < Numcategoria; i++)
    {
        printf("Categoria %d: %s\n", i + 1, Listacategoria[i].categoria);
    }

    if (rel)
    {
        Sleep(1000);
        printf("Pressione ENTER para voltar: ");
        while (getchar() != '\n')
            ;
        getchar();
        menurelatorios();
    }
    else
    {
        return;
    }
}
void editacategoria()
{
    int opCat = 0;
    char opIn = 'a';

    CLS
        printf("Digite 1 para pesquisar sua categoria pelo nome\n");
    printf("Digite 2 para exibir a lista de categorias\n");
    printf("Digite 3 para voltar\nDigite a opcao: ");

    opIn = valida13();
    if (opIn == '1')
    {
        int i = buscaxnome(3);
        alteracategoria(i);
    }
    else if (opIn == '2')
    {
        printf("Qual categoria deseja editar?: \n");
        exibecategoria(false);
        printf("\n: ");
        while (opCat < 1 || opCat > Numcategoria)
        {
            scanf(" %d", &opCat);
            if (opCat < 1 || opCat > Numcategoria)
            {
                ERRO(8);
            }
        }
        opCat--;
        alteracategoria(opCat);
    }
    else
    {
        menucategoria();
    }
}

bool validasimnao()
{
    char op;

    do
    {
        fflush(stdin);
        scanf(" %c", &op);
        if (op != 's' && op != 'n' && op != 'S' && op != 'N')
        {
            ERRO(1);
        }
    } while (op != 's' && op != 'n' && op != 'S' && op != 'N');

    if (op == 's' || op == 'S')
    {
        return true;
    }
    return false;
}

void criacategoria()
{
    char str[100];

    CLS
        printf("Voce tem %d categorias no momento\n", Numcategoria);

    (Numcategoria == 0) ? (Listacategoria = (tCategoria *)malloc(1 * sizeof(tCategoria))) : (Listacategoria = (tCategoria *)realloc(Listacategoria, (Numcategoria + 1) * sizeof(tCategoria)));
    verifica_alocacao(Listacategoria);

    Listacategoria[Numcategoria].id = 0;

    printf("\nQual nome deseja para sua categoria?: ");
    GTS
        Listacategoria[Numcategoria]
            .categoria = (char *)malloc((strlen(str) + 1) * sizeof(char));
    verifica_alocacao(Listacategoria[Numcategoria].categoria);
    strcpy(Listacategoria[Numcategoria].categoria, str);

    Numcategoria++;
    printf("Categoria adicionada com sucesso!\n");
    Sleep(2000);
    menucategoria();
}

void menucategoria()
{

    CLS
        printf("***MENU CATEGORIA***\n\nDigite:\n");
    printf("1. para criar uma categoria\n");
    printf("2. para editar uma categoria\n");
    printf("3. para excluir uma categoria\n");
    printf("4. para voltar\n");
    printf("\nO que deseja fazer?: ");
    char op = valida14();
    switchcategoria(op);
    return;
}

void switchcategoria(char op)
{
    switch (op)
    {
    case '1':
        criacategoria();
        break;
    case '2':
        if (Numcategoria == 0)
        {
            printf("Nao ha categorias para serem editadas!");
            Sleep(2500);
            return;
        }
        else
        {
            editacategoria();
            break;
        }

    case '3':
        if (Numcategoria == 0)
        {
            printf("Nao ha catetgorias para serem excluidas!");
            Sleep(2500);
            return;
        }
        else if (Numcategoria < 2)
        {
            adviser(3);
        }
        else
        {
            orientaexcluicat();
            break;
        }

    case '4':
        menuprincipal();
    }
    return;
}

void start()
{

    char word[] = "Hello, world!";

    CLS for (int i = 0; word[i] != '\0'; i++)
    {
        printf("%c", word[i]);
        Sleep(100);
    }
    Sleep(900);
    menuprincipal();
}

void switchrelatorios(char op)
{

    switch (op)
    {
    case '5':
        menuprincipal();
        break;
    case '1':
        if (Numamigo < 1)
        {
            CLS
                ERRO(7);
            Sleep(1500);
            menurelatorios();
        }
        else
        {
            exibeamigo(true, true);
        }
        break;

    case '3':
        if (Numcategoria < 1)
        {
            CLS
                ERRO(10);
            Sleep(1500);
            menurelatorios();
        }
        else
        {
            exibecategoria(true);
        }
    case '2':
        if (Numlocal < 1)
        {
            CLS
                ERRO(18);
            Sleep(1500);
            menurelatorios();
        }
        else
        {
            exibelocal(true, true);
        }
    }
    return;
}

void menurelatorios()
{
    CLS
        printf("***MENU DE RELATORIOS***\n\n");
    printf("Digite:\n");
    printf("1. para exibir o relatorio de amigos\n");
    printf("2. para exibir o relatorio de locais\n");
    printf("3. para exibir o relatorio de categorias\n");
    printf("4. para exibir o relatorio de encontros\n");
    printf("5. para voltar\n");
    printf("\nO que deseja fazer?: ");
    char op = valida15();
    switchrelatorios(op);
    return;
}

void exibeamigo(bool prolongar, bool rel)
{

    CLS if (!prolongar)
    {
        printf("AMIGOS:\n\n");
        for (int i = 0; i < Numamigo; i++)
        {
            printf("%d amigo: %s\n", i + 1, Listaamigo[i].nome);
        }
    }

    else if (prolongar)
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

    if (rel)
    {
        Sleep(1000);
        printf("Pressione ENTER para voltar: ");
        while (getchar() != '\n')
            ;
        getchar();
        menurelatorios();
    }
    else
    {
        return;
    }
}

void editaamigo()
{
    int opAmigo = 0, i = 1;
    char editor;

    CLS
        printf("Digite 1 para pesquisar seu amigo pelo nome\n");
    printf("Digite 2 para exibir a lista de amigos\n");
    printf("Digite 3 para voltar\nDigite a opcao:");

    char opIn = valida13();

    if (opIn == '1')
    {
        i = buscaxnome(1);
        menueditaamigo(i);
        printf("\n\nDigite para editar: ");
        editor = valida13();
        alteraramigo(editor, i);
    }
    else if (opIn == '2')
    {
        printf("Qual o numero do amigo que deseja editar?: \n");
        exibeamigo(false, false);
        while (opAmigo < 1 || opAmigo > Numamigo)
        {
            scanf(" %d", &opAmigo);
            if (opAmigo < 1 || opAmigo > Numamigo)
            {
                ERRO(2);
            }
        }
        opAmigo--;
        menueditaamigo(opAmigo);
        editor = valida15();
        alteraramigo(editor, opAmigo);
    }
    else
    {
        return;
    }
}

void alteraramigo(char editor, int amigo)
{

    char str[100];

    switch (editor)
    {
    case '1':
        printf("Qual o novo nome de %s?: ", Listaamigo[amigo].nome);
        do
        {
            GTS if (validanome(str))
            {
                Listaamigo[Numamigo].nome = (char *)malloc((strlen(str) + 1) * sizeof(char));
                verifica_alocacao(Listaamigo[Numamigo].nome);
                strcpy(Listaamigo[Numamigo].nome, str);
                break;
            }
            else
            {
                printf("\nJa existe um amigo com este nome.\nAdicione um sobrenome para diferencia-lo: ");
            }
        } while (!validanome(str));
        break;

    case '2':
        printf("Qual o novo apelido de %s?: ", Listaamigo[amigo].nome);
        GTS
            Listaamigo[Numamigo]
                .apelido = (char *)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(Listaamigo[Numamigo].apelido, str);
        break;

    case '3':
        do
        {
            GTS if (validanumero(str))
            {
                Listaamigo[Numamigo].telefone = (char *)malloc((strlen(str) + 1) * sizeof(char));
                verifica_alocacao(Listaamigo[Numamigo].telefone);
                strcpy(Listaamigo[Numamigo].telefone, str);
            }
            else
            {
                printf("Ja existe um amigo com este telefone.\nDigite novamente: ");
            }

        } while (!validanumero(str));
        break;

    case '4':
        printf("Qual o novo email de %s?: ", Listaamigo[amigo].nome);
        do
        {
            GTS if (validaemail(str))
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
        } while (!validaemail(str));
        break;

    case '5':
        printf("Qual eh a data de nascimento de %s? (dd mm aaaa): ", Listaamigo[Numamigo].nome);
        do
        {
            scanf("%d%d%d", &Listaamigo[Numamigo].nascimento.dia, &Listaamigo[Numamigo].nascimento.mes, &Listaamigo[Numamigo].nascimento.ano);
            if (!(valide_data(Listaamigo[Numamigo].nascimento.dia, Listaamigo[Numamigo].nascimento.mes, Listaamigo[Numamigo].nascimento.ano)))
            {
                printf("Data invalida! Digite novamente: ");
            }
        } while (!(valide_data(Listaamigo[Numamigo].nascimento.dia, Listaamigo[Numamigo].nascimento.mes, Listaamigo[Numamigo].nascimento.ano)));
        break;
    }

    printf("Amigo Editado com sucesso!");
    Sleep(1500);
    return;
}

void menueditaamigo(int opAmigo)
{
    CLS
        printf("Digite 1 para alterar o nome (%s)\n", Listaamigo[opAmigo].nome);
    printf("Digite 2 para alterar o apelido (%s)\n", Listaamigo[opAmigo].apelido);
    printf("Digite 3 para alterar o numero de telefone (%s)\n", Listaamigo[opAmigo].telefone);
    printf("Digite 4 para alterar o email (%s)\n", Listaamigo[opAmigo].email);
    printf("Digite 5 para alterar a data de nasicemnto (%d/%d/%d)\n", Listaamigo[opAmigo].nascimento.dia, Listaamigo[opAmigo].nascimento.mes, Listaamigo[opAmigo].nascimento.ano);
}

void excluiamigo(int opAmigo)
{
    free(Listaamigo[opAmigo].nome);
    free(Listaamigo[opAmigo].apelido);
    free(Listaamigo[opAmigo].email);
    free(Listaamigo[opAmigo].telefone);

    if (opAmigo < Numamigo)
    {
        for (int i = opAmigo; i < Numamigo - 1; i++)
        {
            Listaamigo[i] = Listaamigo[i + 1];
        }
    }

    Numamigo--;
    Listaamigo = (tAmigo *)realloc(Listaamigo, Numamigo * sizeof(tAmigo)); // realloca a Lista para o novo tamanho de Numamigo
    verifica_alocacao(Listaamigo);
    printf("Amigo excluido com sucesso!\n");
    Sleep(2000);
    menuamigo();
}

void orientaexcluiamigo()
{
    int opAmigo;

    CLS
        printf("Digite 1 para pesquisar seu amigo pelo nome\n");
    printf("Digite 2 para exibir a lista de amigos\n");
    printf("Digite 3 para voltar\nDigite a opcao: ");
    char opIn = valida13();

    if (opIn == '1')
    {
        opAmigo = buscaxnome(1);
        excluiamigo(opAmigo);
    }
    else if (opIn == '2')
    {

        printf("Qual o numero do amigo que deseja excluir?: ");
        exibeamigo(false, false);

        while (opAmigo < 1 || opAmigo > Numamigo)
        {
            scanf(" %d", &opAmigo);
            if (opAmigo < 1 || opAmigo >= Numamigo)
            {
                printf("Amigo inválido! Digite novamente: \n");
            }
        }
        opAmigo--;
        excluiamigo(opAmigo);
    }
    else
    {
        return;
    }
}

void limpamemoria()
{

    for (int i = 0; i < Numamigo; i++)
    {
        free(Listaamigo[i].nome);
        free(Listaamigo[i].apelido);
        free(Listaamigo[i].email);
        free(Listaamigo[i].telefone);
    }
    free(Listaamigo);

    for (int i = 0; i < Numlocal; i++)
    {
        free(Listalocal[i].endereco.estado);
        free(Listalocal[i].endereco.cidade);
        free(Listalocal[i].endereco.bairro);
        free(Listalocal[i].endereco.numero);
        free(Listalocal[i].endereco.logradouro);
        free(Listalocal[i].nomelocal);
    }
    free(Listaamigo);

    for (int i = 0; i < Numcategoria; i++)
    {
        free(Listacategoria[i].categoria);
    }
    free(Listacategoria);

    end();
}

void end()
{
    char word[] = "Obrigado por trabalhar com nossos produtos!";

    CLS for (int i = 0; word[i] != '\0'; i++)
    {
        printf("%c", word[i]);
        Sleep(55);
    }
    Sleep(750);
    exit(0);
}

void verifica_alocacao(void *v)
{
    if (!v)
    {
        ERRO(4);
        Sleep(1000);
        limpamemoria();
    }
}

char valida16()
{
    char op;
    do
    {
        scanf(" %c", &op);
        if (op != '1' && op != '2' && op != '3' && op != '4' && op != '5' && op != '6')
        {
            ERRO(1);
        }
    } while (op != '1' && op != '2' && op != '3' && op != '4' && op != '5' && op != '6');

    return op;
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

    char str[100];

    CLS
        printf("Voce tem %d amigo(s) no momento\n\n", Numamigo);

    (Numamigo == 0) ? (Listaamigo = (tAmigo *)malloc(1 * sizeof(tAmigo))) : (Listaamigo = (tAmigo *)realloc(Listaamigo, (Numamigo + 1) * sizeof(tAmigo)));
    verifica_alocacao(Listaamigo);

    Listaamigo[Numamigo].id = 0;

    printf("Qual o nome do seu %d amigo?: ", Numamigo + 1);
    do
    {
        GTS if (validanome(str))
        {
            Listaamigo[Numamigo].nome = (char *)malloc((strlen(str) + 1) * sizeof(char));
            verifica_alocacao(Listaamigo[Numamigo].nome);
            strcpy(Listaamigo[Numamigo].nome, str);
            break;
        }
        else
        {
            printf("\nJa existe um amigo com este nome.\nAdicione um sobrenome para diferencia-lo: ");
        }
    } while (!validanome(str));

    printf("Qual eh o apelido de %s?: ", Listaamigo[Numamigo].nome);
    GTS
        Listaamigo[Numamigo]
            .apelido = (char *)malloc((strlen(str) + 1) * sizeof(char));
    verifica_alocacao(Listaamigo[Numamigo].apelido);
    strcpy(Listaamigo[Numamigo].apelido, str);

    printf("Qual eh o telefone do seu amigo?: ");
    do
    {
        GTS if (validanumero(str))
        {
            Listaamigo[Numamigo].telefone = (char *)malloc((strlen(str) + 1) * sizeof(char));
            verifica_alocacao(Listaamigo[Numamigo].telefone);
            strcpy(Listaamigo[Numamigo].telefone, str);
        }
        else
        {
            printf("Ja existe um amigo com este telefone.\nDigite novamente: ");
        }

    } while (!validanumero(str));

    printf("Qual o email de %s?: ", Listaamigo[Numamigo].nome);
    do
    {
        GTS if (validaemail(str))
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
    } while (!validaemail(str));

    printf("Qual eh a data de nascimento de %s? (dd mm aaaa): ", Listaamigo[Numamigo].nome);
    do
    {
        scanf("%d%d%d", &Listaamigo[Numamigo].nascimento.dia, &Listaamigo[Numamigo].nascimento.mes, &Listaamigo[Numamigo].nascimento.ano);
        if (!(valide_data(Listaamigo[Numamigo].nascimento.dia, Listaamigo[Numamigo].nascimento.mes, Listaamigo[Numamigo].nascimento.ano)))
        {
            printf("Data invalida! Digite novamente: ");
        }
    } while (!(valide_data(Listaamigo[Numamigo].nascimento.dia, Listaamigo[Numamigo].nascimento.mes, Listaamigo[Numamigo].nascimento.ano)));

    Numamigo++;
    CLS
        printf("Amigo adicionado com sucesso!\n");
    Sleep(2000);
    menuamigo();
}

void switchamigo(char op)
{
    switch (op)
    {
    case '1':
        criaamigo();
        break;
    case '2':
        if (Numamigo == 0)
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
        if (Numamigo == 0)
        {
            printf("Nao ha amigos para serem excluidos!");
            Sleep(2500);
            menuamigo();
        }
        else if (Numamigo < 2)
        {
            adviser(1);
        }
        else
        {
            orientaexcluiamigo();
        }
        break;
    case '4':
        menuprincipal();
        break;
    }
}

void menuamigo()
{

    CLS
        printf("***MENU AMIGO***\n\nDigite:\n");
    printf("1. para criar um amigo\n");
    printf("2. para editar um amigo\n");
    printf("3. para excluir um amigo\n");
    printf("4. para voltar\n");
    printf("\nO que deseja fazer?: ");
    char op = valida14();
    switchamigo(op);
}

void switchprincipal(int op)
{

    switch (op)
    {
    case '6':
        limpamemoria();

    case '5':
        menurelatorios();
        break;

    case '1':
        menuamigo();
        break;

    case '2':
        menulocal();
        break;

    case '3':
        menucategoria();
    }
}

void menuprincipal()
{
    CLS
        printf("***MENU PRINCIPAL***\n\n");
    printf("Digite:\n");
    printf("1. para manter amigo\n");
    printf("2. para manter local\n");
    printf("3. para manter categoria\n");
    printf("4. para manter encontro\n");
    printf("5. para Relatorios\n");
    printf("6. para Sair\n");
    printf("\nO que deseja fazer?: ");
    orienta();
}

void orienta()
{
    char op = valida16();
    switchprincipal(op);
}

bool validanome(char *nome)
{

    for (int i = 0; i < Numamigo; i++)
    {
        if (strcmp(nome, Listaamigo[i].nome) == 0)
        {
            return false;
        }
    }
    return true;
}

bool validaemail(char *email)
{

    int countA = 0, countB = 0;

    // step 1v
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
        printf("Email invalido! O email deve conter 1 '@' e ao menos 1 '.'\n");
        return false;
    }

    // step 2v
    for (int i = 0; i < Numamigo; i++)
    {
        if (strcmp(email, Listaamigo[i].email) == 0)
        {
            printf("Email invalido! Este email ja existe!\n");
            return false;
        }
    }
    return true;
}

bool validanumero(char *num)
{

    for (int i = 0; i < Numamigo; i++)
    {
        if (strcmp(num, Listaamigo[i].telefone) == 0)
        {
            return false;
        }
    }
    return true;
}

int buscaxnome(int op)
{
    int i;
    char str[100];

    CLS while (1)
    {
        printf("Digite o nome a ser buscado: ");
        GTS
            printf("Buscando");
        for (int j = 0; j < 3; j++)
        {
            printf(".");
            Sleep(400);
        }
        CLS switch (op)
        {
        case 1:
            for (i = 0; i < Numamigo; i++)
            {
                if (strcmp(Listaamigo[i].nome, str) == 0)
                {
                    printf("Amigo encontrado!");
                    Sleep(1000);
                    CLS return i;
                }
            }
            ERRO(3);
            Sleep(1500);
        case 2:
            for (i = 0; i < Numlocal; i++)
            {
                if (strcmp(Listalocal[i].nomelocal, str) == 0)
                {
                    printf("Local encontrado!");
                    Sleep(1000);
                    CLS return i;
                }
            }
            ERRO(20);
            Sleep(1500);
        case 3:
            for (i = 0; i < Numcategoria; i++)
            {
                if (strcmp(Listacategoria[i].categoria, str) == 0)
                {
                    printf("Categoria encontrada!");
                    Sleep(1000);
                    CLS return i;
                }
            }
            ERRO(9);
            Sleep(1500);
        }
        continue;
    }
}

void ERRO(int opErro)
{

    switch (opErro)
    {
    case 0:
        printf("Realocar um vetor dinâmico para 0 posições não é uma boa ideia.\nTem certeza de que deseja prosseguir?(S/N): ");
        break;
    case 1:
        printf("Operador invalido! Digite novamente: ");
        break;
    case 2:
        printf("Amigo invalido! Digite novamente: ");
        break;
    case 3:
        printf("Amigo nao encontrado! Digite novamente: ");
        break;
    case 4:
        printf("ERRO AO ALOCAR MEMORIA!!!");
        break;
    case 5:
        printf("Nao existem amigos para serem editados!");
        break;
    case 6:
        printf("Nao existem amigos para serem excluidos!");
        break;
    case 7:
        printf("Nao existem amigos para serem listados!");
        break;
    case 8:
        printf("Categoria invalida! Digite novamente: ");
        break;
    case 9:
        printf("Categotria nao encontrada! Digite novamente: ");
        break;
    case 10:
        printf("Nao existem categorias para serem listadas!");
        break;
    case 11:
        printf("Nao existem categorias para serem editadas!");
        break;
    case 12:
        printf("Nao existem categorias para serem excluidas!");
        break;
    case 13:
        printf("Encontro invalido! Digite novamente: ");
        break;
    case 14:
        printf("Encontro nao encontrado! Digite novamente: ");
        break;
    case 15:
        printf("Nao existem encontros para serem listados!");
        break;
    case 16:
        printf("Nao existem encontros para serem editados!");
        break;
    case 17:
        printf("Nao existem encontros para serem excluidos!");
        break;
    case 18:
        printf("Nao existem Locais para serem listados!");
        break;
    case 19:
        printf("Local invalido! Digite novamente: ");
        break;
    case 20:
        printf("Local nao encontrado! Digite novamente: ");
        break;
    case 21:
        printf("Nao existem Locais para serem editados!");
        break;
    case 22:
        printf("Nao existem Locais para serem excluidos!");
        break;
    default:
        printf("___FUDEU MUITO___");
        limpamemoria();
    }
}
