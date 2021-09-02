#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll x,ll y)
{
    if(x==y)
        return x;
    else if(x>y)
        return gcd(x-y,y);
    else
        return gcd(x,y-x);
}

int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}