#include "matrix.h"

// arguements' of command line checking
static int arg_quant_check( int argc ) {
    if( argc != 2) {
        printf("Wrong number of arguements\n");
        return 1;
    }
}
// norm_l calculation
static float norm_l(Matrix* matrix, int rows, int cols ) {
    float norm = 0.;
    float tmp_norm = 0.;
    for ( size_t j = 0; j < cols; ++j ) {
        tmp_norm = 0.;
        for ( size_t i = 0; i < rows; ++i ) 
            tmp_norm += fabs(get_elem(matrix,i,j));
        if (tmp_norm > norm)
            norm = tmp_norm;
    }
    return norm;
}

int main( int argc, char* argv[] ) {
    if ( !arg_quant_check( argc ) )
        return 1;
    FILE *file = fopen(argv[1], "r");
    if ( !file ) {
         printf("Cannot open the file\n");
        return 1;
    }
    Matrix* matrix = create_matrix_from_file(file);
    float norm = norm_l(matrix,get_rows(matrix), get_cols(matrix));
    printf("L-norm = %2.2f\n",norm);
    fclose(file);
    free_matrix(matrix);
    return 0;
}
