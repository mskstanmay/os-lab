#include <stdio.h>
#include <limits.h>

struct Process
{
  int id, at, bt, ct, wt, tat, done;
};

int main()
{
  int n, completed = 0, time = 0;
  printf("Enter no. of processes: ");
  scanf("%d", &n);

  struct Process p[n];
  printf("Enter arrival times: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &p[i].at);
    p[i].id = i + 1;
    p[i].done = 0;
  }
  printf("Enter burst times: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &p[i].bt);
  }

  while (completed < n)
  {
    int idx = -1;
    int min_bt = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      if (!p[i].done && p[i].at <= time)
      {
        if (p[i].bt < min_bt)
        {
          min_bt = p[i].bt;
          idx = i;
        }
      }
    }
    if (idx == -1)
    {
      time++;
    }
    else
    {
      time += p[idx].bt;
      p[idx].ct = time;
      p[idx].tat = p[idx].ct - p[idx].at;
      p[idx].wt = p[idx].tat - p[idx].bt;
      p[idx].done = 1;
      completed++;
    }
  }

  float avg_wt = 0, avg_tat = 0;

  printf("\nProcess\t\tAT\tBT\tCT\tTAT\tWT\n");
  for (int i = 0; i < n; i++)
  {
    printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    avg_wt += p[i].wt;
    avg_tat += p[i].tat;
  }

  printf("\nAvg waiting time: %.2f", avg_wt / n);
  printf("\nAvg turnaround time: %.2f\n", avg_tat / n);

  return 0;
}
