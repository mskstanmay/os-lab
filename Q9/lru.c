#include <stdio.h>
int findlru(int time[], int f){
    int min = time[0], pos = 0;
    for(int i = 1; i < f; i++){
        if(time[i] < min){
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main(){
    int n, f, pages[30], frames[10], time[10];
    int fault = 0, counter = 0, i, j, pos, flag1, flag2;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++){
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nReference String\tFrames\n");
    for(i = 0; i < n; i++){
        flag1 = flag2 = 0;
        for(j = 0; j < f; j++){
            if(frames[j] == pages[i]){
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }
        if(flag1 == 0){
            for(j = 0; j < f; j++){
                if(frames[j] == -1){
                    counter++;
                    fault++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        if(flag2 == 0){
            pos = findlru(time, f);
            counter++;
            fault++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        printf("%d\t\t", pages[i]);
        for(j = 0; j < f; j++){
            if(frames[j] == -1)
                printf(" - ");
            else
                printf("%d ", frames[j]);
        }
        if(flag1 == 0)
            printf(" Fault");
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", fault);
}

