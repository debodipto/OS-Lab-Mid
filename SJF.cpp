#include <stdio.h>

struct Process {
    int id, at, bt, ct, wt, tat, done;
};

int main() {
    struct Process p[5] = {
        {1, 2, 4},
        {2, 10, 1},
        {3, 3, 2},
        {4, 2, 5},
        {5, 0, 5}
    };

    int time = 0, completed = 0;
    while (completed < 5) {
        int idx = -1, min_bt = 999;
        for (int i = 0; i < 5; i++) {
            if (!p[i].done && p[i].at <= time && p[i].bt < min_bt) {
                min_bt = p[i].bt;
                idx = i;
            }
        }
        if (idx == -1) {
            time++;
        } else {
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].done = 1;
            completed++;
        }
    }

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < 5; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}
