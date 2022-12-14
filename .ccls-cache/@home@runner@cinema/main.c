#include "lists.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

//создание главного списка по файлу
list scan(FILE *in) {

  list l;
  l.size = 0;
  l.head = NULL;
  l.tail = NULL;

  char temp[100];
  while (fgets(temp, 100, in) != NULL) {

    film *f = (film *)malloc(sizeof(film));

    strcpy(f->title, temp);

    fgets(temp, 100, in);
    f->year = atoi(temp);

    fgets(temp, 100, in);
    strcpy(f->country, temp);

    fgets(temp, 100, in);
    strcpy(f->genre, temp);

    fgets(temp, 100, in);
    f->rating = atof(temp);

    push(&l, f);
  }
  return l;
}

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