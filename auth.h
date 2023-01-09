#include <stdio.h>

typedef struct user{
  char login[20];
  char password[20];
  char cardNumber[16];
  int favorites,isAdmin;
  struct user *next;
} user;

typedef struct userlist {
  int size;
  user *head;
  user *tail;
} userlist;

void reg(char login, char password, char cardNumber);
void login(char login, char password);