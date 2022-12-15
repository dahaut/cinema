#include "lists.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *films = fopen("films.txt", "r");

  list whole = scan(films);

  listprint(whole);

  fclose(films);
  return 0;
}