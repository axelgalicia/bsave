#ifndef TYPES_H
#define TYPES_H
#include "configs.h"

typedef enum
{
    READ,
    WRITE,
    APPEND,
    READ_BINARY,
    WRITE_BINARY,
    READ_WRITE_BINARY,
    NUM_ENUM_VALUES,
} FILE_MODE;

static const char *FILE_MODES[] = {
    "r",
    "w",
    "a",
    "rb",
    "wb",
    "wb+",
};

typedef struct
{
    int id;
    int date;
    char *title;
    char *text;
} Page;

typedef struct
{
    char *email;
    char *password;
    Page *pages;
} User;

#endif