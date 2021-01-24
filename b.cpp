#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int count,altcount,b,t,n,m,i,j;
    cin>>t;
    for(b=0;b<t;b++)
    {
        cin>>m>>n;
        vector<vector<char>> board(m,vector<char> (n));
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                cin>>board[i][j];
        count=0;
        altcount=0;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if((i+j)%2==0)
                {
                    if(board[i][j]!='*')
                        count++;
                }
                else
                    if(board[i][j]!='.')
                        count++;
            }
        
        if((m*n)%2==0)
        {
          for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if((i+j)%2==0)
                {
                    if(board[i][j]!='.')
                        altcount++;
                }
                else
                    if(board[i][j]!='*')
                        altcount++;
            }
            cout<<min(count,altcount)<<"\n";
        }
        else
        {
            cout<<count<<"\n";
        }
    }
    return 0;
}