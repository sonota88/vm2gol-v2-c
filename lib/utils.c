#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _err_exit(char* msg, char* filename, int lineno) {
  fprintf(stderr, "ERROR %s: %d: ", filename, lineno);
  fprintf(stderr, "%s\n", msg);
  exit(1);
}

void _assert(int exp, int act, int id) {
  char msg[100];

  if (exp != act) {
    sprintf(msg, "assertion failed (%d): exp(%d) act(%d)", id, exp, act);
    _err_exit(msg, __FILE__, __LINE__);
  }
}

void puts_e(char* str){
  fprintf(stderr, "%s", str);
  fprintf(stderr, "\n");
}

void read_stdin_all(char* dest, int size_max) {
  int ch;
  int i = -1;

  for (;;) {
    i++;
    if (size_max <= i) {
      _err_exit("too large input", __FILE__, __LINE__);
    }

    ch = getchar();
    if (ch == EOF) {
      break;
    }

    dest[i] = ch;
  }
  dest[i] = '\0';
}

int find_index(char* str, char ch, int from) {
  int i = from;
  while (1) {
    if (str[i] == '\0') {
      return -1;
    }
    if (str[i] == ch) {
      break;
    }
    i++;
  }
  return i;
}

int is_numeric(char ch) {
  if ('0' <= ch && ch <= '9') {
    return 1;
  } else {
    return 0;
  }
}

int find_non_numeric_index(char* str) {
  int i;
  for (i = 1; i < strlen(str); i++) {
    if (is_numeric(str[i])) {
      ;
    } else {
      break;
    }
  }
  return i;
}

void substring(char* dest, char* src, int index_start, int index_end) {
  int i;
  int size = index_end - index_start;
  for (i = 0; i < size; i++) {
    if (src[index_start + i] == '\0') {
      size = i;
      break;
    }
    dest[i] = src[index_start + i];
  }
  dest[size] = '\0';
}

int s_to_i(char* str) {
  int status;
  int n;
  status = sscanf(str, "%d", &n);
  if (status != 1) {
    fprintf(stderr, "sscanf failed\n");
    exit(1);
  }
  return n;
}

int str_eq(char* s1, char* s2) {
  return strcmp(s1, s2) == 0;
}

int match_any_char(char *chars, char ch) {
  if (0 <= find_index(chars, ch, 0)) {
    return 1;
  } else {
    return 0;
  }
}
