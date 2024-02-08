#include "s21_string.h"

/**
 * @brief Проверка символа.
 *
 * @param val Значение.
 * @param base Система счисления.
 * @param upperCase Верхний регистр.
 * @return Верхний регистр.
 */
int itoc(int val, int base, int upperCase) {
  const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
  const char DIGITS[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  return upperCase ? DIGITS[val % base] : digits[val % base];
}
