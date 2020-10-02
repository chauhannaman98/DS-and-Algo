/*
    Problem statement: https://leetcode.com/problems/jump-game/
*/

#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int goodPos = n-1;

    for(int i=n-2; i>=0; i--)   {
        if(i+nums[i] >= goodPos)    {
            goodPos = i;
        }
    }

    if(goodPos == 0)
        return true;
    else
        return false;
}

int main()    {
    vector<int> nums1 = {3,1,1,0,4};
    vector<int> nums2 = {1,2,5,3,0};
    cout<<canJump(nums1)<<endl;
    cout<<canJump(nums2)<<endl;
    return 0;
}