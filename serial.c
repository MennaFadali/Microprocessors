#include <stdio.h>
#include <stdlib.h>

int a[50000];

void merge(int start, int end, int *left, int *right) {
    int l = 0, r = 0;
    int mid = (start + end) / 2;
    int lenLeft = mid - start + 1;
    int lenRight = end - mid;
    for (int i = start; i <= end; i++) {
        if (r == lenRight || (l < lenLeft && left[l] <= right[r])) {
            a[i] = left[l++];
        } else
            a[i] = right[r++];
    }
}

void mergeSort(int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int left[mid - l + 1], right[r - mid];
    for (int i = l; i <= mid; i++)
        left[i - l] = a[i];
    for (int i = mid + 1; i <= r; i++)
        right[i - (mid + 1)] = a[i];
    merge(l, r, left, right);
}

int main(int argc, char **argv) {
    FILE * pFile;
    int n;
    pFile = fopen("test1.txt", "r");
    fscanf(pFile, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(pFile, "%d", &a[i]);

    }

    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

}
