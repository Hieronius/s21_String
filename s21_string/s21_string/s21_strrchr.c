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

// Находит последнее совпадение символа с в строке str
char *s21_strrchr(const char *str, int c) {
    // Обьявляем нулевой указатель на строку
   char *result = s21_NULL;
    // Проходимся по строке str и сравниваем каждый символ
  do {
      // Если символ найден, приравниваем его значение result
      // В противном случае возвращаем NULL
      if (*str == c) {
          result = (char *)str;
      }
  } while (*str++);

  return result;
}
