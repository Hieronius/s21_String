#include "s21_string.h"

// Возвращает сообщение об ошибке из массива s21_error
char *s21_strerror(int errnum) {
  static const char *strerr[] = s21_error;
  return (char *)strerr[errnum - 1];
}
