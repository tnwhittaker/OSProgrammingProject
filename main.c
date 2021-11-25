#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fcfs(int numberOfProcess, int startingPoint);

typedef struct Process {
        int PID;
        int task;
        int data;//should be an array
        int attempts;
        time_t start_time;
        time_t end_time;
} Process;

int main(void)
{
    srand(time(0));
    int nP, startPoint;
    // int sharedList[10][2]={{2,1},{4,1},{6,1},{8,1},{10,1},{12,1},{14,1},{16,1},{18,1},{20,1}};

    printf("Enter the number of process(MINIMUM 10; MAXIMUM:30): ");
    scanf("%d", &nP);

    printf("Enter starting point(Must NOT BE GREATER THAN 10): ");
    scanf("%d", &startPoint);

    fcfs(nP,startPoint);
    
    return 0;
}

void fcfs(int numberOfProcess, int startingPoint){
    int sharedList[10][2]={{2,1},{4,1},{6,1},{8,1},{10,1},{12,1},{14,1},{16,1},{18,1},{20,1}};

    int sharedListLength = (sizeof(sharedList) / sizeof(int))/2;

    for (int i = 0; i < sharedListLength; i++)
    {
        int innerLength = (sizeof(sharedList[i]) / sizeof(int));
        printf("%d ---- %d\n",sharedList[i][0],sharedList[i][1]);
       
        
    }

    for (int x = 0; x < numberOfProcess; x++)
    {
        Process process[x];
        process->PID = rand() % 500;
        process->task = (rand() % 3) + 1;//to be changed
        
        /* unfinished code */
    }
    
    
  
}