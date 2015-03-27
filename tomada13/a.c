#include <stdio.h>
#include <stdlib.h>

int main (/* int argc, char const *argv[] */) {
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d\n", (a + b + c + d) - 3);
    
    return 0;
}