// 
// dataStructures.h
// testes
// 
// Created by Jederson Sousa Luz
// Copyrigths ® 2018 Jederson Sousa Luz
//

typedef struct List {
  void * value;
  char type;
  struct List * next;
}*List;

List newList ();

void listadd (List list, void * value, char type);

void * listget (List list, int index);

void listdelete (List list, int index);

void listdeleteall (List list);

void listprint(List list);

int listlen (List list);