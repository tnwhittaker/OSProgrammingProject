//============================================================================
// Name        : Osproj.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

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

 //Two Dimmensional array that stores the integer values and their key values(All are unlocked by default)
    int sharedList[10][2]={{2,1},{4,1},{6,1},{8,1},{10,1},{12,1},{14,1},{16,1},{18,1},{20,1}};


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
    bool done;
}active[5];//Stores active processes(Ready queue)

void activeFive(int b, int batch, struct PCB pblock[30]){
    for(;b<batch;b++){
        active[b].task=pblock[b].task;
        active[b].PID=pblock[b].PID;
        active[b].startTime=pblock[b].startTime;
        active[b].done=false;
        active[b].attempts=0;
    }

}//Loads 5 processes into the ready queue


void mainDriver(){


    int processNum, startingPoint,sze=0,batch=5;

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
        pBlock[a].task=rand() % 3 +1;
        pBlock[a].PID=rand() % 150;
        Sleep(5000);
        pBlock[a].startTime= time(NULL);


    }//Assigns a random PID to each of the processes

    activeFive(0,processNum,pBlock);//Calls the function that loads 5 processes into the ready queue
    int pri=0,task=1;
    bool run= true;
    while(run){
            for(pri=0;pri<processNum;pri++){
            if(active[pri].task==1){

            	cout<<endl<<"Shared List Before Adding: "<<std::flush;
            	for(int x = 0; x < 10; x++){
            		cout<<sharedList[x][0]<<" "<<std::flush;
            	}

                sharedList[startingPoint][1]=0;//Locks the integer in the shared list
                sharedList[startingPoint+1][1]=0;//Locks the integer in the shared list
                active[pri].data[0]=startingPoint;
                active[pri].data[1]=startingPoint+1;
                cout<<endl<<sharedList[startingPoint][0]<<"+"<<sharedList[startingPoint+1][0]<<std::flush;
                sharedList[startingPoint+1][0]=sharedList[startingPoint][0]+sharedList[startingPoint+1][0];
                cout<<"= "<<sharedList[startingPoint+1][0]<<endl;
                cout<<"Replacing Index "<<startingPoint+1<<endl;
                startingPoint++;
                active[pri].done=true;
                active[pri].endTime=time(NULL);
                cout<<"Shared List After Adding: "<<std::flush;
                for(int x = 0; x < 10; x++){
                            		cout<<sharedList[x][0]<<" "<<std::flush;
                            	}
                cout<<endl;
                if(pri % 5 == 0){
                   cout<<"Reach 5!"<<endl;

                }
                if(startingPoint>9){
                    startingPoint=0;
                }
                //continue;
            }else{
                active[pri].attempts++;
            }

            }//Searches through the active processes and executes all with priority 1

            for(pri=0;pri<processNum;pri++){
            if (active[pri].done==true){
                    continue;
                }
            if(active[pri].task==2){
                int a=startingPoint+1;
                sharedList[startingPoint][1]=0;//Locks the integer in the shared list
                sharedList[a][1]=0;//Locks the integer in the shared list
                cout<<endl<<"Shared List Before Copying: "<<std::flush;
                            	for(int x = 0; x < 10; x++){
                            		cout<<sharedList[x][0]<<" "<<std::flush;
                            	}
                cout<<endl<<"Shared list value before copying: "<<sharedList[a][0]<<endl;
                sharedList[a][0]=sharedList[startingPoint++][0];
                cout<<"Shared list value after copying: "<<sharedList[a][0]<<endl;
                active[pri].data[0]=startingPoint;
                active[pri].data[1]=a;
                active[pri].endTime=time(NULL);
                cout<<"Shared List After Copying: "<<std::flush;
                for(int x = 0; x < 10; x++){
                     cout<<sharedList[x][0]<<" "<<std::flush;
                }
                cout<<endl;
                startingPoint++;
                a++;
                if(pri % 5 == 0){
                                   cout<<"Reach 5!"<<endl;

                                }
                active[pri].done=true;
                if(startingPoint>9){
                    startingPoint=0;
                }


            }else{
                active[pri].attempts++;
                }
            }

            for(pri=0;pri<processNum;pri++){
            if (active[pri].done==true){
                    continue;
                }
            if(active[pri].task==3 ){
                sharedList[startingPoint][1]=0;//Locks the integer in the shared list
                active[pri].data[0]=startingPoint;
                active[pri].data[1]=0;
                active[pri].endTime=time(NULL);
                cout<<endl<<"Displaying >> "<<sharedList[startingPoint][0]<<endl;
                startingPoint++;
                 if(startingPoint>9){
                     startingPoint=0;
                 }
                active[pri].done=true;
                if(pri % 5 == 0){
                                   cout<<"Reach 5!"<<endl;

                                }

            }else{
                active[pri].attempts++;
                }
            }



            if (pri>1)
            {
                run=false;
            }


        //}
    }

//    time_t now = time( NULL);
//    struct tm now_tm = *localtime( &now);

    cout<<endl<<"Process ID\tTask\tData\tStart Time\tEnd Time\tAttempts"<<endl<<endl;
    for(int a=0;a<processNum;a++){

    	struct tm now_starttm = *localtime( &active[a].startTime);
    	struct tm now_endtm = *localtime( &active[a].endTime);

    	now_endtm.tm_sec += rand() % 10 + 1;


    	cout<<active[a].PID<<"\t\t   "<<
    	active[a].task<<"\t"<<
		active[a].data[0]<<","<<active[a].data[1]<<"\t"<<
		now_starttm.tm_hour<<":"<<now_starttm.tm_min<<":"<<now_starttm.tm_sec<<"\t\t"<<
		now_endtm.tm_hour<<":"<<now_endtm.tm_min<<":"<<now_endtm.tm_sec<<"\t\t   "<<
		active[a].attempts<<
		endl;


        Sleep(1500);
    }


}

int main(){
    mainDriver();


}
