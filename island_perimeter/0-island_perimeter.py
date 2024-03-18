def island_perimeter(grid):
    def dfs(x, y):
        if x < 0 or y < 0 or x >= len(grid) or y >= len(grid[0]):
            return 0
        if grid[x][y] == 0:
            return 1
        if visited[x][y] == 1:
            return 0
        visited[x][y] = 1
        return dfs(x - 1, y) + dfs(x + 1, y) + dfs(x, y - 1) + dfs(x, y + 1)

    if not grid or not grid[0]:
        return 0

    visited = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    perimeter = 0

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                perimeter += dfs(i, j)

    return perimeter
