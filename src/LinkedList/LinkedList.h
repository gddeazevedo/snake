#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include "../Block/Block.h"

struct node {
    Block block;
    struct node* next;
};

typedef struct node Node;

typedef struct {
    Node* head;
    Node* tail;
    int length;
} LinkedList;

LinkedList* _LinkedList();
Block get_block(LinkedList* list, int index);
void push_back(LinkedList* list, Block block);
void push_front(LinkedList* list, Block block);
Block pop_back(LinkedList* list);
void print_list(LinkedList* list);


#endif
