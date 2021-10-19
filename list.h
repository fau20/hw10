struct spend {
  char food[100];
  int price;
  struct spend *next;
};

void print_spend(struct spend *f);
void print_list(struct spend *s);
struct spend * insert_front(struct spend *front, char *c, int i);
struct spend * free_list(struct spend *s);
struct spend * remove_node(struct spend *front, int data);
