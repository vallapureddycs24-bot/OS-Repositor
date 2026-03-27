#include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
int find_lcm(int p[], int n) {
    int res = p[0];
    for (int i = 1; i < n; i++) {
        res = lcm(res, p[i]);
    }
    return res;
}

int main() {
    int n;
    printf("VALLAPUREDDY VAISHNAVI 1BF24CS329");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int C[n], P[n];

    printf("Enter CPU burst times:\n");
    for (int i = 0; i < n; i++) scanf("%d", &C[i]);

    printf("Enter time periods:\n");
    for (int i = 0; i < n; i++) scanf("%d", &P[i]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (P[i] > P[j]) {
                int temp = P[i]; P[i] = P[j]; P[j] = temp;
                temp = C[i]; C[i] = C[j]; C[j] = temp;
            }
        }
    }

    int hyper = find_lcm(P, n);
    printf("\nLCM = %d\n", hyper);

    int remaining[n];
    for (int i = 0; i < n; i++) remaining[i] = 0;

    printf("\nScheduling (5 ms blocks):\n\n");

    int count[n];
    for (int t = 0; t < hyper; t += 5) {

        for (int i = 0; i < n; i++) count[i] = 0;

        for (int k = 0; k < 5 && (t + k) < hyper; k++) {

            int time = t + k;

            for (int i = 0; i < n; i++) {
                if (time % P[i] == 0) {
                    remaining[i] = C[i];
                }
            }
            int selected = -1;
            for (int i = 0; i < n; i++) {
                if (remaining[i] > 0) {
                    selected = i;
                    break;
                }
            }

            if (selected != -1) {
                remaining[selected]--;
                count[selected]++;
            }
        }
        int max = 0, proc = -1;
        for (int i = 0; i < n; i++) {
            if (count[i] > max) {
                max = count[i];
                proc = i;
            }
        }

        if (proc == -1)
            printf("%d - %d ms : IDLE\n", t, t + 5);
        else
            printf("%d - %d ms : Process %d running\n", t, t + 5, proc + 1);
    }

    return 0;
}
