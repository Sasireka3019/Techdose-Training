#include <bits/stdc++.h>
using namespace std;
void selectionSort(int n, int arr[])
{
  for(int i=0; i<n-1; i++)
  {
    int minIdx = i;
    for(int j=i+1; j<n; j++)
    {
      if(arr[j] < arr[minIdx])
        minIdx = j;
    }
    int temp = arr[i];
    arr[i] = arr[minIdx];
    arr[minIdx] = temp;
  }
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
  selectionSort(n, arr);
  for(int i=0; i<n; i++)
  {
    cout<<arr[i]<<" ";
  }
}
