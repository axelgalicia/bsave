#ifndef FILE_H
#define FILE_H
#include "types.h"

void create_directory_if_required(const char * directory_name);
void save_file(char *file_name, FILE_MODE file_mode, void *data);

#endif