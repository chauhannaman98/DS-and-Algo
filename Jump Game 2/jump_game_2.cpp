#include<iostream>
#include<vector>
using namespace std;

int jump(vector<int>& A)    {
    int n = A.size();
    if(n==1) return 0;
    if(A[0]==0) return -1;

    int ladder = A[0];  // max reachable index
    int stair = A[0];   // current ladder
    int jump = 1;

    for(int i=1; i<n; i++)  {
        if(i==n-1)  return jump;

        if(i+A[i] > ladder)
            ladder = i+A[i];
        
        stair--;    // traversing current ladder

        if(stair==0)    {   // current ladder finished
            jump++;
            if(i>=ladder) return -1;
            stair = ladder -1;
        }
    }

    return -1;
}

int main()    {
    vector<int> A = {1,1,1,1,1};
    cout<<jump(A)<<endl;
    return 0;
}
