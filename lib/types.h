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
    char title[MAX_TITLE_LENGTH + 1];
    char text[MAX_TEXT_LENGTH + 1];
} Page;

typedef struct
{
    char email[MAX_EMAIL_LENGTH + 1];
    char password[MAX_PASSWORD_LENGTH + 1];
    Page *pages[MAX_USER_PAGES];
} User;

#endif