#include <stdio.h>

struct Process{
int id, at,bt,ct,wt,tat;
};

int main(){
  int n;
  printf("Enter no. of processes: ");
  scanf("%d",&n);

struct Process p[n];
printf("Enter arrival times: ");
for(int i =0;i<n;i++){
  scanf("%d",&p[i].at);
  p[i].id=i+1;
}
printf("Enter burst times: ");
for(int i =0;i<n;i++){
  scanf("%d",&p[i].bt);
 }

for(int i =0;i<n-1;i++){
for(int j =i+1;j<n;j++){
if(p[i].at > p[j].at){
  struct Process t = p[i];
  p[i]=p[j];
  p[j] = t;
}

}

}

int time = 0;

for(int i =0; i<n;i++){
if(time< p[i].at){
time = p[i].at;
}
time +=p[i].bt;
p[i].ct = time;
p[i].tat = p[i].ct - p[i].at;
p[i].wt = p[i].tat - p[i].bt;
}

float avg_wt =0,avg_tat=0;

printf("\nProcess\t\tAT\tBT\tCT\tTAT\tWT\n");
for(int i =0;i<n;i++){
printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
avg_wt += p[i].wt;
avg_tat += p[i].tat;
}

printf("\nAvg waiting time: %.2f",avg_wt/n);
printf("\nAvg turnaround time: %.2f\n",avg_tat/n);

return 0;}
