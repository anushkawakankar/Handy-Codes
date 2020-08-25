// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
//
// Sample Input :
//
// (1, 1)
// (2, 2)
// Sample Output :
//
// 2


int gcd(int x, int y) {
    return (y==0?x:gcd(y,x%y));
}

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_map<string,int> Line;
    int overlap=0,vertical=0,MaxPoints;
    MaxPoints=2<=A.size()?2:A.size();
    int cur=0;
    for(int i1=0;i1<A.size();i1++)
    {
      overlap=0; vertical=0; cur=0;Line.clear();
      for(int i2=i1+1;i2<A.size();i2++)
      {
        int N=B[i2]-B[i1];
        int D=A[i2]-A[i1];
        if(N<0)
          N*=-1; D*=-1;
        if((N==0)&&(D==0))
          ++overlap;
        else if(D==0)
        {
          ++vertical;cur=(cur>=vertical)?cur:vertical;
        }
        else
        {
          int X=gcd(N,D);
          N/=X;
          D/=X;
          long long C1=A[i2]*B[i1]-B[i2]*A[i1];
          long long C2=A[i2]-A[i1];
          X=gcd((int)C1,(int)C2);
          C1=(int)C1/X;
          C2=(int)C2/X;
          string s=to_string(N);
          s+=to_string(D);
          s+=to_string(C1);
          s+=to_string(C2);
          Line[s]++;
          cur=(cur>=(Line[s])?cur:(Line[s]));
        // cout<< s<<" “;
        }
        //cout<<N<<”/"<<D<<":";
        // cout<< overlap << " “<< vertical<<” "<<cur;
        // cout<<endl;

      }
      MaxPoints=(MaxPoints>=(cur+overlap+1))?MaxPoints:(cur+overlap+1);
    }
    return MaxPoints;
}
