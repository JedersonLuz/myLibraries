// 
// util.c
// testes
// 
// Created by Jederson Sousa Luz
// Copyrigths ® 2018 Jederson Sousa Luz
//

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "util.h"

char * input (const char * format, ...) {
  char *value = malloc(255);
  va_list arg;

  va_start (arg, format);
  vfprintf (stdout, format, arg);
  va_end (arg);

  setbuf(stdin, NULL);
  scanf("%[^\n]s", value);

  return value;
}

int str4int (char *message) {
  if (!strcmp(message, "0")) {
    return 0;
  } else {
    int value = atoi(message);
    while (value == 0) {
      message = input("Enter a valid value!\n");
      value = atoi(message);
      if (!strcmp(message, "0"))
        break;
    }
    free(message);
    return value;
  }
}

float str4float (char *message) {
  if (!strcmp(message, "0")) {
    return 0;
  } else {
    float value = atof(message);
    while (value == 0) {
      message = input("Enter a valid value!\n");
      value = atof(message);
      if (!strcmp(message, "0"))
        break;
    }
    free(message);
    return value;
  }
}

void sysPause (const char * format, ...) {
  va_list arg;

  va_start (arg, format);
  vfprintf (stdout, format, arg);
  va_end (arg);

  setbuf(stdin, NULL);
  getchar();
}

void printerr(const char * format, ...) {
  va_list arg;

  va_start (arg, format);
  vfprintf (stderr, format, arg);
  va_end (arg);
}