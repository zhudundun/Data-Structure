#include "Friend.h"
#include<iostream>
using namespace std;
int find(int x, std::vector<int>& parents) {
   // your code
   while (x != parents[x]) {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }
        return x;
    }


int findCircleNum(std::vector<std::vector<int>>& M) {
    // your code
    int n = M.size(), res = n;
        vector<int> root(n);
        for (int i = 0; i < n; ++i) root[i] = i;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j] == 1) {
                    int p1 = find(i,root);
                    int p2 = find(j,root);
                    if (p1 != p2) {
                        --res;
                        root[p2] = p1;
                    }
                }
            }
        }
        return res;
}
