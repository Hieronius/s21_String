#include "s21_string.h"

/**
 * @brief Ищет последнее вхождения символа, код которого указан в аргументе c, в
 * строке, на которую указывает аргумент str.
 *
 * @param str Указатель на строку, в которой будет осуществляться поиск.
 * @param c Код искомого символа.
 * @return char* Указатель на искомый символ, если он найден в строке str, иначе
 * NULL.
 */
char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  do {
    if (*str == c) result = (char *)str;
  } while (*str++);

  return result;
}
