#include <iostream>
using namespace std;

void mergeArrays(int *a, int s, int e)    {
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[100];

    while (i <= mid && j <= e)  {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= e)
        temp[k++] = a[j++];

    // We need to copy all element to original arrays
    for (int i = s; i <= e; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int start, int end) {
    // Base case - 1 or 0 elements
    if (start >= end)
        return;

    // Follow 3 steps
    // 1. Divide
    int mid = (start + end) / 2;

    // Recursively the arrays - start,mid and mid+1,end
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);

    // Merge the two parts
    mergeArrays(a, start, end);
}

int main()  {
    int arr[] = {1,52,42,5,2,6,5,8,18,21,16,32,0};
    mergeSort(arr, 0, (sizeof(arr)/sizeof(int))-1);

    for (int i = 0; i<(sizeof(arr)/sizeof(int)); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}