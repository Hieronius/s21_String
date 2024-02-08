#include "s21_string.h"

/**
 * @brief Функция strchr ищет последнее вхождения символа, код которого указан в
 * аргументе ch, в строке, на которую указывает аргумент str.
 *
 * @param str Указатель на строку, в которой будет осуществляться поиск.
 * @param c Код искомого символа.
 * @return char* Указатель на искомый символ, если он найден в строке str, иначе
 * NULL.
 */

char *s21_strchr(const char *str, int c) {
  while (*str != c && *str) str++;
  return *str == c ? (char *)str : 0;
}
