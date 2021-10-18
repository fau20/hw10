#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct spend {
  char food[100];
  int price;
  struct spend *next;
};

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

int main() {
  struct spend *pizza = make_spend("pizza", 4);
  struct spend *burger = insert_front(pizza, "burger", 6);
  struct spend *fries = insert_front(burger, "fries", 2);

  print_list(fries);
  free_list(fries);

  return 0;
}
