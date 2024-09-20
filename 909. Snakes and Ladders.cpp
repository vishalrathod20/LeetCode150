class Solution {
public:
   int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    
    // Step 1: Flatten the board into a 1D array
    vector<int> flatBoard(n * n + 1, -1);  // We use a 1-based index for convenience
    bool leftToRight = true;  // To track the direction of filling

    int index = 1;  // Start from 1 since board is 1-based
    for (int i = n - 1; i >= 0; --i) {
        if (leftToRight) {
            for (int j = 0; j < n; ++j) {
                flatBoard[index++] = board[i][j];
            }
        } else {
            for (int j = n - 1; j >= 0; --j) {
                flatBoard[index++] = board[i][j];
            }
        }
        leftToRight = !leftToRight;  // Switch direction for the next row
    }

    // Step 2: BFS to find the shortest path
    vector<bool> visited(n * n + 1, false);
    queue<pair<int, int>> q;  // {current square, number of moves}
    q.push({1, 0});  // Start from square 1 with 0 moves
    visited[1] = true;

    while (!q.empty()) {
        auto [pos, moves] = q.front();
        q.pop();

        // If we reach the last square, return the number of moves
        if (pos == n * n) {
            return moves;
        }

        // Roll the dice and move to one of the next 6 positions
        for (int i = 1; i <= 6; ++i) {
            int nextPos = pos + i;
            if (nextPos > n * n) break;  // Skip if it exceeds the board

            // If there's a snake or ladder, take it
            if (flatBoard[nextPos] != -1) {
                nextPos = flatBoard[nextPos];
            }

            // If not visited, push to the queue
            if (!visited[nextPos]) {
                visited[nextPos] = true;
                q.push({nextPos, moves + 1});
            }
        }
    }

    // If we can't reach the last square, return -1
    return -1;
}
};
