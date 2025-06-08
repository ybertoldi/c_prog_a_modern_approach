
#define NAME_LEN 25
#define MAX_PARTS 100
struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} inventory[MAX_PARTS];

double integrate(double (*f)(double), double a, double b);

int compare_parts(const void *p, const void *q) {
  const struct part *p1 = p;
  const struct part *q1 = q;
  if (p1->number < q1->number)
    return -1;
  else if (p1->number == q1->number)
    return 0;
  else
    return 1;
}

int compare_parts_concise(const void *p, const void *q) {
  if (((struct part *)p)->number < ((struct part *)q)->number) 
    return -1;
  else if ( ((struct part*)p)->number == ((struct part*)q)->number)
    return 0;
  else
    return 1;
}
