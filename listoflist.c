#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listoflist.h"

List newlist() {
    List new; 
    new = malloc(sizeof(struct list));
    if (new == NULL) {
        printf("MALLOC ERROR");
        return NULL;
    }
    else {
        new->numlists = 0;
        new->head = NULL;
        new->tail = NULL;
        return new;
    }
}

Array newarray(List L) {
    Array new;
    new = malloc(sizeof(struct rep));
    if (new == NULL) {
        printf("MALLOC ERROR");
        return NULL;
    }
    else {
        if (L->numlists == 0) {
            L->head = new;
        }
        else if (L->numlists == 1) {
            L->head->iterate = new;
        }
        else {
            L->tail->iterate = new;
        }
        L->tail = new;
        L->numlists++;
        new->nitems = 0;
        new->first = NULL;
        new->last = NULL;
        new->iterate = NULL;
        return new;
    }
}

void newnode(Array A, char *content) {
    Node new;
    new = malloc(sizeof(struct node));
    if (new == NULL) {
        printf("MALLOC ERROR");
    }
    else {
        if (A->nitems == 0) {
            A->first = new;
            new->pos = 1;
        }
        else if (A->nitems == 1) {
            A->first->next = new;
            new->pos = 2;
        }
        else {
            A->last->next = new;
            struct node *curr = A->first;
            int position = 1;
            while (curr != new) {
                curr = curr->next;
                position++;
            }
            new->pos = position;
        }
        A->last = new;
        A->nitems++;
        new->next = NULL;
        new->value = malloc(sizeof(content));
        strcpy(new->value, content);
    }
}

void showlist(List L) {
    struct rep *curr = L->head;
    while (curr != NULL) {
        struct node *ptr = curr->first;
        printf("-----------------------------\n");
        while (ptr != NULL) {
            printf("%d %s\n", ptr->pos, ptr->value);
            ptr = ptr->next;
        }
        curr = curr->iterate;
    }
}
