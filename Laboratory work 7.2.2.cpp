#include <iostream>
using namespace std;

double square(double dimension, ...);

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите колличество измерений (2 - 3): ";
	int dimensional;
	cin >> dimensional;
	double x_a, y_a, z_a, x_b, y_b, z_b, x_c, y_c, z_c, a, b, c;
	bool f = true;
	switch (dimensional)
	{
	case 2:
	{
		cout << "Введите координаты точки A:\n";
		cout << "x_a = ";
		cin >> x_a;
		cout << "y_a = ";
		cin >> y_a;
		cout << "Введите координаты точки B:\n";
		cout << "x_b = ";
		cin >> x_b;
		cout << "y_b = ";
		cin >> y_b;
		cout << "Введите координаты точки C:\n";
		cout << "x_c = ";
		cin >> x_c;
		cout << "y_c = ";
		cin >> y_c;

		cout << "Проверьте введенные данные:\n";
		cout << "A(" << x_a << ", " << y_a << "),\n";
		cout << "B(" << x_b << ", " << y_b << "),\n";
		cout << "C(" << x_c << ", " << y_c << "),\n";

		a = square(2, x_a, x_b, y_a, y_b);
		b = square(2, x_b, x_c, y_b, y_c);
		c = square(2, x_c, x_a, y_c, y_a);
		break;
	}
	case 3:
	{
		cout << "Введите координаты точки A:\n";
		cout << "x_a = ";
		cin >> x_a;
		cout << "y_a = ";
		cin >> y_a;
		cout << "z_a = ";
		cin >> z_a;
		cout << "Введите координаты точки B:\n";
		cout << "x_b = ";
		cin >> x_b;
		cout << "y_b = ";
		cin >> y_b;
		cout << "z_b = ";
		cin >> z_b;
		cout << "Введите координаты точки C:\n";
		cout << "x_c = ";
		cin >> x_c;
		cout << "y_c = ";
		cin >> y_c;
		cout << "z_c = ";
		cin >> z_c;

		cout << "Проверьте введенные данные:\n";
		cout << "A(" << x_a << ", " << y_a << ", " << z_a << "),\n";
		cout << "B(" << x_b << ", " << y_b << ", " << z_b << "),\n";
		cout << "C(" << x_c << ", " << y_c << ", " << z_c << "),\n";

		a = square(3, x_a, x_b, y_a, y_b, z_a, z_b);
		b = square(3, x_b, x_c, y_b, y_c, z_b, z_c);
		c = square(3, x_c, x_a, y_c, y_a, z_c, z_a);
		break;
	}
	default:
	{
		cout << "Недопустимое значение!";
		f = false;
	}
	}

	if (f)
	{
		cout << "Сторона AB (a) = " << a << "\n";
		cout << "Сторона BC (b) = " << b << "\n";
		cout << "Сторона CA (c) = " << c << "\n";
		double P = a + b + c;
		cout << "Периметр: \nP = a + b + c =\n= " << a << " + " << b << " + " << c << " =\n= " << P << '\n';
		double p = P / 2;
		cout << "Полупериметр:\np = P / 2 =\n= " << P << " / 2 =\n= " << p << '\n';
		cout << "Площадь ABC:\nS = (p * (p - a) * (p - b) * (p - c))^0.5 = \n";
		cout << "= ((" << p << " * (" << p << " - " << a << ") * (" << p << " - " << b << ") * (" << p << " - " << c << ")) ^ 0.5 = \n";
		cout << "= ((" << p << " * (" << p - a << ") * (" << p - b << ") * (" << p - c << ")) ^ 0.5 = \n";
		double area = pow((p * (p - a) * (p - b) * (p - c)), 0.5);
		cout << "= (" << pow(area, 2) << ")^0.5 = " << area;
	}
	return 0;
}

double square(double dimension, ...)
{
	double* p = &dimension;
	double side = 0;
	for (int i = 0; i < dimension * 2; i = i + 2)
	{
		side = side + pow(*(p + i + 1) - *(p + i + 2), 2);
	}
	return pow(side, 0.5);
}

