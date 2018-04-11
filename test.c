#include "in_out.h"
#include "dataStructures.h"

int main () {
    List *list;

    list = newList();
    
    int value = str4int(input("Digite um valor: "));
    void * val = &value;

    listadd(list, &value);

    //printf("Size: %d\n", listlen(list));
    
    //value = (int*) listget(list, 0);
    
    printf("%d\n", *value));
    printf("%d\n", *((int*) listget(list, 0)));
    
    return 0;
}
