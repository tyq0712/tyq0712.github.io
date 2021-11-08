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
int id;
void output(__int128 x) {
  if(x) {
    output(x/10);
    putchar(x%10+'0');
  }
}
void make(int id) {
  if(id == 1) {
    freopen("geo1.in", "wb", stdout);
    cout << "4 3\n3 3\n3 -3\n-3 3\n-3 -3" << endl;
  } else if(id == 2) {
    freopen("geo2.in", "wb", stdout);
    cout << "4 5\n5 3\n5 -3\n-5 3\n-5 -3" << endl;
  } else if(id == 3) {
    freopen("geo3.in", "wb", stdout);
    cout << "3 4\n5 0\n -5 0\n0 114514" << endl;
  } else if(id == 4) {
    freopen("geo4.in", "wb", stdout);
    cout << "4 10\n3 3\n3 -3\n-3 3\n-3 -3" << endl;
  } else if(id == 5) {
    freopen("geo5.in", "wb", stdout);
    cout << "4 95\n3 3\n3 -3\n-3 3\n-3 -3" << endl;
  } else if(id == 6) {
    freopen("geo6.in", "wb", stdout);
    __int128 x = 1; f(i,1,40) x=x*(__int128)(3);
    cout<<"4 "; output(x); puts("");
    cout<< "3 3\n3 -3\n-3 3\n-3 -3" << endl ;
  } else if(id == 7) {
    freopen("geo7.in", "wb", stdout);
    cout << "4 1000000007\n3 3\n-3 3\n3 -3\n-3 -3" << endl;
  } else if(id == 8) {
    freopen("geo8.in", "wb", stdout);
    cout << "3 10000000007\n0 0\n0 1\n0.5 sqrt(3)/2" << endl;
  } else if(id == 9) {
    freopen("geo9.in", "wb", stdout);
    __int128 x = 1; f(i,1,25) x=x*(__int128)(3);
    cout<<"6 "; output(x); puts("");
    cout << "0 0\n0 1\n-sqrt(3)/2 1.5\n-sqrt(3)/2 -1.5\n-sqrt(3) 0\n-sqrt(3) 1" << endl ;
  } else if(id == 10) {
    freopen("geo10.in", "wb", stdout);
    __int128 x = 1; f(i,1,15) x=x*(__int128)(3);
    cout<<"7 "; output(x); puts("");
    f(i,1,7) {
      cout << "cos(2π/7 * " << i << ")";
      cout << " sin(2π/7 * " << i << ")\n";
    }
  } else if(id == 11) {
    freopen("geo11.in", "wb", stdout);
    cout<<"1023 1024 \n";
    f(i,1,1023) {
      cout << "cos(2π/1023 * " << i << ")";
      cout << " sin(2π/1023 * " << i << ")\n";
    }
  }
}
int main() {
  f(i,1,11) make(i);
  return 0;
}