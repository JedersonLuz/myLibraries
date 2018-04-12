#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List {
  void * value;
  char type;
  struct List * next;
}List;

List * newList ();
void listadd (List * list, void * value);
void * listget (List * list, int index);
void listdelete (List * list, int index);
void listdeleteall (List * list);
void listprint(List * list);
int listlen (List * list);

List * newList () {
  return (List*) malloc (sizeof(List));
}

void listadd (List * list, void * value) {
  List * link = (List*) malloc(sizeof(List));
  while (list->next != NULL) {
    list = list->next;
  }
  list->value = value;
  list->next = link;
}

void * listget (List * list, int index) {
  List * link = (List*) malloc(sizeof(List));
  link = list;
  if ((index < 0) || (index > listlen(list))) {
    return NULL;
  }
  for(int i = 0; i < index; i++) {
    link = link->next;
  }
  return link->value;
}

void listdelete (List * list, int index) {
  List * link;
  List * prev = NULL;
  link = list;
  if ((index < 0) || (index > listlen(list))) {
    return;
  }
  for(int i = 0; i < index; i++) {
    prev = link;
    link = link->next;
  }

  if (prev != NULL) {
    prev->next = link->next;
    free(link->value);
    free(link);
  } else {
    *link = *link->next;
  }
}

void listprint(List * list) {
    int size = listlen(list);
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d", *((int*) listget(list, i)));
        if (i < size-1) {
            printf(",");
        }
    }
    printf("]\n");
    sysPause("Press ENTER to continue.");
}

int listlen (List * list) {
  int len = 0;

  while(list->next != NULL) {
    list = list->next;
    len++;
  }
  return len;
}