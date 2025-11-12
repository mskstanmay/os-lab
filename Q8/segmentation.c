#include <stdio.h>

typedef struct
{
    int base;
    int limit;
} segment;

int main()
{
    int n;
    printf("Enter number of segments: ");
    scanf("%d", &n);

    segment seg_table[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter base address for segment %d: ", i);
        scanf("%d", &seg_table[i].base);
        printf("Enter limit for segment %d: ", i);
        scanf("%d", &seg_table[i].limit);
    }

    int seg_num, offset;

    printf("Enter segment number and offset: ");
    scanf("%d %d", &seg_num, &offset);

    int physical_address = seg_table[seg_num].base + offset;
    printf("Physical Address = base + offset = %d + %d = %d\n",
           seg_table[seg_num].base, offset, physical_address);

    return 0;
}
