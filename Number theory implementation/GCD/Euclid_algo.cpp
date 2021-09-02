#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll x,ll y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}

int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}