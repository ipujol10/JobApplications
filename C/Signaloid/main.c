#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node LinkedList;

void printList(LinkedList* list);

int main(int argc, char *argv[]) {

    Node n0, n1;
    n1 = (Node) {1, NULL};
    n0 = (Node) {0, &n1};
    LinkedList list = n0;
    printList(&list);

    return 0;
}

void printList(LinkedList* list) {
    if (list->next == NULL) {
        printf("%i\n", list->data);
        return;
    }
    printf("%i -> ", list->data);
    printList(list->next);
}
