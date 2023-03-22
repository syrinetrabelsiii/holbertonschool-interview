#!/usr/bin/python3
import sys

def solve(n):
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Initialize the board with all zeros
    board = [[0 for x in range(n)] for y in range(n)]
    solutions = []
    solve_helper(board, 0, solutions)
    
    for solution in solutions:
        print(solution)

def solve_helper(board, col, solutions):
    n = len(board)
    if col == n:
        # We have placed all the queens, so add the solution to the list
        solution = []
        for row in board:
            row_str = ''.join(['Q' if cell == 1 else '.' for cell in row])
            solution.append(row_str)
        solutions.append(solution)
        return
    
    for row in range(n):
        if is_valid_move(board, row, col):
            # Place the queen and recursively solve for the next column
            board[row][col] = 1
            solve_helper(board, col+1, solutions)
            board[row][col] = 0

def is_valid_move(board, row, col):
    n = len(board)
    # Check row
    for i in range(col):
        if board[row][i] == 1:
            return False
    
    # Check upper diagonal
    i = row
    j = col
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1
    
    # Check lower diagonal
    i = row
    j = col
    while i < n and j >= 0:
        if board[i][j] == 1:
            return False
        i += 1
        j -= 1
    
    # The move is valid
    return True

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    
    solve(n)

