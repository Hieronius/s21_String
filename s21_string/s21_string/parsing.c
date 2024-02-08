#include "s21_string.h"

/**
 * @brief Парсит данные и записывает в поля структуры.
 *
 * @param format Исходная строка.
 * @param _format_sprintff Указатель на структуру.
 * @param flag_pars Указатель на возвращаемое значение.
 * @returns Возвращает значение.
 */
int parsing(const char **format, struct format_sprintf *_format_sprintff) {
  int flag_pars = 0;
  while (**format) {
    if (**format == '-' || **format == '+' ||
        **format == ' ') {  // Ckeck for flags
      if (**format == '-') {
        _format_sprintff->flag_minus = 1;
      } else if (**format == '+') {
        _format_sprintff->flag_plus = 1;
      } else if (**format == ' ') {
        _format_sprintff->flag_space = 1;
      }
      (*format)++;

    } else if (is_digit(**format) == ON) {  // Check for Width
      while (is_digit(**format)) {
        _format_sprintff->width = **format - '0' + _format_sprintff->width * 10;
        (*format)++;
      }

    } else if (**format == '.') {  // Check for precision
      _format_sprintff->is_pricision = 1;
      (*format)++;
      while (is_digit(**format)) {
        _format_sprintff->precision =
            **format - '0' + _format_sprintff->precision * 10;
        (*format)++;
      }

    } else if (**format == 'h' || **format == 'l') {  // Check for length
      if (**format == 'h') {
        _format_sprintff->length_h = 1;
      } else if (**format == 'l') {
        _format_sprintff->length_l = 1;
      }
      (*format)++;

    } else if (is_specifier(**format) == ON) {  // Check for specifier
      flag_pars = 1;
      break;

    } else {  // Returns error
      flag_pars = 0;
      break;
    }
  }
  return flag_pars;
}
