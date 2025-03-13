#include <stdio.h>

struct s_type {
    int i;
    char j;
    int *p;
    double d;
} s;

struct str {

} t;

int main() {
    
    printf("s_type is %lu bytes long\n", sizeof(s));
    
    return 0;
}