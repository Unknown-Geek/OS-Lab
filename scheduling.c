#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int pid;          
    int arrival_time; 
    int burst_time;   
    int priority;     
    int completion_time;  
} Process;


void sort(Process process[50],int n) {
    Process temp;
    for(int i=0; i<n ; i++) {
        for(int j=0; j<n-1-i ; j++){
            if(process[j].arrival_time < process[j+1].arrival_time) {
                temp = process[j].arrival_time;
                process[j].arrival_time = process[j+1].arrival_time;
                process[j+1].arrival_time = temp;
            }
        }
    }
}

void FCFS(Process process[50],int n) {
    int waiting_time[n], turnaround_time[n], total_wait = 0;
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < processes[i].arrival_time)
            time = processes[i].arrival_time;
        waiting_time[i] = time - processes[i].arrival_time;
        total_wait += waiting_time[i];
        time += processes[i].burst_time;
    }   
    printf("FCFS Average Waiting Time: %.2f\n",total_wait/n);
}

void SJF(Process process[50],int n){
    bool completed[MAX_PROCESSES] = {false};
    int time = 0, completed_count = 0, total_wait = 0;
    
    while (completed_count < n) {
        int min_burst = INT_MAX, selected = -1;
        for (int i = 0; i < n; i++) {
            if (!completed[i] && processes[i].arrival_time <= time && processes[i].burst_time < min_burst) {
                min_burst = processes[i].burst_time;
                selected = i;
            }
        }
        
        if (selected == -1) {
            time++;
            continue;
        }
        
        int wait_time = time - processes[selected].arrival_time;
        total_wait += wait_time;
        time += processes[selected].burst_time;
        completed[selected] = true;
        completed_count++;
    }
    
    printf("SJF Average Waiting Time: %.2f\n", total_wait / n);
}


void RR(Process process[50], int n, int quantum) {
    int time = 0;
    int remaining_time[n];
    int total_wait = 0;
    for(int i=0 ; i<n ; i++) {
        remaining_time[i] = process[i].burst_time;
    }
    for(int i=0 ; i<n ; i++) {
        
    }
}

int main() {
    Process process[50];
    int n;
    int quantum = 3;
    printf("Enter the number fo processes : ");
    scanf("%d",&n);
    printf("\n");
    printf("Enter the arrival time, CPU burst and priority in order of the processes : \n");
    for(int i=0 ; i<n ; i++) {
        process[i].id = i + 1;
        scanf("%d%d%d",&process[i].pid,&process[i].arrival_time,&process[i].burst_time,&process[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
    }
    printf("\n");
    sort(process,n);

}