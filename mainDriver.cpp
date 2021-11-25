#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

 int generatePID(){
        srand(time(NULL));
        int random=10 + rand() % 100;
        return random;
    };

void mainDriver(){
    int processNum;
    //Two Dimmensional array that stores the integer values and their key values(All are unlocked by default)
    int sharedList[10][2]={{2,1},{4,1},{6,1},{8,1},{10,1},{12,1},{14,1},{16,1},{18,1},{20,1}};
    
    cout<<"Hello, please enter the number of processes\n";
    
    try
    {
        cin>>processNum;
        if(cin.fail()){
            throw 1;
        }
         while(processNum<10 || processNum>30){
            cerr<<"Enter a number within the range of 10 and 30\n";
            cin>>processNum;
        } 
    }
    catch(int err)
    {
        cerr<<"A number was not entered. Run the program and try again";
    }//Checks if the number entered is within range and is actually a number

    struct PCB{
    int PID= generatePID();
    int task;
    int data[];
    string startTime;
    string endTime;
    int attempts;
    }pBlock[processNum];//Creates processes based on how many were inputted
    
    for(int a=0;a<processNum;a++){
        pBlock[a].PID=generatePID();
    }


    for(int a=0;a<3;a++){
        cout<<pBlock[a].PID<<endl;
    }
    

    
};

int main(){
    mainDriver();
    
}