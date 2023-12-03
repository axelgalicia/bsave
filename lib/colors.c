#include <stdio.h>
#include "colors.h"

void red() {
    printf("\033[1;31m");
}

void green() {
    printf("\033[1;102m");
}

void white_background() {
    printf("\033[1;47m");
}

void blue() {
    printf("\33[1;44m");
}

void reset_color() {
    printf("\033[0m");
}