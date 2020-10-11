#include<iostream>
using namespace std;

int partition(int a[], int s, int e) {
    int i=s;
    int pivot=a[e];
    for(int j=s; j<=e-1; j++)   {
        if(a[j]<pivot)  {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[e]);
    return i;
}

void quicksort(int a[], int s, int e)  {
    if(s>=e)    {
        return;
    }
    int p = partition(a, s, e);
    quicksort(a, s, p-1);
    quicksort(a, p+1, e);
}

int main()    {
    int a[] = {2,1,3,4,5,7};
    quicksort(a, 0, (sizeof(a)/sizeof(int))-1);
    for(int i=0;i<(sizeof(a)/sizeof(int)); i++)   {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
