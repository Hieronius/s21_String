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

// Функция определяет является ли str2 частью строки str1
char *s21_strstr(const char *str1, const char *str2) {
  int lenght = s21_strlen(str2) - 1;
  char *str = s21_NULL;
  char *ptr = (char *)str1;

  for (int i = 0; ptr[i] != '\0' && str == s21_NULL; i++) {
      int count = 0;
      int flag = 1;
    while ((count <= lenght) && flag) {
      flag = ptr[i + count] == str2[count];
      count++;
    }
    if (flag && (count > lenght)) {
      str = &(ptr[i]);
    }
  }
 // Возвращаем указатель на символ в строке str1, с которого начинается строка str2 в случае совпадения
  return str;
}
