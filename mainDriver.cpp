#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

struct PCB{
    int PID;
    int task;
    int data[];
    string startTime;
    string endTime;
    int attempts;
    };//Creates processes based on how many were inputted

//Tasks
int priority;
void adding(); //1
void copying();//2
void display(int task, int pid);//3
void Tasks(int p,int pid);

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


void mainDriver(){
    int processNum, startingPoint,task,pid;
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
     clearScreen();

    PCB pBlock[processNum];
    srand(time(NULL));
    for(int a=0;a<processNum;a++){
        pBlock[a].task=rand() %3 +1;
        pBlock[a].PID=rand() % 150;
        task=pBlock[a].task;
        pid=pBlock[a].PID;
        Tasks(task,pid);//testing out tasks
    }//Assigns a random PID to each of the processes


    cout<<"\nProcess ID\tTask\tData\tStart Time\tEnd Time\tAttempts"<<endl;
    for(int a=0;a<processNum;a++){
        cout<<pBlock[a].PID<<"\t\t"<<pBlock[a].task<<endl;
        Sleep(1500);



    }//Generates details of all processes (Not finished)



};

//accepting Tasks function
void Tasks(int p,int pid)
{
   int task,parent;
   task=p;
   parent=pid;
   if(task==1)
   {
      adding();
   }
   else if(task==2)
   {
       copying();
   }
   else if(task==3)
   {
       display(task,parent);
   }
   else
   {
       cout<<"Sorry Task does not exist";
       mainDriver();
   }

}
//Tasks
void adding()//not done :(
{

    priority=1;
    //cout<<"\nThis is the adding function"<<endl;
}

void copying()//not ddoneeeeeeee
{
    //int p,pro,c;
    priority=2;

}
void display(int task, int pid)
{

    int t,p;
    t=task;
    p=pid;
    priority=3;
    cout<<"Displaying Process: "<<p<<endl;
    cout<<"Process ID\tTask\tData\tStart Time\tEnd Time\tAttempts"<<endl;
    cout<<p<<"\t\t"<<t<<endl;
}
int main(){
    mainDriver();

}
