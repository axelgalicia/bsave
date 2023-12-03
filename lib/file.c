#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "file.h"
#include "types.h"

void create_directory_if_required(const char *directory_name)
{
  struct stat stat_buf;
  if (stat(directory_name, &stat_buf) == -1)
  {
    printf("Creating directory");
    mkdir(directory_name, 0700);
  }
}

void save_file(char *file_name, FILE_MODE file_mode, void *data)
{
  FILE *file = fopen(file_name, FILE_MODES[file_mode]);

  if (!file)
  {
    printf("Error to open file %s", file_name);
  }
  else
  {
    fwrite(&data, sizeof(data), 1, file);
  }

  fclose(file);
}