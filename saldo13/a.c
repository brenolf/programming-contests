#include <stdio.h>
#include <stdlib.h>

int main (/* int argc, char const *argv[] */) {
    int n, s, i, m, o;

    scanf ("%d %d", &n, &s);

    m = s;

    for (i = 0; i < n; i++) {
        scanf("%d", &o);

        s += o;

        if (m > s)
            m = s;
    }

    printf("%d\n", m);
    
    return 0;
}