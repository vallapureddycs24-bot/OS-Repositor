#include <stdio.h>

void firstFit(int block[], int nb, int process[], int np) {
    int allocation[np];
    int finish[nb];

    // initialize
    for(int i = 0; i < np; i++)
        allocation[i] = -1;

    for(int i = 0; i < nb; i++)
        finish[i] = 0;

    // First Fit Allocation
    for(int i = 0; i < np; i++) {
        for(int j = 0; j < nb; j++) {

            if(finish[j] == 0 && block[j] >= process[i]) {
                allocation[i] = j;
                finish[j] = 1;
                break;
            }
        }
    }

    printf("\nFIRST FIT\n");
    printf("Process\tSize\tBlock\n");

    for(int i = 0; i < np; i++) {
        printf("P%d\t%d\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int block[], int nb, int process[], int np) {
    int allocation[np];
    int finish[nb];

    // initialize
    for(int i = 0; i < np; i++)
        allocation[i] = -1;

    for(int i = 0; i < nb; i++)
        finish[i] = 0;

    // Best Fit Allocation
    for(int i = 0; i < np; i++) {

        int best = -1;

        for(int j = 0; j < nb; j++) {

            if(finish[j] == 0 && block[j] >= process[i]) {

                if(best == -1 || block[j] < block[best]) {
                    best = j;
                }
            }
        }

        if(best != -1) {
            allocation[i] = best;
            finish[best] = 1;
        }
    }

    printf("\nBEST FIT\n");
    printf("Process\tSize\tBlock\n");

    for(int i = 0; i < np; i++) {
        printf("P%d\t%d\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int block[], int nb, int process[], int np) {
    int allocation[np];
    int finish[nb];

    // initialize
    for(int i = 0; i < np; i++)
        allocation[i] = -1;

    for(int i = 0; i < nb; i++)
        finish[i] = 0;

    // Worst Fit Allocation
    for(int i = 0; i < np; i++) {

        int worst = -1;

        for(int j = 0; j < nb; j++) {

            if(finish[j] == 0 && block[j] >= process[i]) {

                if(worst == -1 || block[j] > block[worst]) {
                    worst = j;
                }
            }
        }

        if(worst != -1) {
            allocation[i] = worst;
            finish[worst] = 1;
        }
    }

    printf("\nWORST FIT\n");
    printf("Process\tSize\tBlock\n");

    for(int i = 0; i < np; i++) {
        printf("P%d\t%d\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int nb, np;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[nb];

    printf("Enter sizes of memory blocks:\n");
    for(int i = 0; i < nb; i++) {
        scanf("%d", &block[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[np];

    printf("Enter sizes of processes:\n");
    for(int i = 0; i < np; i++) {
        scanf("%d", &process[i]);
    }

    firstFit(block, nb, process, np);
    bestFit(block, nb, process, np);
    worstFit(block, nb, process, np);

    return 0;
}
