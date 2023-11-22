#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node* LinkedList;

void printList(LinkedList* list);
void insert(LinkedList* list, int value, int position);

int main(int argc, char *argv[]) {
    printf("Start with a single node with value 1\n");
    Node head = {1, NULL};
    LinkedList list = &head;
    printList(&list);

    return 0;
}

void printList(LinkedList* list) {
    Node node = **list;
    while (node.next != NULL) {
        printf("%i -> ", node.data);
        node = *node.next;
    };
    printf("%i\n", node.data);
}
