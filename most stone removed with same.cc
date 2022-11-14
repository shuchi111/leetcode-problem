class Solution {
public:
int f(int *p, int i) {
while (p[i] != -1) {
  i = p[i];
}
return i;
}

void u(int *p, int i, int j) {
int gi = f(p, i);
int gj = f(p, j);
if (gi != gj) p[gi] = gj;
}

int removeStones(vector<vector<int>> &stones) {
const int len = stones.size();
if (len <= 1) return 0;

int grps[10000 * 2];
for (int i = 0; i < 10000 * 2; i++) grps[i] = -1;
for (const auto &st : stones) {
  u(grps, st[0], 10000 + st[1]);
 }
set<int> s;
for (const auto &st : stones) {
  s.insert(f(grps, st[0]));
}
return len - s.size();
}
};
