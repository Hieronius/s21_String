#include "s21_string.h"

/**
 * @brief Объединение строк
 *
 * @param dest Указатель на строку назначения, к которой добавятся символы
 * строки source
 * @param src Си-строка, которая добавляется в конец строки destination.
 * @return char* Возвращает указатель на массив, в который добавлена строка .
 */
char *s21_strcat(char *dest, const char *src) {
  char *a = dest;
  while (*a) a++;
  while ((*a++ = *src++)) continue;
  return dest;
}
