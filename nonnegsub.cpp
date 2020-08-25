vector<int> Solution::maxset(vector<int> &A) {
    long long sum = 0;
    long long maxSum = -100005;
    long long i;
    vector<int> temp;
    vector<int> ans;
    long long all_neg = -100005;
    for(i=0;i<A.size();i++)
    {
        if(A[i] > all_neg)
            all_neg=A[i];
    }
    if(all_neg <= 0)
    {
        vector<int> ans2 = {all_neg};
        return ans2;
    }
    for(i=0;i<A.size();i++)
    {
        while(A[i]>=0 && i<A.size())
        {
            // cout<<A[i]<<" ";
            sum = sum+A[i];
            temp.push_back(A[i]);
            i++;
        }
        // cout<<A[i]<<" ";
        // cout<<"sum maxsum "<<sum<<" "<<maxSum<<endl;
        // cout<<"printing temp"<<endl;
        // for(int k = 0;k<temp.size();k++)
        //     cout<<temp[k]<<" ";
        //     cout<<endl;
        if(A[i] < 0 || sum > maxSum)
        {
            if(sum>maxSum)
            {
                maxSum = sum;
                ans.clear();
                long long j;
                for(j=0;j<temp.size();j++)
                {
                    ans.push_back(temp[j]);
                }
                temp.clear();
                sum = 0;
            }
            else if(sum == maxSum && temp.size() > ans.size())
            {
                ans.clear();
                long long j;
                for(j=0;j<temp.size();j++)
                {
                    ans.push_back(temp[j]);
                }
                temp.clear();
                sum = 0;
            }
            else if(sum == maxSum && temp.size() == ans.size())
            {
                if(temp[0] < ans[0])
                {
                    ans.clear();
                    long long j;
                    for(j=0;j<temp.size();j++)
                    {
                        ans.push_back(temp[j]);
                    }

                }
                temp.clear();
                sum = 0;
            }
            if(A[i] < 0)
            {
                temp.clear();
                sum = 0;
            }
            // cout<<"printing ans"<<endl;
            // for(int k = 0;k<ans.size();k++)
            //     cout<<ans[k]<<" ";
            //     cout<<endl;

        }

    }
    return ans;
}
