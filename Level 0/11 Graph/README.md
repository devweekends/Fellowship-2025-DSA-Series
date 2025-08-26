## What is Graph Data Structure?

Graph is a non-linear data structure of vertices (nodes) and edges (connections). Formally, G(V, E) where V is set of vertices and E is set of edges.

Think of a football match: players are nodes, passes/tackles are edges. The web of interactions is a graph.

---

### Components of a Graph
- Vertices (nodes)
- Edges (connections)

### Types of Graphs
- Undirected vs Directed
- Connected vs Disconnected
- Cycle Graph, Cyclic Graph, Directed Acyclic Graph (DAG)
- Weighted Graph (directed/undirected)

---

### Representation of Graph
- Adjacency Matrix
- Adjacency List

Adjacency Matrix (skeleton)
```cpp
#include <bits/stdc++.h>
using namespace std;

void displayMatrix(const vector<vector<int>>& mat){
    int V = (int)mat.size();
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j) cout << mat[i][j] << ' ';
        cout << '\n';
    }
}

int main(){
    // vector<vector<int>> mat = ... // fill matrix
    cout << "Adjacency Matrix Representation\n";
    displayMatrix(mat);
}
```

Adjacency List (template)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Undirected, unweighted
vector<vector<int>> buildGraph(int n, const vector<pair<int,int>>& edges) {
    vector<vector<int>> g(n);
    for (auto [u, v] : edges) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    return g;
}

// Directed, weighted
vector<vector<pair<int,int>>> buildWeightedDigraph(int n, const vector<tuple<int,int,int>>& edges) {
    vector<vector<pair<int,int>>> g(n);
    for (auto [u, v, w] : edges) {
        g[u].push_back({v, w});
    }
    return g;
}
```

---

### Traversals
- BFS (level-by-level, shortest path in unweighted graphs)
```cpp
vector<int> bfsShortestPath(const vector<vector<int>>& g, int src) {
    int n = (int)g.size();
    vector<int> dist(n, -1);
    queue<int> q; q.push(src); dist[src] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return dist;
}
```

- DFS (deep exploration, detect cycles, topological sort helper)
```cpp
void dfsUtil(int u, const vector<vector<int>>& g, vector<int>& vis) {
    vis[u] = 1;
    for (int v : g[u]) if (!vis[v]) dfsUtil(v, g, vis);
}
```

Edge cases for traversals
- Disconnected graphs → run BFS/DFS from all unvisited nodes.
- Self-loops / parallel edges → handle naturally with visited arrays.
- Large graphs → iterative DFS to avoid recursion stack overflow.

---

### Classic problems and templates

Topological Sort (DAG only)
```cpp
vector<int> topoKahn(const vector<vector<int>>& g) {
    int n = (int)g.size();
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; ++u) for (int v : g[u]) indeg[v]++;
    queue<int> q;
    for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop(); order.push_back(u);
        for (int v : g[u]) if (--indeg[v] == 0) q.push(v);
    }
    if ((int)order.size() != n) return {}; // cycle exists
    return order;
}
```

Cycle detection
```cpp
// Undirected: if neighbor visited and not parent → cycle
bool hasCycleUndirected(int n, const vector<vector<int>>& g) {
    vector<int> vis(n, 0);
    function<bool(int,int)> dfs = [&](int u, int parent) {
        vis[u] = 1;
        for (int v : g[u]) {
            if (!vis[v]) { if (dfs(v, u)) return true; }
            else if (v != parent) return true;
        }
        return false;
    };
    for (int i = 0; i < n; ++i) if (!vis[i] && dfs(i, -1)) return true;
    return false;
}

// Directed: DFS colors (0=unseen,1=stack,2=done) → back-edge means cycle
bool hasCycleDirected(int n, const vector<vector<int>>& g) {
    vector<int> color(n, 0);
    function<bool(int)> dfs = [&](int u) {
        color[u] = 1;
        for (int v : g[u]) {
            if (color[v] == 0) { if (dfs(v)) return true; }
            else if (color[v] == 1) return true;
        }
        color[u] = 2; return false;
    };
    for (int i = 0; i < n; ++i) if (color[i] == 0 && dfs(i)) return true;
    return false;
}
```

Shortest paths
```cpp
// Dijkstra (non-negative weights)
vector<long long> dijkstra(const vector<vector<pair<int,int>>>& g, int src) {
    const long long INF = (1LL<<60);
    int n = (int)g.size();
    vector<long long> dist(n, INF);
    using P = pair<long long,int>; // dist, node
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[src] = 0; pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : g[u]) if (dist[v] > d + w) {
            dist[v] = d + w;
            pq.push({dist[v], v});
        }
    }
    return dist;
}

// BFS for unweighted graphs is shortest path in edges (see bfsShortestPath above).
```

Minimum Spanning Tree (MST)
```cpp
// Kruskal with DSU
struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n,0){ iota(p.begin(), p.end(), 0);} 
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){ a=find(a); b=find(b); if(a==b) return false; if(r[a]<r[b]) swap(a,b); p[b]=a; if(r[a]==r[b]) r[a]++; return true; }
};

long long kruskalMST(int n, vector<tuple<int,int,int>> edges) {
    sort(edges.begin(), edges.end(), [](auto &a, auto &b){return get<2>(a) < get<2>(b);} );
    DSU dsu(n); long long cost = 0; int used = 0;
    for (auto [u,v,w] : edges) if (dsu.unite(u,v)) { cost += w; used++; }
    if (used != n-1) return -1; // not connected
    return cost;
}
```

Strongly Connected Components (SCC) – Kosaraju
```cpp
vector<int> kosarajuSCC(const vector<vector<int>>& g) {
    int n = (int)g.size();
    vector<vector<int>> gr(n);
    for (int u = 0; u < n; ++u) for (int v : g[u]) gr[v].push_back(u);
    vector<int> vis(n,0), order;
    function<void(int)> dfs1 = [&](int u){ vis[u]=1; for(int v: g[u]) if(!vis[v]) dfs1(v); order.push_back(u); };
    for (int i=0;i<n;++i) if(!vis[i]) dfs1(i);
    vector<int> comp(n,-1); int cid=0;
    function<void(int)> dfs2 = [&](int u){ comp[u]=cid; for(int v: gr[u]) if(comp[v]==-1) dfs2(v); };
    for (int i=n-1;i>=0;--i){ int u=order[i]; if(comp[u]==-1){ dfs2(u); cid++; } }
    return comp; // comp[u] = component id
}
```

---

### Edge cases (collective)
- Disconnected graphs; isolated nodes.
- Self-loops and multi-edges.
- Negative weights (use Bellman-Ford; Dijkstra breaks).
- Very large graphs: prefer adjacency lists; avoid recursion.
- Graph indexing (0-based vs 1-based) consistency.

---

### Common interview questions
- BFS/DFS traversals; number of connected components.
- Detect cycle (directed/undirected).
- Topological sort and prerequisites problems.
- Shortest path (BFS, Dijkstra, Bellman-Ford), network delay time.
- MST (Kruskal/Prim), connecting points with minimum cost.
- SCCs (Kosaraju/Tarjan), course schedule variants.

---

### Important snippets (quick copy)
- Build undirected/unweighted graph (above)
- BFS shortest path (above)
- Dijkstra template (above)
- DSU + Kruskal (above)
- Kahn’s topological sort (above)

---

### Applications
- Data structures: union-find for connectivity; priority queues in Dijkstra/Prim.
- Algorithms: scheduling (topo), routing (shortest paths), clustering (MST), dependency resolution.

---

## 💡 Suggestions

- Start with BFS/DFS on small graphs; draw by hand.
- Practice templates until you can write them from memory.
- Know when to use BFS vs Dijkstra vs Bellman-Ford.
- Watch out for indexing and visited resets between test cases.
- Time-box to 30–40 minutes; keep short notes and test small cases.


