#include<bits/stdc++.h>
using namespace std;



int main(){
    int notes[8]={1,2,5,10,50,100,200,500};
    int amt;
    cout<<"ENTER THE AMOUNT: ";
    cin>>amt;


    vector<vector<int>>dp(9,vector<int>(amt+1,0));

    for(int i=0;i<=amt;i++) dp[0][i]=i;

    for(int i=1;i<8;i++){
        for(int j=0;j<=amt;j++){
            int notTake=dp[i-1][j];

            int take=1e9;
            if(notes[i]<=j){
                take=1+dp[i][j-notes[i]];
            }

            dp[i][j]=min(take,notTake);
        }
    }
    

    cout<<"TOTAL NOTES REQUIRED: "<<dp[7][amt]<<endl;

    return 0;

}