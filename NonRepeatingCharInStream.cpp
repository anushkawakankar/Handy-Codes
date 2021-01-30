/* Q1
// Given a continuous flowing stream of characters, find the first non-repeating char from the stream. 

// Input: 
// a, b, c, d       (   <-- a, b, c, d  <-- )*/

/* Q1
// Given a continuous flowing stream of characters, find the first non-repeating char from the stream. 

// Input: 
// a, b, c, d , a ,c    (   <-- a, b, c, d  <-- )*/
// i

queue<char> q;
long long hash[256];

void func(char s)
{
    
    
    if(hash[s-'0'] == 1) q.push(s);
    while(!q.empty())
    {
        if(hash[q.front() - '0'] > 1) q.pop();
        else cout<<q.front()<<endl;
    }
    if(q.empty()) cout<<""<<endl;
    
}





