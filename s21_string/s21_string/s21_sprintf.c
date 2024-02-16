#include "s21_string.h"

/**
 * @brief Записывает данные в массив.
 *
 * @param str Указатель на изначальный массив.
 * @param format Формат для обработки.
 * @return Функция возвращает количество успешно записанных символов.
 */
int s21_sprintf(char *str, const char *format, ...) {
  va_list vl;
  va_start(vl, format);
  while (*format) {
    if (*format != '%') {
      *str = *format;
      str++;
      format++;
    } else {
      format++;
      struct format_sprintf _format_sprintf;
      ZeroingFields(&_format_sprintf);

      if (parsing(&format, &_format_sprintf) == 1) {
        record_arg(&format, &str, &_format_sprintf, vl);
      }
    }
  }
  va_end(vl);
  return 0;
}
