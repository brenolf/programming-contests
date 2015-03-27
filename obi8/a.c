#include <stdio.h>

int main () {

    int n, p, x, y, i, r = 0;

    scanf("%d %d", &n, &p);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        r += ((x + y) >= p);
    }

    printf("%d\n", r);

    return 0;
}