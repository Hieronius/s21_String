#include "s21_string.h"

int end(const char *mani, const char *minor, s21_size_t head,
        s21_size_t nohead) {
  int end_i = head;
  for (int i = head - 1; i > -1; i--) {
    int flag2 = 0;
    for (s21_size_t j = 0; j < nohead; j++) {
      if (mani[i] == minor[j]) {
        flag2 = 1;
        break;
      }
    }
    if (flag2 == 1) {
      end_i--;
    } else {
      break;
    }
  }
  return end_i;
}
