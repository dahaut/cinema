#include <stdio.h>

typedef struct film {
  char title[100];
  int year;
  char country[100];
  char genre[100];
  float rating;
  struct film *next;
  struct film *prev;
} film;

typedef struct list {
  int size;
  film *head;
  film *tail;
} list;


extern void push(list *l, film *f);
extern void insert(list *l, film *f, int n);
extern film film_delete(list *l, int n);
extern film pop(list *l);
extern void move(list *a, list *b);
extern list scan(FILE *in);
extern void filmprint(film f);
extern void filmfprint(FILE *out, film f);
extern void listprint(list l);
extern void listfprint(FILE *out, list l);