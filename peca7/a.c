#include <stdio.h>
#include <stdlib.h>

int main (/* int argc, char const *argv[] */) {
    int a[1002];

    int n, i, x;

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        a[i] = 0;

    for (i = 1; i <= (n - 1); i++) {
        scanf("%d", &x);
        a[x] = 1;
    }

    for (i = 1; i <= n; i++)
        if (a[i] == 0) {
            printf("%d\n", i);
            break;
        }
    
    return 0;
}