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
typedef vector<string>si;
typedef vector<si>sii;

struct Trie;


//Create Structure of Trie
struct Trie{
    string ch;
    Trie *children[26];
    bool isend;
};


//Initial all children of node contain NULL

Trie* Node(){
    Trie *node=new Trie();
    
    for(int i=0;i<26;i++){
        node->children[i]=NULL;
    }

    node->isend=false; 
    return node; 
}


//Create Trie 

void Create(Trie *root,string st){
     Trie *node=new Trie();
     node=root;

     for(int i=0;i<st.length();i++){
         int index=st[i]-'a';
         if(node->children[index]==NULL){
              node->children[index]=new Trie();
              node->children[index]=Node();
         }

         node->isend=false;   
         node=node->children[index];
         node->isend=true;
     }

}

//Check String in Trie is present or not
bool check(Trie *root, string s){
    
    Trie *node=new Trie();
    node=root;

    for(int i=0;i<s.length();i++){
        int index=s[i]-'a';
        if(node->children[index]==NULL){
            return false;
        }
        node=node->children[index];
    }

    if(node->isend)
        return true;
    else 
        return false;
}

int main(){
    int n;
    cin>>n;

    Trie *root;
    root=Node();

//n-> number of string 

    while(n--){
        string s;
        cin>>s;
        Create(root,s);
    }


    string st;
    cin>>st;

    if(check(root,st)){
        cout<<"Presence"<<endl;
    }
    else 
       cout<<"No"<<endl;
    
}



//I implement Trie using Struct but you can also implement using 2D matrix which was soon push on repositories


//For more details related to trie follow below articles


//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/


//Talk is cheap. Show me the code.

//Happy Coding :)

