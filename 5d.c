#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int pid;
    int btime;
    int wtime;
} sp;

int main() {
    int i, j, n, tbm = 0, totwtime = 0, totttime = 0;
    sp *p, t;
    printf("\n sjf scheduling...\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    p = (sp*)malloc(n * sizeof(sp));
    printf("\n Enter the burst times:\n");
    for(i = 0; i < n; i++) {
        printf("\n Process %d: ", i+1);
        scanf("%d", &p[i].btime);
        p[i].pid = i+1;
        p[i].wtime = 0;
    }
    for(i = 0; i < n; i++)
        for(j = i+1; j < n; j++)
            if(p[i].btime > p[j].btime) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
    printf("\n Process scheduling\n");
    printf("\n Process \t Burst Time \t Waiting Time \n");
    for(i = 0; i < n; i++) {
        p[i].wtime = tbm;
        tbm += p[i].btime;
        printf("\n %d \t\t %d \t\t %d", p[i].pid, p[i].btime, p[i].wtime);
        totwtime += p[i].wtime;
        totttime += p[i].wtime + p[i].btime;
    }
    printf("\n\n Total waiting time: %d", totwtime);
    printf("\n Average waiting time: %f", (float)totwtime/n);
    printf("\n Total turn around time: %d", totttime);
    printf("\n Average turn around time: %f", (float)totttime/n);
    return 0;
}
