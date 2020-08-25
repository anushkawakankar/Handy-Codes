#include<stdio.h>
#include<set>
using namespace std;

int a[100005];
int b[100005];
int c[100005];
multiset<int> s;

int main() {
  int t;
  for( scanf("%d", &t); t--; )
  {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for( int i=0; i<n; ++i ) scanf("%d", a+i );
    for( int i=0; i<m; ++i ) scanf("%d", b+i );
    for( int i=0, x; i<k; ++i ) {
      scanf("%d", &x );
      s.insert(x);
    }

    if( m > n ) { printf("No\n"); continue; }
    int f = 1;
    int i, j;
    for( i=0, j=0; f==1 && i<n; )
    {
      if( a[i] == b[j] ) { /*printf("matched %d %d\n", a[i], a[i]);*/ ++i; ++j; continue; }
      // printf("%d %d dont match\n", a[i], b[j]);
      auto l = s.find(a[i]);
      if( l == s.end() ) { /*printf("%d not found in c\n",a[i]);*/ f = 0; break; }
      // printf("%d found in c\n",a[i]);
      ++i;
      s.erase(l);
    }
    if( f == 0 ) {
      printf("No\n");
    } else if( j != m ) {
      printf("No\n");
    } else {
      printf("Yes\n");
    }
    s.clear();
  }
}
