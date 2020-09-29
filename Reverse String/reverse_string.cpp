#include <iostream>
#include <stack>
using namespace std;

class Solution  {
    public:
        string reverseString(string A) {
            int start = 0;
            int end = A.size()-1;

            while(start<=end)   {
                swap(A[start],A[end]);
                start++;
                end--;
            }

            // ****using stack****
            // stack<char> st;
            // for(int i=0; i<A.size(); i++)   {
            //     // push every char inside stack
            //     st.push(A[i]);
            // }

            // //pop every character
            // for(int i=0; i<A.size(); i++)    {
            //     A[i] = st.top();
            //     st.pop();
            // }

            return A;   
        }
};

int main()    {
    string str = "hello";
    Solution sol;
    cout<<sol.reverseString(str);
    return 0;
}