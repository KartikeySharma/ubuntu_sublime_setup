#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test int t;cin>>t;while(t--)
#define REP(i,n) for (int i = 0; i < n; i++)
#define RREP(i,n) for (int i = n; i >= 0; i--)
#define MOD 1000000007
#define MOD2 998244353
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define ii pair<int,int>
#define llll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<ii>
#define vllll vector<llll>
#define ff first
#define ss second
#define INF 1000000000
#define HINF 1000000000000000
#define mem(a,b) memset(a,b,sizeof(a))
#define arrin(x,n) int x[n]; for(int o=0;o<n;o++) cin>>x[o]
#define arrout(x,n) for(int o=0;o<n;o++) cout<<x[o]<<" "; cout<<endl
#define vecin(x,n); vi x;int hool; for(int o=0;o<n;o++) {cin>>hool; x.pb(hool);}
#define vecout(x,n) for(int o=0;o<n;o++) cout<<x[o]<<" "; cout<<endl
#define all(x) x.begin(),x.end()
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<" "<<#y<<'='<<y<<endl
#define deb3(x,y,z) cout<<#x<<'='<<x<<" "<<#y<<'='<<y<<" "<<#z<<'='<<z<<endl
#define debarr(arr,n) for(int o=0;o<n;o++) deb2(o,arr[o])
#define debarrall(arr) for(int o=0;o<arr.size();o++) deb2(o,arr[o])
#define IO freopen("input.txt", "r", stdin); freopen("output.txt", "w+", stdout)
const double pi = 3.14159265358979323846;

namespace number_theory{
    int powersimple(int a, int b){//a^b
        int res=1;
        while(b>0){
            if(b&1)
            {res=(res*a);
            b--;}
            a=(a*a);
            b>>=1;
        }
        return res;
    }

    int ncr(int n,int k)
    {
        int ans=1;
        if(k>n-k)
        k=n-k;
        for(int i=1;i<=k;i++)
        ans*=(n-i+1),ans/=i;
        return ans;
    }


    int power(int x,int y,int p)
    {
        int res = 1;
        x = x % p;
        while (y > 0) {
            if (y & 1)
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    int modInverse(int n, int p)
    {
        return power(n, p - 2, p);
    }

    int ncrModPFermat(int n,int r, int p)
    {

        if (r == 0)
            return 1;

        int fac[n + 1];
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = (fac[i - 1] * i) % p;

        return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
    }

    int gcd(int a, int b){
        return (b==0)?a:gcd(b,a%b);
    }
}
using namespace number_theory;

///////////////END OF TEMPLATE//////////////////

void solve(){
    int m,n;cin>>m>>n;
    vector<string> board(m);
    REP(i,m){
        cin>>board[i];
    }
    int cnt=0,cnt2=0;
    REP(i,m) {
        REP(j,n) {
            int ch=i+j;
            if(ch%2==0) {
                if(board[i][j]=='.')
                    cnt++;
            }
            else {
                if(board[i][j]=='*')
                    cnt++;
            }
        }
    }
    int ch=m*n;
    if(ch%2==0) {
        REP(i,m) {
            REP(j,n) {
                int check=i+j;
                if(check%2==0) {
                    if(board[i][j]=='*')
                        cnt2++;
                }
                else {
                    if(board[i][j]=='.')
                        cnt2++;
                }
            }
        }
        cout<<min(cnt,cnt2)<<endl;
    }
    else {
        cout<<cnt<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
     #endif
    
    test{
        solve();
    }
    return 0;
}
