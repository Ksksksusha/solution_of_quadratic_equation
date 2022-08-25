#ifndef SQUARE_H
#define SQUARE_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <locale>

#define DEBUG_MOD

#define ASSERT(condition)                                             \
    if(!(condition))                                                  \
        printf("Error in %s in line %d in function %s in file %s \n", \
               #condition, __LINE__, __PRETTY_FUNCTION__, __FILE__);


//calculating number of roots and return them
int calc_roots(double a, double b, double c, double *x1, double *x2);

//checking input and return coefficients of square equation
void check_in(double *a, double *b, double *c);

//output roots of square equation
void output_roots(int roots_num, double x1, double x2);

//decide linear equation and return root
int solve_lin_eq(double b, double c, double **x);

//comparing two numbers with certain accuracy
bool equality(double x, double y, double epsilon);

//checking are our roots of square equation right
bool check_ans(int roots_num, double x1, double x2, FILE *test_file);

//testing is our program correct
void testing();


const double EPSILON = 1e-6;

enum
{
    ROOTS_ZERO = 0,
    ROOTS_ONE = 1,
    ROOTS_TWO = 2,
    ROOTS_INF = -1,
    ERROR = -5
};


#endif // SQUARE_H


