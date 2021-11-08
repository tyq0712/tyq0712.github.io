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
int n, a[1005], t;
int main() {
  rd(t);
  f(i,1,t) {
    int ans=0;
    rd(n);
    if(n%2 == 0) {
      for(int i=1; i<=n; i+=2) cout << i+1 << " " << i << " ";
      cout << endl;
    } else {
      for(int i=1; i<=n-3; i+=2) cout << i+1 << " " << i << " ";
      cout << n-1 << " " << n << " " << n-2 << endl;
    }
  }
  return 0;
}