//
// Created by root on 27.09.15.
//
#include <cxxtest/TestSuite.h>

#ifndef INVERSEMATRIX_MYTEST_H
#define INVERSEMATRIX_MYTEST_H

#include "InverseMatrix.cpp"


class MyTest: public CxxTest::TestSuite
{
public:

    void test_mult(void)
    {
        const int m =3;
        int **matrix = new int * [m];
        vector <int> vect(m);
        vector <double> rezult(m);
        vector <double> truerezult(m);
        for (int i = 0; i < m; i++) {
            matrix[i] = new int[m];
            vect[i] = 1;
            truerezult[i] = 6;
            for (int j = 0; j < m; j++)
                matrix[i][j] = 2;
        }
        TS_ASSERT_EQUALS(MultMtx(matrix, vect, rezult, m),truerezult);

    }

    void test_Get_matr(void) {
        const int m = 3;
        int **matrix = new int * [m];
        int **tempTrue = new int *[m*(m-1)];
        int **temp = new int*[m*(m-1)];
        int row = 0;
        int col = 0;
        for (int i = 0; i < m; i++) {
            matrix[i] = new int[m];
            for (int j = 0; j < m; j++)
                matrix[i][j] = 2;
        }
        for (int i = 0; i < m-1; i++) {
            tempTrue[i] = new int[m-1];
            temp[i] = new int[m-1];
            for (int j = 0; j < m-1; j++)
                tempTrue[i][j] = 2;
        }
        Get_matr(matrix,m,temp,row,col);
        TS_ASSERT_EQUALS(temp, tempTrue);
    }

    void test_Det(void)
    {
        const int m = 3;
        int **matrix = new int * [m];
        for (int i = 0; i < m; i++) {
            matrix[i] = new int[m];
            for (int j = 0; j < m; j++) {
                if (i == j)
                    matrix[i][j] = 8;
                else matrix[i][j] = 2;
            }
        }
        int det = 432;
        TS_ASSERT_EQUALS(Det(matrix,m),det);
    }
    void test_TransponMtx(void)
    {
        const int m = 3;
        int **matrix = new int * [m];
        int **trans = new int*[m];
        int **transTrue = new int*[m];
        for (int i = 0; i < m; i++) {
            matrix[i] = new int[m];
            trans[i] = new int[m];
            transTrue[i] = new int[m];
            for (int j = 0; j < m; j++) {
                if (j == 1){
                    matrix[i][j] = 1;
                    transTrue[j][i] =1;}
                else{
                    matrix[i][j] = 2;
                    transTrue[j][i] = 2;}

            }
        }
        TransponMtx(matrix,trans,m);
        TS_ASSERT_EQUALS(trans,transTrue);
    }

};

#endif //INVERSEMATRIX_MYTEST_H
