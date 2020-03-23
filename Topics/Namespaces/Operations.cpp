#include <stdio.h>

namespace szorzas {
	double a(double aa)
	{
		return 2 * aa;
	}
}

namespace osztas {
	double a(double aa)
	{
		return aa / 2;
	}
}

namespace osszeadas
{
	double a(double aa)
	{
		return aa + 1;
	}
}

double a(double aa)
{
	return osszeadas::a(szorzas::a(szorzas::a(szorzas::a(osztas::a(aa)))));
}

int main()
{
	// Eredmeny: 9
	printf("%.1lf\n", a(2));
	return 0;
}