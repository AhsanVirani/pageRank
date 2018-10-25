// Made by Ahsan Muhammad && Allen

#include <stdio.h>
#include "list.h"
#include "Graph.h"
#include "pagerank.h"

void  PageRankW(Graph my_graph, double d, double diffPR, int maxIterations){


 /*
 Read "web pages" from the collection in file "collection.txt"
            and build a graph structure using Adjacency List Representation

            N = number of urls in the collection

            For each url pi in the collection
                
            End For

            iteration = 0;
            diff = diffPR;   // to enter the following loop

            While (iteration < maxIteration AND diff >= diffPR)
               

                
                

		iteration++;

	     End While

*/

void PageRankW(Graph g , double DF , double diffPR , int maxIteration){
   
    // N = Number of urls in the collection = g->nV
    //Initialising 
    
    double PR_Arr[g->nV];
    int i;
    for(i = 0; i < g->nV; i++){
    
        PR_Arr[i] = 1/((double)g->nV);
        
        //Use format string "%.7f" to output pagerank values
        printf("%.7f\n" , PR_Arr[i]);
    }


    int iteration = 0;
    int run = 0;
    int diff = diffPR;

    while( (iteration < maxIteration) && (diff >= diffPR) ){
    
        PR_Arr[run] = ( (1 - DF)/((double)g->nV) ) + DF;
        
        // Use format string "%.7f" to output pagerank values
        printf("%.7f\n" , PR_Arr[run]);
        
        run++;
        iteration++;
        
   }
    

}
