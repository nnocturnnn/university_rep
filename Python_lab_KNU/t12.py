import numpy as np


print("10.2")

def read_vect(len):
    lst = []
    for i in range(len):
        lst.append(int(input("Input number :")))
    return np.array(lst)
    

def read_matrix(col,row):
    lst = []
    for i in range(col):
        lst_col = []
        for j in range(row):
            lst_col.append(int(input("Input number :")))
        lst.append(lst_col)
    return np.array(lst)

def read_vect_File(name):
    vect = np.loadtxt(name, usecols=range(1))
    return vect

def read_matrix_FIle(name, col):
    matrix = np.loadtxt(name, usecols=range(col))
    return matrix

def print_vect(vect):
    print(vect)

def print_matrix(matrix):
    np.matrix.view(matrix)

def print_vect_File(name,vect):
    np.savetxt(name,vect)

def print_matrix_File(name, matrix):
    np.savetxt(name,matrix)

def mn_matrix(matrix, matrix2):
    return matrix.dot(matrix2)

def mn_matrix_vector(matrix, vect):
    return matrix.dot(vect)

def mn_vector_num(vect, num):
    return vect.dot(num)

def mn_vector_matrix(matrix, vect):
    return vect.dot(matrix)

def swap_row(matrix, f_row, s_row):
    matrix[[f_row, s_row]] = matrix[[s_row, f_row]]
    return matrix

def swap_col(matrix, f_col, s_col):
    matrix[:,[f_col, s_col]] = matrix[:,[f_col, s_col]]

def get_row(matrix, i):
    return matrix[i]