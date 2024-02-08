#include "s21_string.h"

/**
 * @brief Проверяет символ на число.
 *
 * @param ch Входной символ.
 * @returns Функция возвращает положительный или негативный резульатат.
 */
int is_digit(char ch) {
  int f = OFF;
  if (ch >= '0' && ch <= '0' + 10) {
    f = ON;
  }
  return f;
}
