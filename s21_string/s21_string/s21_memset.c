#include "s21_string.h"

/**
 * @brief Заполняет первые n байт в области памяти.
 *
 * @param str Указатель на заполняемый массив.
 * @param c Код символа для заполнения.
 * @param n Размер заполняемой части массива в байтах.
 * @return Функция возвращает указатель на заполняемый массив.
 */
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *a = str;
  while (n--) *a++ = c;
  return str;
}
