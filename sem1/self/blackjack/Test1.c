#define _DEFAULT_SOURCE
#include <stdlib.h>

#include <stdio.h>
#include <time.h>

int main(void)
{
    srandom(time(NULL));
    int e = random();
    printf("%d\n", e%52);
    printf("%d\n", e);
    printf("%lu\n", random());
}