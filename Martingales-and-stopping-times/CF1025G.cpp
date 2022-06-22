#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define uf(i,x,y) for(int i=x, i##end=y; i<i##end; ++i)
#define ll long long
#define pir pair<int, int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back 
char ch;
int rd() {
	int f=1, x=0; ch=getchar();
	while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
void rd(int& x) { x=rd(); }
using namespace std;
vector<int> node[505]; ll pow2[505], mod=1e9+7; int n;
int main() {
	rd(n); f(i,1,n) { int x=rd(); if(~x) node[x].pb(i); }
	pow2[0]=1; f(i,1,n) pow2[i]=2*pow2[i-1]%mod;
	ll ans = 0;
	f(i,1,n) { ans -= (pow2[node[i].size()]-1); ans = ans <= -mod ? ans + mod : ans; }
	ans += pow2[n-1]-1; ans = ans < 0 ? ans + mod : ans;
	cout << ans << endl;
	return 0;
}