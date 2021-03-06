//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpll; 

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int t;cin>>t;while(t--)
#define forn(f,n) for(int i=f;i<f+n;i++)
#define rforn(l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i];
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 1005;
/////////////////FastExp///////////////////
ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}
/////////////////FastExp///////////////////
//////////////////Sieve////////////////////
vector<bool> is_prime(MAX+1, true);
void Sieve()
{
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i <= MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
        	for (j = i * i; j <= MAX; j += i)
            	is_prime[j] = false;
    	}
	}
}
//////////////////Sieve////////////////////



int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vi A(n+5),B(m+5);
	take(A,0,n);
	take(B,0,m);
	vector<ll> iB(m+5),iA(n+5);
	int i=0;
	while(i<m)
	{
		int siz=0;
		while(B[i]==1&&i<m)
		{
			i++;
			siz++;
			iB[siz]++;
		}
		i++;
	}
	i=0;
	while(i<n)
	{
		int siz=0;
		while(A[i]==1&&i<n)
		{
			i++;
			siz++;
			iA[siz]++;
		}
		i++;
	}
	
	for(int i=n+1;i>0;i--)
	{
		iA[i]+=iA[i+1];
	}
	for(int i=m+1;i>0;i--)
	{
		iB[i]+=iB[i+1];
	}

	ll sum=0;
	for(int i=1;i<n+5;i++)
	{
		if(k%i==0)
		{
			if(k/i>m) continue;
			sum+=iA[i]*iB[k/i];
		}
	}
	cout<<sum<<endl;


}		