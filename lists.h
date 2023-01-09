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

typedef struct filmlist {
  int size;
  film *head;
  film *tail;
} filmlist;

extern void push(filmlist *l, film *f);
extern void pushback(filmlist *l, film *f);
extern void insert(filmlist *l, film *f, int n);
extern film filmdelete(filmlist *l, int n);
extern film pop(filmlist *l);
extern void move(filmlist *a, filmlist *b);
extern filmlist scan(FILE *in);
extern void filmprint(film f);
extern void filmfprint(FILE *out, film f);
extern void listprint(filmlist l);
extern void listfprint(FILE *out, filmlist l);