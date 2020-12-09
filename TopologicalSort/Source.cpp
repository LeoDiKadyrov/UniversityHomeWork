#include "BoolMatrix.h"
#include "BoolVector.h"
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "russian");
    int n = 9, i = 0;
    char** s;
    s = new char* [n];
    for (int i = 0; i < n; i++)
    {
        s[i] = new char[n];
    }
    strcpy_s(s[0], 10, "000101000"); 
    strcpy_s(s[1], 10, "101000100"); 
    strcpy_s(s[2], 10, "000100000"); 
    strcpy_s(s[3], 10, "000000000"); 
    strcpy_s(s[4], 10, "001000000"); 
    strcpy_s(s[5], 10, "000010000"); 
    strcpy_s(s[6], 10, "000000010"); 
    strcpy_s(s[7], 10, "000010000"); 
    strcpy_s(s[8], 10, "000111000");
    BoolMatrix bm(s, n);
    BoolVector v0(n), v1(n), d(n), w(n);
    int* res;
    res = new int[100];

    cout << "Исходная матрица: " << endl;
    cout << bm;

    while (i < n)
    {
        d = bm.Disn();
        w = ~d;       
        v1 = v0 ^ w;

        for (int j = 0; j < n; j++)
        {
            if (v1[n - j - 1])
            {
                res[i] = j + 1;
                i++;
                bm.SetUp0(j, n, 0);
            }
        }
        v0 = w;
    }
    cout << "res = ";
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    delete[] s;
    delete[] res;
    return 0;
}