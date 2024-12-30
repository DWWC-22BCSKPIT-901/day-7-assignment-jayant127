#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& grid, int i, int j) {
    // Check if the current position is out of bounds or water (0)
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
        return 0;
    }

    // Mark the current cell as visited by setting it to 0
    grid[i][j] = 0;

    // Explore all four directions and sum up the area
    int area = 1;
    area += dfs(grid, i + 1, j); // Down
    area += dfs(grid, i - 1, j); // Up
    area += dfs(grid, i, j + 1); // Right
    area += dfs(grid, i, j - 1); // Left

    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) { // If it's land, start DFS
                maxArea = max(maxArea, dfs(grid, i, j));
            }
        }
    }

    return maxArea;
}

int main() {
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the grid values row by row (0 or 1):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "Maximum area of island: " << maxAreaOfIsland(grid) << endl;

    return 0;
}
