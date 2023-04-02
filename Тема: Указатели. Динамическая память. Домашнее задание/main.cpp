#include <iostream>
#include <time.h>

//Задание 1.
//Объявить указатели на две переменные указанного типа.
//Используя указатели произвести операции сложения и вычитания над переменными. Вывести адреса указателей.
// Тип переменных в моём случае - double(14 вариант).


//double Summirovanie(double*A, double*B, double &Sum){
//    return Sum = *A + *B;
//}

//double Raznost(double*A, double*B, double &Raz){
//    return Raz = *A - *B;
//}

//void show(double*A, double*B, double Sum, double Raz){
//    std::cout << "numA:   " << *A << std::endl;
//    std::cout << "numB:   " << *B << std::endl << std::endl ;

//    std::cout << "A + B:  " << Sum << std::endl;
//    std::cout << "A - B:  " << Raz << std::endl << std::endl;

//    std::cout << "A:   " << A << std::endl;
//    std::cout << "B:   " << B << std::endl;

//}

//void deleted(double*A, double*B){
//    delete A;
//    delete B;

//    std::cout << std::endl;

//    std::cout << "delete A:      " << *A << std::endl;
//    std::cout << "delete B:      " << *B << std::endl;
//}

//int main()
//{

//    double* A;
//    double* B;

//    double Sum, Raz;
//    A = new double;
//    B = new double;

//    *A = 54.61;
//    *B = 12.32;

// double S = Summirovanie(A, B, Sum);
// double R = Raznost(A, B, Raz);
// show(A, B, S, R);
// deleted(A, B);

//return 0;
//}

//Задание 2.
//Написать функцию для обмена значений переменных, указанных выше. Передача по
//указателю. Выполнить программу по шагам и выписать в тетрадь адреса указателей
//и величины переменных. double.

//void show(double*A, double*B){
//    std::cout << "numA:   " << *A << std::endl;
//    std::cout << "numB:   " << *B << std::endl << std::endl ;

//    std::cout << "A:   " << A << std::endl;
//    std::cout << "B:   " << B << std::endl;
//}

//double switch_(double*&A, double*&B, double*&C){
//   C = A;
//    A = B;
//     B = C;
//     std::cout << std::endl;
//}
//void deleted(double*A, double*B){
//    delete A;
//    delete B;

//    std::cout << std::endl;

//    std::cout << "delete A:      " << *A << std::endl;
//    std::cout << "delete B:      " << *B << std::endl;
//}

//int main()
//{

//    double* A;
//    double* B;
//    double* rem = 0;

//    A = new double;
//    B = new double;

//    *A = 54.61;
//    *B = 12.32;

// show(A, B);
// switch_(A, B, rem);
// show(A, B);
// deleted(A, B);
//return 0;
//}

//Задание 3.
//Объявить динамический массив. Размер массива задаёт пользователь. Заполнить
//массив случайными числами. Вывести на экран адреса и значения элементов
//массива. double.

//void massive(double *A[], int n){
//    for(int i = 0; i < n; i++){
//        A[i] = new double[i];
//        *A[i] = rand()% 54;

//    }
//}

//void show(double *A[], int n){
//    for(int i = 0; i < n; i++){
//        std::cout << " adress: " << A[i] << "; " << " chislo: " << *A[i] << std::endl;
//    }
//}

//double deleted(double *A[], int n){
//       delete A;
//}

//int main()
//{
//    srand(time(NULL));
//    int n;
//    std::cin  >> n;
//    double* A[n];

//   massive(A, n);
//  show(A, n);
// deleted(A, n);
//return 0;
//}


//Задание 4.
//Объявить сущность и описать её свойства. Объявить динамический массив
//сущностей. Реализовать функцию, которая изменяет значения элемента (структура)
//массива. Заполнить атрибуты числовыми и текстовыми значениями (диапазон
//значений определить самостоятельно)(Книги).

#include <iostream>

int N = 3;

struct Book
{
    int pages;
    float mass;
    double cost;
};

void changes(Book* books,const int N)
{
    for (int i = 0; i < N; i++)
    {
        books [i].pages += 6;
        books [i].mass += 0.99;
        books [i].cost += 0.99;
    }
}

int main()
{
    Book* books = nullptr;
    books = new Book[N];
    for (int i = 0; i < N; i++)
    {
        books[i].pages = rand()%100 + 50;
        books[i].mass = rand()%5;
        books[i].cost = rand()%500 + 100;

        std::cout << &books[i] << std::endl <<" Pages: " << books[i].pages
                  <<"; weight: "<< books[i].mass << "; cost: " << books[i].cost << std::endl;
    }

    std::cout<<std::endl;


    changes(books,N);

    for (int i = 0; i < N; i++)
    {
        std::cout << &books[i] << std::endl << " Pages: "<< books[i].pages
                  <<"; weight: " << books[i].mass << "; cost: "<< books[i].cost << std::endl;
    }

    delete [] books;

    return 0;
}
