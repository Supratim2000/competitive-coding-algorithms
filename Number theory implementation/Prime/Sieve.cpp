#include<iostream>
using namespace std;
typedef long long ll;
const ll NMAX=1e8+1;

bool prime[NMAX];

void sieve()
{
    prime[0]=false;
    prime[1]=false;
    for(ll i=2;i<NMAX;i++)
        prime[i]=true;
    for(ll i=2;i*i<NMAX;i++)
    {
        if(prime[i])
        {
            for(ll j=i*i;j<NMAX;j+=i)
                prime[j]=false;
        }
    }
}

int main()
{
    sieve();
    for(ll i=10e6;i<=10e7;i++)
        if(prime[i])
            cout<<i<<" ";
    cout<<endl;
    return 0;
}