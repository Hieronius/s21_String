#include "s21_string.h"

int start(const char *mani, const char *minor, s21_size_t head,
          s21_size_t nohead) {
  int start_i = 0;
  for (s21_size_t i = 0; i < head; i++) {
    int flag1 = 0;
    for (s21_size_t j = 0; j < nohead; j++) {
      if (mani[i] == minor[j]) {
        flag1 = 1;
        break;
      }
    }
    if (flag1 == 1) {
      start_i++;
    } else {
      break;
    }
  }
  return start_i;
}
