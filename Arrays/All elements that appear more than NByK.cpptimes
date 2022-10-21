#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, i = 0;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    sort(arr, arr+n);
    vector <int> result;
    while(i < n)
    {
        int cnt = 1;
        while(i<n-1 && arr[i+1] == arr[i])
        {
            cnt++;
            i++;
        }
        if(cnt > (n/k))
        {
            result.push_back(arr[i]);
        }
        i++;
    }
    for(int i : result)
    {
        cout<<i<<" ";
    }
}
