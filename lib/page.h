#ifndef PAGE_H
#define PAGE_H

#include "types.h"

Page save_page(User user, Page page);
Page read_page(User user, char *title);

#endif