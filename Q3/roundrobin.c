#include <stdio.h>

struct Process {
    int pid;
    int at, bt, rem, wt, ct, tat;
};

int main() {
    int n, tq, t = 0, done = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter AT, BT for process %d: ", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].rem = p[i].bt;
        p[i].wt = p[i].tat = p[i].ct = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int order[100 * n], front = 0, rear = 0;
    int inQueue[n];
    for(int i = 0; i < n; i++) inQueue[i] = 0;

    while(done < n) {
        for(int i = 0; i < n; i++) {
            if(p[i].at <= t && p[i].rem > 0 && !inQueue[i]) {
                order[rear++] = i;
                inQueue[i] = 1;
            }
        }

        if(front == rear) { 
            t++;
            continue;
        }

        int idx = order[front++]; 

        if(p[idx].rem > tq) {
            t += tq;
            p[idx].rem -= tq;
        } else {
            t += p[idx].rem;
            p[idx].rem = 0;
            p[idx].ct = t;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            done++;
        }

        for(int i = 0; i < n; i++) {
            if(p[i].at <= t && p[i].rem > 0 && !inQueue[i]) {
                order[rear++] = i;
                inQueue[i] = 1;
            }
        }

        if(p[idx].rem > 0) {
            order[rear++] = idx; 
        } else {
            inQueue[idx] = 0; 
        }
    }

    float avgwt = 0, avgtat = 0;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        avgwt += p[i].wt;
        avgtat += p[i].tat;
    }

    avgwt /= n;
    avgtat /= n;

    printf("\nAverage Waiting Time = %.2f", avgwt);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat);

    return 0;
}

