#include "list.h"

Node* NodeNew(int elem) {
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->elem = elem;
    return node;
}

List ListNew() {
    List list = {
        .head = NULL,
        .last = NULL,
        .length = 0 
    };
    return list;
}

void ListDealloc(List* list) {
    Node* cursor = list->head;
    while (cursor != NULL) {
        Node* next = cursor->next;; 
        free(cursor);
        cursor = next;
    }
    *list = ListNew();
}

void ListPushl(List* list, int elem) {
    Node* new_node = NodeNew(elem);
    if (list->head == NULL) {
        assert(list->last == NULL);
        list->head = new_node;
        list->last = new_node;
    } else {
        list->head->prev = new_node;
        new_node->next = list->head;
        list->head = new_node;
    }
    list->length++;
}

void ListPrint(List const* list) {
    Node* cursor = list->head;
    while (cursor != NULL) {
        printf("Node(%d), ", cursor->elem);
        cursor = cursor->next;
    }
    putchar('\n');
}

void ListPushr(List* list, int elem) {
    Node* new_node = NodeNew(elem);
    if (list->length == 0) {
        assert(list->last == NULL);
        assert(list->head == NULL);
        list->head = new_node;
        list->last = new_node;
    } else {
        list->last->next = new_node;
        new_node->prev = list->last;
        list->last = new_node;
    }
    list->length++;
}

int ListPopl(List* list) {
    assert(list->length != 0);
    int popped = list->head->elem;
    if (list->length == 1) {
        assert(list->head != NULL);
        free(list->head);
        *list = ListNew();
    } else {
        list->head = list->head->next;
        free(list->head->prev);
        list->head->prev = NULL;
    } 
    list->length--;
    return popped;
}

int ListPopr(List* list) {
    assert(list->length != 0);
    int popped = list->last->elem;
    if (list->length == 1) {
        assert(list->head != NULL);
        free(list->head);
        *list = ListNew();
    } else {
        list->last = list->last->prev;
        free(list->last->next);
        list->last->next = NULL;
    } 
    list->length--;
    return popped;
}