/*
Powering a number
Problem:Compute an, where n ∈N.
Naive algorithm:Θ(n).
an=an/2 ⋅an/2                 if n is even;
  =a(n–1)/2 ⋅a(n–1)/2 ⋅a    if n is odd.
   Divide-and-conquer algorithm:T(n) = T(n/2) + Θ(1) 
									⇒T(n) = Θ(lgn).
*/
#include<iostream>
int Powering_a_number(int a, int n) {
	if (0 == n) {
		return 1;
	}
	if (1 == n) {
		return a;
	}
	if (2 == n) {
		return a*a;
	}
	bool p = (n % 2) ? true : false;
	if (p) {
	return Powering_a_number(Powering_a_number(a, (n - 1) / 2), 2)*a;
	}
	else {
		return Powering_a_number(Powering_a_number(a, n / 2), 2);
	}
}

int main() {
	int an = Powering_a_number(2, 10);
	std::cout << an << std::endl;

	return 0;
}