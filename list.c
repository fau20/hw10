#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


void print_spend(struct spend *f) {
  printf("food: %s\tcost: %d\n", f->food, f->price);
}

struct spend * make_spend(char *f, int r) {
  struct spend *n = malloc(sizeof(struct spend));

  strncpy(n->food, f, sizeof(n->food));
  n->price = r;

  return n;
}

void print_list(struct spend *s) {
  while(s) {
    printf("food: %s\tcost: %d\n", s->food, s->price);
    s = s->next;
  }
}

struct spend * insert_front(struct spend *front, char *c, int i) {
  struct spend *p = make_spend(c, i);
  p->next = front;
  return p;
}

struct spend * free_list(struct spend *s) {
  struct spend *d = s;
  while(s) {
    struct spend *b = s;
    s = s->next;
    free(b);
  }
  return d;
}

struct spend * remove_node(struct spend *front, int data) {
  if (front == NULL) return NULL;
  if(front->price == data) front = front->next;

  struct spend * first = front;
  while(first->next) {
  if(first->next->price == data) {
    first->next = first->next->next;
    return front;
  }
  else {
    first = first-> next;
  }
  }
  return front;
}
