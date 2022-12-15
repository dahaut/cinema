#include "lists.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//добавление фильма в начало
void push(list *l, film *f) {
  if (l->size > 0) {
    f->next = l->head;
    f->prev = l->tail;
    l->head->prev = f;
    l->tail->next = f;
    l->head = f;
    l->size++;
  } else {
    l->head = f;
    l->tail = f;
    f->next = f;
    f->prev = f;
    l->size++;
  }
}

//добавление фильма перед фильмом n
void insert(list *l, film *f, int n) {
  if (n == 0)
    push(l, f);
  else if (n > 0 && n <= l->size) {

    film *current = l->head;
    int i = 0;
    while (i < n - 1) {
      current = current->next;
      i++;
    }
    f->next = current->next;
    f->prev = current;
    current->next = f;
    l->size++;
  }
}

//удаление фильма n с возвратом
film film_delete(list *l, int n) {
  film f;
  if (n < l->size && n > 0) {
    film *current = l->head;
    int i = 0;
    while (i < n - 1) {
      current = current->next;
      i++;
    }
    f = *current->next;
    film *temp = current->next->next;
    free(current->next);
    current->next = temp;
    current->next->prev = current;
    l->size--;
  } else if (n == 0) {
    f = *l->head;
    film *temp1 = l->head->next;
    film *temp2 = l->head->prev;
    free(l->head);
    l->head = temp1;
    l->head->prev = temp2;
    l->size--;
  }
  return f;
}

//удаление фильма с начала с возвратом
film pop(list *l) {
  film f;
  if (l->size < 1) {

  } else if (l->size == 1) {
    f = *l->head;
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
  } else {
    f = film_delete(l, 0);
  }
  return f;
}

//перемещение фильма из a в b
void move(list *a, list *b) {
  film *f = (film *)malloc(sizeof(film));
  *f = pop(a);
  push(b, f);
}

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

void filmprint(film f) {
  printf("%s", f.title);
  printf("%d\n", f.year);
  printf("%s", f.country);
  printf("%s", f.genre);
  printf("%.1f\n", f.rating);
}

void filmfprint(FILE *out, film f) {
  fprintf(out, "%s", f.title);
  fprintf(out, "%d\n", f.year);
  fprintf(out, "%s", f.country);
  fprintf(out, "%s", f.genre);
  fprintf(out, "%.1f\n", f.rating);
}

void listprint(list l) {
  film *current = l.head;
  int i = 0;
  while (i < l.size) {
    filmprint(*current);
    current = current->next;
    i++;
  }
}

void listfprint(FILE *out, list l) {
  film *current = l.head;
  int i = 0;
  while (i < l.size) {
    filmfprint(out, *current);
    current = current->next;
    i++;
  }
}