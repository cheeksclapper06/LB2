#include<stdio.h>
#include<math.h>

int main()
{
    char restart; // введення символьної змінної для рестарту коду при виконанні усіх умов правильно
    do
        {
        printf("Enter length between 0.001 and 1000\n");
        double a = 0, b = 0, c = 0; // дійсні змінні a, b, c - сторони трикутника
        int n = 0; // змінна n - визначає кількість знаків після крапки
        int valid_input = 0; // змінна для введення циклу на рестарт коду при знаходженні введення неприпустимого значення змінної
        while (!valid_input) //цикл, який шукає неприпустиме значення та запускає рестарт коду
            {
            printf("Enter the side (a) of triangle:\n");
            scanf("%lf", &a); // зчитування змінної a та її валідація
            if (a <= 0 || a > 1000)
            {
                printf("Invalid input, try again\n");
                continue;
            }

            printf("Enter the side (b) of triangle:\n");
            scanf("%lf", &b); // зчитування змінної b та її валідація
            if (b <= 0 || b > 1000)
            {
                printf("Invalid input, try again\n");
                continue; // пропускає решту коду, бо значення не пройшло валідацію та виконує умову циклу (перезапуск)
            }

            printf("Enter the side (c) of triangle:\n");
            scanf("%lf", &c); // зчитування змінної c та її валідація
            if (c <= 0 || c > 1000)
            {
                printf("Invalid input, try again\n");
                continue;
            }

            if ((a + b < c) || (a + c < b) || (b + c < a)) // валідація правила суми двох сторін трикутника
            {
                printf("Invalid input. Sum of two sides of a triangle must be greater than the third one\n");
                printf("\nTry again\n");
                continue;
            }

            printf("Enter the number of decimal places (from 0 to 12):\n");
            scanf("%d", &n);
            if (n < 0 || n > 12) // валідація змінної n
            {
                printf("Invalid number of decimal places, try again\n");
                continue;
            }
            valid_input ++; //при всіх правильних введених значеннях цикл закінчується та код переходить до наступного етапу
        }
        double Perimeter = (a + b + c);
        double p = Perimeter / 2;
        double S = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("\nPerimeter: %.*lf\n", n, Perimeter);
        printf("\nArea: %.*lf\n", n, S);

        double Ha = (2 * S) / a;
        double Hb = (2 * S) / b;
        double Hc = (2 * S) / c;

        printf("\nHeight(a): %.*lf\n", n, Ha);
        printf("Height(b): %.*lf\n", n, Hb);
        printf("Height(c): %.*lf\n", n, Hc);

        double Ma= 0.5 * sqrt(2 * pow(b, 2) + 2 * pow(c, 2) - pow(a, 2));
        double Mb = 0.5 * sqrt(2 * pow(c, 2) + 2 * pow(a, 2) - pow(b, 2));
        double Mc = 0.5 * sqrt(2 * pow(a, 2) + 2 * pow(b, 2) - pow(c, 2));

        printf("\nMedian(A): %.*lf\n", n, Ma);
        printf("Median(B): %.*lf\n", n, Mb);
        printf("Median(C): %.*lf\n", n, Mc);

        double Ba = (2 / (b + c)) * sqrt(b * c * p * (p - a));
        double Bb = (2 / (a + c)) * sqrt(a * c * p * (p - b));
        double Bc = (2 / (a + b)) * sqrt(a * b * p * (p - c));

        printf("\nBisector(A): %.*lf\n", n, Ba);
        printf("Bisector(B): %.*lf\n", n, Bb);
        printf("Bisector(C): %.*lf\n", n, Bc);

        printf("\nRestart the code? (y/n)\n"); //запит на перезапуск коду
        while (getchar() != '\n');
        scanf("%c", &restart); //зчитування символьної змінної restart
    }

    while (restart == 'y' || restart == 'Y'); // значення, які  може ввести користувач, якщо хоче перезапустити код
    if (restart == 'n' || restart == 'N') // значення, які може ввести користувач, щоб завершити код
    {
        return 0;
    }
}
