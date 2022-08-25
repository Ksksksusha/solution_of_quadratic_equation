#ifndef SQUARE_H
#define SQUARE_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <locale>

//#define DEBUG_MOD

#define ASSERT(condition)                                             \
    if(!(condition))                                                  \
        printf("Error in %s in line %d in function %s in file %s \n", \
               #condition, __LINE__, __PRETTY_FUNCTION__, __FILE__);


/**
@brief calculating number of roots and return them
@param  a  coefficient near x^2
@param  b  coefficient near x^1
@param  c  coefficient near x^0
@param  x1 first root of square equation
@param  x2 first root of square equation
*/
int calc_roots(double a, double b, double c, double *x1, double *x2);

/**
@brief checking input and return coefficients of square equation
@param  a  coefficient near x^2
@param  b  coefficient near x^1
@param  c  coefficient near x^0
*/
void check_in(double *a, double *b, double *c);

/**
@brief output roots of square equation
@param roots_num number of roots
@param  x1       first root of square equation
@param  x2       first root of square equation
*/
void output_roots(int roots_num, double x1, double x2);

/**
@brief decide linear equation and return root
@param  b  coefficient near x^1
@param  c  coefficient near x^0
@param  x  root of lineal equation
*/
int solve_lin_eq(double b, double c, double *x);

/**
@brief comparing two numbers with certain accuracy
@param x        first number, which we want to compare
@param y        second number, which we want to compare
@param epsilon  calculation accuracy
*/
bool equality(double x, double y, double epsilon);

/**
@brief checking are our roots of square equation right
@param roots_num number of roots
@param x1        first root of square equation
@param x2        first root of square equation
@param test_file file with control tests
*/
bool check_ans(int roots_num, double x1, double x2, FILE *test_file);

/** @brief testing is our program correct */
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


