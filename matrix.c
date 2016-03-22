#include "matrix.h"

// put elements to the end of array
static void put_to_end( Matrix* matrix, int row, int col, float value ) {
    matrix->elements = (struct Element*)realloc(matrix->elements,(matrix->n_elements + 1) * sizeof(struct Element));
    struct Element* new_element;
    new_element = matrix->elements + matrix->n_elements;
    new_element->row = row;
    new_element->col = col;
    new_element->value = value;
    matrix->n_elements++;
}

// create matrix struct from file
Matrix* create_matrix_from_file( FILE* file ) {
    int n_col = 0;
    int n_row = 0;
    int count = 0;
    float value = 0;
    fscanf(file, "%d", &n_col);
    fscanf(file, "%d", &n_row);
    Matrix* matrix = create_matrix(n_col, n_row);
    for( size_t i = 0; i < n_row; ++i ) {
        for( size_t j = 0; j < n_col; ++j ) {
            fscanf(file, "%f", &value);
            if (value) {
                put_to_end(matrix, i, j, value);
            }
        }
    }
    for (size_t k = 0; k < matrix->n_elements; ++k ) {
       // printf("%d, %d, %f\n",matrix->elements[k].row, matrix->elements[k].col,matrix->elements[k].value);
       // printf("%d, %d, %f\n",matrix->elements[k].row, matrix->elements[k].col, get_elem(matrix, matrix->elements[k].row, matrix->elements[k].col));
    }
    return matrix;
}

// create an empty struct
Matrix* create_matrix( int row, int col ) {
    Matrix* matrix = (struct Matrix*)malloc(sizeof( struct Matrix));
    matrix->elements = NULL;
    matrix->n_elements = 0;
    matrix->rows = row;
    matrix->cols = col;
}

// free memory
void free_matrix( Matrix* matrix ) {
    free( matrix );
}

// get element with its indexes
double get_elem( Matrix* matrix, int row, int col ) {
    for (size_t k = 0; k < matrix->n_elements; ++k) {
        if ( (matrix->elements[k].row == row) && (matrix->elements[k].col == col) )
            return matrix->elements[k].value;
        else
            continue;
    }
    return 0;
}

// set element
void set_elem( Matrix* matrix, int row, int col, double val) {
    for ( size_t k = 0; k < matrix->n_elements; ++k ) {
        if ( matrix->elements[k].row > row ) {
             matrix->elements = (struct Element*)realloc(matrix->elements,(matrix->n_elements + 1) * sizeof(struct Element));
             memmove(matrix->elements + k + 1, matrix->elements + k, sizeof(struct Element) * (matrix->n_elements - k));
             matrix->elements[k].row = row;
             matrix->elements[k].col = col;
             matrix->elements[k].value = val;
        } else {
            if ( matrix->elements[k].col > col) {
                 matrix->elements = (struct Element*)realloc(matrix->elements,(matrix->n_elements + 1) * sizeof(struct Element));
                 memmove(matrix->elements + k + 1, matrix->elements + k, sizeof(struct Element) * (matrix->n_elements - k));
                 matrix->elements[k].row = row;
                 matrix->elements[k].col = col;
                 matrix->elements[k].value = val;
   
            } else
                put_to_end(matrix, row, col, val);
        }
    }
}

// get rows number
int get_rows(Matrix* matrix) {
    return matrix->rows;
}

// get the cols number
int get_cols( Matrix* matrix ) {
    return matrix->cols;
}
