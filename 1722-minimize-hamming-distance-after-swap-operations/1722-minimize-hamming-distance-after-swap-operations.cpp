#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

class Solution {
public:

    struct DSU {
        vi p, sz;

        // kick everyone out as their own parent (island party of one)
        DSU(int n) : p(n), sz(n, 1) {
            iota(p.begin(), p.end(), 0);
        }

        // chase up the tree to find root, squish path as we go
        int f(int x) {
            return p[x] == x ? x : p[x] = f(p[x]);
        }

        // merge two groups: big eats small
        void u(int a, int b) {
            a = f(a), b = f(b);
            if (a == b) return; // already besties, nothing to do
            if (sz[a] < sz[b]) swap(a, b);
            p[b] = a;
            sz[a] += sz[b];
        }
    };

    int minimumHammingDistance(vi& s, vi& t, vector<vi>& sw) {
        int n = s.size(), ans = 0;
        DSU d(n);

        // wire up all the allowed swap connections
        for (auto& e : sw) d.u(e[0], e[1]);

        // bucket each index under its group's root
        unordered_map<int, vi> g;
        for (int i = 0; i < n; i++)
            g[d.f(i)].push_back(i);

        // for each component, count source values then eat target values
        for (auto& [_, v] : g) {
            unordered_map<int, int> mp;

            // tally up what source gives us in this group
            for (int i : v) mp[s[i]]++;

            // check if target can be satisfied from this group's stash
            for (int i : v) {
                if (mp[t[i]] > 0) mp[t[i]]--; // got a match, spend it
                else ans++;                    // nope, that's a miss
            }
        }
        return ans;
    }
};