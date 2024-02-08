#include "s21_string.h"

/**
 * @brief Ищет первое вхождение в строку, одного из символов, входящих в строку
 * 2
 *
 * @param str1 Указатель на строку, в которой ведется поиск.
 * @param str2 Указатель на строку с набором искомых символов.
 * @return char* Указатель на первый найденный в строке str1 символ из множества
 * символов строки str2.
 */
char *s21_strpbrk(const char *str1, const char *str2) {
  char *string1 = (char *)str1;
  char *string2 = (char *)str2;
  int flag = 1;
  char *res = s21_NULL;
  for (int i = 0; string1[i] != '\0' && flag == 1; i++) {
    char symbol = string1[i];
    if (s21_strchr(string2, symbol) != s21_NULL) {
      res = &string1[i];
      flag = 0;
    }
  }
  return res;
}
