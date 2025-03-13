#include <stdio.h>

struct s_type {
    int i;
    int j;
} s;

int main() {
    int i = 10;
    s.i = i;
    s.j = 100;
    printf("%d %d %d\n", i, s.i, s.j);
}