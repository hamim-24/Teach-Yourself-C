#include <stdio.h>
#include <time.h>

int main() {
    char ch;
    struct tm *systime;
    time_t t;
    t = time(NULL);
    systime = localtime(&t);

    printf("Time : %.2d:%.2d:%.2d\n", systime->tm_hour, systime->tm_min, systime->tm_sec);
    printf("Date : %.2d:%.2d:%.2d\n", systime->tm_mon + 1, systime->tm_mday, systime->tm_year);
    
    return 0;
}