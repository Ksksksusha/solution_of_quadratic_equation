#include "squaree.h"

int main(int argc, char *argv[])
{

    setlocale(LC_ALL, "Russian");

    if(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
    {
        printf("Hi\n" "Way to your file is  %s", __FILE__);
        return 0;
    }


    if(argc == 2 && argv[1][0] == '-' && argv[1][1] == 't')
    {
        testing();
        return 0;
    }

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
