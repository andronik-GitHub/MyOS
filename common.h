#pragma once

#define va_list __builtin_va_list // змінна-"курсор", що вміє ходити по додаткових аргументах
#define va_start __builtin_va_start // поставити курсор на перший аргумент після fmt
#define va_end __builtin_va_end // прочитати поточний аргумент як вказаний тип і пересунути курсор далі
#define va_arg __builtin_va_arg // завершити роботу з курсором (прибрати за собою)

void printf(const char *fmt, ...);