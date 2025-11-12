#include <stdio.h>

struct Process {
    int pid;
    int at, bt, ct, pr, tat, wt, done;
};

int main() {
    int n;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter AT,BT,Priority for process %d: ", i + 1);
        scanf("%d%d%d", &p[i].at, &p[i].bt, &p[i].pr);
        p[i].done = 0;
    }
    int t = 0, completed = 0;
    float totalTAT = 0, totalWT = 0;

    printf("\nGantt chart: ");

    while (completed < n) {
        int idx = -1, highest = 100000; 
        for (int i = 0; i < n; i++) {
            if (p[i].at <= t && p[i].done == 0) {
                if (p[i].pr < highest || (p[i].pr == highest && p[i].at < p[idx].at)) {
                    highest = p[i].pr;
                    idx = i;
                }
            }
        }
        if (idx != -1) {
            printf("|P%d ", p[idx].pid);
            t = t < p[idx].at ? p[idx].at : t;
            p[idx].ct = t + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            totalTAT += p[idx].tat;
            totalWT += p[idx].wt;
            t += p[idx].bt;
            p[idx].done = 1;
            completed++;
        } else {
            printf("|Idle ");
            t++;
        }
    }
    printf("|\n");

    printf("PID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].pr, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("Average TAT = %.2f\n", totalTAT / n);
    printf("Average WT = %.2f\n", totalWT / n);
    return 0;
}

