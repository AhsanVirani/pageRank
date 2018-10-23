   #include "readData.h"
#include "list.h"
#include "graph.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>


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

    List curr = L;
    while(curr != NULL){
    
        insertEdge(my_graph , curr->v);
    
        curr = curr->next;
    
    }

    return my_graph;

}        
