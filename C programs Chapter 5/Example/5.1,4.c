#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int item[100];
    int a, b, t;
    int count;

    // read in numbers
    printf("How many numbers?\n");
    scanf("%d", &count);

    for (a = 0; a < count; a++)
        scanf("%d", &item[a]);

    // now sort them using a bubble sort
    for (a = 0; a < count; ++a)
    {
        for (b = count - 1; b >= a; --b)
        {
            // compare adjacent element
            if (item[b - 1] > item[b])
            {
                // exchange element
                t = item[b - 1];
                item[b - 1] = item[b];
                item[b] = t;
            }
        }
    }

    // display sorted list
    for (t = 0; t < count; t++)
    {
        printf("\n%d", item[t]);
    }

    return 0;
}
