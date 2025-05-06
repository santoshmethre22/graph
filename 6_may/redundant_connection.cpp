#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


// this question solved by graph -------------------------->


/*#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path Compression
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};
*/




class Solution {
    public:
    

    
        vector<int>parent;
        vector<int>rank;


        void union_set (int x,int y){

            int rootX=find(x);
            int rootY=find(y);


            if(rootX==rootY)return ;

            if(rank[rootX]<rank[rootY]){
                parent[rootX]=rootY;
            }

            else if(rank[rootY]<rank[rootY]){

                parent[rootY]=rootX;
            }

            else{

                parent[rootY]=rootX;

                rank[rootX]++;
            }


           
        }

        int find(int x){
            if(parent[x]!=x){
                parent[x]=find(parent[x]);
            }


            return parent[x];

        }

        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            
            int n=edges.size();

            parent.resize(n+1);

            rank.resize(n+1,0);


            for(int i=1;i<=n;i++){
                parent[i]=i;
            }


           vector<int>p(2,0);


    for(auto i:edges)
    {
        
        int x=i[0];
        int y=i[1];

        int x_p=find(x);
        int y_p=find(y);

        if(x_p==y_p){
             p[0]=x;
             p[1]=y;
        }
        
        else{

            union_set(x,y);

        }

    }


    return p;
        }
    };



int main() {

    // Your code here

    return 0;
}