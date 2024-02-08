#include "s21_string.h"

/**
 * @brief Копирует данные из строки, на которую указывает аргумент src, в dest
 *
 * @param dest Указатель на строку, в которую будут скопированы данные.
 * @param src Указатель на строку источник копируемых данных.
 * @return char* Возвращает указатель на строку, в которую скопированы данные.
 */
char *s21_strcpy(char *dest, const char *src) {
  char *res = &dest[0];
  for (int i = 0; (dest[i] = src[i]); i++) {
  }
  return res;
}
