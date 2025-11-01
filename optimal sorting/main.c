#include <stdio.h>

extern void sort(int *arr, int n);

int main() {
    int arr[100];
    int n = 0;

    while (n < 100 && scanf("%d", &arr[n]) == 1) n++;

    int original[100];
    for (int i = 0; i < n; i++) {
        original[i] = arr[i];
    }
    sort(arr, n);

    int changed = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != original[i]) changed++;
    }

    return changed;
}
