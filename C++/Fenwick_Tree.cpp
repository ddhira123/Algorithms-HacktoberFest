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



void update(vi &v, int index, int val){
     
    while(index<v.size()){
        v[index]+=val;
        index+=(index&-index);
    }
}


int range_qurey(vi &v, int l, int r){
    int sum1=0,sum2=0;      

    while(r>0){
        sum1+=v[r];
        r-=(r&-r);
    }

    while(l>0){
        sum2+=v[l];
        l-=(l&-l);
    }
    return sum1-sum2;
}


int main(){
    isro;
    int n,t;
    cin>>n>>t;

    vi bit(n+1,0);

//Create Fenwick_tree

    for(int i=1;i<=n;i++){
        int val;
        cin>>val;
        update(bit,i,val);
    }


    while(t--){
        int choice;
        cin>>choice;

//Choice 1 for update
        if(choice==1){
            int index,val;
            cin>>index>>val;
            update(bit,index,val);
        }

//Choice 2 for find sum in range l to r

        if(choice==2){
            int l,r;
            cin>>l>>r;
            cout<<range_qurey(bit,l,r);
        }
    }

}




//For more deitals please follow below link

//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/tutorial/

