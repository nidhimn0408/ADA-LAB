#include<bits/stdc++.h>
using namespace std;

int fact(int i){
    if(i<=1) return 1;
    return i*fact(i-1);
}

int get_mobile(int n , vector<int>v , vector<int>dir){
    int m=0, pm=0;
    for(int i=1;i<=n;i++){
        if(i>1 && dir[v[i]]==0){
            if(v[i]>v[i-1] && v[i]>pm){
                m=v[i]; pm=m;
            }            
        }
        else if(i<n && dir[v[i]]==1){
            if(v[i]>v[i+1] && v[i]>pm){
                m=v[i]; pm=m;
            }
        }
    }
    return m;
}

int pos(int n , vector<int>v , int m){
    for(int i=1;i<=n;i++) {
        if(v[i]==m) return i;
    }
    return -1;
}


void permutations(int n , vector<int>&v , vector<vector<int>>&ans , vector<int>&dir){
    
    int mob = get_mobile(n,v,dir);
    int p = pos(n,v,mob); 
    
    if(dir[mob]==0) iter_swap(v.begin()+p-1, v.begin()+p);
    else iter_swap(v.begin()+p, v.begin()+p+1);  

    for(int i=1;i<=n;i++){
        if(v[i]>mob){
            dir[v[i]] = 1 - dir[v[i]];
        }
    }
    
    ans.push_back(v);
}

int main(){
    cout<<"Enter value of n"<<endl;
    int n; cin>>n;
    int f=fact(n); 
    vector<int>v(n+1,0);
    vector<vector<int>>ans;
    for(int i=0;i<=n;i++) v[i]=i;
    ans.push_back(v);

    vector<int>dir(n+1,0); 
    // l <- r (right to left) is 0
    // l -> r (left to right) is 1

    for(int i=1; i<f;i++){
        permutations(n,v,ans,dir);
    }

    for(int i=0; i<f ; i++){
        for(int j=1;j<=n ;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}