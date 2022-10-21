#include <iostream>
using namespace std;
int merge(int arr[], int left, int mid, int right)
{
    int lst[right], inversionCount = 0;
    int i = left, j = mid, k = 0;
    while(i < mid && j <= right)
    {
        if(arr[i] <= arr[j])
        {
            lst[k] = arr[i];
            i++;
        }
        else 
        {
            inversionCount += (mid-i);
            lst[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid)
    {
        lst[k] = arr[i];
        k++;
        i++;
    }
    while(j <= mid)
    {
        lst[k] = arr[j];
        k++;
        j++;
    }
    for(i = left, k = 0; i <= right; i++, k++) 
    {
        arr[i] = lst[k];
    }
    return inversionCount;
}
int mergeSort(int arr[], int left, int right)
{
    if(right <= left)
        return 0;
    int inversionCount = 0;
    int mid = left + (right-left)/2;
    inversionCount += mergeSort(arr, left, mid);
    inversionCount += mergeSort(arr, mid+1, right);
    inversionCount += merge(arr, left, mid+1, right);
    return inversionCount;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int count = mergeSort(arr, 0, n-1);
    cout<<count;
}
