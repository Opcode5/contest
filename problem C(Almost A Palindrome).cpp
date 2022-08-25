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
//#define ff first
//#define ss second
#define mp make_pair
#define mod 1000000007
#define mod1 1000000009
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mx=300009;
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
struct segtree
{
    pair<ll,ll>  tree[mx*4];
    pair<ll,ll>  lazy[mx*4];
    void pushdown(ll node,ll b,ll e)
    {
        if(lazy[node]!=mp(0LL,0LL))
        {
            tree[node].first+=(e-b+1)*lazy[node].first;
            tree[node].first%=mod;
            tree[node].second+=(e-b+1)*lazy[node].second;
            tree[node].second%=mod1;
            if(b!=e)
            {
                lazy[node*2].first+=lazy[node].first;
                lazy[node*2].first%=mod;
                lazy[node*2].second+=lazy[node].second;
                lazy[node*2].second%=mod1;
                lazy[node*2+1].first+=lazy[node].first;
                lazy[node*2+1].first%=mod;
                lazy[node*2+1].second+=lazy[node].second;
                lazy[node*2+1].second%=mod1;
            }
            lazy[node]={0,0};
        }
    }
    void update(ll node,ll b, ll e, ll i, ll j,pair<ll,ll> value)
    {
        pushdown(node,b,e);
        if(e<i or b>j) return ;
        if(b>=i and e<=j)
        {
            lazy[node].first+=value.first;
            lazy[node].second+=value.second;
            pushdown(node,b,e);
            return ;
        }
        ll mid=(b+e)>>1;
        update(2*node, b,mid,i,j,value);
        update(2*node+1,mid+1,e,i,j,value);
        tree[node].first=(tree[2*node].first+tree[2*node+1].first)%mod;
        tree[node].second=(tree[2*node].second+tree[2*node+1].second)%mod1;
    }
    pair<ll,ll>  query(ll node,ll b, ll e, ll i,ll j)
    {
        pushdown(node,b,e);
        if(e<i or b>j) return {0,0};
        if(b>=i and e<=j)
        {
            return tree[node];
        }
        ll mid=(b+e)>>1;
        pair<ll,ll> x=query(2*node, b,mid,i,j);
        pair<ll,ll> y=query(2*node+1,mid+1,e,i,j);
        return {(x.first+y.first)%mod,(x.second+y.second)%mod1};
    }
}ss1,pp1;
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
    pair<ll ,ll > value(ll  l,ll  r,bool ck)
    {
        ll a,b=0;
        if(ck==0)
        {
            a=(ss1.query(1,1,n,r,r).first- ss1.query(1,1,n,l-1,l-1).first)%mod;
            a=(a*p[n-l])%mod; a=(a+mod)%mod;
            b=(ss1.query(1,1,n,r,r).second- ss1.query(1,1,n,l-1,l-1).second)%mod1;
            b=(b*p1[n-l])%mod1; b=(b+mod1)%mod1;
        }
        else
        {
            a=(pp1.query(1,1,n,r,r).first- pp1.query(1,1,n,l-1,l-1).first)%mod;
            a=(a*p[n-l])%mod; a=(a+mod)%mod;
            b=(pp1.query(1,1,n,r,r).second- pp1.query(1,1,n,l-1,l-1).second)%mod1;
            b=(b*p1[n-l])%mod1; b=(b+mod1)%mod1;
        }
        return {a,b};
    }
}ss,pp;
int main()
{
    fast;
//    filein;
   pre();
   ll t; cin>>t;
   ll cs=1;
   while(t--){
        cout<<"Case "<<cs++<<":"<<endl;
   string str;
   cin>>str;
   ss.init(str);
   string temp=str;
   reverse(all(temp));
   pp.init(temp);
   ll n=sz(str);
   for(ll i=1;i<=n*4;i++) ss1.tree[i]={0,0},ss1.lazy[i]={0,0},pp1.tree[i]={0,0},pp1.lazy[i]={0,0};
   for(ll i=1;i<=n;i++) ss1.update(1,1,n,i,i,{ss.h[i],ss.h1[i]});
   for(ll i=1;i<=n;i++) pp1.update(1,1,n,i,i,{pp.h[i],pp.h1[i]});
   vector<int>dp(n+2);
   dp[1]=1;
   for(int i=2;i<=n;i++)
   {
       if(str[i-1]==str[i-2]) dp[i]=dp[i-1]+1;
       else dp[i]=1;
   }
   ll q; cin>>q;
   while(q--)
   {
       ll id; cin>>id;
       if(id==1)
       {
           ll l,r;
           cin>>l>>r;
           ll low=l,high=r;
           ll ind=l-1;
           pair<ll,ll>value=ss.value(l,r,0);
           pair<ll,ll> value1=pp.value(n-r+1,n-l+1,1);
           if(value==value1)
           {
               cout<<0<<endl;
               continue;
           }
           while(low<=high)
           {
               ll mid=(low+high)>>1;
               if(ss.value(l,mid,0)==pp.value(n-r+1,n-r+1+mid-l,1))
               {
                   ind=mid;
                   low=mid+1;
               }
               else high=mid-1;
           }
           ind+=2;
           ll len=ind-l;
           if(ss.value(ind,r-len+1,0)==pp.value(n-r+1+len-1,n-l+1-len,1))
           {
               if(ind-2>=l and str[ind-3]==str[ind-2])
               {
                   cout<<max(l,ind-2-dp[ind-2]+1)<<endl;
               }
               else cout<<ind-2+1<<endl;
           }
           else if(ss.value(ind-1,r-len,0)==pp.value(n-r+1+len,n-l+1-len+1,1)) cout<<r-len+1<<endl;
           else cout<<-1<<endl;
       }
       else
       {
            ll ind; cin>>ind;
            char ch; cin>>ch;
            ll d=ch-str[ind-1];
            ss1.update(1,1,n,ind,n,{d*p[ind]%mod,d*p1[ind]%mod1});
            pp1.update(1,1,n,n-ind+1,n,{d*p[n-ind+1]%mod,d*p1[n-ind+1]%mod1});
            str[ind-1]=ch;
       }
   }

   }
}
