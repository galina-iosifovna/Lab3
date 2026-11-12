#include <stdio.h>
#include <math.h>

int main(void) {
    int choice;

    do {
        printf("\n Меню завдань (Варіант 23) \n");
        printf("1. Завдання 79 (Прямокутники)\n");
        printf("2. Завдання 86 (Зріст трьох осіб)\n");
        printf("3. Завдання 105 (Гострокутний трикутник)\n");
        printf("4. Завдання 29 (Заміна чисел)\n");
        printf("5. Завдання 90 (Цегла і отвір)\n");
        printf("6. Завдання 68 (Перетин прямокутників)\n");
        printf("7. Завдання 82 (Залишок від ділення)\n");
        printf("8. Завдання 25 (Відстань до початку координат)\n");
        printf("9. Завдання 16 (Число-паліндром)\n");
        printf("10. Завдання 61 (Площа трикутника)\n");
        printf("0. Вихід\n");
        printf("Оберіть номер завдання: ");

        if (scanf("%d", &choice) != 1) {
            printf("Помилка: потрібно ввести ціле число.\n");
            return 1;
        }

        switch (choice) {

            case 1: {
                // Завдання 79. Найменший прямокутник для двох заданих.
                double x1, y1, w1, h1, x2, y2, w2, h2;
                double left, bottom, right, top;

                printf("Перший прямокутник (x y ширина висота): ");
                if (scanf("%lf %lf %lf %lf", &x1, &y1, &w1, &h1) != 4) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                printf("Другий прямокутник (x y ширина висота): ");
                if (scanf("%lf %lf %lf %lf", &x2, &y2, &w2, &h2) != 4) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                if (w1 <= 0 || h1 <= 0 || w2 <= 0 || h2 <= 0) {
                    printf("Ширина і висота мають бути додатними.\n");
                    break;
                }

                left = x1;
                if (x2 < left) {
                    left = x2;
                }

                bottom = y1;
                if (y2 < bottom) {
                    bottom = y2;
                }

                right = x1 + w1;
                if (x2 + w2 > right) {
                    right = x2 + w2;
                }

                top = y1 + h1;
                if (y2 + h2 > top) {
                    top = y2 + h2;
                }

                printf("Лівий нижній кут: (%.2f, %.2f)\n", left, bottom);
                printf("Правий верхній кут: (%.2f, %.2f)\n", right, top);

                break;
            }

            case 2: {
                // Завдання 86. Чи однаковий зріст трьох осіб.
                double h1, h2, h3;

                printf("Введіть зріст трьох осіб: ");
                if (scanf("%lf %lf %lf", &h1, &h2, &h3) != 3) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                if (h1 <= 0 || h2 <= 0 || h3 <= 0) {
                    printf("Зріст має бути додатним.\n");
                } else if (h1 == h2 && h2 == h3) {
                    printf("Зріст усіх трьох осіб однаковий.\n");
                } else {
                    printf("Зріст осіб не однаковий.\n");
                }

                break;
            }

            case 3: {
                // Завдання 105. Існування і гострокутність трикутника.
                double a, b, c;

                printf("Введіть три додатні сторони: ");
                if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                if (a <= 0 || b <= 0 || c <= 0) {
                    printf("Сторони мають бути додатними.\n");
                } else if (a + b > c && a + c > b && b + c > a) {
                    printf("Трикутник існує.\n");

                    if (a*a + b*b > c*c &&
                        a*a + c*c > b*b &&
                        b*b + c*c > a*a) {
                        printf("Трикутник гострокутний.\n");
                    } else {
                        printf("Трикутник не гострокутний.\n");
                    }
                } else {
                    printf("Трикутник не існує.\n");
                }

                break;
            }

            case 4: {
                // Завдання 29. Заміна цілих чисел.
                int m, n, bigger;

                printf("Введіть цілі числа m і n: ");
                if (scanf("%d %d", &m, &n) != 2) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                if (m == n) {
                    m = 0;
                    n = 0;
                } else {
                    bigger = m;

                    if (n > bigger) {
                        bigger = n;
                    }

                    m = bigger;
                    n = bigger;
                }

                printf("m = %d, n = %d\n", m, n);

                break;
            }

            case 5: {
                // Завдання 90. Чи пройде цегла через отвір.
                double a, b, c, x, y;

                printf("Введіть ребра цегли a b c: ");
                if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                printf("Введіть сторони отвору x y: ");
                if (scanf("%lf %lf", &x, &y) != 2) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                if (a <= 0 || b <= 0 || c <= 0 || x <= 0 || y <= 0) {
                    printf("Усі розміри мають бути додатними.\n");
                } else if ((a <= x && b <= y) ||
                           (a <= y && b <= x) ||
                           (a <= x && c <= y) ||
                           (a <= y && c <= x) ||
                           (b <= x && c <= y) ||
                           (b <= y && c <= x)) {
                    printf("Цегла пройде через отвір.\n");
                } else {
                    printf("Цегла не пройде через отвір.\n");
                }

                break;
            }

            case 6: {
                // Завдання 68. Перетин прямокутників у першому квадранті.
                double x1, y1, x2, x3, y3, x4;
                double left, right, top, area;

                printf("Перший прямокутник (x1 y1 x2), нижня межа y = 0: ");
                if (scanf("%lf %lf %lf", &x1, &y1, &x2) != 3) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                printf("Другий прямокутник (x3 y3 x4), нижня межа y = 0: ");
                if (scanf("%lf %lf %lf", &x3, &y3, &x4) != 3) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                if (x1 < 0 || x3 < 0 || y1 <= 0 || y3 <= 0 ||
                    x2 <= x1 || x4 <= x3) {
                    printf("Некоректні координати прямокутників.\n");
                    break;
                }

                left = x1;
                if (x3 > left) {
                    left = x3;
                }

                right = x2;
                if (x4 < right) {
                    right = x4;
                }

                top = y1;
                if (y3 < top) {
                    top = y3;
                }

                // Якщо межі лише торкаються, площа перетину дорівнює нулю.
                if (left <= right) {
                    area = (right - left) * top;

                    printf("Прямокутники мають спільні точки.\n");
                    printf("Площа спільної частини: %.2f\n", area);
                } else {
                    printf("Прямокутники не перетинаються.\n");
                }

                break;
            }

            case 7: {
                // Завдання 82. Перевірка залишку від ділення.
                int a, b, c, d, remainder;

                printf("Введіть невід'ємне a і додатне b: ");
                if (scanf("%d %d", &a, &b) != 2) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                printf("Введіть числа c і d: ");
                if (scanf("%d %d", &c, &d) != 2) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                if (a < 0 || b <= 0) {
                    printf("Потрібно a >= 0 та b > 0.\n");
                } else {
                    remainder = a % b;

                    if (remainder == c || remainder == d) {
                        printf("Так, залишок %d дорівнює c або d.\n", remainder);
                    } else {
                        printf("Ні, залишок %d не дорівнює ні c, ні d.\n", remainder);
                    }
                }

                break;
            }

            case 8: {
                // Завдання 25. Яка точка ближче до (0, 0).
                double x1, y1, x2, y2, distA, distB;

                printf("Введіть координати точки A (x y): ");
                if (scanf("%lf %lf", &x1, &y1) != 2) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                printf("Введіть координати точки B (x y): ");
                if (scanf("%lf %lf", &x2, &y2) != 2) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                distA = x1*x1 + y1*y1;
                distB = x2*x2 + y2*y2;

                if (distA < distB) {
                    printf("Точка A ближче до початку координат.\n");
                } else if (distB < distA) {
                    printf("Точка B ближче до початку координат.\n");
                } else {
                    printf("Точки на однаковій відстані.\n");
                }

                break;
            }

            case 9: {
                // Завдання 16. Чи є тризначне число паліндромом.
                int number, first, last;

                printf("Введіть тризначне ціле число: ");
                if (scanf("%d", &number) != 1) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                if (number >= -999 && number <= -100) {
                    number = -number;
                }

                if (number < 100 || number > 999) {
                    printf("Число не є тризначним.\n");
                } else {
                    first = number / 100;
                    last = number % 10;

                    if (first == last) {
                        printf("Число є паліндромом.\n");
                    } else {
                        printf("Число не є паліндромом.\n");
                    }
                }

                break;
            }

            case 10: {
                // Завдання 61. Площа трикутника за формулою Герона.
                double a, b, c, p, area;

                printf("Введіть три додатні сторони a b c: ");
                if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
                    printf("Помилка введення.\n");
                    return 1;
                }

                if (a <= 0 || b <= 0 || c <= 0) {
                    printf("Сторони мають бути додатними.\n");
                } else if (a + b > c && a + c > b && b + c > a) {
                    p = (a + b + c) / 2.0;
                    area = sqrt(p * (p - a) * (p - b) * (p - c));

                    printf("Трикутник існує. Його площа: %.2f\n", area);
                } else {
                    printf("Трикутник не існує.\n");
                }

                break;
            }

            case 0:
                printf("Завершення програми.\n");
                break;

            default:
                printf("Немає такого пункту меню.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}
