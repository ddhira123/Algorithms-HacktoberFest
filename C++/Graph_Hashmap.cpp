//Impelemt Graph using Hash_Map

#include<bits/stdc++.h>
#include<string.h>
#define all(c) c.begin(),c.end()
#define ll long long int
#define tr(x,n) for(int i=x;x<n?i<n:i>n;x<n?i++:i--)
#define find(v,x)  find(all(v),x)!=v.end()
#define isro ios_base::sync_with_stdio(false)
#define em emplace_back
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define debug(c) cout<<c<<endl;

using namespace std;

typedef vector<ll>vi;
typedef vector<vi>vii;
typedef pair<ll,ll>pi;
typedef vector<pi>vpi;
typedef tuple<ll,ll,ll>ti;

ll Max=1e6;
//vi visited(Max,0);
vi cost(Max,1e9);
map<string,int>visited;
queue<int>q;
map<string,vector<pair<string,int>>>m;


void dfs(string city){

//If city already visited then escape if block else visited city

    if(!visited[city]){

//put city visited

        visited[city]=1;
        cout<<city<<" ";

//Recursive call same function until not visited all city

        for(auto i:m[city]){
             dfs(i.first);  
        }

    }
}

void Create_Graph(int e){

    for(int i=0;i<e;i++){
        string source,destination;
        int distance;
        cin>>source>>destination>>distance; 
        m[source].em(destination,distance);
    }
 
}

int main(){
    isro;
    int e;
    cin>>e;
        
    Create_Graph(e);
    dfs("Udaipur");

}


/*
Input:-
    4
    Udaipur Jaipur 50
    Udaipur Mumbai 100
    Jaipur Delhi 200
    Mumbai Delhi 100      

*/


/*
Output:-
    Udaipur Jaipur Delhi Mumbai   

*/   


//More details how to implement Graph using Hashmap follow below link

//https://www.youtube.com/watch?v=MTsvJUwZdS4&t=2981s


//Happy Coding :)