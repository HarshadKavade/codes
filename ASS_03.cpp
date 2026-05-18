#include<bits/stdc++.h>
using namespace std;

/* -------------------------------------------------
   BACKTRACKING APPROACH
------------------------------------------------- */

int cnt1 = 0;

bool isSafe(int r, int c, vector<vector<int>> &board, int n){

    // Column Check
    for(int i=0;i<r;i++){
        if(board[i][c]==1)
            return false;
    }

    // Left Diagonal Check
    for(int i=r-1,j=c-1; i>=0 && j>=0; i--,j--){
        if(board[i][j]==1)
            return false;
    }

    // Right Diagonal Check
    for(int i=r-1,j=c+1; i>=0 && j<n; i--,j++){
        if(board[i][j]==1)
            return false;
    }

    return true;
}

void printBoard(vector<vector<int>> &board, int n){

    cout << "----------------------" << endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(board[i][j]==1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

void solveBacktracking(vector<vector<int>> &board, int row, int n){

    if(row == n){

        cnt1++;

        printBoard(board,n);
        return;
    }

    for(int col=0; col<n; col++){

        if(isSafe(row,col,board,n)){

            board[row][col] = 1;

            solveBacktracking(board,row+1,n);

            // Backtracking
            board[row][col] = 0;
        }
    }
}

/* -------------------------------------------------
   BRANCH AND BOUND APPROACH
------------------------------------------------- */

int cnt2 = 0;

void solveBranchBound(
    vector<vector<int>> &board,
    int row,
    int n,
    vector<int> &column,
    vector<int> &leftDiagonal,
    vector<int> &rightDiagonal
){

    if(row == n){

        cnt2++;

        printBoard(board,n);
        return;
    }

    for(int col=0; col<n; col++){

        if(column[col]==0 &&
           leftDiagonal[row-col+n-1]==0 &&
           rightDiagonal[row+col]==0){

            // Place Queen
            board[row][col] = 1;

            column[col] = 1;
            leftDiagonal[row-col+n-1] = 1;
            rightDiagonal[row+col] = 1;

            solveBranchBound(
                board,
                row+1,
                n,
                column,
                leftDiagonal,
                rightDiagonal
            );

            // Backtracking
            board[row][col] = 0;

            column[col] = 0;
            leftDiagonal[row-col+n-1] = 0;
            rightDiagonal[row+col] = 0;
        }
    }
}

/* -------------------------------------------------
   MAIN MENU
------------------------------------------------- */

int main(){

    int n, choice;

    cout << "Enter value of N: ";
    cin >> n;

    do{

        cout << "\n========== N-Queens Menu ==========\n";
        cout << "1. Solve using Backtracking\n";
        cout << "2. Solve using Branch and Bound\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){

            case 1:{

                cnt1 = 0;

                vector<vector<int>> board(n, vector<int>(n,0));

                cout << "\nSolutions using Backtracking:\n";

                solveBacktracking(board,0,n);

                if(cnt1 == 0)
                    cout << "No Solution Found\n";

                break;
            }

            case 2:{

                cnt2 = 0;

                vector<vector<int>> board(n, vector<int>(n,0));

                vector<int> column(n,0);
                vector<int> leftDiagonal(2*n-1,0);
                vector<int> rightDiagonal(2*n-1,0);

                cout << "\nSolutions using Branch and Bound:\n";

                solveBranchBound(
                    board,
                    0,
                    n,
                    column,
                    leftDiagonal,
                    rightDiagonal
                );

                if(cnt2 == 0)
                    cout << "No Solution Found\n";

                break;
            }

            case 3:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    }while(choice != 3);

    return 0;
}