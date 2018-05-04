// 
// dataStructures.c
// testes
// 
// Created by Jederson Sousa Luz
// Copyrigths ® 2018 Jederson Sousa Luz
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericList.h"
#include "util.h"

List newList () {
  return (List) malloc (sizeof(List));
}

void listadd (List list, void * value, char type) {
  List link = (List) malloc(sizeof(List));
  while (list->next != NULL) {
    list = list->next;
  }
  if (type == 'i') {
    list->type = type;// int
  } else if (type == 'f') {
    list->type = type;// float
  } else if (type == 'd') {
    list->type = type;// double
  } else if (type == 'c') {
    list->type = type;// char
  } else if (type == 's') {
    list->type = type;// string
  } else if (type == 'l') {
    list->type = type;// long
  }
  list->value = value;
  list->next = link;
}

void * listget (List list, int index) {
  List link = (List) malloc(sizeof(List));
  link = list;
  if ((index < 0) || (index > listlen(list))) {
    return NULL;
  }
  for(int i = 0; i < index; i++) {
    if (list->next == NULL) return NULL;
    link = link->next;
  }
  return link->value;
}

void listdelete (List list, int index) {
  List link;
  List prev = NULL;
  link = list;
  if ((index < 0) || (index > listlen(list))) {
    return;
  }
  if (listlen(list) != 0) {
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
}

void listdeleteall (List list) {
  if (list->next == NULL) {
    list->next = NULL;
    free(list->value);
    free(list);
  } else {
    listdeleteall(list->next);
    list->next = NULL;
    free(list->value);
    free(list);
  }
}

void listprint(List list) {
    int size = listlen(list);
    printf("[");
    for(int i = 0; i < size; i++) {
        if (list->type == 'i') {
          printf("%d", *((int*) list->value));// int
        } else if (list->type == 'f') {
          printf("%f", *((float*) list->value));// float
        } else if (list->type == 'd') {
          printf("%f", *((double*) list->value));// double
        } else if (list->type == 'c') {
          printf("%c", *((char*) list->value));// char
        } else if (list->type == 's') {
          printf("%s", (char*) list->value);// string
        } else if (list->type == 'l') {
          printf("%ld", *((long*) list->value));// long
        }
        list = list->next;
        if (i < size-1) {
            printf(",");
        }
    }
    printf("]\n");
    sysPause("Press ENTER to continue.");
}

int listlen (List list) {
  int len = 0;

  while(list->next != NULL) {
    list = list->next;
    len++;
  }
  return len;
}