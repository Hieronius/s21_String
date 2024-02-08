#include "s21_string.h"

/**
 * @brief Побайтно сравнивает два массива, на которые указывают аргументы arr1 и
 * arr2.
 *
 * @param arr1 Указатель на сравниваемый массив.
 * @param arr2 Указатель на сравниваемый массив.
 * @param n Размер сравниваемой части массива в байтах.
 * @return Результат сравнивания.
 */

// Сравнивает два блока памяти.
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  // Используем const unsigned для работы с неизменяемыми массивами символов
  const unsigned char *s1;
  const unsigned char *s2;
  s1 = str1;
  s2 = str2;
  char count = 0;
    // Сравниваем каждый символ каждой строки
  for (s21_size_t i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      count = s1[i] - s2[i];
      break;
    }
  }
  return count;
}
