// 1 2 3 4 5 6 -> 6 1 5 2 4 3

#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    long arr[n];
	    for(int i =0;i<n;i++)cin>>arr[i];
	    long maxEle  = arr[n-1]+1;


	    //multiplying every number by a number greater than maxEle to save
	    //it in   Dividend = Divisor * Quotient + Remainder form
	    //Dividend = number at arr[i] (stores both old and new)
	    //Divisor = maxEle +1, Quotient = new number , Remainder = old no


	    //multiplying all nos; by maxEle to covert to above form
	    //notice old element will be zero for now in all that means no old element
	    //since array begins from atleast 1;
	    for(int i =0;i<n;i++)arr[i]*=maxEle;

	    int minIndex = 1;
        for(int j=0;j<n/2;j++){
            //2*minIndex-1 gives index where next minimum no to be filled
            //j gives minimum index
            arr[2*minIndex-1] = arr[2*minIndex-1]+arr[j]/maxEle;
            minIndex++;
        }
        int maxIndex = 0;
        for(int j=n-1;j>=n/2;j--){
            //2*maxIndex gives index where next maximum no to be filled
            //j gives maximum next maximum no index
            arr[2*maxIndex] =arr[2*maxIndex]+arr[j]/maxEle;
            maxIndex++;
        }

        for(int i =0;i<n;i++){
            arr[i]=arr[i]%maxEle;
            cout<<arr[i]<<" ";
        }
        cout<<endl;

	}
	return 0;
}
