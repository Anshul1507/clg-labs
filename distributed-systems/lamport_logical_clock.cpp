#include <bits/stdc++.h>

using namespace std;

int main(){

    cout << "Enter the events: " ;
    int e1,e2;
    cin >> e1 >> e2;
    int p1[50],p2[50],dp[50][50];

    for(int i=0;i<e1;i++){
        p1[i]=i+1;
    }
    for(int i=0;i<e2;i++){
        p2[i]=i+1;
    }

    cout << "Enter the  matrix: ";
    cout << "enter 1 if e1->e2 \n enter -1, if e2->e1 \n else enter 0 \n";

    for(int i=0;i<e1;i++){
        for(int j=0;j<e2;j++){
            cin >> dp[i][j];
        }
    }

    for(int i=0;i<e1;i++){
        for(int j=0;j<e2;j++){
            if(dp[i][j]==1){
                p2[j]=max(p2[j],p1[i]+1);
                for(int k=j;k<e2;k++){
                    p2[k+1]=p2[k]+1;
                }
            }
            if(dp[i][j]==-1){
                p1[i]=max(p1[i],p2[j]+1);
                for(int k=i;k<e1;k++){
                    p2[k+1]=p1[k]+1;
                }
            }
        }
    }

    cout << "P1: ";
    for(int i=0;i<e1;i++){
        cout << p1[i] << " ";
    }

    cout << "P2: ";
    for(int i=0;i<e2;i++){
        cout << p2[i] << " ";
    }

}
