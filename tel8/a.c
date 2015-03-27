#include <stdio.h>
#include <stdlib.h>


int main (/* int argc, char const *argv[] */) {
    char c;
    
    while ((c = getchar()) != '\n') {

        if (c >= 'A' && c <= 'Z') {
            if (c <= 'R')
                c = ((c - 'A') / 3) + 2 + '0';

            else if (c == 'S')
                c = '7';

            else if (c >= 'T' && c <= 'V')
                c = '8';

            else
                c = '9';
        }

        printf("%c", c);
    }

    printf("\n");
    
    return 0;
}