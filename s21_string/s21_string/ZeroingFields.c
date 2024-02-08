#include "s21_string.h"

/**
 * @brief Обнуляет поля структуры.
 *
 * @param formatS Указатель на структуру.
 */
void ZeroingFields(struct format_sprintf *formatS) {
  formatS->flag_minus = 0;
  formatS->flag_plus = 0;
  formatS->flag_space = 0;
  formatS->length_h = 0;
  formatS->length_l = 0;
  formatS->precision = 0;
  formatS->width = 0;
  formatS->is_pricision = 0;
}
