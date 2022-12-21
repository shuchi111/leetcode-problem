class Solution {
public:
    
   vector <int> f, p;
int find(int x) {
    if (f[x] != x) {
        int next = find(f[x]);
        p[x] ^= p[f[x]];
        f[x] = next;
    }
    return f[x];
}
bool possibleBipartition(int n, vector<vector<int>>& a) {
    f.resize(n + 1);
    p.resize(n + 1, 0);
    iota(f.begin(), f.end(), 0);
    for (auto &z : a) {
        int x = z[0], y = z[1];
        if (f[y] == y) { f[y] = x; p[y] = 1; }
        else if (find(x) == find(y) && p[x] == p[y]) 
            return false;
    }
    return true;
}
};
