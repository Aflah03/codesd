#include<stdio.h>

typedef struct {
    int row, col, value;
} entry;

int convert_to_tuple(int A[][3], int r, int c, entry tuple[]) {
    tuple[0].col = c;
    tuple[0].row = r;
    tuple[0].value = 0;

    int indx = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (A[i][j] != 0) {
                indx++;
                tuple[indx].col = j;
                tuple[indx].row = i;
                tuple[indx].value = A[i][j];
            }
        }
    }
    tuple[0].value = indx;  // Total count of non-zero elements
    return indx;
}

int add_tuple(entry t1[], entry t2[], entry result[]) {
    int ind1 = 1, ind2 = 1;
    int t1Max = t1[0].value;
    int t2Max = t2[0].value;
    int res = 1;

    result[0].row = t1[0].row;  // Dimensions for the resulting matrix
    result[0].col = t1[0].col;

    while (ind1 <= t1Max && ind2 <= t2Max) {
        if (t1[ind1].row == t2[ind2].row && t1[ind1].col == t2[ind2].col) {
            result[res].col = t1[ind1].col;
            result[res].row = t1[ind1].row;
            result[res].value = t1[ind1].value + t2[ind2].value;
            ind1++;
            ind2++;
            res++;
        } else if ((t1[ind1].row == t2[ind2].row && t1[ind1].col < t2[ind2].col) || (t1[ind1].row < t2[ind2].row)) {
            result[res++] = t1[ind1++];
        } else {
            result[res++] = t2[ind2++];
        }
    }

    while (ind1 <= t1Max) {
        result[res++] = t1[ind1++];
    }
    while (ind2 <= t2Max) {
        result[res++] = t2[ind2++];
    }

    result[0].value = res - 1;  // Update result count (total non-zero entries)
    return result[0].value;
}

void print_tuple(entry tuple[], int size) {
    printf("Tuple representation (row, col, value):\n");
    for (int i = 1; i <= size; i++) {
        printf("(%d, %d, %d)\n", tuple[i].row, tuple[i].col, tuple[i].value);
    }
}

int main() {
    int A[][3] = {
        {0, 0, 3},
        {4, 2, 0},
        {0, 5, 6}
    };
    int B[][3] = {
        {0, 9, 1},
        {0, 0, 0},
        {7, 0, 0}
    };

    entry tuple1[30];
    entry tuple2[30];
    entry sum[30];

    int x1 = convert_to_tuple(A, 3, 3, tuple1);
    printf("Matrix A in tuple form:\n");
    print_tuple(tuple1, x1);

    int x2 = convert_to_tuple(B, 3, 3, tuple2);
    printf("Matrix B in tuple form:\n");
    print_tuple(tuple2, x2);

    printf("The sum of A and B in tuple form:\n");
    int res = add_tuple(tuple1, tuple2, sum);
    print_tuple(sum, res);

    return 0;
}

