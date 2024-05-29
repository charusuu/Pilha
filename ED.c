#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Defini��o da estrutura do n� da pilha
typedef struct Node {
    int data;
    struct Node* next;
} Node;

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

// Fun��o para verificar se a pilha est� vazia
int isEmpty(Node* top) {
    return top == NULL;
}

// Fun��o para inserir um elemento na pilha
void push(Node** top, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(*top)) {
        *top = newNode;
    } else {
        Node* temp = *top;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d inserido na pilha\n", data);
}

// Fun��o para remover um elemento da pilha
int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Pilha vazia. N�o � poss�vel remover elementos.\n");
        return -1; // Indicador de erro, j� que a pilha est� vazia
    }
    Node* temp = *top;
    if (temp->next == NULL) {
        int poppedData = temp->data;
        free(temp);
        *top = NULL;
        return poppedData;
    }

    Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    int poppedData = temp->data;
    free(temp);
    prev->next = NULL;
    return poppedData;
}

// Fun��o para exibir o elemento no topo da pilha
int peek(Node* top) {
    if (isEmpty(top)) {
        printf("Pilha vazia.\n");
        return -1; // Indicador de erro, j� que a pilha est� vazia
    }
    Node* temp = top;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp->data;
}

// Fun��o para imprimir todos os elementos da pilha
void printStack(Node* top) {
    Node* temp = top;
    printf("Elementos na pilha:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Node* stack = NULL;
    int opcao, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir elemento na pilha\n");
        printf("2. Remover elemento da pilha\n");
        printf("3. Mostrar elemento no topo da pilha\n");
        printf("4. Mostrar todos os elementos da pilha\n");
        printf("5. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                push(&stack, valor);
                break;
            case 2:
                valor = pop(&stack);
                if (valor != -1) {
                    printf("Elemento removido: %d\n", valor);
                }
                break;
            case 3:
                valor = peek(stack);
                if (valor != -1) {
                    printf("Elemento no topo: %d\n", valor);
                }
                break;
            case 4:
                printStack(stack);
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

