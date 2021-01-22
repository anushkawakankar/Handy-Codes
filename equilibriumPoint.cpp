// sum of left side = sum of right side

#include <iostream>
using namespace std;

int main() {
 int T;
 cin>>T;
 for(int i=0;i<T;i++)
 {
     int N;
     cin>>N;
     int A[N],B[N],C[N];
     for(int j=0;j<N;j++)
         cin>>A[j];
     int suml=0,sumr=0,flag=0;
     for(int j=0;j<N;j++)
     {
         suml=suml+A[j];
         B[j]=suml;
         sumr=sumr+A[N-j-1];
         C[N-j-1]=sumr;
     }
     int j=1;
     while(j<N-1)
     {
         if(B[j-1]==C[j+1])
             {
                 cout<<j+1<<"\n";
                 flag=1;
                 break;
             }
         j++;
     }
     if(N==1)
     {
         cout<<1<<"\n";
         flag=1;
     }
     if(flag==0)
         cout<<"-1"<<"\n";
 }
 return 0;
}
