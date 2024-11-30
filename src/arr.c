#include "../include/arr.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Array NewArray(size_t elementSize, size_t initialSize) {
    Array arr;
    arr.data = (Data *)malloc(elementSize * initialSize);
    if (arr.data == NULL) {
        perror("Failed to allocate the array");
        exit(EXIT_FAILURE);
    }
    arr.elemSize = elementSize;
    arr.capacity = initialSize;
    arr.size = 0;
    arr.Push = Push;
    /*arr.Pop = Pop;*/
    /*arr.Read = Read;*/
    return arr;
}

void ResizeArray(Array *arr) {
    arr->capacity *= 2;
    arr->data = realloc(arr->data, arr->elemSize * arr->capacity);
    if (arr->data == NULL) {
        perror("Failed to reallocate the array");
        exit(EXIT_FAILURE);
    }
}

void Push(Array *arr, void *val) {
    Data value = *(Data *)val;
    if (arr->size > 0 &&
        !__builtin_types_compatible_p(typeof(arr->data[0]), typeof(value))) {
        fprintf(stderr, "%s\n", "error: type incompatible");
        exit(EXIT_FAILURE);
    }
    if (arr->size == arr->capacity) {
        ResizeArray(arr);
    }
    arr->data[arr->size] = value;
    arr->size++;
}
