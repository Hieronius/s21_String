#include "s21_string.h"

/**
 * @brief Проверяет символ на спецификатор.
 *
 * @param is Входной символ.
 * @returns Функция возвращает положительный или негативный резульатат.
 */
int is_specifier(char ch) {
  int f = OFF;
  if (ch == 'd' || ch == 'i' || ch == 'c' || ch == 'f' || ch == 's' ||
      ch == 'u' || ch == '%') {
    f = ON;
  }
  return f;
}
