#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void initialize(struct Node** top_ref) {
    *top_ref = NULL;
}

void push(struct Node** top_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    if (!new_node) {
        printf("Erro: Memória insuficiente.\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = *top_ref;

    *top_ref = new_node;
}

int pop(struct Node** top_ref) {
    if (*top_ref == NULL) {
        return 1;  
    }

    struct Node* temp = *top_ref;
    int popped_data = temp->data;

    *top_ref = temp->next;

    free(temp);

    return popped_data;
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

void printStack(struct Node* top) {
    if (top == NULL) {

        return;
    }

    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void reinitialize(struct Node** top_ref) {
    struct Node* current = *top_ref;
    struct Node* next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *top_ref = NULL;  
}

void reverseStack(struct Node** top_ref) {
    struct Node *prev = NULL, *current = *top_ref, *next = NULL;

    while (current != NULL) {
        next = current->next;   
        current->next = prev;   
        prev = current;         
        current = next;         
    }

    *top_ref = prev;  
}

int main() {
    struct Node* top = NULL;
    initialize(&top);

   
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printf("Pilha original:\n");
    printStack(top);

    reverseStack(&top);

    printf("Pilha invertida:\n");
    printStack(top);

    
    reinitialize(&top);
    printStack(top);

    return 0;
}