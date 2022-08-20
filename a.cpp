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
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mx=1000009;
int main()
{
    fast;
    int cs=1;
    int t; cin>>t;
    while(t--)
    {
        cout<<"Case "<<cs++<<": ";
        int n; cin>>n;
        vector<int>v(n);
        for(auto &x: v) cin>>x;
        int maxi=*max_element(all(v));
        if(maxi<=0)
        {
            cout<<maxi<<' '<<0<<endl;
        }
        else
        {
            ll sum=0;
            for(auto x: v) if(x>=0) sum+=x;
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(v[i]<=0) continue;
                int j=i;
                while(j<sz(v) and v[j]>=0) j++;
                i=j-1;
                cnt++;
            }
            cout<<sum<<' '<<cnt-1<<endl;
        }
    }
}
