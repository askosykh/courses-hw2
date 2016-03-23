#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// one object per one element
typedef struct Element {
    // number of element's row
    int row;
    // number of element's col
    int col;
    // value of element
    float value;
} Element;

// object for matrix
typedef struct Matrix {
    struct Element *elements;
    // count of elements
    int n_elements;
    // count of rows
    int rows;
    // count of cols
    int cols;
} Matrix;

Matrix* create_matrix_from_file( FILE* file );
Matrix* create_matrix( int row, int col );
void free_matrix( Matrix* matrix );
double get_elem( Matrix* matrix, int row, int col );
void set_elem( Matrix* matrix, int row, int col, double val );
int get_rows(Matrix* matrix);
int get_cols(Matrix* matrix);
#endif //_MATRIX_H_
