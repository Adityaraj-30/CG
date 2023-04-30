
//  Question 01: Write a program to implement Bresenhams line drawing algorithm.

//    Program:

#include <bits/stdc++.h>
#include <graphics.h>
#include <iostream>
using namespace std;

void line(int x1, int y1, int x2, int y2, float X, float Y)
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char *)"");
	int P, k;
	float m = Y / X;
	if (m < 1)
	{
		P = 2 * Y - X;
	}
	else if (m >= 1)
	{
		P = 2 * X - Y;
	}
	cout << "\n\n__________Table______________\n\n";
	cout << "\nk\tP\tx   y\n";
	k = 0;
	do
	{
		cout << k << "\t" << P;
		if (m < 1 && P < 0)
		{
			x1++, y1;
			P = P + 2 * Y;
		}
		else if (m < 1 && P >= 0)
		{
			x1++;
			y1++;
			P = P + (2 * Y - 2 * X);
		}
		else if (m >= 1 && P < 0)
		{
			x1;
			y1++;
			P = P + 2 * X;
		}
		else if (m >= 1 && P >= 0)
		{
			x1++;
			y1++;
			P = P + (2 * X - 2 * Y);
		}
		cout << "\t" << x1 << "  " << y1 << "\n";
		k++;
		putpixel(x1, y1, YELLOW);
	} while ((x1 != x2) && (y1 != y2));
	getch();
	closegraph();
}
int main()
{
	int x1, y1, x2, y2;
	float X, Y;
	cout << "Enter coordinate x1,y1 -> ";
	cin >> x1 >> y1;
	cout << "\n\nEnter coordinate x2,y2 -> ";
	cin >> x2 >> y2;
	X = x2 - x1;
	Y = y2 - y1;
	line(x1, y1, x2, y2, X, Y);
	return 0;
}

// Question 02: Write a program to implement mid-point circle drawing algorithm.

//    Program:

#include <iostream>
#include <graphics.h>
using namespace std;

int main()
{
	int gd = DETECT, gm;			 // initalize graphics drivers and graphics mode
	initgraph(&gd, &gm, (char *)""); // initialize graph
	int xc, yc, x, y, r, d;
	cout << "\n\n______________________Mid Point circle Drawing    Algorithm___________________________\n\n";
	cout << "Enter co-ordinates of Center of Circle -> ";
	cin >> xc >> yc;
	cout << "Enter Radius of Circle -> ";
	cin >> r;
	d = (5 / 4) - r;
	x = 0;
	y = r;
	while (x <= y)
	{
		putpixel(xc + x, yc + y, 5); // 5 for pink color
		putpixel(xc - x, yc + y, 5);
		putpixel(xc - x, yc - y, 5);
		putpixel(xc + x, yc - y, 5);
		putpixel(xc + y, yc + x, 5); // 5 for pink color
		putpixel(xc + y, yc - x, 5);
		putpixel(xc - y, yc - x, 5);
		putpixel(xc - y, yc + x, 5);
		if (d <= 0)
		{
			d = d + 2 * x + 3;
		}
		else
		{
			d = d + 2 * (x - y) + 5;
			y = y - 1;
		}
		x = x + 1;
	}
	getch();
	closegraph();
}

// Question 03:  Write a program to clip a line using Cohen and Sutherland line clipping algorithm.

//  Program:

#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8, xmin, ymin, xmax, ymax;

int getcode(int x, int y)
{
	int code = 0;
	if (y > ymax)
		code = TOP;
	if (y < ymin)
		code = BOTTOM;
	if (x < xmin)
		code = LEFT;
	if (x > xmax)
		code = RIGHT;
	return code;
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char *)"");
	setcolor(WHITE);
	cout << "\n\nEnter coordinates of Clipping window -> ";
	cin >> xmin >> ymin >> xmax >> ymax;
	setcolor(2);
	rectangle(xmin, ymin, xmax, ymax);
	int a[4], b[4];
	int x1, y1, x2, y2;
	cout << "\n\nEnter the end points of line -> ";
	cin >> x1 >> y1 >> x2 >> y2;
	setcolor(WHITE);
	line(x1, y1, x2, y2);
	getch();
	int outcode1 = getcode(x1, y1), outcode2 = getcode(x2, y2);
	int accept = 0;
	while (1)
	{
		float m = (float)(y2 - y1) / (x2 - x1);
		if (outcode1 == 0 && outcode2 == 0)
		{
			accept = 1;
			break;
		}
		else if ((outcode1 & outcode2) != 0)
		{
			break;
		}
		else
		{
			int x, y;
			int temp;
			if (outcode1 == 0)
			{
				temp = outcode2;
			}
			else
			{
				temp = outcode1;
			}
			if (temp & TOP)
			{
				x = x1 + (ymax - y1) / m;
				y = ymax;
			}
			else if (temp & BOTTOM)
			{
				x = x1 + (ymin - y1) / m;
				y = ymin;
			}
			else if (temp & LEFT)
			{
				x = xmin;
				y = y1 + m * (xmin - x1);
			}
			else if (temp & RIGHT)
			{
				x = xmax;
				y = y1 + m * (xmax - x1);
			}
			if (temp == outcode1)
			{
				x1 = x;
				y1 = y;
				outcode1 = getcode(x1, y1);
			}
			else
			{
				x2 = x;
				y2 = y;
				outcode2 = getcode(x2, y2);
			}
		}
	}
	cout << "\n\n\t\t-----------------------------After Clipping-------------------------\n\n";
	if (accept)
	{
		cleardevice();
		rectangle(xmin, ymin, xmax, ymax);
		setcolor(YELLOW);
		line(x1, y1, x2, y2);
	}
	getch();
	closegraph();
}

// Question 04: Write a program to clip a polygon using Sutherland Hodgeman algorithm.
//    Program:
#include <iostream>
#include <graphics.h>
#include <conio.h>
#define round(a) ((int)(a + 0.5))
using namespace std;

int k;
float xmin, ymin, xmax, ymax, arr[20], m;

void clipleft(float x1, float y1, float x2, float y2)
{
	if (x2 - x1)
		m = (y2 - y1) / (x2 - x1);
	else
		m = 100000;
	if (x1 >= xmin && x2 >= xmin)
	{
		arr[k] = x2;
		arr[k + 1] = y2;
		k += 2;
	}
	if (x1 < xmin && x2 >= xmin)
	{
		arr[k] = xmin;
		arr[k + 1] = y1 + m * (xmin - x1);
		arr[k + 2] = x2;
		arr[k + 3] = y2;
		k += 4;
	}
	if (x1 >= xmin && x2 < xmin)
	{
		arr[k] = xmin;
		arr[k + 1] = y1 + m * (xmin - x1);
		k += 2;
	}
}
void cliptop(float x1, float y1, float x2, float y2)
{
	if (y2 - y1)
		m = (x2 - x1) / (y2 - y1);
	else
		m = 100000;
	if (y1 <= ymax && y2 <= ymax)
	{
		arr[k] = x2;
		arr[k + 1] = y2;
		k += 2;
	}
	if (y1 > ymax && y2 <= ymax)
	{
		arr[k] = x1 + m * (ymax - y1);
		arr[k + 1] = ymax;
		arr[k + 2] = x2;
		arr[k + 3] = y2;
		k += 4;
	}
	if (y1 <= ymax && y2 > ymax)
	{
		arr[k] = x1 + m * (ymax - y1);
		arr[k + 1] = ymax;
		k += 2;
	}
}
void clipright(float x1, float y1, float x2, float y2)
{
	if (x2 - x1)
		m = (y2 - y1) / (x2 - x1);
	else
		m = 100000;
	if (x1 <= xmax && x2 <= xmax)
	{
		arr[k] = x2;
		arr[k + 1] = y2;
		k += 2;
	}
	if (x1 > xmax && x2 <= xmax)
	{
		arr[k] = xmax;
		arr[k + 1] = y1 + m * (xmax - x1);
		arr[k + 2] = x2;
		arr[k + 3] = y2;
		k += 4;
	}
	if (x1 < xmax && x2 > xmax)
	{
		arr[k] = xmax;
		arr[k + 1] = y1 + m * (xmax - x1);
		k += 2;
	}
}
void clipbottom(float x1, float y1, float x2, float y2)
{
	if (y2 - y1)
		m = (x2 - x1) / (y2 - y1);
	else
		m = 100000;
	if (y1 >= ymin && y2 >= ymin)
	{
		arr[k] = x2;
		arr[k + 1] = y2;
		k += 2;
	}
	if (y1 < ymin && y2 >= ymin)
	{
		arr[k] = x1 + m * (ymin - y1);
		arr[k + 1] = ymin;
		arr[k + 2] = x2;
		arr[k + 3] = y2;
		k += 4;
	}
	if (y1 >= ymin && y2 < ymin)
	{
		arr[k] = x1 + m * (ymin - y1);
		arr[k + 1] = ymin;
		k += 2;
	}
}
int main()
{
	int gd = DETECT, gm, n, poly[20];
	float xi, yi, xf, yf, polyy[20];
	int i;
	cout << "\nEnter coordinates of rectangular Clip Window:\n\n";
	cout << "Enter (xmin,ymin) -> ";
	cin >> xmin >> ymin;
	cout << "Enter (xmax,ymax) -> ";
	cin >> xmax >> ymax;
	cout << "\n\nPolygon to be cliped:\n\n\t\t Enter number of sides -> ";
	cin >> n;
	cout << "\n\nEnter the coordinates of Plygon -\n\n";
	for (i = 0; i < 2 * n; i++)
	{
		cin >> polyy[i];
	}
	polyy[i] = polyy[0]; // change
	polyy[i + 1] = polyy[1];
	for (int i = 0; i < 2 * n + 2; i++)
	{
		poly[i] = round(polyy[i]);
	}
	initgraph(&gd, &gm, (char *)"");
	setcolor(YELLOW);
	rectangle(xmin, ymax, ymax, ymin);
	cout << "\n\t\tUnclipped Polygon....";
	setcolor(WHITE);
	fillpoly(n, poly);
	getch();
	cleardevice();
	k = 0;
	for (i = 0; i < 2 * n; i += 2)
		clipleft(polyy[i], polyy[i + 1], polyy[i + 2], polyy[i + 3]);
	n = k / 2;
	for (i = 0; i < k; i += 2)
		polyy[i] = arr[i];
	polyy[i] = polyy[0];
	polyy[i + 1] = polyy[1];
	k = 0;
	for (i = 0; i < 2 * n; i += 2)
		cliptop(polyy[i], polyy[i + 1], polyy[i + 2], polyy[i + 3]);
	n = k / 2;
	for (i = 0; i < k; i++)
		polyy[i] = arr[i];
	polyy[i] = polyy[0];
	polyy[i + 1] = polyy[1];
	k = 0;
	for (i = 0; i < 2 * n; i += 2)
		clipright(polyy[i], polyy[i + 1], polyy[i + 2], polyy[i + 3]);
	n = k / 2;
	for (i = 0; i < k; i++)
		polyy[i] = arr[i];
	polyy[i] = polyy[0];
	polyy[i + 1] = polyy[1];
	k = 0;
	for (i = 0; i < 2 * n; i += 2)
		clipbottom(polyy[i], polyy[i + 1], polyy[i + 2], polyy[i + 3]);
	for (i = 0; i < k; i++)
		poly[i] = round(arr[i]);
	if (k)
		fillpoly(k / 2, poly);
	setcolor(YELLOW);
	rectangle(xmin, ymax, xmax, ymin);
	cout << "\nClipped Polygon........";
	getch();
	closegraph();
}

// Question 05: Write a program to fill a polygon using Scan line fill algorithm.
//    Program:

// Scan line fill Algorithm for Polygon Filling

#include <iostream>
#include <graphics.h>

using namespace std;
int main()
{
	int gd = DETECT, gm, n, i, j, k, dy, dx;
	int x, y, temp;
	int p[20][2], xi[20];
	float slope[20];
	cout << "\n\n\t-------------------------------------SCAN LINE FILLING POLYGON-------------------------------\n\n\n";
	cout << "\n\nEnter the number of vertices or edges for polygon -> ";
	cin >> n;
	cout << "\n\nEnter the coordinates of polygon \n\n";
	for (i = 0; i < n; i++)
	{
		cout << "\t\t\t\t\t\t\t------------>  ";
		cout << "(X" << i << ",Y" << i << ") -> ";
		cin >> p[i][0] >> p[i][1];
	}
	p[i][0] = p[0][0];
	p[i][1] = p[0][1];
	initgraph(&gd, &gm, (char *)"");
	for (i = 0; i < n; i++)
	{
		line(p[i][0], p[i][1], p[i + 1][0], p[i + 1][1]);
	}
	getch();
	for (i = 0; i < n; i++)
	{
		dy = p[i + 1][1] - p[i][1]; // dy=y2-y1
		dx = p[i + 1][0] - p[i][0]; // dx=x2-x1
		if (dy == 0)
			slope[i] = 1.0;
		if (dx == 0)
			slope[i] = 0.0;
		if ((dy != 0) && (dx != 0))
		{
			slope[i] = (float)dx / dy;
		}
	}
	for (y = 0; y < 480; y++)
	{
		k = 0;
		for (i = 0; i < n; i++)
		{
			if (((p[i][1] <= y) && (p[i + 1][1] > y)) || ((p[i][1] > y) && (p[i + 1][1] <= y)))
			{
				xi[k] = (int)(p[i][0] + slope[i] * (y - p[i][1]));
				k++;
			}
		}
		for (j = 0; j < k - 1; j++)
			for (i = 0; i < k - 1; i++)
			{
				if (xi[i] > xi[i + 1])
				{
					temp = xi[i];
					xi[i] = xi[i + 1];
					xi[i + 1] = temp;
				}
			}
		setcolor(2);
		for (i = 0; i < k; i += 2)
		{
			line(xi[i], y, xi[i + 1], y);
			delay(20);
			getch();
		}
	}
	closegraph();
}

// Question 06: Write a program to apply various 2D transformations on a 2D object (use homogenous coordinates).

// Program:

#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void translation()
{
	cout << "\n\n\n\t\t\t---------->Performing TRANSLATION OF FIGURE...............\n ";
	int gd = DETECT, gm;
	int x1, y1, x2, y2, x3, y3, dx, dy;
	initgraph(&gd, &gm, (char *)"");
	cout << "\n\n\t\t\tEnter coordinates of A -> ";
	cin >> x1 >> y1;
	cout << "\n\n\t\t\tEnter coordinates of B -> ";
	cin >> x2 >> y2;
	cout << "\n\n\t\t\tEnter coordinates of C -> ";
	cin >> x3 >> y3;
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
	cout << "\n\n\t\t\tEnter translating factor for x -> ";
	cin >> dx;
	cout << "\n\n\t\t\tEnter translating factor for y -> ";
	cin >> dy;
	line(x1 + dx, y1 + dy, x2 + dx, y2 + dy);
	line(x2 + dx, y2 + dy, x3 + dx, y3 + dy);
	line(x3 + dx, y3 + dy, x1 + dx, y1 + dy);
	getch();
	closegraph();
}

void rotation()
{
	cout << "\n\n\n\t\t\t---------->Performing ROTATION OF FIGURE...............\n ";
	int gd = DETECT, gm;
	int x1, y1, x2, y2, x3, y3;
	double s, c, A; // s->Sine c->Cos A->Angle of Rotation
	initgraph(&gd, &gm, (char *)"");
	cout << "\n\n\t\t\tEnter coordinates of A -> ";
	cin >> x1 >> y1;
	cout << "\n\n\t\t\tEnter coordinates of B -> ";
	cin >> x2 >> y2;
	cout << "\n\n\t\t\tEnter coordinates of C -> ";
	cin >> x3 >> y3;
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
	cout << "\n\nEnter the angle through which you want to Rotate -> ";
	cin >> A;
	c = cos(A * 3.14 / 180);
	s = sin(A * 3.14 / 180);
	x1 = floor(x1 * c + y1 * s);
	y1 = floor(-x1 * s + y1 * c);
	x2 = floor(x2 * c + y2 * s);
	y2 = floor(-x2 * s + y2 * c);
	x3 = floor(x3 * c + y3 * s);
	y3 = floor(-x3 * s + y3 * c);
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
	getch();
	closegraph();
}

void scaling()
{
	cout << "\n\n\n\t\t\t---------->Performing SCALING OF FIGURE...............\n ";
	int gd = DETECT, gm;
	int x1, y1, x2, y2, x3, y3, dx, dy; // dx and dy scaling factor in x and y direction respectively.
	initgraph(&gd, &gm, (char *)"");
	cout << "\n\n\t\t\tEnter coordinates of A -> ";
	cin >> x1 >> y1;
	cout << "\n\n\t\t\tEnter coordinates of B -> ";
	cin >> x2 >> y2;
	cout << "\n\n\t\t\tEnter coordinates of C -> ";
	cin >> x3 >> y3;
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
	cout << "\n\n\t\t\tEnter scaling factor for x -> ";
	cin >> dx;
	cout << "\n\n\t\t\tEnter scaling factor for y -> ";
	cin >> dy;
	line(x1 * dx, y1 * dy, x2 * dx, y2 * dy);
	line(x2 * dx, y2 * dy, x3 * dx, y3 * dy);
	line(x3 * dx, y3 * dy, x1 * dx, y1 * dy);
	getch();
	closegraph();
}
int main()
{
	cout << "\n\n\t-------------------------------------2-D TRANFORMATIONS -------------------------------\n\n\n";
	char ch = 'y';
	int n;
	while (ch == 'y' || ch == 'Y')
	{
		cout << "\n\n\t\t1.)TRANSLATION."
			 << "\n\n\t\t2.)ROTATION."
			 << "\n\n\t\t2.)SCALING.";
		cout << "\n\n\t------------->Enter your choice -> ";
		cin >> n;
		if (n == 1)
		{
			translation();
		}
		else if (n == 2)
		{
			rotation();
		}
		else if (n == 3)
		{
			scaling();
		}
		else
		{
			cout << "\n\nWrong choice entered by User!.......";
		}
		cout << "\n\nEnter Y/y for continue the 2-D TRANFORMATIONS.......... -> ";
		cin >> ch;
	}
	return 0;
}

// Question 07: Write a program to apply various 3D transformations on a 3D object and then apply parallel and perspective projection on it.
// Program:

#include <iostream>
#include <direct.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>
#include <process.h>
using namespace std;

int gd = DETECT, gm;
double x1, x2, y2;

void draw_cube(double edge[20][3])
{
	double y1;
	initgraph(&gd, &gm, NULL);
	int i;
	clearviewport();
	for (i = 0; i < 19; i++)
	{
		x1 = edge[i][0] + edge[i][2] * (cos(2.3562));
		y1 = edge[i][1] - edge[i][2] * (sin(2.3562));
		x2 = edge[i + 1][0] + edge[i + 1][2] * (cos(2.3562));
		y2 = edge[i + 1][1] - edge[i + 1][2] * (sin(2.3562));
		line(x1 + 320, 240 - y1, x2 + 320, 240 - y2);
	}
	line(320, 240, 320, 25);
	line(320, 240, 550, 240);
	line(320, 240, 150, 410);
	getch();
	closegraph();
}

void scale(double edge[20][3])
{
	double a, b, c;
	int i;
	cout << "Enter The Scaling Factors: ";
	cin >> a >> b >> c;
	initgraph(&gd, &gm, NULL);
	clearviewport();
	for (i = 0; i < 20; i++)
	{
		edge[i][0] = edge[i][0] * a;
		edge[i][1] = edge[i][1] * b;
		edge[i][2] = edge[i][2] * c;
	}
	draw_cube(edge);
	closegraph();
}

void translate(double edge[20][3])
{
	int a, b, c;
	int i;
	cout << "Enter The Translation Factors: ";
	cin >> a >> b >> c;
	initgraph(&gd, &gm, NULL);
	clearviewport();
	for (i = 0; i < 20; i++)
	{
		edge[i][0] += a;
		edge[i][0] += b;
		edge[i][0] += c;
	}
	draw_cube(edge);
	closegraph();
}

void rotate(double edge[20][3])
{
	int ch;
	int i;
	double temp, theta, temp1;
	cout << "-=[ Rotation About ]=-" << endl;
	cout << "1:==> X-Axis " << endl;
	cout << "2:==> Y-Axis" << endl;
	cout << "3:==> Z-Axis " << endl;
	cout << "Enter Your Choice: ";
	cin >> ch;
	switch (ch)
	{
	case 1:
		cout << "Enter The Angle: ";
		cin >> theta;
		theta = (theta * 3.14) / 180;
		for (i = 0; i < 20; i++)
		{
			edge[i][0] = edge[i][0];
			temp = edge[i][1];
			temp1 = edge[i][2];
			edge[i][1] = temp * cos(theta) - temp1 * sin(theta);
			edge[i][2] = temp * sin(theta) + temp1 * cos(theta);
		}
		draw_cube(edge);
		break;

	case 2:
		cout << "Enter The Angle: ";
		cin >> theta;
		theta = (theta * 3.14) / 180;
		for (i = 0; i < 20; i++)
		{
			edge[i][1] = edge[i][1];
			temp = edge[i][0];
			temp1 = edge[i][2];
			edge[i][0] = temp * cos(theta) + temp1 * sin(theta);
			edge[i][2] = -temp * sin(theta) + temp1 * cos(theta);
		}
		draw_cube(edge);
		break;

	case 3:
		cout << "Enter The Angle: ";
		cin >> theta;
		theta = (theta * 3.14) / 180;
		for (i = 0; i < 20; i++)
		{
			edge[i][2] = edge[i][2];
			temp = edge[i][0];
			temp1 = edge[i][1];
			edge[i][0] = temp * cos(theta) - temp1 * sin(theta);
			edge[i][1] = temp * sin(theta) + temp1 * cos(theta);
		}
		draw_cube(edge);
		break;
	}
}

void reflect(double edge[20][3])
{
	int ch;
	int i;
	cout << "-=[ Reflection About ]=-" << endl;
	cout << "1:==> X-Axis" << endl;
	cout << "2:==> Y-Axis " << endl;
	cout << "3:==> Z-Axis " << endl;
	cout << "Enter Your Choice: ";
	cin >> ch;
	switch (ch)
	{
	case 1:
		for (i = 0; i < 20; i++)
		{
			edge[i][0] = edge[i][0];
			edge[i][1] = -edge[i][1];
			edge[i][2] = -edge[i][2];
		}
		draw_cube(edge);
		break;

	case 2:
		for (i = 0; i < 20; i++)
		{
			edge[i][1] = edge[i][1];
			edge[i][0] = -edge[i][0];
			edge[i][2] = -edge[i][2];
		}
		draw_cube(edge);
		break;

	case 3:
		for (i = 0; i < 20; i++)
		{
			edge[i][2] = edge[i][2];
			edge[i][0] = -edge[i][0];
			edge[i][1] = -edge[i][1];
		}
		draw_cube(edge);
		break;
	}
}

void perspect(double edge[20][3])
{
	int ch;
	int i;
	double p, q, r;
	cout << "-=[ Perspective Projection About ]=-" << endl;
	cout << "1:==> X-Axis " << endl;
	cout << "2:==> Y-Axis " << endl;
	cout << "3:==> Z-Axis" << endl;
	cout << "Enter Your Choice := ";
	cin >> ch;
	switch (ch)
	{
	case 1:
		cout << " Enter P := ";
		cin >> p;
		for (i = 0; i < 20; i++)
		{
			edge[i][0] = edge[i][0] / (p * edge[i][0] + 1);
			edge[i][1] = edge[i][1] / (p * edge[i][0] + 1);
			edge[i][2] = edge[i][2] / (p * edge[i][0] + 1);
		}
		draw_cube(edge);
		break;

	case 2:
		cout << " Enter Q := ";
		cin >> q;
		for (i = 0; i < 20; i++)
		{
			edge[i][1] = edge[i][1] / (edge[i][1] * q + 1);
			edge[i][0] = edge[i][0] / (edge[i][1] * q + 1);
			edge[i][2] = edge[i][2] / (edge[i][1] * q + 1);
		}
		draw_cube(edge);
		break;

	case 3:
		cout << " Enter R := ";
		cin >> r;
		for (i = 0; i < 20; i++)
		{
			edge[i][2] = edge[i][2] / (edge[i][2] * r + 1);
			edge[i][0] = edge[i][0] / (edge[i][2] * r + 1);
			edge[i][1] = edge[i][1] / (edge[i][2] * r + 1);
		}
		draw_cube(edge);
		break;
	}
	closegraph();
}

int main()
{
	int choice;
	double edge[20][3] = {
		100, 0, 0,
		100, 100, 0,
		0, 100, 0,
		0, 100, 100,
		0, 0, 100,
		0, 0, 0,
		100, 0, 0,
		100, 0, 100,
		100, 75, 100,
		75, 100, 100,
		100, 100, 75,
		100, 100, 0,
		100, 100, 75,
		100, 75, 100,
		75, 100, 100,
		0, 100, 100,
		0, 100, 0,
		0, 0, 0,
		0, 0, 100,
		100, 0, 100};
	while (1)
	{
		cout << "1:==> Draw Cube " << endl;
		cout << "2:==> Scaling " << endl;
		cout << "3:==> Rotation " << endl;
		cout << "4:==> Reflection " << endl;
		cout << "5:==> Translation " << endl;
		cout << "6:==> Perspective Projection " << endl;
		cout << "7:==> Exit " << endl;
		cout << "Enter Your Choice := ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			draw_cube(edge);
			break;

		case 2:
			scale(edge);
			break;

		case 3:
			rotate(edge);
			break;

		case 4:
			reflect(edge);
			break;

		case 5:
			translate(edge);
			break;

		case 6:
			perspect(edge);
			break;

		case 7:
			exit(0);

		default:
			cout << "\nPress A Valid Key...!!! ";
			getch();
			break;
		}
		closegraph();
	}
	return 0;
}

// Question 08: Write a program to draw Hermite/Bezier curve.
// Program: 100 200 300 400 400 300 200 100

#include <iostream>
#include <math.h>
#include <graphics.h>

using namespace std;
const int size = 4;

void bezier(int x[], int y[])
{
	int gr = DETECT, gm;
	initgraph(&gr, &gm, (char *)"");
	double put_x, put_y;
	cout << "\nCURVE IS BEING DRAWN...";

	for (int i = 0; i < size; i++)
	{
		putpixel(x[i], y[i], 3);
		delay(1);
	}

	for (double t = 0; t <= 1; t += 0.001)
	{
		put_x = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];

		put_y = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];

		putpixel(put_x, put_y, WHITE);
		delay(1);
	}

	cout << "\n\nCURVE IS DRAWN!";
}

void hermite(int x[], int y[])
{
	int gr = DETECT, gm;
	initgraph(&gr, &gm, (char *)(""));
	double put_x, put_y;
	cout << "\nCURVE IS BEING DRAWN...";

	for (int i = 0; i < size; i++)
	{
		putpixel(x[i], y[i], 3);
		delay(1);
	}

	for (double t = 0; t <= 1; t += 0.001)
	{
		put_x = (2 * pow(t, 3) - 3 * pow(t, 2) + 1) * x[0] + (-2 * pow(t, 3) + 3 * pow(t, 2)) * x[1] + (pow(t, 3) - 2 * pow(t, 2) + t) * x[2] + (pow(t, 3) - pow(t, 2)) * x[3];

		put_y = (2 * pow(t, 3) - 3 * pow(t, 2) + 1) * y[0] + (-2 * pow(t, 3) + 3 * pow(t, 2)) * y[1] + (pow(t, 3) - 2 * pow(t, 2) + t) * y[2] + (pow(t, 3) - pow(t, 2)) * y[3];

		putpixel(put_x, put_y, WHITE);
		delay(1);
	}

	cout << "\n\nCURVE IS DRAWN!";
}

int main()
{
	int x[4], y[4];
	int choice;

	do
	{
		cout << "\nChosse the curve you want to draw:-";
		cout << "\n1. Bezier Curve";
		cout << "\n2. Hermite Curve";
		cout << "\nEnter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "\nEnter the control points:-\n";
			for (int i = 0; i < size; i++)
			{
				cout << "x" << i << ": ";
				cin >> x[i];
				cout << "y" << i << ": ";
				cin >> y[i];
			}
			bezier(x, y);
		}
		break;
		case 2:
		{
			cout << "\nEnter the control points:-\n";
			for (int i = 0; i < size; i++)
			{
				cout << "x" << i << ": ";
				cin >> x[i];
				cout << "y" << i << ": ";
				cin >> y[i];
			}
			hermite(x, y);
		}
		break;
		default:
			cout << "Please enter a valid input!";
		}
		cout << "\nDo you want to continue? ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');

	getch();
	closegraph();

	return 1;
}
