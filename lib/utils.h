#pragma once

void puts_e(char* str);

void read_stdin_all(char* dest);
int find_index(char* str, char ch, int from);
void substring(char* dest, char* src, int index_start, int index_end);
int s_to_i(char* str);
int str_eq(char* s1, char* s2);
int match_any_char(char *chars, char ch);
int is_numeric(char ch);
int find_non_numeric_index(char* str);

void _err_exit(char* msg, char* filename, int lineno);
void _todo(char* msg, char* filename, int lineno);
