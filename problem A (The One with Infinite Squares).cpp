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
typedef long long T;
ll seed1,seed2;
ll n;
ll get_random()
{
    seed1 = (seed1 * 1103515243 + 12345)%(2012345671);
    seed2 = (seed2 * 1092104927 + 54321)%(2094828103);
    ll r = (seed1 * seed2) % 100000;
    return r;
}
struct pt
{
    ll x, y;
    pt(T _x, T _y) : x(_x), y(_y) {}
    pt() {}
    pt operator+(const pt &p) const
    {
        return pt(x + p.x, y + p.y);
    }
    pt operator-(const pt &p) const
    {
        return pt(x - p.x, y - p.y);
    }
    bool operator<(const pt &p) const
    {
        if (x != p.x)
            return x < p.x;
        return y < p.y;
    }
    bool operator==(const pt &p) const
    {
        return (x == p.x and y == p.y);
    }
};
ll cross(pt v, pt w)
{
    return v.x * w.y - v.y * w.x;
}
ll orient(pt a, pt b, pt c)
{
    return cross(b - a, c - a);
}
ll sz;
vector<pt> monotoneChain(vector<pt> &v)
{
    if(v.size()==1)
        return v;
    sort(v.begin(), v.end());
    vector<pt> up(2*v.size()+2),
           down(2*v.size()+2);
    ll szup=0, szdw=0;
    for(ll i=0; i<v.size(); i++)
    {
        while(szup>1 && orient(up[szup-2], up[szup-1],v[i])>=0) szup--;
        while(szdw>1 && orient(down[szdw-2], down[szdw-1], v[i])<=0) szdw--;
        up[szup++]=v[i];
        down[szdw++]=v[i];
    }
    if(szdw>1) szdw--;
    reverse(up.begin(), up.begin()+szup);
    for(ll i=0; i<szup-1; i++) down[szdw++]= up[i];
    if(szdw==2 && down[0].x==down[1].x && down[0].y==down[1].y)
    {
        szdw--;
    }
    sz=szdw;
    return down;
}

ll is_point_in_convex(vector<pt>& p, pt &x)
{
    ll n = p.size();
    if (n < 3)
        return 1;
    ll a =orient(p[0], p[1], x), b = orient(p[0], p[n- 1], x);
    if (a < 0 || b > 0)
        return 1;
    ll l = 1, r = n - 1;
    while (l + 1 < r)
    {
        ll mid = l + r >> 1;
        if (orient(p[0], p[mid], x) >= 0)
            l = mid;
        else
            r = mid;
    }
    ll k = orient(p[l], p[r], x);
    if (k <= 0)
        return -k;
    if (l == 1 && a == 0)
        return 0;
    if (r == n - 1 && b == 0)
        return 0;
    return -1;
}
ll areaPolygon(const vector<pt> &p)
{
    ll area = 0;
    for (ll i = 0, n = p.size(); i < n; i++)
    {
        area += cross(p[i], p[(i + 1) % n]);
    }
    return abs(area);
}
int main()
{
    fast;
    ll cs=1;
    ll t;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<cs++<<": ";
        cin>>n>>seed1>>seed2;
        vector<pt>v;
        for(ll i=0; i<n; i++)
        {
            v.pb({get_random(),get_random()});
        }
        vector<pt>vv;
        ll ans=0;
        ll pre=0;
        for(ll i=0; i<n; i++)
        {

            if(is_point_in_convex(vv,v[i])<=0) ans+=pre;
            else
            {
                vv.pb(v[i]);
                sz=vv.size();
                auto tmp = monotoneChain(vv);
                vv.clear();
                for(ll j=0; j<sz; j++)
                {
                    vv.pb(tmp[j]);
                }
                pre = areaPolygon(vv);
                ans+=pre;
            }
        }
        cout<<ans<<endl;
    }
}

