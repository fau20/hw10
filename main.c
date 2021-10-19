#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main() {
  struct spend *list = NULL;
  list = insert_front(list, "pizza", 4);
  list = insert_front(list, "burger", 6);
  list = insert_front(list, "fries", 2);

  printf("list:\n");
  print_list(list);
  list = remove_node(list, 4);
  printf("list after removing node:\n");
  print_list(list);
  free_list(list);

  return 0;
}
