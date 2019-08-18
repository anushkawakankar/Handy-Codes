#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int dist[10000][10000];
int non_affect_dist[10000][10000];
int affected[10000];

int travllingSalesmanProblem(int s,int n) 
{ 
    vector<int> vertex; 
    for (int i = 1; i < n; i++) 
        if (i != s) 
            vertex.push_back(i); 
  
    int min_path = 100000; 
    do { 
  
        int current_pathweight = 0; 
          
        int k = s; 
        for (int i = 0; i < vertex.size(); i++) { 
            current_pathweight += dist[k][vertex[i]]; 
            k = vertex[i]; 
        } 
        current_pathweight += dist[k][s]; 
  
        min_path = min(min_path, current_pathweight); 
         
    } while (next_permutation(vertex.begin(), vertex.end())); 
  
    return min_path; 
} 


void tsp(vector<bool>& v, int currPos,int s, int n,int count, int cost,int nodes_to_reach, int &ans)
{
	// cout<<"nodes to reach "<<nodes_to_reach<<endl;

	cout<<s<<" to "<<currPos<<" is "<<cost<<" dist"<<endl;

	if(count == nodes_to_reach)
	{
		ans = min(ans,cost);
		return;
	}

	for( int i = 1; i<=n; i++)
	{
		if(!v[i] && dist[currPos][i])
		{
			v[i] = true;
			tsp(v,i,s,n,count+1,cost+dist[currPos][i],nodes_to_reach,ans);

			v[i] = false;
		}
	}
}

int min_dist(int s,int n,int k)
{
	int i;
	for(i=1;i<=n;i++)
	{
		dist[s][i] = non_affect_dist[s][i];
		dist[i][s] = non_affect_dist[i][s];
	}

	cout<<s<<endl;
	// for(i=1;i<=n;i++)
	// {
	// 	for(int j = 1;j<=n;j++)
	// 	{
	// 		cout<<dist[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	vector<bool> v(n+1);
	for(i=0;i<=n;i++)
		v[i] = false;

	v[s] = true;
	int ans = travllingSalesmanProblem(s,n);;
	// tsp(v,s,s,n,1,0,k+1,ans);
	// ans = 10000000;
	for(i=0;i<=n;i++)
		v[i] = false;
	for(i=1;i<=n;i++)
	{
		dist[s][i] = 0;
		dist[i][s] = 0;
	}
	return ans;


}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	
	int i;
	for(i=0;i<n;i++)
		affected[i] = 0;
	int temp;

	for(i=0;i<k;i++)
	{
		scanf("%d",&temp);
		affected[temp]=1;
	}

	int u,v,w;
	for(i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		if(!affected[u] && !affected[v])
		{
			// cout<<"adding "<<u<<", "<<v<<" to non affected"<<endl;
			non_affect_dist[u][v] = w;
			non_affect_dist[v][u] = w;
		}
		else
		{
			// cout<<"adding "<<u<<", "<<v<<" to affected"<<endl;

			dist[u][v] = w;
			dist[v][u] = w;
		}
	}

	vector<int> mins;

	for(i=1;i<=n;i++)
	{
		if(affected[i] == 0)
			mins.push_back(min_dist(i,n,k));

		else
			continue;

	}

	vector<int>::iterator ptr; 
	cout<<"distances are ";
	for(ptr = mins.begin(); ptr < mins.end(); ptr++)
		cout<<*ptr<<" ";
	cout<<endl;

}