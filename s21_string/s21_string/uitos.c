#include "s21_string.h"

/**
 * @brief Проверка беззнакового числа.
 *
 * @param number Числовое значение.
 * @param str Входная строка.
 * @param base Система счисления.
 * @param upperCase Верхний регист.
 * @return Функция возвращает указатель на строку.
 */
char *uitos(unsigned number, char *str, unsigned base, int upperCase) {
  int i = 0;

  if (!number) {
    str[i++] = '0';
    str[i] = '\0';
    return str;
  }

  while (number != 0) {
    int digit = base > 0 ? number % base : number % 10;
    str[i++] = uitoc(digit, base, upperCase);
    number /= base;
  }

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
