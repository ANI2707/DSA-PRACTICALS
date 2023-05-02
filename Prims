#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class graph1{
    public:
    int arr[10][10];
    int edges;
    int weight;
    int cost[10][10];
    int b[10][10];
    int dist[10];
    int vis[10];
    int from[10];
    int total=0;
    int V;
    graph1(){
        for(int i=0;i<10;i++){
            dist[i]=0;
            vis[i]=0;
            from[i]=0;
            for(int j=0;j<10;j++){
                arr[i][j]=0;
                b[i][j]=0;
                cost[i][j]=0;
            }
        }
    }
    void readgraph(){
        cout<<"Enter Number of edges :"<<endl;
        cin>>edges;
        cout<<"Enter Number of vertex :"<<endl;
        cin>>V;
        for(int i=0;i<edges;i++){
            int a,b;
            cout<<"Enter the edge and weight";
            cin>>a>>b>>weight;
            arr[a][b]=weight;
            arr[b][a]=weight;
            }
        }
    
    void prims(int vertex){
       for(int i=0;i<10;i++){ 
           for(int j=0;j<10;j++){
               if(arr[i][j]==0){
                   cost[i][j]=MAX;
                //   cost[j][i]=MAX;
               }
               else{
                   cost[i][j]=arr[i][j];
                //   cost[j][i]=arr[i][j];
               }
           }
       }
       vis[vertex]=1;
       dist[vertex]=0;
       for(int i=(vertex+1);i<edges;i++){
            dist[i]=cost[vertex][i];
            from[i]=vertex;
       }
       for(int count=0;count<(edges-1);count++){
           int v=minimum(dist,vis);
           int u=from[v];
           if(cost[u][v]==MAX){
                b[u][v]=0;
                b[v][u]=0;
                vis[v]=1;
           }
           else{
               b[u][v]=cost[u][v];
               b[v][u]=cost[u][v];
               vis[v]=1;
           }
           
           total=total+b[u][v];
           for(int i=(vertex+1);i<edges;i++){
               if(vis[i]==0 && dist[i]>cost[v][i]){
                   from[i]=v;
                   dist[i]=cost[v][i];
               }
           }
           
       }
      cout<<"Total:"<<total;
       
       
       
    }
    int minimum(int dist[],int vis[]){
        int min=MAX;
        int minimum;
        for(int i=0;i<edges;i++){
            if(dist[i]<min && vis[i]==0){
                min=dist[i];
                minimum=i;
            }
        }
        return minimum;
    }
    void printgraph(){
        // cout<<"EDGE\tWEIGHT\n";
        // for(int i=0;i<V;i++){
        //     cout<<from[i]<<"-"<<i<<"\t"<<b[i][from[i]]<<"\n";
        //     // total=total+b[i][from[i]];
        // }
        
        for(int i=0;i<edges;i++){
          for(int j=0;j<edges;j++){
              cout<<b[i][j]<<" ";
            //   if(b[i][j]!=0){
            //       total=total+b[i][j];
                  
            //   }
          }
          cout<<endl;
        }
        // cout<<"Total:"<<total;
    }
};
int main() {
    graph1 g;
    int ch;
    int v;
    int vertex;
    while(1){
        cout<<"\nEnter a choice:";
        cin>>ch;
        switch(ch){
            case 1:
                
                g.readgraph();
                break;
            case 2:
                cout<<"Enter vertex to call prims :"<<endl;
                cin>>v;
                g.prims(v);
                break;
            case 3:
                g.printgraph();
                break;
            case 4:
                exit(1);
        }
    }
    return 0;
}
