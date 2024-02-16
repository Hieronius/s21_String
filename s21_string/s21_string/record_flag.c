#include "s21_string.h"

void record_arg(const char **format, char **str,
                struct format_sprintf *_format_spr, va_list vl) {
  char buffer[BUFF_SIZE];

  if (**format == 'c') {
    char ch = _format_spr->length_l ? va_arg(vl, long int) : va_arg(vl, int);

    if (_format_spr->flag_minus) {
      **str = ch;
      (*str)++;
    }

    for (int i = 1; i < _format_spr->width; i++) {
      **str = ' ';
      (*str)++;
    }

    if (!_format_spr->flag_minus) {
      **str = ch;
      (*str)++;
    }

    (*format)++;

  } else if (**format == '%') {
    **str = '%';
    (*str)++;
    (*format)++;

  } else if (**format == 'd' || **format == 'i') {
    int int_temp;

    short int si_temp;
    char *str_temp;
    char str_res[BUFF_SIZE] = {0};

    if (_format_spr->length_l) {
      long int li_temp;
      li_temp = va_arg(vl, long int);
      str_temp = litos(li_temp, buffer, 10, 0);
    } else if (_format_spr->length_h) {
      si_temp = (short)va_arg(vl, int);
      str_temp = sitos(si_temp, buffer, 10, 0);
    } else {
      int_temp = va_arg(vl, int);
      str_temp = itos(int_temp, buffer, 10, 0);
    }

    int len = s21_strlen(str_temp);
    int res_len = len;

    if (_format_spr->flag_plus && !_format_spr->flag_space &&
        str_temp[0] != '-') {
      s21_strcat(str_res, "+");
      res_len++;
    }

    if (_format_spr->flag_space) {
      s21_strcat(str_res, " ");
      res_len++;
    }

    while (_format_spr->precision-- > len) {
      s21_strcat(str_res, "0");
      res_len++;
    }

    s21_strcat(str_res, str_temp);

    if (_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }

    for (; res_len < _format_spr->width--;) {
      **str = ' ';
      (*str)++;
    }

    if (!_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }

    (*format)++;

  } else if (**format == 's') {
    char *str_temp;
    char str_res[BUFF_SIZE] = {0};

    str_temp = va_arg(vl, char *);

    int len = s21_strlen(str_temp);
    int res_len = len;

    s21_strcat(str_res, str_temp);

    if (_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }

    for (; res_len < _format_spr->width--;) {
      **str = ' ';
      (*str)++;
    }

    if (!_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }
    (*format)++;

  } else if (**format == 'u') {
    unsigned short int si_temp;
    char *str_temp;
    char str_res[BUFF_SIZE] = {0};

    if (_format_spr->length_l) {
      unsigned long int li_temp;
      li_temp = va_arg(vl, unsigned long int);
      str_temp = uitos(li_temp, buffer, 10, 0);
    } else if (_format_spr->length_h) {
      si_temp = (short)va_arg(vl, unsigned int);
      str_temp = uitos(si_temp, buffer, 10, 0);
    } else {
      unsigned int int_temp;
      int_temp = va_arg(vl, unsigned int);
      str_temp = uitos(int_temp, buffer, 10, 0);
    }

    int len = s21_strlen(str_temp);
    int res_len = len;

    while (_format_spr->precision-- > len) {
      s21_strcat(str_res, "0");
      res_len++;
    }

    s21_strcat(str_res, str_temp);

    if (_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }

    for (; res_len < _format_spr->width--;) {
      **str = ' ';
      (*str)++;
    }

    if (!_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }
    (*format)++;

  } else if (**format == 'f') {
    double double_temp = va_arg(vl, double);
    char *str_temp;
    char str_res[BUFF_SIZE] = {0};
    int decimal = 0;
    int sign = 0;
    int counter = 0;

    int fact = fabs(double_temp) > 1.0 ? 1 : 0;
    if (_format_spr->is_pricision != 1) {
      _format_spr->precision = 6;
    }
    str_temp =
        fcvt(double_temp, _format_spr->precision + fact, &decimal, &sign);
    int len = s21_strlen(str_temp);
    int res_len = len;

    if (_format_spr->flag_plus && !_format_spr->flag_space && sign == 0) {
      s21_strcat(str_res, "+");
      res_len++;
    }

    if (_format_spr->flag_space) {
      s21_strcat(str_res, " ");
      res_len++;
    }

    if (sign != 0) {
      s21_strcat(str_res, "-");
      res_len++;
    }

    if (decimal <= 0) {
      s21_strcat(str_res, "0.");
      res_len += 2;
      decimal *= -1;

      for (int i = 0; i < decimal; i++) {
        s21_strcat(str_res, "0");
        res_len++;
      }

      for (int i = 0; str_temp[i] != '\0'; i++) {
        char ch = str_temp[i];
        str_res[res_len - len + i] = ch;
        if (counter == decimal + 1) {
          str_res[res_len - len + i] = '.';
        }
      }

    } else {
      for (int i = 0; str_temp[i]; i++) {
        counter++;
        char ch = str_temp[i];
        str_res[res_len - len + i] = ch;
        if (counter == decimal + 1) {
          str_res[res_len - len + i] = '.';
        }
      }
    }
    if (_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }

    for (; res_len < _format_spr->width--;) {
      **str = ' ';
      (*str)++;
    }

    if (!_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }
    /*
    if (sign != 0) {
      **str = '-';
      str++;
    }
    */

    (*format)++;
  }
}
