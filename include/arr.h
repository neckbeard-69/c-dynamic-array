#pragma once

#include <stddef.h>

typedef union {
    double d;
    int i;
    float f;
    char c;
} Data;

typedef struct arr Array;

struct arr {
    Data *data;
    size_t size;
    size_t elemSize;
    size_t capacity;
    void (*Push)(Array *arr, void *value);
    /*void (*Pop)(Array *arr);*/
    /*Data (*Read)(Array *arr, int index);*/
};

Array NewArray(size_t elementSize, size_t initialCapacity);
void ResizeArray(Array *arr);
Data Read(Array *arr, int index);
void FreeArray(Array *arr);
void Push(Array *arr, void *value);
void Pop(Array *arr);
