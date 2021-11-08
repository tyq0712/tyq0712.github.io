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

int tr[35000005][2], las=1, tot=1, len[35000005], fail[35000005], p, q0, cur, nw;
void insert(char ch) {
  p=las, cur=las=++tot; len[cur]=len[p]+1;
  while(p && !tr[p][ch]) { tr[p][ch]=cur; p=fail[p]; }
  if(!p) fail[cur]=1;
  else {
    q0=tr[p][ch];
    if(len[q0]==len[p]+1) fail[cur]=q0;
    else {
      int nw=++tot; len[nw]=len[p]+1; fail[nw]=fail[q0]; tr[nw][0]=tr[q0][0]; tr[nw][1]=tr[q0][1];
      while(p && tr[p][ch]==q0) { tr[p][ch]=nw; p=fail[p]; }
      fail[cur]=fail[q0]=nw;
    }
  }
}
void build(char* str) {f(i,1,strlen(str+1)) insert(str[i]-'0');}

int l=1, r=0, c=0;
void bfs(int s) {
  len[++r]=s; int solved = 0;
  while(r>=l) {
    int lf=l, rf=r; l=r+1; 
    f(i,lf,rf) {
      if(!tr[tr[len[i]][1]][0] || !tr[tr[len[i]][1]][1]) solved=tr[len[i]][1];
      if(!tr[tr[len[i]][0]][0] || !tr[tr[len[i]][0]][1]) solved=tr[len[i]][0];
      if(tr[len[i]][1] && !fail[tr[len[i]][1]]) { 
        len[++r] = (tr[len[i]][1]); fail[tr[len[i]][1]]=len[i];
      }
      if(tr[len[i]][0] && !fail[tr[len[i]][0]]) {
        len[++r] = (tr[len[i]][0]); fail[tr[len[i]][0]]=len[i];
      }
    }
    if(solved) break;
  }
  int p=solved, q=-1;
  while( p!=1 ) {
    q=p; p=fail[p]; cout << ( tr[p][1] == q );
  }
  cout<< ( !tr[solved][0] ? 0 : 1 ) << endl;
}

int main() {
  freopen("D11.in", "rb", stdin);
  int c1=clock(), c0=getchar();
  while(isdigit(c0)) { insert(c0-'0'); c0=getchar(); }
  int c2=clock();
  // cerr << c2 - c1 << "ms" << '\n' ;
  bfs(1);
  int c3=clock();
  // cerr << c3 - c1 << "ms" << '\n' ;
  return 0;
}