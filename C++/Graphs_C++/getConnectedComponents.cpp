#include<bits/stdc++.h>
using namespace std;
   class Edge {
       public:
          int src;
          int nbr;
          int wt;

      Edge(int src, int nbr, int wt){
         this->src = src;
         this->nbr = nbr;
         this->wt = wt;
      }
   };
   
   void drawandgenerateTree(vector<Edge> graph[],int src,vector<int> &comp,vector<bool>& visited){
       visited[src]=true;
       comp.push_back(src);
       for(Edge e:graph[src]){
           if(visited[e.nbr]==false){
               drawandgenerateTree(graph,e.nbr,comp,visited);
           }
       }
   }
   
   int main(){
      int vtces;
      cin>>vtces;
      vector<Edge>graph[vtces];

      int edges;
      cin>>edges;
      for(int i = 0; i < edges; i++){
         int v1 ;
         int v2 ;
         int wt ;
         cin>>v1>>v2>>wt;
         graph[v1].push_back( Edge(v1, v2, wt));
         graph[v2].push_back( Edge(v2, v1, wt));
      }

      
        vector<vector<int>> comps;
        vector<bool> visited(vtces,false);
        // recursive function...
        for(int v=0;v<vtces;v++){
            if(visited[v]==false){
                vector<int> comp;
                drawandgenerateTree(graph,v,comp,visited);
                comps.push_back(comp);
            }
        }
        cout<<"[";
        for(int i = 0 ; i<comps.size() ; i++){
            cout<<"[";
            for(int j = 0 ; j<comps[i].size() ; j++){
                if(j!=comps[i].size()-1)
                    cout<<comps[i][j]<<", ";
                else
                    cout<<comps[i][j];

            }
            cout<<"]";
            if(i!=comps.size()-1)cout<<", ";
        }
        cout<<"]";
    }


// 7
// 5
// 0 1 10
// 2 3 10
// 4 5 10
// 5 6 10
// 4 6 10
