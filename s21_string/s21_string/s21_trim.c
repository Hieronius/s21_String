#include "s21_string.h"

/**
 * @brief Удаляет все начальные и конечные вхождения набора символов, заданного
 * в виде массива, из текущей строки.
 *
 * @param src Искомая строка
 * @param trim_chars Символы которые нужно заменить
 * @return void* Возвращает новую строку, в которой удаляются все начальные и
 * конечные вхождения набора заданных символов из данной строки
 */
void *s21_trim(const char *src, const char *trim_chars) {
  char *mani = (char *)src;
  char *minor = (char *)trim_chars;
  char *arr;
  int man = 1;
  if (minor == s21_NULL) {
    trim_chars = " ";
    minor = (char *)trim_chars;
  }
  if (mani == s21_NULL) man = 0;
  if (man) {
    int arr_i = 0;
    s21_size_t head = s21_strlen(src);
    s21_size_t nohead = s21_strlen(trim_chars);
    arr = (char *)malloc((head + 1) * sizeof(char));
    int st_i = start(mani, minor, head, nohead);
    int en_i = end(mani, minor, head, nohead);
    for (int i = st_i; i < en_i; i++) {
      arr[arr_i] = src[i];
      arr_i++;
    }
    arr[arr_i] = '\0';
  }
  if (man == 0) {
    return s21_NULL;
  } else {
    return (char *)arr;
  }
}
