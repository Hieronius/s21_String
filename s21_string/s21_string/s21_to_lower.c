#include "s21_string.h"

/**
 * @brief Опускает все символы из верхнего регистра в нижний.
 *
 * @param str Указатель на изначальный массив.
 * @return Функция возвращает указатель на измененный массив.
 */

// Делает все символы строки строчными
// Возвращает указатель на новую измененную строку
void *s21_to_lower(const char *str) {
  char *our_str2 = s21_NULL;
    // Проверяем что исходная строка не пустая
  if (str) {
      // Если все верно, выделяем внутренней строке такой же обьем памяти + null terminator
    our_str2 = (char *)realloc(our_str2, (s21_strlen(str) + 1) * sizeof(char));
    our_str2[s21_strlen(str)] = '\0';
  }
  if (our_str2) {
      // Если все верно, копируем содержимое исходной строки в новую строку
    s21_strncpy(our_str2, str, s21_strlen(str));
      // Итерируем каждый символ новой строки и добавляем 32, чтобы получить строчные версии букв
    for (char *i = our_str2; *i; i++) {
      if (*i >= 'A' && *i <= 'Z') *i += 32;
    }
  }
  return (void *)our_str2;
}
