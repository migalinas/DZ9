#include <stdio.h>

#ifndef INC_9_9_H
#define INC_9_9_H

typedef struct {
    char* line;
    size_t length;
} Line;

typedef struct {
    Line* lines;
    size_t size;
    size_t capacity;
} LineBuffer;

void initLine(Line* line);
void initLineBuffer(LineBuffer* buffer);
void addLine(LineBuffer* buffer, const char* text, size_t length);
void freeLine(Line* line);
void freeLineBuffer(LineBuffer* buffer);
void tail(const char* filename, int n);
void interleaveLines(FILE *file1, FILE *file2);


#endif //INC_9_9_H
