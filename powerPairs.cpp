//Given two arrays X[] and Y[] of size M and N respectively. Find number of pairs such that x^y > y^x where x is an element from X[] and y is an element from Y[].

long long countPairs(int X[], int Y[], int m, int n) {
        long long res = 0;
        sort(X,X+m);
        sort(Y,Y+n);
        int cnt[5] = {};
        for(int i = 0; i<n; i++)
            if(Y[i]<5)
                cnt[Y[i]]++;

        for(int i = 0;i<m;i++)
        {
            int num = n - (upper_bound(Y,Y+n,X[i])-Y);
            if(X[i] == 1)
                res += cnt[0];
            else if(X[i] == 2)
                res += num + cnt[0] + cnt[1] - cnt[3] - cnt[4];

            else if(X[i] == 3)
                res += num + cnt[0] + cnt[1] + cnt[2];

            else
                res += num + cnt[0] + cnt[1];

        }
        return res;

    }
