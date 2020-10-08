/*
    Question: https://leetcode.com/problems/single-number/submissions/
    Answer: https://leetcode.com/submissions/detail/406255584/
*/

#include<iostream>
#include<vector>
using namespace std;

int getSingleNumber(vector<int>& nums)  {
    int ans=0;
    for(int i=0; i<nums.size(); i++)    {
        ans = ans^nums[i];
    }
    return ans;
}

int main()    {
    vector<int> nums = {2,7,3,3,2};
    cout<<getSingleNumber(nums);
    return 0;
}
