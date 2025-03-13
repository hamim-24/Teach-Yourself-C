#include <stdio.h>

struct s_type {
    int i;
    double d;
} s;

struct s_type f();

int main() {
    struct s_type var;
    var = f();
    printf("%d %lf\n", var.i, var.d);

    return 0;
}

struct s_type f() {
    struct s_type temp;
    temp.d = 10.12;
    temp.i = 10;
    return temp;
}