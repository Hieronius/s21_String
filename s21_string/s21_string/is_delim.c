#include "s21_string.h"

/**
 * @brief Вспомогательная функция определения является ли делитель частью строки
 * @param c строка
 * @param delim делитель
 * @return Булево значение
 */
int is_delim(char c, const char *delim) {
  int ret_flag = 0;

  while (*delim != '\0') {
    if (c == *delim) {
      ret_flag = 1;
      break;
    }

    delim++;
  }
  return ret_flag;
}

char *s21_strerror(int errnum) {
  static const char *strerr[] = s21_error;
  return (char *)strerr[errnum - 1];
}
