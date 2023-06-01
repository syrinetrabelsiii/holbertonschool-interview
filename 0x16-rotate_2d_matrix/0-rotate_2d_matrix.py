#!/usr/bin/python3
""" Given an n x n 2D matrix, rotate it 90 degrees """


def rotate_2d_matrix(matrix):
    """ The matrix is edited in-place. It doesn't return anything. """

    l = len(matrix)
    for z in range(3):
        for i in range(0, int(l/2)):
            for j in range(i, l - 1 - i):
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][l - 1 - i]
                matrix[j][l - 1 - i] = matrix[l - 1 - i][l - 1 - j]
                matrix[l - 1 - i][l - 1 - j] = matrix[l - 1 - j][i]
                matrix[l - 1 - j][i] = temp
