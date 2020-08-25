/* return 1 if there exist redundant braces. 0 if not */

int Solution::braces(string A) {
    stack<char> stk;
int n = A.length();
for(int i=0;i<n;i++){
    if(A[i]==' ')
        continue;
    if(A[i]=='(')
        stk.push('(');
    //'e' indicated that there are some expression present between the braces
    else if(A[i]=='+' || A[i]=='-' || A[i]=='*' || A[i]=='/')
        stk.push('e');
    else if(A[i]==')'){
        if(stk.empty() || stk.top()!='e')
            return 1;
        while(!stk.empty() && stk.top()!='(')
            stk.pop();
        stk.pop();
    }
}
return 0;
}
