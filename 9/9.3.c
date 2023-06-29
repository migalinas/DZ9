#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int strings_in_pages = atoi(argv[2]);
    int length = atoi(argv[4]);
    int current_string = 0;
    char c;
    int buffer_string;

    FILE *file;

    file = fopen("file.txt", "r");

    int page_number = 1;
    do {
        printf(" -- Page %d --\n", page_number);
        buffer_string = current_string;
        current_string = 0;
        while (current_string < strings_in_pages) {
            printf("%d: ", current_string + 1);
            int current_length = 1;
            if (c != '\n' && buffer_string + 1 >= strings_in_pages) {
                putchar(c);
                current_length += 1;
            }
            while ((c = fgetc(file)) != '\n' && current_length <= length) {
                putchar(c);
                ++current_length;
            }
            putchar('\n');
            current_string += 1;
        }
        ++page_number;

    } while (c != EOF);
}