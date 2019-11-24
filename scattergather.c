#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int a[500000];

void merge(int start, int end, int *left, int *right, int lenLeft, int lenRight, int *arr) {
    int l = 0, r = 0;
    for (int i = start; i <= end; i++) {
        if (r == lenRight || (l < lenLeft && left[l] <= right[r])) {
            arr[i] = left[l++];
        } else
            arr[i] = right[r++];
    }
}

void mergeSort(int l, int r, int *arr) {
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(l, mid, arr);
    mergeSort(mid + 1, r, arr);
    int left[mid - l + 1], right[r - mid];
    for (int i = l; i <= mid; i++)
        left[i - l] = arr[i];
    for (int i = mid + 1; i <= r; i++)
        right[i - (mid + 1)] = arr[i];
    merge(l, r, left, right, mid - l + 1, r - mid, arr);
}

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    FILE *pFile;
    int n;
    pFile = fopen("test1.txt", "r");
    fscanf(pFile, "%d", &n);
    if (rank == 0) {
        for (int i = 0; i < n; i++)
            fscanf(pFile, "%d", &a[i]);
    }
    int size = n / world_size;
    int receive[size];
    MPI_Scatter(a, size, MPI_INT, receive, size, MPI_INT, 0, MPI_COMM_WORLD);
    mergeSort(0, size - 1, receive);
    MPI_Gather(receive, size, MPI_INT, a, size, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        int l = n - n % world_size, r = n - 1;
        if (l < r) mergeSort(l, r, a);
        for (int i = 0; i < world_size; i++) {
            int m = size * (i + 1);
            int left[m];
            int mm = size;
            if (i == world_size - 1) mm = n % world_size;
            if (mm == 0) break;
            int right[mm];
            for (int j = 0; j < m; j++)
                left[j] = a[j];
            for (int j = m; j < m + mm; j++)
                right[j - m] = a[j];
            merge(0, m + mm - 1, left, right, m, mm, a);
        }
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
    }
    MPI_Finalize();

}
