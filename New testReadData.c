



#include <stdio.h>
#include "list.h"
#include "graph.h"
#include "readData.h"


int main(void)
{

    List L = GetCollection();
    Graph my_graph = GetGraph(L);
    showGraph(my_graph , sizeLL(L));
    deleteLL(L, "url11");
    showLL(L);
    freeLL(L);
    disposeGraph(my_graph);





    return 0;
}
