#include <iostream>
#include <string.h>
using namespace std;

/*
int lcs(string s1, string s2, int n, int m)
{
    if(memo[n][m]!=-1)
        return memo[n][m];

    if(n==0 || m==0)
        memo[n][m]=0;

    else
    {
        if(s1[n-1]==s2[m-1])
            memo[n][m] = 1 + lcs(s1,s2,n-1,m-1);
        else
            memo[n][m] = max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
    }
}
*/
int lcs1(string s1, string s2, int n, int m)
{
  int dp[n+1][m+1];
  for(int i=0;i<n+1;i++)
  {
    dp[0][i]=0;
  }
  for(int i=0;i<n+1;i++)
  {
    dp[i][0]=0;
  }
  for(int i=1;i<n+1;i++)
  {
    for(int j=1;j<m+1;j++)
    {
      if(s1[i]==s2[j])
      {
        dp[i][j]=1+dp[i-1][j-1];
      }
      else
      dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }

for(int i=0;i<n+1;i++)
{
  for(int j=0;j<m+1;j++)
  {
    cout<<dp[i][j]<<"\t";
  }
  cout<<"\n";
}

cout<<"--------------------------------------------------";
int i=n,j=m,l=dp[n][m];
int index = dp[m][n];

char lcs[index+1];
lcs[index] = '\0'; // Set the terminating character

while(i>0 && j>0)
{
  cout<<i<<"\t"<<j<<"\n";
  if(s1[i-1]==s2[j-1])
  {
    lcs[index-1] = s1[i-1]; // Put current character in result
    i--;
    j--;
    index--;
  }
  else
  {
    if(dp[i-1][j]>dp[i][j-1])
      i-=1;
    else
    j-=1;
  }
}
cout<<lcs;
return dp[n][m];
}

int main() {


	string s1="GEEK", s2="GFEK";

	int n = 4, m = 4;

	cout<<lcs1(s1,s2,n,m);
}
