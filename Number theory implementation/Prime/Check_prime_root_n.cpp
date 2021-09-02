#include<iostream>
using namespace std;
typedef long long ll;

bool isPrime(ll n)
{
    if(n==0 || n==1)
        return false;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
    for(ll i=0;i<=50;i++)
        cout<<i<<" -> "<<boolalpha<<isPrime(i)<<endl;

    return 0;
}