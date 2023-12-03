#include <stdio.h>
#include <stdlib.h>

#include "configs.h"
#include "types.h"
#include "diary.h"
#include "page.h"

void trigger_option(int option)
{
  switch (option)
  {
  case 1:
    write_new_page();
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    break;
  }
}

void write_new_page()
{
  Page page;

  printf("\nTitle:\t");
  scanf("%s", &page.title);

  printf("\n\nText:\n\n");
  scanf("%[^~]s", &page.text);

  Page pages[1] = {0, 1000, "title0", "Test0"};
  User user = {"axelgalicia", "pass", &pages};

  save_page(user, page);
}

void start_menu()
{
  // system("clear");
  // system("gnome-terminal");
  printf("\n\n");
  printf("1. Write a new page\n");
  printf("2. Look for diary page\n");
  printf("3. Exit\n\n");
  printf("Option:");

  int selected_option = 0;

  scanf("%d", &selected_option);
  trigger_option(selected_option);
}
