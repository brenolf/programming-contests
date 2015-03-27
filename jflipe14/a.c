#include <stdio.h>
#include <stdlib.h>

int main (/* int argc, char const *argv[] */) {
    int p, r;

    const char a[2][2] = {
        {'C', 'C'},
        {'B', 'A'}
    };

    scanf("%d %d", &p, &r);

    printf("%c\n", a[p][r]);
    
    return 0;
}