#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
  a ^= b;
  b ^= a;
  a ^= b;
}
int main()
{
  int a, b;
  cin>>a>>b;
  swap(a,b);
  cout<<a<<" "<<b;
}
