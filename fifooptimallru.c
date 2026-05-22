#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10
#define MAX_PAGES 50
int isPresent(int frames[], int num_frames, int page) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i] == page) return 1;
    }
    return 0;
}

void printFrames(int frames[], int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i] == -1) printf("- ");
        else printf("%d ", frames[i]);
    }
    printf("\n");
}

void fifo(int pages[], int n, int num_frames) {
    int frames[MAX_FRAMES];
    for (int i = 0; i < num_frames; i++) frames[i] = -1;
    int page_faults = 0, next = 0;

    printf("\nFIFO Page Replacement:\n");
    for (int i = 0; i < n; i++) {
        if (!isPresent(frames, num_frames, pages[i])) {
            frames[next] = pages[i];
            next = (next + 1) % num_frames;
            page_faults++;
        }
        printFrames(frames, num_frames);
    }
    printf("Total Page Faults (FIFO): %d\n", page_faults);
}

void optimal(int pages[], int n, int num_frames) {
    int frames[MAX_FRAMES];
    for (int i = 0; i < num_frames; i++) frames[i] = -1;
    int page_faults = 0;

    printf("\nOptimal Page Replacement:\n");
    for (int i = 0; i < n; i++) {
        if (!isPresent(frames, num_frames, pages[i])) {
            int replaceIndex = -1;
            if (i < num_frames) {
                frames[i] = pages[i];
            } else {
                int farthest = -1;
                for (int j = 0; j < num_frames; j++) {
                    int k;
                    for (k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) break;
                    }
                    if (k == n) {
                        replaceIndex = j;
                        break;
                    }
                    if (k > farthest) {
                        farthest = k;
                        replaceIndex = j;
                    }
                }
                frames[replaceIndex] = pages[i];
            }
            page_faults++;
        }
        printFrames(frames, num_frames);
    }
    printf("Total Page Faults (Optimal): %d\n", page_faults);
}

void lru(int pages[], int n, int num_frames) {
    int frames[MAX_FRAMES];
    int last_used[MAX_FRAMES];
    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }
    int page_faults = 0;

    printf("\nLRU Page Replacement:\n");
    for (int i = 0; i < n; i++) {
        if (!isPresent(frames, num_frames, pages[i])) {
            int replaceIndex = -1;
            if (i < num_frames) {
                frames[i] = pages[i];
                last_used[i] = i;
            } else {
                int lruIndex = 0;
                for (int j = 1; j < num_frames; j++) {
                    if (last_used[j] < last_used[lruIndex]) {
                        lruIndex = j;
                    }
                }
                replaceIndex = lruIndex;
                frames[replaceIndex] = pages[i];
                last_used[replaceIndex] = i;
            }
            page_faults++;
        } else {
            for (int j = 0; j < num_frames; j++) {
                if (frames[j] == pages[i]) {
                    last_used[j] = i;
                    break;
                }
            }
        }
        printFrames(frames, num_frames);
    }
    printf("Total Page Faults (LRU): %d\n", page_faults);
}

int main() {
    int num_frames = 3;
    int pages[] = {5,0,1,0,2,3,0,2,4,3,3,2,0,2,1,2,7,0,1,1,0};
    int n = sizeof(pages)/sizeof(pages[0]);

    fifo(pages, n, num_frames);
    optimal(pages, n, num_frames);
    lru(pages, n, num_frames);

    return 0;
}

