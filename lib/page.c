#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "page.h"
#include "types.h"

void save_page(User *user, Page *page)
{

    // printf("Title: %s", &page);
    // // Calculate the required length
    // int length = strlen(DIARY_DIRECTORY) + strlen(page->title) + 2; // +1 for slash, +1 for null terminator
    // printf("Length: %i", length);
    // char *FILE_LOCATION = malloc(length);


    // if (FILE_LOCATION == NULL)
    // {
    //     // Handle memory allocation error
    //     perror("Failed to allocate memory for FILE_LOCATION");
    //     return;
    // }

    // snprintf(FILE_LOCATION,length, "%s/%s", DIARY_DIRECTORY, page->title);

    // create_directory_if_required(DIARY_DIRECTORY);

    // // for (int i = 0; i < MAX_USER_PAGES; i++) {
    // //     if (&user->pages[i] == NULL) {
    // //         printf("Free page: %d ", i);
    // //         break;
    // //     }
    // // }

    // save_file(FILE_LOCATION, WRITE_BINARY, page);

    // free(FILE_LOCATION);
}

Page read_page(User *user, char *title)
{
    FILE *f;
    f = fopen(title, "rb");
    for (int i = 0; i < sizeof(Page); i++)
    {
        printf("%c", f[i]);
    }
    fclose(f);
}