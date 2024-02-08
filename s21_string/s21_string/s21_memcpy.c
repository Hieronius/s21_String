#include "s21_string.h"

/**
 * @brief Копирует n байт в массив.
 *
 * @param destination Указатель на массив в которой будут скопированы данные.
 * @param source Указатель на массив источник копируемых данных.
 * @param n Количество байт для копирования.
 * @return Возвращает указатель на массив, в который скопированы данные.
 */

// Копирует n байт из "source" в "destination"
void *s21_memcpy(void *destination, const void *source, s21_size_t n) {
    char *dst = destination;
    const char *src = source;
    // Итерируем пока n не будет равен 0
    while (n--) {
        // Каждую итерацию присваиваем текущий символ source в destination
        // Дополнительную память не выделяем, потому что предпологаем, что destination уже имеет достаточно памяти
        *dst++ = *src++;
    }
    return destination;
}
