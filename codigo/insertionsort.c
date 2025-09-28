#include "base.h"
#include <stdio.h>

void sort(int a[], size_t n) {
    for (size_t i = 1; i < n; ++i) {
        int key = a[i];
        ssize_t j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
