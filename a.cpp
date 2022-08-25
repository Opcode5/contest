#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define line cout<<"--------------------------"<<endl
#define dd(x) cout<<#x<<" = "<<x<<' '
#define sz(v) (ll)v.size()
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define all(v) v.begin(),v.end()
#define pb push_back
#define pi acos(-1)
#define ff first
#define ss second
#define mp make_pair
#define mod 1000000007
#define mod1 1000000009
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mx=300009;
int main()
{
    fast;
    ll cs=1;
    ll t; cin>>t;
    while(t--)
    {
        cout<<"Case "<<cs++<<": ";
        ll n; cin>>n;
        vector<ll>solve(n+3),penalty(n+3);
        vector<ll>f[n+3];
        for(ll i=1;i<=n;i++)
        {
            ll id; cin>>id;
            cin>>solve[id-1];
            cin>>penalty[id-1];
            ll d; cin>>d;
            for(ll j=0;j<d;j++)
            {
                ll x; cin>>x;
                f[id-1].pb(x);
            }
        }
        vector<ll>result(n);
        for(auto &x: result) cin>>x;
        bool ck=0;
        bool aa=0;
        ll ss=0,pp=0;
        for(auto x: result)
        {
            if(aa==0)
            {
                aa=1;
                ss=solve[x-1]+sz(f[x-1]);
                pp=penalty[x-1];
                for(auto xx: f[x-1]) pp+=xx;
            }
            else
            {
                ll pe=penalty[x-1];
                ll se=solve[x-1];
                for(ll j=0;j<sz(f[x-1]);j++)
                {
                    if(solve[x-1]+j+1<ss)
                    {
                        se++;
                        pe+=f[x-1][j];
                    }
                    if(solve[x-1]+j+1==ss)
                    {
                        if(pe+f[x-1][j]>=pp)
                        {
                            se++;
                            pe+=f[x-1][j];
                        }
                    }
                }
                if(se>ss or (se==ss and pe<pp )) ck=1;
                pp=pe;
                ss=se;
            }
//            cout<<x<<' '<<ss<<' '<<pp<<endl;
        }
        if(ck) cout<<"Say no to rumour >:"<<endl;
        else cout<<"We respect our judges :)"<<endl;
    }
}

