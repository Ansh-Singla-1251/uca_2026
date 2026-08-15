#include <stdio.h>
#include <string.h>

typedef int (*Compare)(const void *, const void *);

/* Swap two generic elements */
void swap(void *a, void *b, size_t size) {
    char temp[size];

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

/* Heapify-down */
void heapify(void *arr, int n, int i, size_t size, Compare compare) {

    while (1) {
        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n &&
            compare((char *)arr + left * size,
                    (char *)arr + largest * size) > 0) {
            largest = left;
        }

        if (right < n &&
            compare((char *)arr + right * size,
                    (char *)arr + largest * size) > 0) {
            largest = right;
        }

        if (largest == i)
            break;

        swap((char *)arr + i * size,
             (char *)arr + largest * size,
             size);

        i = largest;
    }
}

/* Generic Heap Sort */
void heapSort(void *arr, int n, size_t size, Compare compare) {

    /* Build max heap */
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, size, compare);
    }

    /* Repeatedly remove maximum */
    for (int i = n - 1; i > 0; i--) {

        swap((char *)arr,
             (char *)arr + i * size,
             size);

        heapify(arr, i, 0, size, compare);
    }
}

/* Comparator for integers */
int compareInt(const void *a, const void *b) {

    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x > y)
        return 1;

    if (x < y)
        return -1;

    return 0;
}

int main() {

    int arr[] = {5, 3, 8, 4, 1, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n, sizeof(int), compareInt);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}