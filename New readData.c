   #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "graph.h"
#include "readData.h"

List GetCollection(void);
Graph GetGraph(List L);


// Read URl's from text files return list
static List readUrlFile(char *Url_File)
{
   // Open File: For Reading
   FILE *in;
   in = fopen(Url_File, "r");

   if (in == NULL){
   
        fprintf(stderr, "%s", "No File Exists\n");
   
   } 

   // Make new List
   
   List L = NULL;
   char line[1000] = {'\0'};


   // Case 1: collections.txt
   // Case 2: <url>.txt

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



// Reading Data from text file 'collections.txt'

List GetCollection(void){

   return readUrlFile("./Sample1/collection.txt");
}





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
        curr2 = readUrlFile(path);
        while(curr2 != NULL){
            addEdge(my_graph , curr->v, curr2->v);
    
            curr2 = curr2->next;
        }
        curr = curr->next;
        
    }

    return my_graph;

}        
