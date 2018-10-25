// Linked list interface ... COMP2521 

#ifndef LIST_H
#define LIST_H


#include <stdbool.h>

typedef struct Node {
   char*        v;
   struct Node *next; 
} Node;


typedef struct Node *List;

List insertLL(List, char *);
List deleteLL(List, char *);
bool inLL(List, char *);
void freeLL(List);
void showLL(List);
int sizeLL(List);

#endif
