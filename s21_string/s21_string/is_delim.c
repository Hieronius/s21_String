#include "s21_string.h"

/**
 * @brief Вспомогательная функция определения является ли делитель частью строки
 * @param c строка
 * @param delim делитель
 * @return Булево значение
 */

// Определяет является ли символ С делителем строки delim
// Например: ',' и "abc, def" вернет 1, потому что ',' является делителем строки
int is_delim(char c, const char *delim) {
  int ret_flag = 0;

    // Проходимся по строки пока она не закончится и сравниваем каждый символ
  while (*delim != '\0') {
    if (c == *delim) {
      ret_flag = 1;
      break;
    }

    delim++;
  }
  return ret_flag;
}
