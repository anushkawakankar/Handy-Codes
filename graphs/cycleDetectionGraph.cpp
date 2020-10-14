//cycle in UD graph

bool DFS(int u, int p, vector<int> g[], vector<bool> &vis)
{
    vis[u] = true;
    for(auto i:g[u])
    {
        if(!vis[i])
        {
            if(DFS(i,u,g,vis))
                return true;
        }
        else if(i!=p || i == u)
            return true;
    }
    return false;
}

bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   vector<bool> vis(V);
   for(int i = 0;i<V;i++)
   {
       if(!vis[i] && DFS(i,-1,g,vis))
            return true;
        return false;
   }

}

// cycle in Directed graph

bool cyclic(int i, int V, vector<int> adj[],bool visited[], bool inTheCall[])
{

    visited[i]=true;
    inTheCall[i]=true;
    for(int j =0;j<adj[i].size();j++)
    {
        if(!visited[adj[i][j]] &&  cyclic(adj[i][j],V,adj,visited,inTheCall))
        {
            return true;
        }
        else{
            if(inTheCall[adj[i][j]])
            return true;
        }
    }

    inTheCall[i]=false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    bool visited[V];
    bool inTheCall[V];
    for(int  i=0;i<V;i++)
    {
        visited[i]=false;
        inTheCall[i]= false;
    }

    for(int i =0;i<V;i++)
    {  if(!visited[i]){
      if(cyclic(i,V,adj,visited,inTheCall))
      return true;
    }
    }
    return false;
}
