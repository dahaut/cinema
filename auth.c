#include "auth.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void takeInput(char ch[50]){
  fgets(ch, 50, stdin);
  ch[strlen(ch) - 1] = 0;
}

