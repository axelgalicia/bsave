#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_SIZE 50
#define MAX_TEXT_SIZE 10000
#define MAX_PAGES 100
#define MAX_USER_SIZE 50
#define MAX_PASSWORD_SIZE 50
#define FILE_EXTENSION ".diary"

typedef struct {
    char title[MAX_TITLE_SIZE];
    char text[MAX_TEXT_SIZE];
} Page;

typedef struct {
    char username[MAX_USER_SIZE];
    char password[MAX_PASSWORD_SIZE];
    Page pages[MAX_PAGES];
    int pageCount;
} User;

// Function Declarations
void write_new_page(User* user);
void save_pages(const User* user);
void load_pages(User* user);
void list_pages(const User* user);
void search_page_by_title(const User* user, const char* title);

int main() {
    User currentUser = {"username", "password", {}, 0};  // Example user
    int option;

    load_pages(&currentUser); // Load pages at the start

    do {
        printf("\nDiary Application\n");
        printf("1. Write new page\n");
        printf("2. List all pages\n");
        printf("3. Search page by title\n");
        printf("4. Exit\n");
        printf("Select option: ");
        scanf("%d", &option);
        getchar(); // Consume newline

        switch(option) {
            case 1:
                write_new_page(&currentUser);
                save_pages(&currentUser);
                break;
            case 2:
                list_pages(&currentUser);
                break;
            case 3:
                {
                    char title[MAX_TITLE_SIZE];
                    printf("Enter title to search: ");
                    fgets(title, MAX_TITLE_SIZE, stdin);
                    title[strcspn(title, "\n")] = 0; // Remove newline character
                    search_page_by_title(&currentUser, title);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}

void write_new_page(User* user) {
    if (user->pageCount >= MAX_PAGES) {
        printf("Page limit reached.\n");
        return;
    }

    Page new_page;
    printf("Enter title: ");
    fgets(new_page.title, MAX_TITLE_SIZE, stdin);
    new_page.title[strcspn(new_page.title, "\n")] = 0; // Remove newline

    printf("Enter text (end with ~): ");
    scanf("%[^~]", new_page.text);
    getchar(); // Consume the '~' character

    user->pages[user->pageCount++] = new_page;
}

void save_pages(const User* user) {
    char filename[MAX_USER_SIZE + sizeof(FILE_EXTENSION)];
    sprintf(filename, "%s%s", user->username, FILE_EXTENSION);

    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return;
    }

    fwrite(&user->pageCount, sizeof(int), 1, file);
    fwrite(user->pages, sizeof(Page), user->pageCount, file);

    fclose(file);
}

void load_pages(User* user) {
    char filename[MAX_USER_SIZE + sizeof(FILE_EXTENSION)];
    sprintf(filename, "%s%s", user->username, FILE_EXTENSION);

    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Failed to open file for reading");
        return;
    }

    fread(&user->pageCount, sizeof(int), 1, file);
    fread(user->pages, sizeof(Page), user->pageCount, file);

    fclose(file);
}

void list_pages(const User* user) {
    for (int i = 0; i < user->pageCount; ++i) {
        printf("Title: %s\n", user->pages[i].title);
    }
}

void search_page_by_title(const User* user, const char* title) {
    for (int i = 0; i < user->pageCount; ++i) {
        if (strcmp(user->pages[i].title, title) == 0) {
            printf("Text: %s\n", user->pages[i].text);
            return;
        }
    }
    printf("Page not found.\n");
}
