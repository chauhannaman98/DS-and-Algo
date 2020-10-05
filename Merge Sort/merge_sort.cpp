#include <iostream>
using namespace std;

void mergeArrays(int x[], int y[], int a[], int start, int end) {
    int mid = (start+end)/2;
    int i=end;
    int j=mid+1;
    int k=start;
    while(i<=mid && j<=end) {
        if(x[i] < y[j]) {
            a[k] = x[i];
            i++;
            k++;
        }
        else    {
            a[k] = y[j];
            j++;
            k++;
        }
    }
    while(i<=mid)   {
        a[k] = x[i];
        k++;
        i++;
    }
    while(j<=end)   {
        a[k] = y[i];
        k++;
        j++;
    }
}

void mergeSort(int a[], int start, int end)   {
    if(start>=end)  {
        return;
    }
    int mid = (start+end)/2;
    int x[100], y[100];
    for(int i=0; i<=mid; i++)    {
        x[i] = a[i];
    }
    for(int i=mid+1; i<=end; i++)    {
        x[i] = a[i];
    }
    mergeSort(x, start, mid);
    mergeSort(y, mid+1, end);
    mergeArrays(x, y, a, start, end);
}

int main()    {
    int arr[] = {1,5,2,6,5};
    mergeSort(arr, 0, 4);

    for(int i=0; i<5; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}