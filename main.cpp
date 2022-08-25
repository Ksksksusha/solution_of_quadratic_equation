#include "squaree.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    #ifndef DEBUG_MOD

    double a = NAN, b = NAN, c = NAN ,x1 = NAN, x2 = NAN;
    int roots_num = 0;

    check_in(&a, &b, &c);

    roots_num = calc_roots(a, b, c, &x1, &x2);
    ASSERT(roots_num!=ERROR);

    output_roots(roots_num, x1, x2);
    #endif

    #ifdef DEBUG_MOD

    testing();

    #endif

    return 0;
}
