#include <bits/stdc++.h>

using namespace std;

int main(){

    /* Variables */
    int n,time_quantum,cur_time=0,t_exec=0,t_wt=0,t_tat=0;
    int p[n],bt[n],wt[n],tat[n];
    vector<int> v;

    /* Inputs */
    cin >> n >> time_quantum;
    for(int i=0;i<n;i++){
        cin >> p[i] >> bt[i];
    }

    /* Waiting Time */
    int temp_wt[n];
    for(int i=0;i<n;i++){
        temp_wt[i] = bt[i];
    }

    while(true){
        
        for(int i=0;i<n;i++){
            
            if(temp_wt[i] > time_quantum){
                // if greater than quantum time
                cur_time += time_quantum; //increase the current time by quantum time.
                temp_wt[i] -= time_quantum; //process executed -> remove/subtract
                v.push_back(i); //inserting the sequence of process execution
            }else{
                // less than quantum time
                t_exec++; //execution counter for processes.
                cur_time += temp_wt[i]; //increase the current time by left execution time of current process.
                wt[i] = cur_time - bt[i]; //waiting time is current time minus used by the process.
                temp_wt[i] = 0;
            }
            
        }
        
        if(t_exec == n-1){
            //when all process executes
            break;
        }
    }    

    /* Turn Around Time */
    for(int i=0;i<n;i++){
        tat[i] = bt[i] + wt[i];
    }

    /* Total Waiting and Turn Around Time */
    for(int i=0;i<n;i++){
        t_wt += wt[i];
        t_tat += tat[i];
    }

    /* Average Time */
    float avg_wt = t_wt/(float)n;
    float avg_tat = t_tat/(float)n;

    /* Display */
    cout << "Average Waiting Time : " << avg_wt << endl;
    cout << "Average Turn Around Time : " << avg_tat << endl;
    cout << "Process Flow: ";
    for(int i=0;i<v.size();i++){
        cout << "P" << v[i] << " ";
    }


}
