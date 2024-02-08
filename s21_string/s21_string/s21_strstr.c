#include "s21_string.h"

/**
 * @brief Ищет первое вхождение строки 1 в строку 2. Если строка 2 имеет нулевую
 * длину, то функция вернет указатель на начало строки 2.
 *
 * @param haystack Указатель на строку, в которой ведется поиск.
 * @param needle Указатель на искомую строку.
 * @return char* NULL – если строка heystack не входит в строку needle.
 * Указатель на первое вхождение строки heystack в строку needle.
 */
char *s21_strstr(const char *haystack, const char *needle) {
  int len_needle = s21_strlen(needle) - 1;
  char *str = s21_NULL;
  char *ptr = (char *)haystack;

  for (int i = 0; ptr[i] != '\0' && str == s21_NULL; i++) {
    int count = 0, flag = 1;
    while ((count <= len_needle) && flag) {
      flag = ptr[i + count] == needle[count];
      count++;
    }
    if (flag && (count > len_needle)) {
      str = &(ptr[i]);
    }
  }
  return str;
}
