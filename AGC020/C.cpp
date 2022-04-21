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
int sum, n, a[2001]; bitset< 2000 * 2000 + 1 > exi;
int main() {
  rd(n); f(i,1,n) {rd(a[i]); sum+=a[i];}
  exi[0]=1; f(i,1,n) exi |= (exi << a[i]);
  f(i,(sum+1)/2,sum) if(exi[i]) { cout << i << endl; return 0; }
  return 0;
}