#include "stdlib.h"
#include "assert.h"
#include "stdio.h"

typedef struct Node_ {
    struct Node_ * prev;
    struct Node_ * next;
    int elem;    
} Node;

typedef struct {
    Node* head;
    Node* last;
    int length;
} List;

Node* NodeNew(int elem);
List ListNew();
void ListDealloc(List*);

void ListPushl(List* list, int elem);
void ListPushr(List* list, int elem);

void ListPrint(List const*);

int ListPopl(List* list);
int ListPopr(List* list);