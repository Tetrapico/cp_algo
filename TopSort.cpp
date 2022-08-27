#include<bits/stdc++.h>
using namespace std;

vector<int>adj[500];

int main()
{
    int nodeCount,edgeCount;
    cin>>nodeCount>>edgeCount;

    vector<int>indegree(nodeCount+1,0);

    for(int i=0;i<edgeCount;i++)
    {
        int u,v;
        cin>>u>>v;
        indegree[v]++;
        adj[u].push_back(v);
    }
    vector<int>sequenceTask;
    for(int i=1;i<=nodeCount;i++)
    {
        if(indegree[i]==0)
        {
            sequenceTask.push_back(i);
        }
    }

    for(int i=0;i<sequenceTask.size();i++)
    {
        int node = sequenceTask[i];
        for(int dependentNode:adj[node]){
             indegree[dependentNode]--;
             if(indegree[dependentNode]==0)
             {
                sequenceTask.push_back(dependentNode);
             }
         }
    }

    for(int u:sequenceTask)
    {
        cout<<u<<" ";
    }
    cout<<endl;
}
