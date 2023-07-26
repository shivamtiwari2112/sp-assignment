#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    char *data;
    struct Node* next;
};

struct LL {
    struct Node *head;
    struct Node *tail;
    int size;
};

struct LL* createLL(){
    struct LL *list = (struct LL*)malloc(sizeof(struct LL));
    list->head = NULL;
    list->head = NULL;
    list->size = 0;
    return list;
}

void removeFirstNode(struct LL *list) {
    if (list->size == 0)
        return;

    struct Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

void addNode(struct LL *list, const char *line) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = strdup(line);
    newNode->next = NULL;

    if (list->size == 0) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;
}

void printLastNLines(struct LL *list, int n) {
    if (n <= 0 || list->size == 0)
        return;

    n = (n > list->size) ? list->size : n;

    int skip = list->size - n;

    struct Node *current = list->head;
    while (skip > 0) {
        current = current->next;
        skip--;
    }

    while (current) {
        printf("%s", current->data);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Invalid value of 'n'.\n");
        return 1;
    }

    struct LL *list = createLL();

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        addNode(list, buffer);

        if (list->size > n)
            removeFirstNode(list);
    }

    printLastNLines(list, n);
    printf("\n");

    return 0;
}