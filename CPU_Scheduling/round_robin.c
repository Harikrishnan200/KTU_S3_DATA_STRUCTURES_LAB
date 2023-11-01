#include <stdio.h>

#define MAX_PROCESS 10

struct Process {
    int pid;
    int burst_time;
    int temp;
    int waiting_time;
    int turnaround_time;
};

void roundRobinScheduling(struct Process processes[], int n, int quantum) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

   
    for (int i = 0; i < n; i++) {
        processes[i].temp = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    int y = 0;
    int current_time = 0;
    int i = 0;

    while (y < n) {
        if (processes[i].temp > 0) {
            if (processes[i].temp <= quantum) {
                current_time += processes[i].temp;
                processes[i].turnaround_time = current_time;
                processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                processes[i].temp = 0;
                y++;
            } else {
                current_time += quantum;
                processes[i].temp -= quantum;
            }
        }
        i = (i + 1) % n;
    }

    
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

  
    printf("Process ID | Burst Time | Waiting Time | Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%9d | %10d | %12d | %15d\n", processes[i].pid, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }

   
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes (max %d): ", MAX_PROCESS);
    scanf("%d", &n);

    

    struct Process processes[MAX_PROCESS];

    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
     
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    roundRobinScheduling(processes, n, quantum);

    return 0;
