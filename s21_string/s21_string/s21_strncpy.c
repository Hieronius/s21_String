#include "s21_string.h"

/**
 * @brief Копирует  данные из строки, на которую указывает аргумент src, в dest
 *
 * @param dest Указатель на строку в которую будут скопированы данные.
 * @param src Указатель на строку источник копируемых данных.
 * @param n Ограничение длинны копирования
 * @return char* Возвращает указатель на строку, в которую скопированы данные.
 */
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n && src[i]) {
    dest[i] = src[i];
    i++;
  }
  if (i > s21_strlen(src)) {
    dest[i++] = 0;
  }
  return dest;
}
