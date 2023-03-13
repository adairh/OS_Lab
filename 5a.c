#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pno;
    int pri;
    int btime;
    int wtime;
} sp;

int main() {
    int i, j, n;
    int tbm = 0, totwtime = 0, totttime = 0;
    sp *p, t;

    printf("\n PRIORITY SCHEDULING.\n");
    printf("\n enter the no of process....\n");
    scanf("%d", &n);

    p = (sp*)malloc(n * sizeof(sp));

    printf("enter the burst time and priority:\n");
    for (i = 0; i < n; i++) {
        printf("process %d: ", i + 1);
        scanf("%d %d", &p[i].btime, &p[i].pri);
        p[i].pno = i + 1;
        p[i].wtime = 0;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].pri > p[j].pri) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }

    printf("\n process\tbursttime\twaiting time\tturnaround time\n");
    for (i = 0; i < n; i++) {
        p[i].wtime = tbm;
        tbm += p[i].btime;
        printf(" %d\t\t%d\t\t%d\t\t%d\n", p[i].pno, p[i].btime, p[i].wtime, p[i].wtime + p[i].btime);
        totwtime += p[i].wtime;
    }

    totttime = tbm;

    printf("\n total waiting time: %d", totwtime);
    printf("\n average waiting time: %f", (float)totwtime / n);
    printf("\n total turnaround time: %d", totttime);
    printf("\n average turnaround time: %f", (float)totttime / n);

    free(p);

    return 0;
}
