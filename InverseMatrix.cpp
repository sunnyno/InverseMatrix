//
// Created by root on 27.09.15.
//
#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;

template <typename T> void FreeMem(T **matr, int n);
template <typename T> void PrintMtx(T **matr, int n);
template <typename T> void PrintVec(T vec, int n);
template <typename T> void SetMtx(T **matr, int n);
template <typename T> T SetVec(T vec, int n);
template <typename T> void TransponMtx(T **matr, T **tMatr, int n);
template <typename T> vector<double> MultMtx(T **matr, vector<int> vec, vector<double> rez, int n);
void Get_matr(int **matr, int n, int **temp_matr, int indRow, int indCol);
int Det(int **matr, int n);
int n=3;
void init();
int add(int a, int b);
void Get_InverseMtx(int det);
//int n = Get_n();
int **matr = new int * [n];
double **obr_matr = new double * [n];
double **tobr_matr = new double * [n];
vector <int> vec(n);
vector <double> rez(n);


//#include "InverseMatrix.h"

extern int add(int a, int b){
    return a+b;
}
int start() {
    init();
    SetMtx(matr, n);
    vec = SetVec(vec,n);
    PrintMtx(matr, n);
    PrintVec(vec,n);
    clock_t startTime = clock();
    Get_InverseMtx(Det(matr, n));
    clock_t Get_InverseMtx_Time = clock() - startTime;//Транспонирование матрицы
    TransponMtx(obr_matr, tobr_matr, n);
    clock_t TransponMtx_Time = clock() - Get_InverseMtx_Time -startTime;
    rez = MultMtx(tobr_matr, vec, rez, n);
    clock_t MultMtx_Time = clock() - Get_InverseMtx_Time - TransponMtx_Time -startTime;
    clock_t workTime = clock() - startTime;
    cout << "Результат: " << endl;
    PrintVec(rez, n);
    cout << "Время инвертирования матрицы и поиска детерминанта = " << Get_InverseMtx_Time << "ms"<< endl;
    cout << "Время транспонирования матрицы = " << TransponMtx_Time << "ms"<< endl;
    cout << "Время умножения матриц = " << MultMtx_Time << "ms"<< endl;
    cout << "Общее время работы = " << workTime << "ms"<< endl;
    FreeMem(tobr_matr, n);
    FreeMem(matr, n);
    FreeMem(obr_matr, n);
}

void Get_InverseMtx(int det){
    cout << "Определитель матрицы = " << det << endl;
    if(det){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int m = n - 1;
                int **temp_matr = new int * [m];
                for(int k = 0; k < m; k++)
                    temp_matr[k] = new int[m];
                Get_matr(matr, n, temp_matr, i, j);
                obr_matr[i][j] = pow(-1.0, i + j + 2) * Det(temp_matr, m) / det;
                FreeMem(temp_matr, m);
            }
        }
    }else cout << "Т.к. определитель матрицы = 0,\nто матрица вырожденная и обратной не имеет!!!" << endl;
}

void init(){
    srand((unsigned)time(NULL));
    setlocale(0, "");
    for(int i = 0; i < n; i++){
        matr[i] = new int[n];
        obr_matr[i] = new double[n];
        tobr_matr[i] = new double[n];
    }

}


//int Get_n(){
////    int n;
////    cout << "Введите размер матрицы: ";
////    cin >> n;
////    if (n < 0) {
////        cout << "Размер матрицы не может быть отрицательным";
////        return 0;
////    }
//    return ;
//
//}


//Функция транспонирования матрицы
template <typename T> void TransponMtx(T **matr, T **tMatr, int n){//
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tMatr[j][i] = matr[i][j];
}
//Функция умножения матрицы на вектор
template <typename T> vector<double> MultMtx(T **matr, vector<int> vec, vector<double> rez, int n){
    for (int i = 0; i < n; i++)
    {
        rez[i] = 0; //очищаем элемент массива
        for (int j = 0; j < n; j++)
        {
            rez[i] += vec[j]*matr[i][j]; //производим умножение матрицы на вектор
        }
    }
    return rez;
}


//Функция освобождения памяти
template <typename T> void FreeMem(T **matr, int n)
{
    for(int i = 0; i < n; i++)
        delete [] matr[i];
    delete [] matr;
}

//функция заполнения матрицы
template <typename T> void SetMtx(T **matr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matr[i][j] = rand()%9 + 1;
}

//функция заполнения вектора
template <typename T> T SetVec(T vec, int n)
{
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 9 + 1;
    }
    return vec;
}

//функция печати матрицы
template <typename T> void PrintMtx(T **matr, int n)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << matr[i][j] << " ";
        cout << endl;
    }
}

//функция печати вектора
template <typename T> void PrintVec(T vec, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << vec[i] << " ";
        cout << endl;
    }


}

//функция вычеркивания строки и столбца
void Get_matr(int **matr, int n, int **temp_matr, int indRow, int indCol)
{
    int ki = 0;
    for (int i = 0; i < n; i++){
        if(i != indRow){
            for (int j = 0, kj = 0; j < n; j++){
                if (j != indCol){
                    temp_matr[ki][kj] = matr[i][j];
                    kj++;
                }
            }
            ki++;
        }
    }
}

//==============================================================================================================
//                              вычисление определителя
//==============================================================================================================
//функция вычисления определителя матрицы
int Det(int **matr, int n)
{
    int temp = 0;   //временная переменная для хранения определителя
    int k = 1;      //степень
   if (n == 1)
        temp = matr[0][0];
    else if (n == 2)
        temp = matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1];
    else{
        for(int i = 0; i < n; i++){
            int m = n - 1;
            int **temp_matr = new int * [m];
            for(int j = 0; j < m; j++)
                temp_matr[j] = new int [m];
            Get_matr(matr, n, temp_matr, 0, i);
            temp = temp + k * matr[0][i] * Det(temp_matr, m);
            k = -k;
            FreeMem(temp_matr, m);
        }
    }
    return temp;
}
