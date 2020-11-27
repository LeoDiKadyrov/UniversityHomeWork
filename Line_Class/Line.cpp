#include "Line.h"
#include <iostream>
#include <locale.h>
#include <exception>
#include <stdexcept>

using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	cout << "������� a, b, c ������ ������ ��������������: ";
	double a, b, c, a1, b1, c1;
	cin >> a >> b >> c;
	cout << "������� a, b, c ������ ������ ��������������: ";
	cin >> a1 >> b1 >> c1;
	try {
		Pramaya line = Pramaya{ a, b, c };
		Pramaya line2 = Pramaya{a1, b1, c1};
		line.parallel();
		line.cut();
		line.angle();
		line.same(line2);
		line.perpendicularity(line2);
		line.beginning();
		line.point();
		line.distance();
		line.cross(line2);
		line.angleBetween(line2);
		line.further(line2);
		line.linesParallel(line2);
		line.distanceParallel(line2);
		line.lejitje(line2);
	}
	catch (exception err) {
		cout << err.what() << endl;
	}
	
	return 0;
}

