#include <stdio.h>

int main() {
    int page_size, num_pages, num_frames;
    int page_table[50];
    int logical_address, page_number, offset, physical_address;

    printf("Enter page size (in bytes): ");
    scanf("%d", &page_size);

    printf("Enter number of logical pages: ");
    scanf("%d", &num_pages);

    printf("Enter number of physical frames: ");
    scanf("%d", &num_frames);

    printf("Enter page table (frame numbers for each page)\n");
    printf("(Enter -1 if the page is not present in any frame)\n");

    for (int i = 0; i < num_pages; i++) {
        printf("Page %d → Frame: ", i);
        scanf("%d", &page_table[i]);
    }

    while (1) {
        printf("\nEnter logical address (page number and offset): ");
        scanf("%d %d", &page_number, &offset);

        if (page_number < 0 || page_number >= num_pages) {
            printf("Invalid page number!\n");
            continue;
        }

        if (offset < 0 || offset >= page_size) {
            printf("Invalid offset! Must be less than page size.\n");
            continue;
        }

        if (page_table[page_number] == -1) {
            printf("Page fault: Page %d not present in physical memory.\n", page_number);
        } else {
            physical_address = (page_table[page_number] * page_size) + offset;
            printf("Physical Address = (Frame %d * %d) + %d = %d\n",
                   page_table[page_number], page_size, offset, physical_address);
        }

        int cont;
        printf("Do you want to continue? (1 = Yes / 0 = No): ");
        scanf("%d", &cont);
        if (cont == 0)
            break;
    }
}

