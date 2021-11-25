#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Process {
        int PID;
        int task;
        int data;
        int attempts;
        time_t start_time;
        time_t end_time;
} Process;

int main(void)
{
    int nP, startPoint;
    int sharedList[10][2]={{2,1},{4,1},{6,1},{8,1},{10,1},{12,1},{14,1},{16,1},{18,1},{20,1}};

    printf("Enter the number of process(MINIMUM 10; MAXIMUM:30): ");
    scanf("%d", &nP);

    printf("Enter starting point(Must NOT BE GREATER THAN 10): ");
    scanf("%d", &startPoint);

    
    return 0;
}