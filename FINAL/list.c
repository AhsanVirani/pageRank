// Linked list implementation ... COMP2521 
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

List insertLL(List, char *);
List deleteLL(List, char *);
bool inLL(List, char *);
void freeLL(List);
void showLL(List);
int sizeLL(List);
static Node *makeNode(char *n);


static Node *makeNode(char *n) {
   Node *new = malloc(sizeof(Node));
   n = strdup(n);
   assert(new != NULL);
   new->v = n;
   new->next = NULL;
   return new;
}

List insertLL(List L, char *n) {
    if(inLL(L, n))  return L;
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
    
        size++;
        L = L->next;
    
    
    }

    return size;
    
}

//Reference geekforgeeks help
/* Bubble sort the given linked list */
void bubbleSort(List start) 
{ 
    int swapped; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (strcmp(ptr1->v, ptr1->next->v) > 0) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

/* function to swap data of two nodes a and b*/
void swap(List a, List b) 
{ 
   char *temp = a->v; 
    a->v = b->v; 
    b->v = temp; 
} 


char *ConvertToString(List L){
    char *string  = malloc(sizeof(char)*BUFSIZ);
    memset(string, '\0', BUFSIZ);
    while ( L != NULL){
        strcat(string, L->v);
        strcat(string, " ");
        L = L->next;

    }
    return string;
}
