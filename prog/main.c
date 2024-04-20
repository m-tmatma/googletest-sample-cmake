#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 1;
    if ((num % 2) == 0) {
        printf("%d is even.\n", num);
    }
    else {
        printf("%d is odd.\n", num);
    }
    return 0;
}
