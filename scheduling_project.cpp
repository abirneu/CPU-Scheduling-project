/*
It was my 3rd year 2nd semester Operating System lab project.
implemented by Abir Hasan
Sheikh Hasina University, Netrkona
Dept. of CSE
Session: 2019-2020
Date: December 1, 2023
*/
#include <bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{

    system("color f2");
    cout<<"\t\t\t\t================================================"<<endl;
    cout<<"\t\t\t\t||                                            ||"<<endl;
    cout<<"\t\t\t\t||"<<"           Scheduling Project               ||"<<endl;
    cout<<"\t\t\t\t||\t\t\t\t\t      ||"<<endl;
    cout<<"\t\t\t\t================================================"<<endl;
    string file_name;
call_from_invalid_file_name:
    cout << "\t\t\t\tEnter file name (with extension, e.g., file.txt): ";
    cin >> file_name;
    cout<<"\t\t\t\t"<<"Input file name is: "<<file_name;
    cout << endl<< endl;
    ifstream file_(file_name);
    vector<string> process;
    vector<int> burst_time;
    vector<int> arrival_time;
    vector<int> priority;

    int tempPriority;
    string tempProcess;
    int tempBurstTime;
    int tempArrivalTime;

    // Read the first line as a header and ignore it
    string header;
    getline(file_, header);
    int total_process=0;
    if (file_.is_open())
    {

        while (file_>> tempProcess >> tempBurstTime >> tempArrivalTime>>tempPriority)
        {
            total_process++;
            process.push_back(tempProcess);
            burst_time.push_back(tempBurstTime);
            arrival_time.push_back(tempArrivalTime);
            priority.push_back(tempPriority);
        }
        file_.close();

    }
    else
    {
        //cout<<"\t\t\t\tFile is not open"<<endl;
        cout<<"\t\t\t\tEnter a valid file name"<<endl;
        goto call_from_invalid_file_name;
    }

    //file input---XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX--file input
    ofstream file_input_value("scheduling_file.txt");

call_from_fcfs:
call_from_sjf:
call_from_priority:
call_from_rr:
    int enter_option;
    cout<<"\t\t\t\t-------------------------------------------------"<<endl;
    cout<<"\t\t\t\t|\t   1. FCFS scheduling\t\t\t|"<<endl;
    cout<<"\t\t\t\t|\t   2. SJF scheduling\t\t\t|"<<endl;
    cout<<"\t\t\t\t|\t   3. Priority scheduling\t\t|"<<endl;
    cout<<"\t\t\t\t|\t   4. RR scheduling\t\t\t|"<<endl;
    cout<<"\t\t\t\t|\t   5. Exit\t\t\t\t|"<<endl;
    cout<<"\t\t\t\t-------------------------------------------------"<<endl;
backk:

    cout<<endl<<"\t\t\t\t\t\tEnter your choice: ";
    cin>>enter_option;




    //FCFS----XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    if(enter_option==1)
    {
        system("cls");
        cout<<endl<<"\t\t\t\t***********************************************";
        cout<<endl<<"\t\t\t\t*\t\t\t\t\t      *";
        cout<<endl<<"\t\t\t\t*\tYou Choose FCFS scheduling   \t      *";
        cout<<endl<<"\t\t\t\t*\t\t\t\t\t      *";
        cout<<endl<<"\t\t\t\t***********************************************"<<endl;

        int wt[total_process], tat[total_process], ct[total_process], i, fcfs_n;// wt = waiting time, tat = turnaround time, ct= completion time

        float fcfs_avg_waiting = 0, tatavg = 0;

        fcfs_n = total_process;

        // Sort processes based on arrival time
        for (i = 0; i < fcfs_n; i++)
        {
            for (int j = 0; j < fcfs_n - 1; j++)
            {
                if (arrival_time[i] < arrival_time[j]) // jhamela ache ei line e
                {
                    swap(arrival_time[i], arrival_time[j]);
                    swap(burst_time[i], burst_time[j]);
                    swap(process[i], process[j]);
                }
            }
        }
        ct[0] = arrival_time[0] + burst_time[0];
        tat[0] = ct[0] - arrival_time[0];
        wt[0] = tat[0] - burst_time[0];
        fcfs_avg_waiting += wt[0];
        tatavg += tat[0];
        for (i = 1; i < fcfs_n; i++)
        {
            // Calculate the completion time based on the arrival time and previous completion time
            if (arrival_time[i] > ct[i - 1])
                ct[i] = arrival_time[i] + burst_time[i];
            else
                ct[i] = ct[i - 1] + burst_time[i];

            tat[i] = ct[i] - arrival_time[i];
            wt[i] = tat[i] - burst_time[i];
            fcfs_avg_waiting += wt[i];// wt = waiting time, wtavg = avg waiting time
            tatavg += tat[i];
        }

        for(int i=0; i<fcfs_n; i++)
        {
            cout<<process[i]<<" Process execute... ";
            for(int j=0; j<burst_time[i]; j++)
            {
                cout<<"#";
            }

            cout<<endl;
        }


        file_input_value<<"FCFS Scheduling.......... "<<endl;
        // Output the process details
        cout <<"Proess\t\tArrival_time\tBurst_time\tCompletion_time\t  Waiting_time\t\tTurnaround_time"<<endl;
        file_input_value << "Proess\tArrival_time\tBurst_time\tCompletion_time\tWaiting_time\tTurnaround_time"<<endl;
        for (i = 0; i < fcfs_n; i++)
        {
            cout <<process[i]<<"\t\t"<<arrival_time[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<ct[i]<<"\t\t\t"<<wt[i]<<"\t\t\t"<<tat[i]<<"\n";
            file_input_value << process[i] << "\t\t " << arrival_time[i] << "\t\t\t " << burst_time[i] << "\t\t " << ct[i] << "\t\t\t " << wt[i] << "\t\t\t " << tat[i]<<endl;
        }
        float average_waiting_time = fcfs_avg_waiting / fcfs_n;
        float average_turnaround_time = tatavg / fcfs_n;// Output the averages
        cout << "\nAverage Waiting Time:  " << average_waiting_time;
        cout << "\nAverage Turnaround Time: " << average_turnaround_time;
        file_input_value << "Average Waiting Time:  " << average_waiting_time<<endl;
        file_input_value << "Average Turnaround Time: " << average_turnaround_time<<endl;
        cout<<endl<<endl;
        goto call_from_fcfs;  //end of fcfs scheduling
    }


    //sjf--XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    else if(enter_option==2)
    {
        system("cls");
        cout<<endl<<"\t\t\t\t***********************************************";
        cout<<endl<<"\t\t\t\t*\t\t\t\t\t      *";
        cout<<endl<<"\t\t\t\t*\tYou Choose SJF   scheduling   \t      *";
        cout<<endl<<"\t\t\t\t*\t\t\t\t\t      *";
        cout<<endl<<"\t\t\t\t***********************************************"<<endl;
        int  temp, tt=0;
        int min, d,i,j;
        float  avg_tat=0, avg_wt=0;
        int t_tat=0;
        int t_wt=0;
        int sjf_n=total_process;
        int c[sjf_n],tat[sjf_n],wt[sjf_n];

        //min to max sort burst time er upor depend kore
        for(i=0; i<sjf_n; i++)
        {
            for(j=i+1; j<sjf_n; j++)
            {
                if(burst_time[i] > burst_time[j])
                {
                    swap(process[i],process[j]);
                    swap(arrival_time[i],arrival_time[j]);
                    swap(burst_time[i],burst_time[j]);
                }
            }
        }
        min = arrival_time[0];
        for(i=0; i<sjf_n; i++)
        {
            if(min > arrival_time[i])
            {
                min = arrival_time[i]; //arrival time theke min ta ber korlam
                d = i;
            }
        }
        tt = min; //tt= temporary variable dhora hoyche
        //c = completion time
        c[d] = tt+ burst_time[d];
        tt = c[d];
        for(i=0; i<sjf_n; i++)
        {
            if(arrival_time[i]!=min) // mim ta to agei ber kora holo tai min chara baki gula ber korar jonno
            {
                c[i] = burst_time[i]+tt;
                tt= c[i];
            }
        }
        for(i=0; i<sjf_n; i++)
        {
            cout<<process[i]<<" Process execute... ";
            for(int j=0; j<burst_time[i]; j++)
            {
                cout<<"#";
            }
            cout<<endl;
        }
        file_input_value<<endl<<endl<<"SJF Scheduling.......... "<<endl;

        cout<<endl<<"\t\t\tPrcoess\tArrival_time\tBurst_time\t Turnaround_time\t Waiting_time"<<endl;
        file_input_value<<"Prcoess\tArrival_time\tBurst_time\t Turnaraund_time\t Waiting_time"<<endl;
        for(i=0; i<sjf_n; i++)
        {
            tat[i] = c[i] - arrival_time[i];
            t_tat = t_tat + tat[i];

            wt[i] = tat[i] - burst_time[i];
            t_wt = t_wt + wt[i];

            cout<<"\t\t\t"<<process[i]<<"\t\t"<<arrival_time[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i]<<endl;
            file_input_value<< process[i]<<"\t\t"<<arrival_time[i]<<"\t\t\t"<<burst_time[i]<<"\t\t\t"<<tat[i]<<"\t\t"<<wt[i]<<endl;
        }
        avg_tat = t_tat/sjf_n;
        avg_wt = t_wt/sjf_n;
        cout<<endl<<"Avg tat :"<<avg_tat<<endl;
        cout<<endl<<"Avg waiting time : "<<avg_wt<<endl;
        file_input_value<<endl<<"Avg tat :"<<avg_tat<<endl;
        file_input_value<<"Avg waiting time : "<<avg_wt<<endl;
        goto call_from_sjf; //end of sjf scheduling....XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    }


    //prioroty--XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    else if(enter_option==3)
    {
        system("cls");
        cout<<endl<<"\t\t\t\t***********************************************";
        cout<<endl<<"\t\t\t\t*\t\t\t\t\t      *";
        cout<<endl<<"\t\t\t\t*\tYou Choose priority  scheduling       *";
        cout<<endl<<"\t\t\t\t*\t\t\t\t\t      *";
        cout<<endl<<"\t\t\t\t***********************************************"<<endl;



        int i,j,priority_n=total_process;
        int waiting_time_priority[priority_n],tat[priority_n];//turn around time
        int total_tat=0,total_waiting=0;
        float avg_tat,avg_wt;

        for(i=0; i<priority_n; i++)
        {
            for(j=i+1; j<priority_n; j++)
            {
                if(priority[j]< priority[i])
                {
                    swap(priority[i], priority[j]);
                    swap(burst_time[i], burst_time[j]);
                    swap(process[i], process[j]);
                }
            }
        }
        waiting_time_priority[0]=0; //waiting time prothom tar jonno to zero
        //calculate waiting time
        for(i=1; i<priority_n; i++)// 1 5 10 2 1
        {
            waiting_time_priority[i]=0;
            for(j=0; j<i; j++)
            {
                waiting_time_priority[i]= waiting_time_priority[i] + burst_time[j];
            }

            total_waiting= total_waiting + waiting_time_priority[i];
        }
        avg_wt=(float)total_waiting/(float)priority_n;

        file_input_value<<endl<<"Priority scheduling......."<<endl;
        cout<<"\t\t\tProcess"<<"\t\tBurst_ime"<<"\tPriority"<<"\tWaiting_time"<<endl;
        file_input_value<<"Process"<<"\t\tBurst_time"<<"\tPriority"<<"\tWaiting_time"<<endl;
        for(i=0; i<priority_n; i++)
        {
            tat[i]=burst_time[i]+waiting_time_priority[i];     //calculate turnaround time
            total_tat=total_tat + tat[i];

            cout<<"\t\t\t"<<process[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<priority[i]<<"\t\t"<<waiting_time_priority[i]<<endl;
            file_input_value<<process[i]<<"\t\t\t"<<burst_time[i]<<"\t\t"<<priority[i]<<"\t\t"<<waiting_time_priority[i]<<endl;
        }

        avg_tat=(float)total_tat/(float)priority_n;
        cout<<endl;
        cout<<endl<<"Average Waiting Time: "<<avg_wt<<endl;
        cout<<"Average Turnaround Time: "<<avg_tat<<endl;

        file_input_value<<endl<<"Average Waiting Time: "<<avg_wt<<endl;
        file_input_value<<"Average Turnaround Time: "<<avg_tat<<endl;

        goto call_from_priority;

    }

    //rr------XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    else if(enter_option==4)
    {
        system("cls");
        cout<<endl<<"\t\t\t\t***********************************************";
        cout<<endl<<"\t\t\t\t*\t\t\t\t\t      *";
        cout<<endl<<"\t\t\t\t*\tYou Choose RR   scheduling   \t      *";
        cout<<endl<<"\t\t\t\t*\t\t\t\t\t      *";
        cout<<endl<<"\t\t\t\t***********************************************"<<endl;

        int t_quantum;

        cout<<endl<<"\t\t\t\tEnter Time Quantum : ";
        cin>>t_quantum;
        cout<<"\t\t\t\tTime Quantum is : "<<t_quantum<<endl;

        file_input_value<<endl<<"Round Robin Scheduling Algorithm....."<<endl;
        file_input_value<<"Time Quantum is : "<<t_quantum<<endl;
        int rr_n = total_process;
        // process id's
        // int process[rr_n] = {1, 2, 3,4};
        // Burst time of all processes
        //int burst_time[rr_n] = {21,3,6,2};
        int  total_wt = 0, total_tat = 0;
        int rr_time = 0; // Current time
        int wt[rr_n];
        // Time quantum
        int quantum = t_quantum;
        // Make a copy of burst times bt[] to store remaining ------ burst times.
        int rem_bt[rr_n]; // remaining burst time
        for (int i = 0; i < rr_n; i++)
        {
            rem_bt[i] = burst_time[i]; // inputed burst time copy kore remaining er vitor rakhlam
        }
        // Keep traversing processes in round robin manner
        // until all of them are not done.
        while(rr_n!=0)// joto khon process gula sesh na hoy
        {
            bool done = true; // jodi kono process er burst time zero hoye jay seta true kore dibo taile seta r execute korbe nah
            // Traverse all processes one by one repeatedly
            for (int i = 0; i < rr_n; i++)
            {
                if (rem_bt[i] > 0)
                {
                    done = false; // burst time ekhon o zero hoy ni tai false set kora jeno eta execute kore aber
                    if (rem_bt[i] > quantum)
                    {
                        rr_time = rr_time + quantum;
                        rem_bt[i] = rem_bt[i] - quantum;
                    }
                    else
                    {
                        // ei llop e asche mane burst time zero er boro but quantum time er choto .
                        //tar mane etar time e hobe tat. r seta diye amra wt ber korte parbo
                        rr_time = rr_time + rem_bt[i];
                        wt[i] = rr_time - burst_time[i]; // tat = ct - at  ; wt = tat - bt ei khan e at =0 tai wt = ct - bt
                        rem_bt[i] = 0;// jehetu  process fully executed hoye geche tai burst time = 0 kore dewa holo jeno next process er jonno somossa na hoy
                    }
                }
            }
            if (done == true)
            {
                break;
            }
        }
        for(int i=0; i<rr_n; i++)
        {
            total_wt = total_wt + wt[i];
        }
        cout <<endl<<"Process"<<"\tBurst_time"<<"\tWaiting_time" << endl;//output part
        file_input_value<<endl<<"Process"<<"\tBurst_time"<<"\tWaiting_time" << endl;
        for (int i = 0; i <rr_n; i++)
        {
            cout<< process[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<wt[i]<<endl;
            file_input_value<< process[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<wt[i]<<endl;
        }
        cout << "Average waiting time: " << (float)total_wt /(float)rr_n<<endl;
        file_input_value<<endl<< "Average waiting time: " << (float)total_wt /(float)rr_n<<endl;
        goto call_from_rr;

    }
    else if(enter_option==5)
    {
        exit(0);
    }
    else
    {
        cout<<"Please enter a valid number"<<endl;
    }
    return 0;

}




