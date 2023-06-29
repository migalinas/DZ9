#include <stdio.h>
#include <stdlib.h>
#include "9.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("You must write a filename!\n");
        return 1;
    }

    const char *filename = argv[1];
    int n = 5;

    if (argc >= 3) {
        n = atoi(argv[2]);
        if (n <= 0) {
            printf("Incorrect value for N. Default value - 5.\n");
            n = 5;
        }
    }

    tail(filename, n);

    printf("\n");

    return 0;
}