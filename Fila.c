#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definição da estrutura do nó da fila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estrutura da fila com ponteiros para a frente e para o final
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para criar uma nova fila
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Função para inserir um elemento na fila
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d inserido na fila\n", data);
}

// Função para remover um elemento da fila
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Fila vazia. Não é possível remover elementos.\n");
        return -1; // Indicador de erro, já que a fila está vazia
    }
    Node* temp = queue->front;
    int dequeuedData = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return dequeuedData;
}

// Função para exibir o elemento no início da fila
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Fila vazia.\n");
        return -1; // Indicador de erro, já que a fila está vazia
    }
    return queue->front->data;
}

// Função para imprimir todos os elementos da fila
void printQueue(Queue* queue) {
    Node* temp = queue->front;
    printf("Elementos na fila:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Queue* queue = createQueue();
    int opcao, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir elemento na fila\n");
        printf("2. Remover elemento da fila\n");
        printf("3. Mostrar elemento no início da fila\n");
        printf("4. Mostrar todos os elementos da fila\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                enqueue(queue, valor);
                break;
            case 2:
                valor = dequeue(queue);
                if (valor != -1) {
                    printf("Elemento removido: %d\n", valor);
                }
                break;
            case 3:
                valor = peek(queue);
                if (valor != -1) {
                    printf("Elemento no início da fila: %d\n", valor);
                }
                break;
            case 4:
                printQueue(queue);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

