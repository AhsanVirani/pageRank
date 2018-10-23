



#include "list.h"
#include "graph.h"
#include "readData.h"
#include <stdio.h>


int main(void)
{

    List L = GetCollection();
    deleteLL(L, "url11");
    showLL(L);
    freeLL(L);





    return 0;
}
