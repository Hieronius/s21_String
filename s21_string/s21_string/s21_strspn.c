#include "s21_string.h"

/**
 * @brief Определяет наибольшую длину начального участка строки содержащего
 * только символы строки, на которую указывает аргумент
 *
 * @param str1 Указатель на строку, в которой ведется поиск.
 * @param str2 Указатель на строку с набором символов, которые должны входить в
 * участок строки str1.
 * @return s21_size_t Длина начального участка строки, содержащая только
 * символы, указанные в аргументе str2.
 */
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t i, j, counter = 0;

  for (i = 0; &str1[i] != s21_NULL; i++) {
    if (counter != i) break;
    for (j = 0; &str2[j] != s21_NULL; j++) {
      if (str1[i] == str2[j]) {
        counter++;
      } else {
        break;
      }
    }
  }
  return counter;
}
