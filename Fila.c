#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Defini��o da estrutura do n� da fila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estrutura da fila com ponteiros para a frente e para o final
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Fun��o para criar um novo n�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro de aloca��o de mem�ria\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fun��o para criar uma nova fila
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Erro de aloca��o de mem�ria\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Fun��o para verificar se a fila est� vazia
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Fun��o para inserir um elemento na fila
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

// Fun��o para remover um elemento da fila
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Fila vazia. N�o � poss�vel remover elementos.\n");
        return -1; // Indicador de erro, j� que a fila est� vazia
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

// Fun��o para exibir o elemento no in�cio da fila
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Fila vazia.\n");
        return -1; // Indicador de erro, j� que a fila est� vazia
    }
    return queue->front->data;
}

// Fun��o para imprimir todos os elementos da fila
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
        printf("3. Mostrar elemento no in�cio da fila\n");
        printf("4. Mostrar todos os elementos da fila\n");
        printf("5. Sair\n");
        printf("Escolha uma op��o: ");
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
                    printf("Elemento no in�cio da fila: %d\n", valor);
                }
                break;
            case 4:
                printQueue(queue);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

