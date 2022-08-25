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
const ll mx=4e6+7;
ll  p[mx],p1[mx];
void pre()
{
    p[0]=1; p1[0]=1;
    for(ll  i=1;i<mx;i++)
    {
        p[i]=(p[i-1]*13331LL)%mod;
        p1[i]=(p1[i-1]*23333LL)%mod1;
    }
}
struct Hash
{
    ll h[mx],h1[mx];
    ll  n;
    void init(string &str)
    {
        n=str.size();
         h[0]=0; h1[0]=0;
        for(ll  i=1;i<=n;i++)
        {
            h[i]=h[i-1]+(str[i-1]-'a'+1)*p[i]; h[i]%=mod;
            h1[i]=h1[i-1]+(str[i-1]-'a'+1)*p1[i]; h1[i]%=mod1;
        }
    }
    pair<ll ,ll > value(ll  l,ll  r)
    {
        ll  a=h[r]-h[l-1]; a=(a*p[n-l])%mod; a=(a+mod)%mod;
        ll  b=h1[r]-h1[l-1];b=(b*p1[n-l])%mod1; b=(b+mod1)%mod1;
        return {a,b};
    }
}ss,pp;
string str,pat;
ll k;
pair<ll,ll> get(ll ind, ll a, ll b)
{
    ll suru=a-ind+sz(str);
    ll ses=b-ind+sz(str);
    return {suru,ses};
}
bool check(ll ind)
{
    ll cnt=-1;
    ll pre=ind-1;
    while(pre<ind+sz(pat) and cnt<=k)
    {
        pre++;
        cnt++;
        ll low=pre,high=ind+sz(pat)-1;
        ll ans=pre-1;
        while(low<=high)
        {
            ll mid=(low+high)>>1;
            if(ss.value(pre+1,mid+1)==ss.value(get(ind,pre,mid).ff+1,get(ind,pre,mid).ss+1))
            {
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        pre=ans+1;
    }
    return cnt<=k;
}
int main()
{
    fast;
   pre();
   int t; cin>>t;
   int cs=1;
   while(t--){
        cout<<"Case "<<cs++<<": ";
   cin>>str>>pat>>k;
   string temp=str+pat;
   ss.init(temp);
   ll ans=0;
   for(ll i=0;i<sz(str);i++)
   {
       if(i+sz(pat)>sz(str)) break;
       if(check(i)) ans++;
   }
   cout<<ans<<endl;
   }
}

