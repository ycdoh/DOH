#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double getrandomnumber(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX;

	temp = min + (max - min)*temp;

	return temp;
}

bool insidecircle(const double x, const double y)
{
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;

	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	
	if (f > 0.0)
	{
		return false;
	}
	else return true;
}
bool insidecircle2(const double x, const double y)
{
	const double x_c = 2.5;
	const double y_c = 0.5;
	const double r = 0.5;

	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;

	if (f > 0.0)
	{
		return false;
	}
	else return true;
}

void main()
{
	FILE *of = fopen("circle.txt", "w");
	srand((unsigned int)time(NULL));
	

	for (int i = 0; i < 10000; i++)
	{
		double x = getrandomnumber(0.0, 1.0);
		double y = getrandomnumber(0.0, 1.0);

		if (insidecircle(x, y) == 1)
		{
			fprintf(of, "%f, %f\n", x, y);
		}
	}
	for (int i = 0; i < 10000; i++)
	{
		double a = getrandomnumber(1.0, 2.0);
		double b = getrandomnumber(0.4, 0.6);
		fprintf(of, "%f, %f\n", a, b);
	}
	for (int i = 0; i < 10000; i++)
	{
		double c = getrandomnumber(2.0, 3.0);
		double d = getrandomnumber(0.0, 1.0);

		if (insidecircle2(c, d) == 1)
		{
			fprintf(of, "%f, %f\n", c, d);
		}
	}

	fclose(of);

}