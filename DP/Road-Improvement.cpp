#include<iostream>
#define ll long long int 
#include<string>
using namespace std;
#include<vector>
#include<set>
#include<algorithm>
#define MOD 1000000007
vector<ll> p(1000000),dp(1000000),cou(1000000),two(1000000);
vector<vector<ll> > adj(1000000);
ll d, x, y;
void extendedEuclid(ll A, ll B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        ll temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}


ll modInverse(ll A, ll M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}


void dfs(ll node , ll parent)
{
    if(adj[node].size()==1&&adj[node][0]==parent)
    {
        dp[node]=0;
        return ;
    }
    else
    {
       // cout<<" +++ ";
        dp[node]=1;
    }
    ll i;
   // cout<<"node "<<node<<" "<<adj[node].size()<<" :size \n";
    for(i=0;i<adj[node].size();i=i+1)
    {
        if(adj[node][i]!=parent)
        {
            dfs(adj[node][i],node);
            if(two[adj[node][i]]==1)
            {
                dp[node]=(dp[node]%MOD*(dp[adj[node][i]]+2)%MOD)%MOD;
            }
            else
            {
                dp[node]=(dp[node]%MOD*(dp[adj[node][i]]+1)%MOD)%MOD;
            }
            //cout<<"\n "<<i<<" "<<dp[node]<<";;;";
        }
    }
    return ;
}


void tdfs(ll node,ll parent)
{
    
    ll i,j,temp_node,temp_parent;
    if(parent!=-1)
    temp_parent=dp[parent];
     temp_node=dp[node];

    if(parent!=-1)
    {
        
        /*if(adj[parent].size()==1&&adj[parent][0]==node)
        {
           dp[parent]=0;
           
        }
        else
        {
       // cout<<" +++ ";
        
          dp[parent]=1;
       }
    for(j=0;j<adj[parent].size();j=j+1)
    {
                if(adj[parent][j]!=node)
                {
                    if(two[adj[parent][j]]==1)
                    {
                        dp[parent]=(dp[parent]%MOD*(dp[adj[parent][j]]+2)%MOD)%MOD;
                    }
                    else
                    {
                        dp[parent]=(dp[parent]%MOD*(dp[adj[parent][j]]+1)%MOD)%MOD;
                    }
                }
    }*/

     
    ll t_node;
    if(two[node]==1)
    {
        t_node=(dp[node]%MOD+2)%MOD;
    }
    else
    {
        t_node=(dp[node]%MOD+1)%MOD;
    }

        if(two[parent]==1)
        {
           dp[parent]=0;
           
        }
        else
        {
        //cout<<"\n node "<<node<<" dp[node]= "<<dp[node]<<" "<<parent<<" "<<dp[parent]<<"\n";
        if(t_node%MOD==0)
        {
            dp[parent]=1;
            for(j=0;j<adj[parent].size();j=j+1)
    {
                if(adj[parent][j]!=node)
                {
                    if(two[adj[parent][j]]==1)
                    {
                        dp[parent]=(dp[parent]%MOD*(dp[adj[parent][j]]+2)%MOD)%MOD;
                    }
                    else
                    {
                        dp[parent]=(dp[parent]%MOD*(dp[adj[parent][j]]+1)%MOD)%MOD;
                    }
                }
    }
        }
        else{
       ll b=modInverse(t_node,MOD);
       
       //cout<<"\n tnode "<<b;
       dp[parent]=(b%MOD*dp[parent]%MOD)%MOD;}
       //dp[parent]=(dp[parent]/t_node)%MOD;
       //cout<<"\n node "<<node<<" dp[node]= "<<dp[node]<<" "<<parent<<" "<<dp[parent]<<"\n";
       }


   
    if(two[node]==1)
    {
        dp[node]=1;
    }
    
   
    if(two[parent]==1)
            {
                 dp[node]=(dp[node]%MOD*(dp[parent]+2)%MOD)%MOD;
            }
            else
            {
                 dp[node]=(dp[node]%MOD*(dp[parent]+1)%MOD)%MOD;
            }
    /*for(i=0;i<adj[node].size();i=i+1)
    {
            if(two[adj[node][i]]==1)
            {
                dp[node]=(dp[node]%MOD*(dp[adj[node][i]]+2)%MOD)%MOD;
            }
            else
            {
                dp[node]=(dp[node]%MOD*(dp[adj[node][i]]+1)%MOD)%MOD;
            }
    }*/
        cou[node]=dp[node];
    }

    
    for(i=0;i<adj[node].size();i=i+1)
    {
        if(adj[node][i]!=parent)
        {
            tdfs(adj[node][i],node);

            
        }
    }
            dp[node]=temp_node;
            if(parent!=-1)
            dp[parent]=temp_parent;
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll n,i,x;
    cin>>n;
    for(i=2;i<=n;i=i+1)
    {
        cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    //cout<<adj[1][0]<<" "<<adj[1][1]<<"\n";
    for(i=1;i<=n;i=i+1)
    {
        //cout<<"node "<<i<<" "<<adj[i].size()<<" :size \n";
        if(adj[i].size()==1)
        two[i]=1;
    }
    dfs(2,-1);
    cou[2]=dp[2];
    //cout<<cou[2]<<"\n";
    tdfs(2,-1);
    for(i=1;i<=n;i=i+1)
    cout<<cou[i]<<" ";
    cout<<"\n";
    return 0;
}
