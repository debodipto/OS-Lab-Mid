#include <stdio.h>
#include <stdlib.h>

int abs_diff(int a, int b) {
    return a > b ? a - b : b - a;
}

int main() {
    int req[] = {137,240,179,75,118,29,15,51};
    int n = 8, head = 55, total_seek = 0, done[8] = {0};

    for (int i = 0; i < n; i++) {
        int min = 9999, idx = -1;
        for (int j = 0; j < n; j++) {
            if (!done[j] && abs_diff(head, req[j]) < min) {
                min = abs_diff(head, req[j]);
                idx = j;
            }
        }
        total_seek += abs_diff(head, req[idx]);
        head = req[idx];
        done[idx] = 1;
    }

    printf("Total seek operations: %d\n", total_seek);
    return 0;
}
