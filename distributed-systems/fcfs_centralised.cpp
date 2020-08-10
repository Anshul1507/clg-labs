#include <bits/stdc++.h>

using namespace std;

int main(){

    /* Variables */
    int n,p[n],bt[n],wt[n],tat[n],t_wt=0,t_tat=0;

    /* Inputs */
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> p[i] >> bt[i];
    }

    /* Waiting Time */
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
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

}
