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

pair<ll,ll> transform(ll x,ll y,ll k)
{
    ll nx;
    ll ny;
    vector<vector<ll>> transMat{
        {1,1},
        {-1,2}
    };
    vector<vector<ll>> mat=matExp(transMat,k);
    nx=mat[0][0]*x+mat[0][1]*y;
    ny=mat[1][0]*x+mat[1][1]*y;
    pair<ll,ll> res({nx,ny});
    return res;
}

int main()
{
    //transformation of (x,y)->(x+y,2y-x) k times;
    ll k=3;
    ll x=3;
    ll y=5;

    pair<ll,ll> res=transform(x,y,k);
    cout<<res.first<<" "<<res.second<<endl;

    return 0;
}