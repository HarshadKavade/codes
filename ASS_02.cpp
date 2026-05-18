#include <bits/stdc++.h>
using namespace std;

// Structure to represent each cell/node
struct Cell
{
    int row, col;      // Position in grid
    int heuristicCost; // h = estimated cost to goal
    int pathCost;      // g = cost from start to current cell
    Cell *parent;      // Pointer to previous cell for path tracing

    // Total cost f = g + h
    int totalCost()
    {
        return pathCost + heuristicCost;
    }
};

// Comparator for priority queue (minimum total cost first)
struct CompareCells
{
    bool operator()(Cell *first, Cell *second)
    {
        return first->totalCost() > second->totalCost();
    }
};

// Manhattan Distance Heuristic
int calculateHeuristic(int currentRow, int currentCol, int goalRow, int goalCol)
{
    return abs(currentRow - goalRow) + abs(currentCol - goalCol);
}

// Check if cell is valid and not blocked
bool isValidCell(int row, int col, int totalRows, int totalCols, vector<vector<int>> &grid)
{
    return (row >= 0 && col >= 0 &&
            row < totalRows && col < totalCols &&
            grid[row][col] == 0);
}

// A* Search Function
void aStarSearch(int startRow, int startCol, int goalRow, int goalCol, vector<vector<int>> &grid)
{

    int totalRows = grid.size();
    int totalCols = grid[0].size();

    // Priority queue for open list
    priority_queue<Cell *, vector<Cell *>, CompareCells> openList;

    // Closed list to mark visited cells
    vector<vector<bool>> visited(totalRows, vector<bool>(totalCols, false));

    // Create start cell
    Cell *startCell = new Cell{
        startRow,
        startCol,
        calculateHeuristic(startRow, startCol, goalRow, goalCol),
        0,
        NULL};

    openList.push(startCell);

    // Movement directions: Right, Left, Up, Down
    int rowMove[] = {0, 0, -1, 1};
    int colMove[] = {1, -1, 0, 0};

    while (!openList.empty())
    {

        // Get cell with minimum cost
        Cell *currentCell = openList.top();
        openList.pop();

        // Skip if already visited
        if (visited[currentCell->row][currentCell->col])
        {
            continue;
        }

        visited[currentCell->row][currentCell->col] = true;

        // Goal reached
        if (currentCell->row == goalRow && currentCell->col == goalCol)
        {

            cout << "\nPath Found:\n";

            vector<pair<int, int>> path;

            // Trace path back using parent pointers
            while (currentCell != NULL)
            {
                path.push_back({currentCell->row, currentCell->col});
                currentCell = currentCell->parent;
            }

            reverse(path.begin(), path.end());

            // Print path
            for (int i = 0; i < path.size(); i++)
            {
                cout << "(" << path[i].first << "," << path[i].second << ") ";
            }
            cout << endl;
            return;
        }

        // Explore neighboring cells
        for (int i = 0; i < 4; i++)
        {

            int newRow = currentCell->row + rowMove[i];
            int newCol = currentCell->col + colMove[i];

            if (isValidCell(newRow, newCol, totalRows, totalCols, grid) && !visited[newRow][newCol])
            {

                Cell *nextCell = new Cell{
                    newRow,
                    newCol,
                    calculateHeuristic(newRow, newCol, goalRow, goalCol),
                    currentCell->pathCost + 1,
                    currentCell};

                openList.push(nextCell);
            }
        }
    }

    cout << "\nNo Path Found\n";
}

int main()
{

    int rows, cols;

    cout << "Enter grid size (rows cols): ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    cout << "Enter grid (0 = free path, 1 = obstacle):\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> grid[i][j];
        }
    }

    int startRow, startCol, goalRow, goalCol;

    cout << "Enter start position (row col): ";
    cin >> startRow >> startCol;

    cout << "Enter goal position (row col): ";
    cin >> goalRow >> goalCol;

    aStarSearch(startRow, startCol, goalRow, goalCol, grid);

    return 0;
}