#include<iostream>
#include<utility>
using namespace std;
typedef long long ll;

//(<x,y>)
pair<ll,ll> extd_eucl(ll a,ll b)
{
    if(b==0)
    {
        pair<ll,ll> ans({1,0});
        return ans;
    }
    pair<ll,ll> temp=extd_eucl(b,a%b);
    ll x1=temp.first;
    ll y1=temp.second;
    pair<ll,ll> ans({y1,x1-(a/b)*y1});
    return ans;
}

int main()
{
    pair<ll,ll> res=extd_eucl(35,20);
    cout<<res.first<<" "<<res.second<<endl;
    return 0;
}