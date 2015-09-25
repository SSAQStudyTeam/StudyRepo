#include <stdio.h>

int check_input(int* first_num, int* sec_num);
int div_rest(int m, int n, int rest);
int lcm_rest(int* first_num, int* sec_num, int *gcd);

int main()
{
	int a, b, init_rest;
	int res;
	printf("gcd test input 2EA numbner \n");
	//scanf_s("%d", &a);
	printf("1st number is ");
	scanf_s("%d", &a, sizeof(a));
	
	printf("\n2nd number is ");
	scanf_s("%d", &b, sizeof(b));
	printf("\n");

	init_rest = check_input(&a, &b);
			/*
			printf("\ntest init %d \n", init_rest);
			printf("A is %d\n", a);
			printf("B is %d\n", b);
			*/

	if (init_rest == 2)
		res = div_rest(a, b, init_rest);
	else
	{
		res = init_rest;
	}

	printf("%d, %d,GCD is %d\n", a, b, res);
	
	printf("%d, %d,LCM is %d", a, b, lcm_rest(&a, &b, &res));

	scanf_s("%d", &b, sizeof(b));
}

int check_input(int* first_num, int* sec_num)
{
	int temp;
	if (*first_num == *sec_num) return *first_num;	//same number case
	else if ((*first_num) * (*sec_num) == 0) return 0; //zero case
	else if (*first_num < *sec_num)  //first number must be big than sec
	{
		temp = *first_num;
		*first_num = *sec_num;
		*sec_num = temp;
		return 2;
	}
	else return 2;
}

//gcd
int div_rest(int m, int n, int rest)
{
	rest = m % n;
	if (rest == 0) return n;
	else div_rest(n, rest, rest);
}

//lcm
int lcm_rest(int* first_num, int* sec_num, int *gcd)
{
	return *first_num * (*sec_num) / (*gcd);

}