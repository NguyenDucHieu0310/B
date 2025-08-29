#include<bits/stdc++.h>
using namespace std;
int n, m;
struct edge{
    int u, v, w;
    edge(int _u, int _v, int _w):
    u(_u), v(_v), w(_w){}
};
vector<edge> edges;
struct UnionFind{
    vector<int> parent;
    UnionFind(int n){
        parent = vector<int> (n);
        for(int i=1; i<=n; i++) parent[i]=i;
    }
    int Find(int x){
        if(parent[x]==x) return x;
        return parent[x]=Find(parent[x]);
        //return parent[x];
    }
    void Unite(int x, int y){
        parent[Find(x)]=Find(y);
    }
};
bool comp(const edge&a, const edge&b){
    return a.w<b.w;
}
vector<edge> Kruskal(int n, vector<edge> edges){
    UnionFind uf(n);
    vector<edge> res;
    //sort(edges.begin(), edges.end(), [](const edge&a, const edge&b){a.w<b.w;});
    sort(edges.begin(), edges.end(), comp);
    for(const edge &e: edges){
        int u=e.u, v=e.v, w=e.w;
        if(uf.Find(u)!=uf.Find(v)){
            uf.Unite(u,v);
            res.push_back(e);
        }
    }
    return res;
}
void input(){
    cin>>n>>m;
    int u,v,w;
    for(int i=0; i<m;i++){
        cin>>u>>v>>w;
        edges.push_back(edge(u,v,w));
    }
}
int main(){
    freopen("data.inp", "r", stdin);
    input();
    vector<edge> res=Kruskal(n, edges);
    for(auto x: res){
        cout<<x.u<<x.v<<x.w<<endl;
    }
}
vector<int> input(){
    vector<int> v;
    thêm các phần tử lần lượt vào v từ bàn phím( cách nhau bởi space) cho đến khi nhâp xuống dòng, sau đó sắp xếp theo thứ tự tăng dần|
    ví dụ 1 2 3 4 5
    return v;
}