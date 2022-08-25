#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
template <typename T> using os=tree < T, null_type ,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update >;

///find_by_order(k) : returns an iterator of the k-th index
///order_of_key(k) :  returns the number of elements less than k
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mx=300009;
int par[mx];
int findp(int x)
{
    if(x==par[x]) return x;
    return par[x]=findp(par[x]);
}
int ss[mx];
vector<int> v;
os<int>s[mx];
int main()
{
    fast;
    int cs=1;
    int t; cin>>t;
    while(t--)
    {
        cout<<"Case "<<cs++<<":"<<endl;
        int n; cin>>n;
        for(int i=1;i<=n;i++) par[i]=i,ss[i]=1;
        for(int i=1;i<=n;i++) s[i].clear();
        int q; cin>>q;
        while(q--)
        {
            int id; cin>>id;
            if(id==0)
            {
                int a,b;
                cin>>a>>b;
                int aa=findp(a);
                int bb=findp(b);
                if(aa==bb) continue;
                if(ss[aa]>ss[bb])
                {
                    par[bb]=aa;
                    for(auto x:s[bb]) s[aa].insert(x);
                    ss[aa]+=ss[bb];
                    s[bb].clear();
                    ss[bb]=0;
                }
                else
                {
                    par[aa]=bb;
                    for(auto x:s[aa]) s[bb].insert(x);
                    ss[bb]+=ss[aa];
                    s[aa].clear();
                    ss[aa]=0;
                }

            }
            else if(id==1)
            {
                int u,x;
                cin>>u>>x;
                int d=findp(u);
                s[d].insert(x);
            }
            else
            {
                int u,l,r;
                cin>>u>>l>>r;
                int d=findp(u);
                int ans=s[d].order_of_key(r+1)-s[d].order_of_key(l);
                cout<<ans<<endl;
            }
        }
    }
}

