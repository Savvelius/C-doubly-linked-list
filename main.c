#include "list.h"
void test_pushr() {
    List list = ListNew();
    ListPushr(&list, 5);
    ListPushr(&list, 10);
    ListPushr(&list, 15);
    ListPushr(&list, 20);
    assert(list.head != NULL);
    assert(list.last != NULL);
    assert(list.head != list.last);
    assert(list.head->elem == 5);
    assert(list.last->elem == 20);
    ListDealloc(&list);
}

void test_pushl() {
    List list = ListNew();
    ListPushl(&list, 5);
    ListPushl(&list, 10);
    ListPushl(&list, 15);
    assert(list.head->elem == 15);
    assert(list.head->next->elem == 10);
    assert(list.head->next->next->elem == 5);
    ListDealloc(&list);
}

void test_popl() {
    List list = ListNew();
    ListPushr(&list, 10);
    ListPushr(&list, 20);
    ListPushr(&list, 30);
    int popped1 = ListPopl(&list);
    int popped2 = ListPopl(&list);
    int popped3 = ListPopl(&list);
    assert(popped1 == 10);
    assert(popped2 == 20);
    assert(popped3 == 30);
    assert(list.head == NULL);
    assert(list.last == NULL);
    ListDealloc(&list);
}

void test_popr() {
    List list = ListNew();
    ListPushr(&list, 10);
    ListPushr(&list, 20);
    ListPushr(&list, 30);
    int popped1 = ListPopr(&list);
    int popped2 = ListPopr(&list);
    int popped3 = ListPopr(&list);
    assert(popped1 == 30);
    assert(popped2 == 20);
    assert(popped3 == 10);
    assert(list.head == NULL);
    assert(list.last == NULL);
    ListDealloc(&list);
}

int main() {
    test_pushl();
    test_pushr();
    test_popl();
    return 0;
}