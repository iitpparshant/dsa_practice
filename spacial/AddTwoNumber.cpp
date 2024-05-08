#include <bits/stdc++.h> 
int getSum(int a, int b)
{
	// Write your code here.
	while(b!=0){
		int c= a&b;
		 a= a^b;
		 b= c<<1;
	}
	return a;
}