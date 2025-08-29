#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    double w;
};

struct DSU {
    int n;
    vector<int> p, r;
    vector<int> origCount; // number of original nodes in the component
    DSU(int n_): n(n_), p(n_), r(n_,0), origCount(n_,0) {
        for(int i=0;i<n;i++) p[i]=i;
    }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b, int &countOriginal){
        a = find(a); b = find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        // if both had original nodes, merging reduces number of original components by 1
        if(origCount[a]>0 && origCount[b]>0) countOriginal--;
        origCount[a] += origCount[b];
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<long long> x(n), y(n);
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    double w, c;
    cin>>w>>c;
    int hub = n;
    vector<Edge> edges;
    edges.reserve(n*(n-1)/2 + n);
    // pairwise cable edges
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double dx = double(x[i]-x[j]);
            double dy = double(y[i]-y[j]);
            double dist = sqrt(dx*dx + dy*dy);
            edges.push_back({i,j, c*dist});
        }
    }
    // edges to hub (install station)
    for(int i=0;i<n;i++){
        edges.push_back({i, hub, w});
    }
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){
        return a.w < b.w;
    });
    DSU dsu(n+1);
    for(int i=0;i<n;i++) dsu.origCount[i]=1;
    dsu.origCount[hub]=0;
    int countOriginal = n;
    double total = 0.0;
    if(countOriginal>1){
        for(const auto &e : edges){
            if(dsu.find(e.u)==dsu.find(e.v)) continue;
            // attempt union
            bool merged = dsu.unite(e.u, e.v, countOriginal);
            if(merged){
                total += e.w;
                if(countOriginal==1) break;
            }
        }
    }
    cout.setf(std::ios::fixed); cout<<setprecision(12)<<total<<"\n";
    return 0;
}