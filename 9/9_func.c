#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "9.h"

#define MAX_LINE_LENGTH 256;

void initLine(Line* line) {
    line->length = 0;
    line->line = NULL;
}

void initLineBuffer(LineBuffer* buffer) {
    buffer->lines = NULL;
    buffer->size = 0;
    buffer->capacity = 0;
}

void addLine(LineBuffer* buffer, const char* text, size_t length) {
    if (buffer->size >= buffer->capacity) {
        buffer->capacity = buffer->capacity == 0 ? 1 : buffer->capacity * 2;
        buffer->lines = (Line*)realloc(buffer->lines, buffer->capacity * sizeof(Line));
    }
    Line* line = &(buffer->lines[buffer->size]);
    line->length = length;
    line->line = (char*)malloc((length+1) * sizeof(char));
    strncpy(line->line, text, length);
    line->line[length] = '\0';

    buffer->size++;
}

void freeLine(Line* line) {
    free(line->line);
}

void freeLineBuffer(LineBuffer* buffer) {
    for (size_t i = 0; i < buffer->size; i++) {
        freeLine(&(buffer->lines[i]));
    }
    free(buffer->lines);
}
void tail(const char* filename, int n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file '%s' !\n", filename);
        return;
    }

    LineBuffer buffer;
    initLineBuffer(&buffer);

    char *line = NULL;
    size_t lineLength = 0;
    ssize_t bytesRead;

    while ((bytesRead = getline(&line, &lineLength, file)) != -1)
        addLine(&buffer, line, bytesRead);

    fclose(file);

    free(line);

    int start = buffer.size > n ? buffer.size - n : 0;
    int count = buffer.size > n ? n : buffer.size;

    for(size_t i = start; i < start + count; i++)
        printf("%s", buffer.lines[i].line);

    freeLineBuffer(&buffer);
}

void interleaveLines(FILE *file1, FILE *file2) {
    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];

    while (!feof(file1) || !feof(file2)) {
        if (fgets(line1, sizeof(line1), file1) != NULL) {
            printf("%s", line1);
        }

        if (fgets(line2, sizeof(line2), file2) != NULL) {
            printf("%s", line2);
        }
    }
}
