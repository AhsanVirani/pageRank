

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "readData.h"
#include "invertedIndex.h"




Tree invertedIndexToFile(){

    FILE *in;
    List List_of_Urls = GetCollection();
    Tree InvertedIndex = GetInvertedList(List_of_Urls);
    in = fopen("invertedIndex.txt", "w");

    showTreeRR(InvertedIndex, 0, in);
    
    fclose(in);
    return InvertedIndex;
}






void showTreeRR(Tree t, int depth, FILE *in) {

   if (t != NULL) {
      showTreeRR(left(t), depth+1, in);
      //int i;
      //for (i = 0; i < depth; i++)
        char *s=ConvertToString(t->Url_List);
	    fprintf(in ,"%s  %s\n", data(t), s);
	    free(s);
      showTreeRR(right(t), depth+1, in);
   }
}


