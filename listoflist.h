
#ifndef LISTOFLIST_H
#define LISTOFLIST_H

struct list {
    int numlists;
    struct rep *head;
    struct rep *tail;
};

struct rep {
    int nitems;
    struct rep *iterate;
    struct node *first;
    struct node *last;
};

struct node {
    char *value;
    int pos;
    struct node *next;
};

typedef struct list *List;
typedef struct rep *Array;
typedef struct node *Node;

List newlist();
Array newarray(List L);
void newnode(Array A, char *content);
void showlist(List L);

#endif
