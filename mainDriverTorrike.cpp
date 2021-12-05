#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

 void clearScreen(){
    system("cls");
    Sleep(100);
    cout<<"Generating processes";
    Sleep(1200);
    cout<<".";
    Sleep(1200);
    cout<<".";
    Sleep(1200);
    cout<<".";
    system("cls");
 }


struct PCB{
    int PID;
    int task;
    int data[2];
    time_t startTime;
    time_t endTime;
    int attempts;
    };//Creates processes based on how many were inputted

struct activeProcesses{
    int PID;
    int task;
    int data[2];
    time_t startTime;
    time_t endTime;
    int attempts;
}active[5];//Stores active processes(Ready queue)

void activeFive(int b, int batch, struct PCB pblock[30]){
    for(;b<batch;b++){
        active[b].task=pblock[b].task;
        active[b].PID=pblock[b].PID;
        active[b].startTime=pblock[b].startTime;
        cout<<active[b].PID<<endl;
    }
}//Loads 5 processes into the ready queue

void mainDriver(){

    
    int processNum, startingPoint,sze=0,batch=5;
    //Two Dimmensional array that stores the integer values and their key values(All are unlocked by default)
    int sharedList[10][2]={{2,1},{4,1},{6,1},{8,1},{10,1},{12,1},{14,1},{16,1},{18,1},{20,1}};
    
    try{
        cout<<"Hello, please enter the number of processes\n";
        cin>>processNum;
        if(cin.fail()){
            throw 1;
        }
        while(processNum<10 || processNum>30){
            cerr<<"Enter a number within the range of 10 and 30\n";
            cin>>processNum;
        } 
        
    }catch(int err)
    {
        cerr<<"A number was not entered. Run the program and try again";
        exit(8);
    }//Checks if the number entered is within range and is actually a number
    
    try{
        cout<<"Enter the starting position for the shared list\n";
        cin>>startingPoint;
        if(cin.fail()){
            throw 1;
        }
        while(startingPoint<0 || startingPoint>9){
            cerr<<"Enter a number between 0 and 9\n";
            cin>>startingPoint;
        } 
        
    }catch(int err)
    {
        cerr<<"A number was not entered. Run the program and try again";
        exit(8);
    }//Checks if the number entered is within range and is actually a number
     //clearScreen();
     PCB pBlock[processNum];
     

    srand(time(NULL));
    for(int a=0;a<processNum;a++){
        pBlock[a].task=rand() %3 +1;
        pBlock[a].PID=rand() % 150;
        Sleep(2000);
        pBlock[a].startTime= time(NULL);
    }//Assigns a random PID to each of the processes

    activeFive(0,batch,pBlock);//Calls the function that loads 5 processes into the ready queue
    
    //Function to lock in integers(FCFS)
    for(;sze<processNum;sze++){
        for(;sze<=batch;sze++){
            if(active[sze].startTime<active[sze+1].startTime){
                if(active[sze].task <= active[sze+1].task && active[sze].task==1){
                    sharedList[startingPoint][1]=0;//Locks the integer in the shared list
                    sharedList[startingPoint+1][1]=0;//Locks the integer in the shared list
                    pBlock[sze].data[0]=startingPoint;  
                    pBlock[sze].data[1]=startingPoint+1;
                    cout<<sharedList[startingPoint][0]<<"+"<<sharedList[startingPoint+1][0];
                    sharedList[startingPoint+1][0]=sharedList[startingPoint][0]+sharedList[startingPoint+1][0];
                    cout<<"= "<<sharedList[startingPoint+1][0]<<endl;
                    startingPoint++;
                    //Still need to unlock integers when finished and add end time
                }
                if(active[sze].task >= active[sze+1].task && active[sze].task==3){
                    sharedList[startingPoint][1]=0;//Locks the integer in the shared list
                    pBlock[sze].data[0]=startingPoint;  
                    pBlock[sze].data[1]=NULL;
                    cout<<"Displaying >>"<<sharedList[startingPoint][0]<<endl;
                }
            }/*else if(active[sze+1].task>active[sze].task && active[sze+1].startTime>active[sze].startTime){
                if(active[sze+1].task==1){
                    sharedList[startingPoint][1]=0;//Locks the integer in the shared list
                    sharedList[startingPoint+1][1]=0;//Locks the integer in the shared list
                    cout<<sharedList[startingPoint][0]<<" has been locked"<<endl;
                    cout<<sharedList[startingPoint+1][0]<<" has been locked"<<endl;
                    pBlock[sze].data[0]=startingPoint;  
                    pBlock[sze].data[1]=startingPoint+1;
                    cout<<pBlock[sze].data[0]<<" was stored"<<endl;  
                    cout<<pBlock[sze].data[1]<<" was stored"<<endl;
                    cout<<sharedList[startingPoint][0]<<"+"<<sharedList[startingPoint+1][0]<<endl;
                    sharedList[startingPoint+1][0]=sharedList[startingPoint][0]+sharedList[startingPoint+1][0];
                    startingPoint++;
                    cout<<"Second if"<<endl;
                }
            }*/
        }
    }

    /*
    for(;sze<processNum;sze++){
        for(;sze<5;sze++){
            if(pBlock[sze].task==1){
                sharedList[startingPoint][1]=0;//Locks the integer in the shared list
                sharedList[startingPoint+1][1]=0;//Locks the integer in the shared list
                cout<<sharedList[startingPoint][0]<<" has been locked"<<endl;
                cout<<sharedList[startingPoint+1][0]<<" has been locked"<<endl;
                pBlock[sze].data[0]=startingPoint;  
                pBlock[sze].data[1]=startingPoint+1;
                cout<<pBlock[sze].data[0]<<" was stored"<<endl;  
                cout<<pBlock[sze].data[1]<<" was stored"<<endl;
                cout<<sharedList[startingPoint][0]<<"+"<<sharedList[startingPoint+1][0]<<endl;
                sharedList[startingPoint+1][0]=sharedList[startingPoint][0]+sharedList[startingPoint+1][0];
                startingPoint++;
            } 
            
        }
    }Doesn't do what its supposed to do but might have use*/
    
   
    cout<<"Process ID\tTask\tData\tStart Time\tEnd Time\tAttempts"<<endl;
    for(int a=0;a<processNum;a++){
        cout<<pBlock[a].PID<<"\t\t"<<pBlock[a].task<<"\t"<<pBlock[a].data[0]<<","<<pBlock[a].data[1]<<endl;
        Sleep(1500);
    }
    
    
}

int main(){
    mainDriver();
    
    
}