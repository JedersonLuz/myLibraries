#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "genericList.h"

void cadastrar(List list);
void recuperar(List list);
void deletar(List list);
void verTamanho(List list);

int main () {
    List list;

    list = newList();

    int option;

    do {
        printf("+---------------+\n");
        printf("| 1 - Adicionar |\n");
        printf("| 2 - Buscar    |\n");
        printf("| 3 - Listar    |\n");
        printf("| 4 - Tamanho   |\n");
        printf("| 5 - Remover   |\n");
        printf("| 6 - Rm Tudo   |\n");
        printf("| 0 - Sair      |\n");
        printf("+---------------+\n");
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
            case 6:
                listdeleteall(list);
            case 0:
                printf("Programa encerrado...\n");
                break;
            default:
                printf("Informe uma opção válida!");
        }
    } while (option != 0);
    
    return 0;
}

void cadastrar(List list) {
    char * type = input("Digite um tipo [i,f,c,s]: ");
    if (*type == 'i') {
        int * value = malloc(sizeof(int));
        *value = str4int(input("Digite o valor: "));
        listadd(list, value, *type);
    } else if (*type == 'f') {
        float * value = malloc(sizeof(float));
        *value = str4float(input("Digite o valor: "));
        listadd(list, value, *type);
    } else if (*type == 'c') {
        //char * value = malloc(sizeof(char));
        char * value = input("Digite o valor: ");
        listadd(list, value, *type);
    } else if (*type == 's') {
        char * value = input("Digite o valor: ");
        listadd(list, value, *type);
    }
}

void recuperar(List list) {
    int value = str4int(input("Informe o indice: "));
    
    if (listget(list, value) != NULL) {
        if (list->type == 'i') {
            printf("%d\n", *((int*) listget(list, value)));// int
        } else if (list->type == 'f') {
            printf("%f\n", *((float*) listget(list, value)));// float
        } else if (list->type == 'd') {
            printf("%f\n", *((double*) listget(list, value)));// double
        } else if (list->type == 'c') {
            printf("%c\n", *((char*) listget(list, value)));// char 
        } else if (list->type == 's') {
            printf("%s\n", (char*) listget(list, value));// string
        } else if (list->type == 'l') {
            printf("%ld\n", *((long*) listget(list, value)));// long
        }
    } else if (list->next == NULL) {
        printf("Não existem valores na lista!\n");
    } else if (listget(list, value) == NULL) {
        printf("O valor informado não foi encontrado!\n");
    }
    sysPause("Press ENTER to continue.");
}

void deletar(List list) {
    int value = str4int(input("Informe o indice: "));
    listdelete(list, value);
}

void verTamanho(List list) {
    printf("size: %d\n", listlen(list));
    sysPause("Press ENTER to continue.");
}