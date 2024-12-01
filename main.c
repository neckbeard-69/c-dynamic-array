#include "include/arr.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    Array arr = NewArray(sizeof(Data), 4);

    int val1 = 5;
    int val2 = 2;
    float val3 = 4.3;
    arr.Push(&arr, &val1);
    arr.Push(&arr, &val2);
    arr.Push(&arr, &val3);
    for (int i = 0; i <= arr.size; ++i) {
        printf("%d\n", arr.data[i]);
    }

    return 0;
}
