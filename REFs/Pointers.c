#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 42, y = 84;

    // Alocar dinamicamente um vetor de ponteiros (int**)
    int **vet = (int **)malloc(2 * sizeof(int *));
    if (vet == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Atribuir endereços aos ponteiros do vetor
    vet[0] = &x; // vet[0] aponta para x
    vet[1] = &y; // vet[1] aponta para y

    // Acessar os valores através do ponteiro para ponteiro
    printf("Valor apontado por vet[0]: %d\n", *vet[0]);
    printf("Valor apontado por vet[1]: %d\n", *vet[1]);

    // Liberar a memória alocada (neste caso, apenas vet)
    free(vet);

    return 0;
}
