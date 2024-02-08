#include "s21_string.h"

/**
 * @brief Выделяет очередную часть строки, отделенную одним из символов
 * разделителей указанных в строке, на которую указывает 2 аргумент
 *
 * @param str Указатель на разбиваемую строку.
 * @param delim Указатель на строку, содержащую набор символов разделителей.
 * @return char* NULL – если строку str невозможно разделить на части. Указатель
 * на первый символ выделенной части строки.
 */
char *s21_strtok(char *s, const char *delim) {
  static char *p;
  int null_flag = 0;

  if (!s) s = p;
  if (!s) null_flag = 1;

  while (1 && !null_flag) {
    if (is_delim(*s, delim)) {
      s++;
      continue;
    }

    if (*s == '\0') null_flag = 1;
    break;
  }

  char *ret = s;

  while (1 && !null_flag) {
    if (*s == '\0') {
      p = s;
      break;
    }

    if (is_delim(*s, delim)) {
      *s = '\0';
      p = s + 1;
      break;
    }

    s++;
  }

  return null_flag ? NULL : ret;
}
