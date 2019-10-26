#include<bits/stdc++.h>
#include<string.h>
#include<tuple>
#define all(c) c.begin(),c.end()
#define tr(n,x) for(int i=x;x<n?i<n:i>=n;x<n?i++:i--)
#define ll long long int
#define pb push_back
#define em emplace_back
#define mk make_pair
#define isro ios_base::sync_with_stdio(false)
#define find(v,x) find(all(v),x)!=v.end()
#define debug(c) cout<<c<<endl;

using namespace std;
typedef vector<ll>vi;
typedef vector<vi>vii;
typedef vector<string>si;
typedef vector<si>sii;
typedef pair<ll,ll>pi;
typedef tuple<ll,ll,ll>ti;

ll Max=1e6;
vi visited(Max,0);



//Create Segment_Tree
void Segment_tree(vi &v,vi &seg_tree,int start,int end,int index){

    if(start==end){
          seg_tree[index]=v[start];
    }
    else{

        int mid=(start)+(end-start)/2;

        Segment_tree(v,seg_tree,start,mid,2*index);
        Segment_tree(v,seg_tree,mid+1,end,2*index+1);

        seg_tree[index]=min(seg_tree[2*index],seg_tree[2*index+1]);
    }
}


//Update function with Lazy_propagation

void update(vi &seg_tree,vi &lazy_pro,int start, int end, int l,int r,int val,int index){

    if(end<l or start>r){
        return ;
    }

    else if(start<=l and r<=end){

//Check if any peding update using Lazy_array if yes and update previous updation
        if(lazy_pro[index]!=0){
             seg_tree[index]+=lazy_pro[index];
             lazy_pro[2*index]+=lazy_pro[index];
             lazy_pro[2*index+1]=lazy_pro[index];
             lazy_pro[index]=0;
        }

//Update current index
        seg_tree[index]+=val;
        lazy_pro[2*index]+=val;
        lazy_pro[2*index+1]+=val;

    }

    else{
        int mid=start+(end-start)/2;

        update(seg_tree,lazy_pro,start,mid,l,r,val,2*index);
        update(seg_tree,lazy_pro,mid+1,end,l,r,val,2*index+1);

        seg_tree[index]=min(seg_tree[2*index],seg_tree[2*index+1]);
        
    }
}

int main(){
    isro;
    int n,t;
    cin>>n>>t;

    vi v(n),seg_tree(3*n,0),lazy_pro(3*n,0);


    for(int i=0;i<n;i++){
        cin>>v[i];
    }


    Segment_tree(v,seg_tree,0,n-1,1);    


    while(t--){
        int l,r,val;
        cin>>l>>r>>val;
        update(seg_tree,lazy_pro,0,n-1,l,r,val,1);  
    }
    

}

/*
Note ->in above code only write code to create segment_tree and updation because Lazy_propagation help to reduce time complexity
 in updation
*/


//Fore more details related to Lazy_propogation follow below link 

//https://www.youtube.com/watch?v=xuoQdt5pHj0


//Happy Coding :)
 