#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <math.h>

using namespace std;

class Pramaya
{
    double a, b, c;
public:
    Pramaya(double a = 1, double b = 1, double c = 1); 
    void parallel();
    void cut();
    void angle();
    bool same(Pramaya line1);
    void perpendicularity(Pramaya line1);
    void beginning();
    void point();
    void distance();
    void cross(Pramaya line1);
    void angleBetween(Pramaya line1);
    void further(Pramaya line1);
    bool linesParallel(Pramaya line1);
    void distanceParallel(Pramaya line1);
    void lejitje(Pramaya line1);
};

Pramaya::Pramaya(double s, double d, double f) {
    if (s == 0 && d == 0) {
       throw exception("� ��� � = 0!");
    }
    else if (c == 0) {
        a = s; b = d; 
        cout << "������ �������� ����� ������ ���������!" << endl;
        printf("%.2lfx + %.2lfy = 0\n", a, b);
    }
    else {
        a = s; b = d; c = f;
        printf("%.2lfx + %.2lfy + %.2lf = 0\n", a, b, c);
    } 
}

void Pramaya::parallel() {
    cout << "____________________________" << endl;
    cout << endl;
    if (a == 0) {
        cout << "������ ����������� ��� ��" << endl;
    }
    else if (b == 0) { cout << "������ ����������� ��� ��" << endl; }
    else { cout << "������ �� ����������� ����" << endl; }
}

void Pramaya::cut() {
    cout << "____________________________" << endl;
    cout << endl;
    double x, y; //���������� ��� �������� ���������� ��������(��� ���� �� � �� ��������������)
    if (c != 0) {
        x = -(c / a);
        y = -(c / b);
        cout << x << " ������� ���������� ������ �� ��� ��" << endl;
        cout << y << " ������� ���������� ������ �� ��� �y" << endl;
    } 
    else { cout << "������ �� �������� ������� �� ����" << endl; }
}

void Pramaya::angle() {
    cout << "____________________________" << endl;
    cout << endl;
    if (b != 0) {
        cout << a / b << " = ������� �����������" << endl;
    }
    else {
        cout << "������ ����������� ��� �y" << endl;
    }
}

bool Pramaya::same(Pramaya line1) {
    cout << "____________________________" << endl;
    cout << endl;
    double k = 0; // ��� �������� ���������
    if (a != 0 && line1.a != 0) {
        k = a / line1.a;
    } 
    else if (b != 0 && line1.b != 0) {
        k = b / line1.b;
    }
    else {
        k = c / line1.c;
    }
    if ((a == k * line1.a) && (b = k * line1.b) && (c = k * line1.c)) {
        cout << "������ ���������" << endl;
        return true;
    }
    else {
        cout << "������ �� ���������" << endl;
        return false;
    }
}

void Pramaya::perpendicularity(Pramaya line1) {
    cout << "____________________________" << endl;
    cout << endl;
    double x, y;
    x = a * line1.a; y = b * line1.b;
    if (x + y == 0) {
        cout << "������ ���������������" << endl;
    }
    else { cout << "������ �����������������" << endl; }
}

void Pramaya::beginning() {
    cout << "____________________________" << endl;
    cout << endl;
    double x;
    if (c != 0) {
        x = fabs(c) / (sqrt(pow(a, 2) + pow(b, 2)));
        cout << "���������� �� ������ ��������� = " << x << endl;
    }
    else {
        cout << "������ �������� ����� ������ ���������" << endl;
    }
}

void Pramaya::point() {
    cout << "____________________________" << endl;
    cout << endl;
    double x, y;
    cout << "������� ���������� ����� � � � ��������������: ";
    cin >> x >> y;
    if ((a * x + b * y + c) == 0) {
        cout << "����� ����������� ������" << endl;
    }
    else { cout << "�� �����������" << endl; }
}

void Pramaya::distance() {
    cout << "____________________________" << endl;
    cout << endl;
    double x, y, normal, q, r, t, answer;
    cout << "������� ���������� ����� � � � ��������������: ";
    cin >> x >> y;
    if (c > 0) {
        normal = -(1 / (sqrt(pow(a, 2) + pow(b, 2))));
    }
    else { normal = (1 / (sqrt(pow(a, 2) + pow(b, 2)))); }
    q = a * normal; r = b * normal; t = c * normal; 
    answer = fabs((q*x) + (r*y) + t); // - lost
    if ((answer) != 0) {
        cout << "���������� �� ������ �� ����� = " << answer << endl;
    }
    else { cout << "����� ����� �� ������" << endl; }
}

void Pramaya::cross(Pramaya line1) {
    cout << "____________________________" << endl;
    cout << endl;
    double x, y;
    double det = a * line1.b - line1.a * b;
    if (det == 0) {
        cout << "������ �����������" << endl;
    }
    else {
        x = (b * line1.c - line1.b * c) / det;
        y = (line1.a * c - a * line1.c) / det;
        
        cout << "����� �����������: " << x << " " << y << endl;
    }
}

void Pramaya::angleBetween(Pramaya line1) {
    cout << "____________________________" << endl;
    cout << endl;
    if (!linesParallel(line1)) {
        double cos, nominator, denominator, angle;
        nominator = fabs(a * line1.a + b * line1.b);
        denominator = sqrt(pow(a, 2) + pow(b, 2)) * sqrt(pow(line1.a, 2) + pow(line1.b, 2));
        cos = nominator / denominator;
        angle = acos(cos);
        cout << "���� ����� ��������������� ������� = " << angle << endl;
    }
    else {
        cout << "������ �� ������������" << endl;
    }
}

void Pramaya::further(Pramaya line1) {
    cout << "____________________________" << endl;
    cout << endl;
    double d1, d2;
    d1 = fabs(c / sqrt(pow(a, 2) + pow(b, 2)));
    d2 = fabs(line1.c / sqrt(pow(line1.a, 2) + pow(line1.b, 2)));
    if (d1 == d2) {
        cout << "�� ����� ����������" << endl;
    }
    else if (d1 < d2) { 
        cout << "������ ������ ����� � ������ ���������" << endl;
    }
    else { cout << "������ ������ ����� � ������ ���������" << endl; }
}

bool Pramaya::linesParallel(Pramaya line1) {
    cout << "____________________________" << endl;
    cout << endl;
    double k = 0; // ��� �������� ���������
    if (a != 0 && line1.a != 0) {
        k = a / line1.a;
    }
    else if (b != 0 && line1.b != 0) {
        k = b / line1.b;
    }
    if ((a == k * line1.a) && (b = k * line1.b) && (c != k * line1.c)) {
        cout << "������ �����������" << endl;
        return true;
    }
    else { 
        cout << "������ �� �����������" << endl;
        return false;
    }
    
}

void Pramaya::distanceParallel(Pramaya line1) {
    double distance;
    if (linesParallel(line1)) {
        distance = (fabs(line1.c - c)) / sqrt(pow(a, 2) + pow(b, 2));
        cout << "���������� ����� ����� ������������� ������� = " << distance << endl;
    }
    else { cout << "������ �� �����������" << endl; }
}

void Pramaya::lejitje(Pramaya line1) {
    cout << "____________________________" << endl;
    cout << "������� ������������ ��������� ������: ";
    double a3, b3, c3; // ������������ ������� ������
    double k1, k2;
    cin >> a3 >> b3 >> c3;
    if (linesParallel(line1)) {
        if (a3 * b3 != 0) {
            k1 = a / line1.a;
            k2 = line1.a / a3;
            double result = (c - (k1 / line1.a) * line1.c) * (c3 - (k2 / line1.a) * line1.c);
            if (result < 0) {
                cout << "����� �������" << endl;
            }
            else { cout << "�� ����� �������" << endl; }
        }
        else if (a3 == 0) {
                if ((c / b > line1.c / line1.b) && (line1.c / line1.b > c3 / b3)) {
                    cout << "����� �������" << endl;
                }
                else { cout << "�� ����� �������" << endl; }
        }
            else {
                if ((c / a > line1.c / line1.a) && (line1.c / line1.a > c3 / a3)) {
                    cout << "����� �������" << endl;
                }
                else { cout << "�� ����� �������" << endl; }
            }
    }
    else if (same(line1)) { cout << "�� ����� �������" << endl; }
    else { 
        cout << "������ �� �����������" << endl;
        cout << "�� ����� �������" << endl;
    }
}


