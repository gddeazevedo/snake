#include "LinkedList.h"


LinkedList* _LinkedList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->length = 0;
    return list;
}

Block get_block(LinkedList* list, int index) {
    if (index >= list->length || index < 0) {
        printf("----INDEX OUT OF RANGE!----\n");
        return _Block(-1, -1);
    }

    Node* aux = list->head;
    int counter = 0;

    while (aux != NULL && counter != index && counter < list->length) {
        counter++;
        aux = aux->next;
    }

    return aux->block;
}


void push_back(LinkedList* list, Block block) {
    if (list->head == NULL) {
        list->head = (Node*) malloc(sizeof(Node));
        list->head->block = block;
        list->tail = list->head;
        list->length += 1;
    } else {
        list->tail->next = (Node*) malloc(sizeof(Node));
        list->tail = list->tail->next;
        list->tail->block = block;
        list->length += 1;
    }
}


void push_front(LinkedList* list, Block block) {
    if (list->head == NULL) {
        list->head = (Node*) malloc(sizeof(Node));
        list->head->block = block;
        list->tail = list->head;
        list->length += 1;
    } else {
        Node* aux = (Node*) malloc(sizeof(Node));
        aux->block = block;
        aux->next = list->head;
        list->head = aux;
        list->length += 1;
    }
}

Block pop_back(LinkedList* list) {
    if (list->length == 1) {
        Node* aux = list->head;
        Block block = aux->block;
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
        return block;
    } else if (list->length > 1) {
        Node* aux = list->head;

        while (aux->next->next != NULL) {
            aux = aux->next;
        }
        list->length -= 1;

        list->tail = aux;
        aux = list->tail->next;
        list->tail->next = NULL;
        return aux->block;
    } else {
        printf("\nWARNING: LIST IS EMPTY!\n");
    }
}


void print_list(LinkedList* list) {
    if (list->head == NULL) {
        printf("[ ]\n");
        return;
    }

    Node* aux = list->head;

    printf("[ ");
    while (aux != NULL) {
        printf("(%d, %d) ", aux->block.x, aux->block.y);
        aux = aux->next;
    }
    printf("]\n");
}
