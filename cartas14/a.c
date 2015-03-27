#include <stdio.h>

int main () {

    int x, y, o = -1, t, i;
    char *a = "CDN";

    scanf("%d", &x);

    for (i = 1; i < 5; i++) {
        scanf("%d", &y);

        if (y >= x)
            t = 0;

        else
            t = 1;

        if (o == -1)
            o = t;

        else if (t != o) {
            o = 2;
            break;
        }

        x = y;
    }

    printf("%c\n", a[o]);

    return 0;
}