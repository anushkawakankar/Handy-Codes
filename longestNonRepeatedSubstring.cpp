// Given a string,
// find the length of the longest substring without repeating characters.
//
// Example:
//
// The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
//
// For "bbbbb" the longest substring is "b", with the length of 1.

int Solution::lengthOfLongestSubstring(string A) {
    set<int> st;
    int maxLen=INT_MIN;
    int i=0,j=0;
    while(j<A.length()){
        // cout<<A[j]<<" "<<st.find(A[j])<<endl;
        // cout<<A[j]<<endl;
        if(st.find(A[j])==st.end()){
            st.insert(A[j]);
            j++;
            maxLen = max(j-i,maxLen);
        }
        else{
            st.erase(find(st.begin(),st.end(),A[i]));
            i++;
        }
    }
    return maxLen;
}
