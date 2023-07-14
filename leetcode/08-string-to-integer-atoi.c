#include <stdlib.h>

int myAtoi(char *s) {
  while (*s == ' ') {
    s++;
  };

  int sign = 1;
  if (*s == '+') {
    s++;
  } else if (*s == '-') {
    sign = -1;
    s++;
  }

  char *tmp = s;
  while (*tmp >= 0x30 && *tmp < 0x40) {
    tmp++;
  }
  *tmp = 0;

}
