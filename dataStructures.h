#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List {
  void * value;
  char type;
  struct List * next;
}List;

List * newList ();
void listadd (List *l, void * value);
void * listget (List * list, int index);
int listlen (List * list);

List * newList () {
  return (List*) malloc (sizeof(List));
}

void listadd (List * list, void * value) {
  List * link = (List*) malloc(sizeof(List));
  link->value = value;
  while (list->next != NULL) {
    list = list->next;
  }
  list->next = link;
}

void * listget (List * list, int index) {
  List * link = (List*) malloc(sizeof(List));
  link = list;
  for(int i = 0; i < index; i++) {
    link = link->next;
  }
  return link->value;
}

int listlen (List * list) {
  int len = 0;
  while(list->next != NULL) {
    list = list->next;
    len++;
  }
  return len;
}