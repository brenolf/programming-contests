#include <stdio.h>
#include <stdlib.h>

int main (/* int argc, char const *argv[] */) {
    int n, i, x, y, a, b, r = 0;

    scanf ("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d", &x, &y, &a, &b);

        r += (x - a) * (x - a) + (y - b) * (y - b);
    }   

    printf("%d\n", r);
    
    return 0;
}