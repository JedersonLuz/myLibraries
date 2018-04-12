#include "in_out.h"
#include "dataStructures.h"

void cadastrar(List * list);
void recuperar(List * list);
void deletar(List * list);
void verTamanho(List * list);

int main () {
    List *list;

    list = newList();

    int option;

    do {
        printf("1 - Cadastrar\n");
        printf("2 - Pesquisar\n");
        printf("3 - Listar\n");
        printf("4 - Ver Tamanho\n");
        printf("5 - Deletar\n");
        printf("0 - Sair\n");
        option = str4int(input(""));

        switch(option) {
            case 1:
                cadastrar(list);
                break;
            case 2:
                recuperar(list);
                break;
            case 3:
                listprint(list);
                break;
            case 4:
                verTamanho(list);
                break;
            case 5:
                deletar(list);
                break;
            case 0:
                break;
            default:
                printf("Informe uma opção válida!");
        }
    } while (option != 0);
    
    return 0;
}

void cadastrar(List * list) {
    int *value = malloc(sizeof(int));
    *value = str4int(input("Digite um valor: "));
    listadd(list, value);
}

void recuperar(List * list) {
    int value = str4int(input("Informe o indice: "));
    printf("%d\n", *((int*) listget(list, value)));
    sysPause("Press ENTER to continue.");
}

void deletar(List * list) {
    int value = str4int(input("Informe o indice: "));
    listdelete(list, value);
}

void verTamanho(List * list) {
    printf("size: %d\n", listlen(list));
    sysPause("Press ENTER to continue.");
}