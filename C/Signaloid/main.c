#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node* LinkedList;

void printList(LinkedList list);
void insert(LinkedList* list, int value, int position);
int search(LinkedList list, int value);

int main(int argc, char *argv[]) {
    printf("Start with a single node with value 1\n");
    Node head = {1, NULL};
    LinkedList list = &head;
    printList(list);

    printf("\nAdd the node 3 at the end and the node 0 at the beginnig\n");
    insert(&list, 3, 1);
    insert(&list, 0, 0);
    printList(list);

    printf("\nAdd the node 2 between 1 and 3\n");
    insert(&list, 2, 2);
    printList(list);

    printf("\nTry to add the node 5 at position 5. It prints an error and keeps"
            " the list intact\n");
    insert(&list, 5, 5);
    printList(list);

    printf("\nTry to add the node -1 at position -1. It prints an error and keeps"
            " the list intact\n");
    insert(&list, -1, -1);
    printList(list);

    printf("\nFind the position of several nodes. If it doesn't exists returns "
            "-1\n");
    printf("Node %i in position %i\n", 0, search(list, 0));
    printf("Node %i in position %i\n", 2, search(list, 2));
    printf("Node %i in position %i\n", 5, search(list, 5));

    return 0;
}

void printList(LinkedList list) {
    Node node = *list;
    while (node.next != NULL) {
        printf("%i -> ", node.data);
        node = *node.next;
    };
    printf("%i\n", node.data);
}

void insert(LinkedList* list, int value, int position) {
    if (position < 0) {
        printf("Index out of range\n");
        return;
    }
    if (position == 0) {
        Node* ptr = malloc(sizeof(Node));
        *ptr = (Node) {value, *list};
        *list = ptr;
        return;
    }

    Node* previous = *list;
    int count = 1;
    while (count < position) {
        if (previous->next == NULL) {
            printf("Index out of range\n");
            return;
        }
        previous = previous->next;
        count++;
    }
    Node* ptr = malloc(sizeof(Node));
    *ptr = (Node) {value, previous->next};
    previous->next = ptr;
}

int search(LinkedList list, int value) {
    int count = 0;
    Node node = *list;
    while (value != node.data) {
        if (node.next == NULL) {
            return -1;
        }
        count++;
        node = *node.next;
    }
    return count;
}
