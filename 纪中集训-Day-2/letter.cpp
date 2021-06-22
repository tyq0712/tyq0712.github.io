#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define ll long long
#define pir pair<int, int>
#define fir first
#define sec second
#define mp make_pair
char ch;
int rd() {
  int f=1, x=0; ch=getchar();
  while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
  while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
  return x*f;
}
void rd(int& x) { x=rd(); }
using namespace std;
const int inf = 0x3f3f3f3f;
#define _ 2000005
int str[_], n, m, ans=inf, p[_], v[_];
namespace brute {
  int chk(int len) {
    pair<string, int> s[10];
    f(i,1,len) {
      s[i].fir.clear();
      f(j,i,len) s[i].fir.push_back(str[j] + '0');
      s[i].sec = i;
    }
    sort(s+1, s+1+len);
    // f(i,1,len) cout<< s[i].fir << endl;
    // getchar();
    f(i,1,len) if(s[i].sec != p[i]) return inf;
    f(i,1,len) printf("%d", str[i]); puts("");
    int ans=0; f(i,1,len) ans += abs(str[i]-v[i]);
    return ans;
  }
  void solve() {
    for(str[1]=1; str[1]<=m; ++str[1]) for(str[2]=1; str[2]<=m; ++str[2]) for(str[3]=1; str[3]<=m; ++str[3]) for(str[4]=1; str[4]<=m; ++str[4]) for(str[5]=1; str[5]<=m; ++str[5]) for(str[6]=1; str[6]<=m; ++str[6]){
      ans = min( ans, chk(n) );
    }
    printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans);
  }
}
#define fopen(X) { freopen(#X".in", "rb", stdin); freopen(#X".out", "wb", stdout); }
int main() {
	fopen(letter);
  rd(n); rd(m); f(i,1,n) rd(p[i]); f(i,1,n) rd(v[i]);
  brute::solve();
  // if s_1 >= s_2 >= s_3 >= etc.
  
  return 0;
}