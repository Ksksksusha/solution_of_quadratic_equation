#include "squaree.h"


void check_in(double *a, double *b, double *c)
{
    ASSERT(a!=NULL);
    ASSERT(b!=NULL);
    ASSERT(c!=NULL);

    printf("Введите коэффициенты уравнения: \n");

    while(scanf("%lg %lg %lg", a, b, c) != 3)
    {
        int symbol = 0;
        while((symbol = getchar()) != '\n')
            ; /*no body */

        printf("ОШИБКА. Неправильно введены данные. \n");
        printf("Введите коэффициенты уравнения, десятиные дроби пишите через \",\": \n");
    }
}

int calc_roots(double a, double b, double c, double *x1, double *x2)
{

    ASSERT(isfinite(a));
    ASSERT(isfinite(b));
    ASSERT(isfinite(c));

    ASSERT(x1!=NULL);
    ASSERT(x2!=NULL);

    ASSERT(x1!=x2);

    if(equality(a, 0, EPSILON))
    {
        return solve_lin_eq(b, c, x1);
    }
    else
    {
        double diskr = b*b - 4*a*c;

        if(equality(diskr, 0, EPSILON))
        {
            *x1 = (-b)/(2*a);

            if(equality(*x1, 0, EPSILON))
                *x1 = 0;

            return ROOTS_ONE;
        }

        if(diskr > 0)
        {
            *x1 = (-b - sqrt(diskr))/(2*a);
            *x2 = (-b + sqrt(diskr))/(2*a);

            if(equality(*x1, 0, EPSILON))
                *x1 = 0;
            if(equality(*x1, 0, EPSILON))
                *x1 = 0;

            return ROOTS_TWO;
        }

        if(diskr < 0)
        {
            return ROOTS_ZERO;
        }
    }
    return ERROR;
}

int solve_lin_eq(double b, double c, double *x)
{
    ASSERT(isfinite(b));
    ASSERT(isfinite(c));
    ASSERT(x != NULL);

    if(equality(b, 0, EPSILON))
    {
        if(equality(c, 0, EPSILON))
            return ROOTS_INF;
        else
            return ROOTS_ZERO;
    }
    else
    {
        *x = (-c)/b;
        if(equality(*x, 0, EPSILON))
            *x=0;
        return 1;
    }
}

void output_roots(int roots_num, double x1, double x2)
{
    ASSERT(isfinite(roots_num));

    switch(roots_num)
    {
    case ROOTS_ZERO:

        printf("Нет решений");
        break;

    case ROOTS_ONE:

        ASSERT(isfinite(x1));

        printf("Один корень, он равен %lg", x1);
        break;

    case ROOTS_TWO:

        ASSERT(isfinite(x1));
        ASSERT(isfinite(x2));

        printf("Есть два корня. Первый равен %lg, а второй %lg соответственно", x1, x2);
        break;

    case ROOTS_INF:

        printf("Бесконечно много решений");
        break;

    default:

        printf("ERROR");
        break;

    }
}

bool equality(double x, double y, double epsilon)
{
    ASSERT(isfinite(x));
    ASSERT(isfinite(y));
    ASSERT(isfinite(epsilon));

    if(fabs(x-y) <= epsilon)
        return true;

    return false;
}

bool check_ans(int roots_num, double x1, double x2, FILE *test_file)
{
    ASSERT(isfinite(roots_num));

    int right_roots_num = 0;
    double right_x1 = NAN, right_x2 = NAN;

    fscanf(test_file, "%d", &right_roots_num);

    switch(right_roots_num)
    {
        case ROOTS_ONE:

            ASSERT(isfinite(x1));

            fscanf(test_file, "%lg", &right_x1);

            if(!equality(x1, right_x1, EPSILON))
            {
                printf("ОШИБКА\n" "Ожидалось: %d %lg\n" "Получено: %d %lg\n", right_roots_num, right_x1, roots_num, x1);
                return false;
            }

            break;

        case ROOTS_TWO:

            ASSERT(isfinite(x1));
            ASSERT(isfinite(x2));

            fscanf(test_file, "%lg %lg", &right_x1, &right_x2);

            if(!equality(x1, right_x1, EPSILON) || !equality(x2, right_x2, EPSILON))
            {
                printf("ОШИБКА\n" "Ожидалось: %d %lg %lg\n" "Получено: %d %lg %lg\n", right_roots_num, right_x1, right_x2, roots_num, x1, x2);
                return false;
            }

            break;

        default:

            break;
    }

    if(right_roots_num != roots_num)
    {
        if(right_roots_num == -1)
        {
            printf("ОШИБКА\n" "Неправильное количество корней\n" "Ожидалось: INF" "Получено: %d\n", roots_num);
            return false;
        }

        printf("ОШИБКА\n" "Неправильное количество корней\n" "Ожидалось: %d\n" "Получено: %d\n", right_roots_num, roots_num);
        return false;
    }

    return true;
}

void testing()
{
    double a = NAN, b = NAN, c = NAN ,x1 = NAN, x2 = NAN;
    int roots_num = 0, test_num = 0, rigth_tests_count = 0;

    FILE *test_file;


    test_file = fopen("C:\\Users\\User\\Documents\\C\\230822\\test.txt", "r");

    printf("Тестирование началось...\n");

    fscanf(test_file,"%d", &test_num);

    for(int i=0; i<test_num; i++)
    {
        fscanf(test_file, "%lg %lg %lg", &a, &b, &c);

        roots_num = calc_roots(a, b, c, &x1, &x2);

        if(!check_ans(roots_num, x1, x2, test_file))
        {
            printf("Ошибка произошла на тесте %d\n\n\n", i+1);
        }
        else
        {
            rigth_tests_count++;
        }
    }

    fclose(test_file);

    printf("Тестирование завершено.\n" "Выполнено верно тестов %d/%d\n", rigth_tests_count, test_num);

}
