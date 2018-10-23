// Linked list implementation ... COMP2521 
#include "list.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
   char*        v;
   struct Node *next; 
} Node;

Node *makeNode(char *n) {
   Node *new = malloc(sizeof(Node));
   n = strdup(n);
   assert(new != NULL);
   new->v = n;
   new->next = NULL;
   return new;
}

List insertLL(List L, char *n) {

    List curr = L;   
    if ( L == NULL ) return makeNode(n);
    else if ( L->next == NULL ){
        L->next = makeNode(n);
        return L;
    } else {
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = makeNode(n);
        return L;
    }
}


List deleteLL(List L, char *n) {
  
  if(L == NULL){
  
    return L;
  
  }
  
  List temp;
  List prev = NULL;
  List curr = L;
  while(curr != NULL){
    
       prev = curr;
    
    if(strcmp(curr->v, n) == 0){
    
    
         temp = curr;
         
        if(prev == curr){
        
            L = L->next;
        
        
        }    
    
        else{
        
            prev->next = curr->next;
        
        
        }
    
    
    }
  
   curr = curr->next;
  
  }
  
  free(temp->v);
  free(temp);
  
    return L;
    
}

bool inLL(List L, char *n) {
   if (L == NULL)
      return false;
   if (!strcmp(L->v, n))
     return true;

   return inLL(L->next, n);
}

void showLL(List L) {
   if (L == NULL)
      putchar('\n');
   else {
      printf("%s ", L->v);
      showLL(L->next);
   }
}

void freeLL(List L) {
   if (L != NULL) {
      freeLL(L->next);
      free(L->v);
      free(L);
   }
}

int sizeLL(List L){

    int size = 0;
    while(L != NULL){
    
        size++
        L = L->next;
    
    
    }

    return size;
    
}
