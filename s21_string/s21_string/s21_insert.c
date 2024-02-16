#include "s21_string.h"

/**
 * @brief Возвращает новую строку, со вставленной подстрокой
 * @param src - Основной массив, в который будем помещать подстроку
 * @param str - Подстрока, которую будем помещать в src
 * @param start_index - Индекс позиции, с которой будем начинать вставку
 * @returns Новая строка
 */


void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t head = s21_strlen(src);
  s21_size_t minor = s21_strlen(str);
  s21_size_t am = 0;

  static char man[BUFF_SIZE] = {0};
  s21_size_t fromSrc = 0;
  s21_size_t fromStr = 0;

  while (fromSrc < head && fromSrc != start_index) {
    man[am++] = src[fromSrc];
    fromSrc++;
  }

  while (fromStr < minor) {
    man[am++] = str[fromStr];
    fromStr++;
  }

  while (fromSrc < head) {
    man[am++] = src[fromSrc];
    fromSrc++;
  }
  man[am] = '\0';
  return start_index <= head ? man : s21_NULL;
}
