#include <stdio.h>
#include "file.h"
#include "page.h"
#include "types.h"

Page save_page(User user, Page page)
{
    FILE *file;

    char *FILE_LOCATION;

    sprintf(FILE_LOCATION, "%s/%s", DIARY_DIRECTORY, page.title);

    create_directory_if_required(DIARY_DIRECTORY);

    save_file(FILE_LOCATION, WRITE_BINARY, &page);

}

Page read_page(User user, char *title)
{
    // FILE *f;
    // f = fopen(title, "rb");
    // for (int i = 0; i < sizeof(Page); i++)
    // {
    //     printf("%c", f[i]);
    // }
    // fclose(f);
}