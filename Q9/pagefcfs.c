#include<stdio.h>
#define MAX_FRAMES 10
#define MAX_PAGES 30

int main() {
    int n, f, pages[MAX_PAGES], frames[MAX_FRAMES];
    int i, j, k = 0, flag, fault = 0;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nReference String\tFrames\n");
    for(i = 0; i < n; i++) {
        flag = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) { 
            frames[k] = pages[i];
            k = (k + 1) % f; 
            fault++;
        }

       
        printf("%d\t\t", pages[i]);
        for(j = 0; j < f; j++) {
            if(frames[j] == -1)
                printf(" - ");
            else
                printf("%d ", frames[j]);
        }
        if(flag == 0)
            printf(" Fault");
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", fault);
    return 0;
}

