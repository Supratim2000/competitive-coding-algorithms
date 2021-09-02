#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

vector<vector<ll>> mult(vector<vector<ll>> mat1,vector<vector<ll>> mat2)
{
    vector<vector<ll>> ans{
        {0,0},
        {0,0}
    };
    ll n=2;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            ll blockRes=0;
            for(ll k=0;k<n;k++)
                blockRes+=mat1[i][k]*mat2[k][j];
            ans[i][j]=blockRes;
        }
    }
    return ans;
}

vector<vector<ll>> Identity()
{
    vector<vector<ll>> ans{
        {1,0},
        {0,1}
    };
    return ans;
}

vector<vector<ll>> matExp(vector<vector<ll>> mat,ll n)
{
    if(n==0)
        return Identity();
    vector<vector<ll>> X=matExp(mat,n/2);
    if(n&1)
        return mult(mult(X,X),mat);
    else
        return mult(X,X);
}

int main()
{
    vector<vector<ll>> a{
        {2,4},
        {5,3}
    };
    vector<vector<ll>> res=matExp(a,7);
    for(ll i=0;i<2;i++)
    {
        for(ll j=0;j<2;j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}