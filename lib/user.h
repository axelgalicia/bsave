#ifndef USER_H
#define USER_H

#include "types.h"

User load_user(char *email, char *password);
User save_user(User user);
void delete_user(User user);

#endif