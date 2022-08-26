#ifndef SQUARE_H
#define SQUARE_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <locale>
#include <string.h>

//#define DEBUG_MOD

#define ASSERT(condition)                                             \
    if(!(condition))                                                  \
        printf("Error in %s in line %d in function %s in file %s \n", \
               #condition, __LINE__, __PRETTY_FUNCTION__, __FILE__);

/**
@brief calculating number of roots and return it, also calculating roots

@param  a  coefficient near x^2
@param  b  coefficient near x^1
@param  c  coefficient near x^0
@param  x1 first root of square equation
@param  x2 first root of square equation

@return number of roots
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
@brief decide linear equation and calculate root

@param  b  coefficient near x^1
@param  c  coefficient near x^0
@param  x  root of lineal equation

@return number of roots of lineal equation
*/
int solve_lin_eq(double b, double c, double *x);

/**
@brief comparing two numbers with certain accuracy

@param x        first number, which we want to compare
@param y        second number, which we want to compare
@param epsilon  calculation accuracy

@return are two numbers approximately equal
*/
bool equality(double x, double y, double epsilon);

/**
@brief checking are our roots of square equation right

@param roots_num number of roots
@param x1        first root of square equation
@param x2        first root of square equation
@param test_file file with control tests

@return true(our answer is right) false(our answer is wrong)
*/
bool check_ans(int roots_num, double x1, double x2, FILE *test_file);

/**
@brief testing if our program is correct
*/
void testing();

/**
@brief precision of comparison of numbers
*/
const double EPSILON = 1e-6;

/**
@brief constants of number of roots
0  - no roots
1  - one root
2  - two roots
-1 - infinity of roots
-5 - we have unknown mistake in function
*/
enum number_of_roots
{
    ROOTS_ZERO = 0,
    ROOTS_ONE = 1,
    ROOTS_TWO = 2,
    ROOTS_INF = -1,
    ERROR = -5
};

#endif // SQUARE_H


