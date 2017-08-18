#include <stdio.h>

//#if 0
//int reverse(int num)
//{
//	int rnum = 0;
//	while (num > 0)
//	{
//		rnum *= 10;
//		rnum += num % 10;
//		num /= 10;
//	}
//	return rnum;
//}
//#endif
//#if 0
//int main(void)
//{
//	int a = 1234567890;
//	printf("%d %d\n", a, reverse(a));
//}
//#endif
//
//int reverse(int num)
//{
//	int r = 0;
//
//	while (r > 0)
//	{
//		r *= 10;
//		r += num % 10;
//		num /= 10;
//	}
//
//	return r;
//}
//
//double sqrt(const double a)
//{
//	double n = a / 2.0;
//	double x = 0.0;
//	while (n != x)
//	{
//		x = n;
//		n = (n + a / n) / 2.0;
//	}
//	return n;
//}
//
//int gcd(a, b){
//	if (b == 0) return a;
//	return gcd(b, a%b);
//}
//
//int lcm(a, b){
//	return a * b / gcd(a,b);
//}
//
//
//int reverse(int num)
//{
//	int r = 0;
//	while (r > 0)
//	{
//		r *= 10;
//		r += num % 10;
//		num /= 10;
//	}
//	return r;
//}
//
//int gcd(int a, int b)
//{
//	if (b == 0)return a;
//	return gcd(b, a%b);
//}
//
//int lcm(int a, int b)
//{
//	return a * b / gcd(a, b);
//}
//
//double sqrt(const double a)
//{
//	double sol = a / 2.0;
//	double x = 0.0;
//	while (x != sol)
//	{
//		x = sol;
//		sol = (sol + a / sol) / 2.0;
//	}
//	return sol;
//}

