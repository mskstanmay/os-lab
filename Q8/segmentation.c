#include <stdio.h>

typedef struct {
    int base;
    int limit;
} segment;

int main() {
    int n;
    printf("Enter number of segments: ");
    scanf("%d", &n);

    segment seg_table[n];

    for (int i = 0; i < n; i++) {
        printf("Enter base address for segment %d: ", i);
        scanf("%d", &seg_table[i].base);
        printf("Enter limit for segment %d: ", i);
        scanf("%d", &seg_table[i].limit);
    }

    int seg_num, offset;

    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        printf("Enter segment number and offset: ");
        scanf("%d %d", &seg_num, &offset);

        if (seg_num < 0 || seg_num >= n) {
            printf("Invalid segment number\n");
        } else if (offset < 0 || offset >= seg_table[seg_num].limit) {
            printf("Invalid offset: exceeds segment limit\n");
        } else {
            int physical_address = seg_table[seg_num].base + offset;
            printf("Physical Address = base + offset = %d + %d = %d\n",
                   seg_table[seg_num].base, offset, physical_address);
        }

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &choice);
    }


}

