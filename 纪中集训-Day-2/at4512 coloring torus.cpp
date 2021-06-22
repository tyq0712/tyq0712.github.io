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
#define _ 1005
int k, mat[_][_];
int main() {
  rd(k);
  if(k == 1) return puts("1\n1") & 0;
  if(k == 2) return puts("2\n1 1\n2 2") & 0;
  if(k == 3) return puts("3\n1 1 1\n2 2 2\n 3 3 3") & 0;
  int n = (k+1)/2, col=1; if(n&1) ++n;
  printf("%d\n", n);
  int t = 2*n - k;
  f(i,1,n) {
    int c[2] = {col, col+ (i>t ? 1 : 0)};
    f(j,1,n) mat[j][(i+j-1) > n ? (i+j-1-n) : (i+j-1)] = c[j&1];
    col = col+ (i>t ? 1 : 0) + 1;
  }
  f(i,1,n) f(j,1,n) printf("%d%c", mat[i][j], " \n"[j==n]);
  return 0;
}