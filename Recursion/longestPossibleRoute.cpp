#include<bits/stdc++.h>
using namespace std;
int ans = 0;
int helper(vector<vector<int>>& matrix, int x, int y, int m, int n, vector<vector<bool>> &vis, int path) {
    if (x >= m || y >= n || x < 0 || y < 0 || vis[x][y] == true || matrix[x][y] == 0) {
        return 0;
    }
    if (x == m - 1 and y == n - 1 and matrix[x][y] == 1) {
        return 1;
    }
    vis[x][y] = true;
    helper(matrix, x + 1, y, m, n, vis, path + 1);
    helper(matrix, x - 1, y, m, n, vis, path + 1);
    helper(matrix, x, y - 1, m, n, vis, path + 1);
    helper(matrix, x, y + 1, m, n, vis, path + 1);
    vis[x][y] = false;
    ans = max(ans, path);
}
int findLongestPath(int m, int n, vector<vector<int>> matrix) {
    //Complete this function. Do not modify the name or parameters. You can make a helper function if needed.
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    return helper(matrix, 0, 0, m, n, vis, 1);
}
int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 1, 1},
        {0, 0, 1}
    };
    int m = matrix.size();
    int n = matrix[0].size();
    cout << findLongestPath(m, n, matrix) << endl;
}
