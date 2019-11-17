#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int a[500000];

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
    int n ;
    pFile = fopen("test4.txt","r");
    fscanf(pFile,"%d",&n);
    for (int i = 0 ; i< n; i++)
        fscanf(pFile,"%d",&a[i]);
    MPI_Init(&argc, &argv);
    int l, r;
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int parent = ((rank + 1) / 2) - 1;
    if (rank % 2 != 0 && rank + 1 >= world_size) {
        MPI_Finalize();
        return 0;
    }
    if (rank == 0) {
        l = 0;
        r = n - 1;
    } else {
        MPI_Recv(&l, 1, MPI_INT, parent, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&r, 1, MPI_INT, parent, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    if (l == r || (2 * rank + 2 >= world_size)) {
        mergeSort(l, r);
    } else {
        int mid = (l + r) / 2, mid2 = mid + 1;
        int left = rank * 2 + 1, right = left + 1;
        MPI_Send(&l, 1, MPI_INT, left, 0, MPI_COMM_WORLD);
        MPI_Send(&mid, 1, MPI_INT, left, 0, MPI_COMM_WORLD);
        MPI_Send(&mid2, 1, MPI_INT, right, 0, MPI_COMM_WORLD);
        MPI_Send(&r, 1, MPI_INT, right, 0, MPI_COMM_WORLD);
        int n1 = mid - l + 1, n2 = r - mid2 + 1;
        int b[n1], c[n2];
        for (int i = 0; i < n1; i++)
            MPI_Recv(&b[i], 1, MPI_INT, left, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for (int i = 0; i < n2; i++)
            MPI_Recv(&c[i], 1, MPI_INT, right, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        merge(l, r, b, c);
    }
    if (rank != 0)
        for (int i = l; i <= r; i++)
            MPI_Send(&a[i], 1, MPI_INT, parent, 0, MPI_COMM_WORLD);
    else
        for (int i = l; i <= r; i++)
            printf("%d ", a[i]);
    MPI_Finalize();

}
