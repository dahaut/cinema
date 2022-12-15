#include "lists.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *films = fopen("films.txt", "r");

  list whole = scan(films);

  printf("%s", whole.head->title);
  printf("%d\n", whole.head->year);
  printf("%s", whole.head->country);
  printf("%s", whole.head->genre);
  printf("%.1f\n", whole.head->rating);

  fclose(films);
  return 0;
}