#include <stdio.h>
#include <stdlib.h>
/*
int GCD(int m, int n)
{
	int r;
	while (1)
	{
		r = m%n;		//E1
		if (!r)			//E2
			return n;
		m = n; n = r;	//E3
	}
}
*/

//I don't know why I did it like this, BUT, notice that r_next = n_current%r_current...intresting!
/*
int GCD_recursive(int m, int n, int r)
{
	static int nested = 1;
	printf("%d\t%d\t%d\t%d\n", nested++, m, n, r);
	if (!r)
		return n;
	//m <- n, n <- r, next iteration: r = m%n = n_current%r_current
	return GCD_recursive(n, r, n%r);
}


int GCD(int m, int n)
{
	return GCD_recursive(m, n, m%n);
}
*/

int GCD(int m, int n)
{
	static int nested = 1, r = 1;
	r = m%n;
	printf("%d\t%d\t%d\t%d\n", nested++, m, n, r);
	if (!r)
		return n;
	return GCD(n, r);
}

/*Smallest Version
int GCD(int m, int n)
{
	if (!(m%n)) //E1 //E2
		return n;
	return GCD(n, (m%n)); //E3
}*/

int main(int argc, char *argv[])
{
	printf("i\tm\tn\tr\n");
	if (argc > 2)
		printf("GCD(m, n) = %d\n", GCD(atoi(argv[1]), atoi(argv[2])));
	else
		printf("Usage: <intger m> <integer n>\n");
	return 0;
}
