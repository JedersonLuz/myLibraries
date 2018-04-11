#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

char * input (const char * format, ...);
int str4int (char *message);
float str4float (char *message);
void sysPause (const char * format, ...);

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
