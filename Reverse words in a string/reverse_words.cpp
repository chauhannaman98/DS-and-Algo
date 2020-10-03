/*
    Problem statement: https://leetcode.com/problems/reverse-words-in-a-string/
    T = O(n)
    S = O(1)
*/

#include <iostream>
using namespace std;

void reverse(string &s, int begin, int end) {
    while(begin<=end)   {
        swap(s[begin], s[end]);
        begin++;
        end--;
    }
}

string reverseWords(string A){
    int begin = 0;
    int end = 0;
    while(end<A.size()) {
        if(A[end]==' ') {   // reverse each word in string
            reverse(A, begin, end-1);
            end++;
            begin = end;
        }
        else    {
            end++;
        }
    }
    reverse(A, begin, end-1);   // reverse last word
    reverse(A, 0, A.size()-1);  // reverse complete string

    string a;
    int i=0;
    // eliminate leading spaces
    while(A[i]==' ')    i++;
    // eliminate multiple spaces into single space
    while(i<A.size())   {
        if(A[i]==' ')   {
            a.push_back(' ');
            i++;
            while(A[i]==' ') i++;
        }
        else    {
            a.push_back(A[i]);
            i++;
        }
    }
    // elinimate trailing spaces
    if(a.back()==' ')   a.pop_back();

    return a;
}

int main()  {
    string str = "  hello whats   up  ";
    cout<<reverseWords(str);
    return 0;
}
