#include<bits/stdc++.h>
#include<string.h>
#define all(c) c.begin(),c.end()
#define ll long long int
#define tr(x,n) for(int i=x;x<n?i<n:i>n;x<n?i++:i--)
#define find(v,x)  find(all(v),x)!=v.end()
#define isro ios_base::sync_with_stdio(false)
#define em emplace_back
#define pb push_back


using namespace std;

typedef vector<ll>vi;
typedef vector<vi>vii;
typedef pair<ll,ll>pi;
typedef tuple<ll,ll,ll>ti;

ll Max=1e6;
vi visited(Max,0);
queue<int>q;

void bfs(vii &v){
     
    if(q.size()>0){
        int node=q.front();
        q.pop();

//If Node not visited then true 
        if(!visited[node]){

            visited[node]=1;
            cout<<node<<" ";
            
//Push all neighbour node of the current node into Queue.            
            for(int i=0;i<v[node].size();i++){
                if (!visited[v[node][i]])  q.push(v[node][i]);
            }

            bfs(v);
    }

    } 
}


int main(){
    isro;

    int n,e;
    cin>>n>>e;

    vii v(n+1);

//Create Graph
    for(int i=0;i<e;i++){
        int u1,v1;
        cin>>u1>>v1;
        v[u1].pb(v1);
    }

    
    for(int i=0;i<=n;i++){
        if(!visited[i]){
            q.push(i);
            bfs(v);
        }
    }

}


//Fore more details please follow below link

//https://www.youtube.com/watch?v=pcKY4hjDrxk





/*
void dfs(vii &v,int node){

    if(!visited[node]){
        cout<<node<<" "<<"Hello Bharat Kumar"<<endl;
        visited[node]=1;
        
        for(int i=0;i<v[node].size();i++){
//              cout<<v[node]
//              dfs(v,v[node][i]);
        }

//        cout<<node<<" ";
//       st.push(node); 
    }

}

*/





/*
    while(st.size()>0){
//         int t=st.pop();
         cout<<t<<" ";
    }
*/


/* 
    for(int i=0;i<v.size();i++){
            cout<<i<<"->";
            for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
*/


