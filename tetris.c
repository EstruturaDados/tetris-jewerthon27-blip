#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char tipo;  
    int id;     
} Peca;

#define MAX_FILA 5

typedef struct {
    Peca itens[MAX_FILA];
    int frente, tras, qtd;
} Fila;

void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
    f->qtd = 0;
}

int filaVazia(Fila *f) {
    return f->qtd == 0;
}

int filaCheia(Fila *f) {
    return f->qtd == MAX_FILA;
}

void enqueue(Fila *f, Peca p) {
    if (filaCheia(f)) {
        printf("Fila cheia! Nao foi possivel adicionar a peca.\n");
        return;
    }
    f->tras = (f->tras + 1) % MAX_FILA;
    f->itens[f->tras] = p;
    f->qtd++;
}

Peca dequeue(Fila *f) {
    Peca p = {'-', -1};
    if (filaVazia(f)) {
        printf("Fila vazia! Nao ha peca para jogar.\n");
        return p;
    }
    p = f->itens[f->frente];
    f->frente = (f->frente + 1) % MAX_FILA;
    f->qtd--;
    return p;
}

void mostrarFila(Fila *f) {
    printf("\n=== Pecas Futuras ===\n");
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    int i, idx;
    for (i = 0; i < f->qtd; i++) {
        idx = (f->frente + i) % MAX_FILA;
        printf("ID: %d | Tipo: %c\n", f->itens[idx].id, f->itens[idx].tipo);
    }
    printf("=====================\n");
}

Peca gerarPeca(int id) {
    char tipos[] = {'I', 'O', 'T', 'L', 'J', 'S', 'Z'};
    Peca p;
    p.tipo = tipos[rand() % 7];
    p.id = id;
    return p;
}
int main() {
    
    FIla Fila; 
    inicializarFila(&fila);
    scrand(time(NULL));

    int idCounter = 1;
    int opcao;
    Peca jogada;

        for (int i = 0; i <MAX_FILA; I++) {
            enqueue(&fila, gerarPeca(idCounter++));
        }

        do {
            mostrarFila(&fila);
            printf("\n=== Menu ===\");
            printf("1 - Jogar peca (remover da frente)\n");
            printf("0 - Sair\n");
            printf("Escolha: ");
            scanf("%d", &opcao);

            switch(opcao) {
                case 1:
                   jogada = dequeue(&fila);
                   if (jogada.id != -1) {
                       printf("Voce jogou a peca ID %d (Tipo %c)\n"), jogada.id,  jogada.tipo);
                       enqueue(&fila, gerarPeca(idCouter++));
                   }
                    break;
                case 0:
                     printf("Saindo do jogo...\n");
                     break;
                 default:
                     printf("Opcao  invalida!\n");
            }
        } while (opcao != 0);   

        return 0;
   }
    // 🧠 Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).


    // 🔄 Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha


    return 0;
}

