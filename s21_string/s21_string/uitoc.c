#include "s21_string.h"

/**
 * @brief Переводит беззнакового числа в целочисленное.
 *
 * @param val Значение.
 * @param base Система счисления.
 * @param upperCase Верхний регистр.
 * @return Целочисленное значение.
 */
int uitoc(unsigned val, unsigned base, int upperCase) {
  const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
  const char DIGITS[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  return upperCase ? DIGITS[val % base] : digits[val % base];
}
