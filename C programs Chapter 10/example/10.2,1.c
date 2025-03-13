#include <stdio.h>
#include <string.h>

struct s_type {
    int i;
    char str[80];
} s, *p;

int main() {
    p = &s;
    s.i = 11;
    p->i = 10;
    strcpy(s.str, "hello");

    printf("%d %d %s %s\n", s.i, p->i, s.str, p->str);
}
