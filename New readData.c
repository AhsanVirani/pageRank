// readData.c
// Written by Ahsan Muhammad && Allen, October 2018
// Assignment 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "graph.h"
#include "readData.h"

List GetCollection(void);
Graph GetGraph(List L);


// Read_UrlFile opens and reads the Urls and makes a linked list out of the Urls
static List read_UrlFile(char *Url_File){

   
   FILE *in;
   in = fopen(Url_File, "r");

   if (in == NULL){
   
        fprintf(stderr, "%s", "No File Exists\n");
   
   } 

   // Make new List
   
   List L = NULL;
   char line[1000] = {'\0'};




   while( fscanf(in, "%s", line) != EOF ){
   
      if (!strcmp(line, "#start") || !strcmp(line, "Section-1")) {
        
        continue;
      
      }   
      
      
      else if (!strcmp(line, "#end") ){
      
        break;
        
      }
      
      else {
      
         L = insertLL(L, line);
      
      }
      
      
   }




   fclose(in);

   return L;
}



// 
//GetCollections goes on to read the txt file from Sample1

List GetCollection(void){

   return read_UrlFile("./Sample1/collection.txt");
}



// Transforms the linked list that we created previously into the Graph structure

Graph GetGraph(List L){

    Graph my_graph = newGraph(sizeLL(L));

    char *path = NULL;
    List curr = L;
    List curr2 = NULL;
    while(curr != NULL){
        path = malloc(sizeof(char) * (strlen("./Sample1/.txt\0") + strlen(curr->v)));
        strcpy(path, "./Sample1/");
        strcat(path, curr->v);
        strcat(path, ".txt");
        curr2 = read_UrlFile(path);
        while(curr2 != NULL){
            addEdge(my_graph , curr->v, curr2->v);
    
            curr2 = curr2->next;
        }
        curr = curr->next;
        
    }

    return my_graph;

}        
