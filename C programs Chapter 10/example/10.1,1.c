#include <stdio.h>

struct s_type {
    int i;
    char ch;
    double d;
    char str[80];
} s;

int main() {
    printf("Enter an integer : ");
    scanf("%d", &s.i);
    getchar(); // preventing taking enter as a character
    printf("Enter a character : ");
    scanf("%c", &s.ch);
    printf("Enter a floating point number : ");
    scanf("%lf", &s.d);
    printf("Enter a string : ");
    scanf("%s", s.str);

    printf("%d\n%c\n%lf\n%s\n", s.i, s.ch, s.d, s.str);

    return 0;
}