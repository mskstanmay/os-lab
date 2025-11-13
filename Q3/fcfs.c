#include <stdio.h>

typedef struct 
{
  int id, at, bt, ct, wt, tat;
} P ;

int main()
{
  int n;
  printf("Enter no. of processes: ");
  scanf("%d", &n);

  P p[n];

  printf("Enter arrival times: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &p[i].at), p[i].id = i + 1;

  printf("Enter burst times: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &p[i].bt);

  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (p[i].at > p[j].at)
      {
        P t = p[i];
        p[i] = p[j];
        p[j] = t;
      }

  int time = 0;
  float avg_wt = 0, avg_tat = 0;

  for (int i = 0; i < n; i++)
  {
    if (time < p[i].at)
      time = p[i].at;
    time += p[i].bt;

    p[i].ct = time;
    p[i].tat = time - p[i].at;
    p[i].wt = p[i].tat - p[i].bt;

    avg_wt += p[i].wt;
    avg_tat += p[i].tat;
  }

  printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
  for (int i = 0; i < n; i++)
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
           p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);

  printf("\nAvg WT = %.2f\nAvg TAT = %.2f\n", avg_wt / n, avg_tat / n);
}
