#include "s21_string.h"

/**
 * @brief Проверяет длины строк.
 *
 * @param number Числовое значение.
 * @param str Входная строка.
 * @param base Система счисления.
 * @param upperCase Верхний регистр.
 * @return Функция возвращает указатель на строку.
 */
char *litos(long int number, char *str, long int base, int upperCase) {
  int isNegative = 0, i = 0;

  if (!number) {
    str[i++] = '0';
    str[i] = '\0';
    return str;
  }

  if (number < 0 && base == 10) {
    isNegative++;
    number = -number;
  }

  while (number > 0) {
    int digit = number % base;
    str[i++] = itoc(digit, (int)base, upperCase);
    number /= base;
  }

  if (isNegative) str[i++] = '-';
  str[i] = '\0';

  int pos = 0;
  i--;

  while (pos < i) {
    int swap = str[pos];
    str[pos] = str[i];
    str[i] = swap;

    pos++;
    i--;
  }

  return str;
}
