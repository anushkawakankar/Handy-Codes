// given a string of numbers, find all combinations of letters possible as on a phone keypad

void letter( int it, string &A, vector<vector<char>> &ip, int s, vector<string> &ans, string curr ) {

    if( curr.size() == s ){

        ans.push_back( curr );
        return;
    }

    for( int i=0; i<ip[A[it]-48].size(); i++ ){

        curr.push_back( ip [A[it]-48][i] );
        letter( it+1, A, ip, s, ans, curr );
        curr.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {

    vector<string> ans;
    int s = A.size();

    vector<vector<char>> ip(10);
    string curr;

    ip[1] = vector<char>(1);
    ip[0] = vector<char>(1);
    ip[7] = vector<char>(4);
    ip[9] = vector<char>(4);

    for( int i=2; i<9; i++ ){

        if( i != 7 )
            ip[i] = vector<char>(3);
    }

    ip[1] = {'1'};
    ip[2] = {'a','b','c'};
    ip[3] = {'d','e','f'};
    ip[4] = {'g','h','i'};
    ip[5] = {'j','k','l'};
    ip[6] = {'m','n','o'};
    ip[7] = {'p','q','r','s'};
    ip[8] = {'t','u','v'};
    ip[9] = {'w','x','y','z'};
    ip[0] = {'0'};

    letter( 0, A, ip, s, ans, curr);

    return ans;
}
