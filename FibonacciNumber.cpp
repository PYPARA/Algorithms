/*
Recursive definition:
Fn=0			if n= 0;
  =1			if n= 1;
  =Fn–1+ Fn–2	if n≥2.
  
  Naive recursive algorithm:Ω(φn)
  (exponential time), where φ=is the golden ratio

  Bottom-up:
  •Compute F0, F1, F2, …, Fn  in order, forming each number by summing the two previous.
  •Running time:Θ(n).
*/
#include<iostream>
#include<vector>
size_t FibonacciNumber(size_t n) {
	std::vector<size_t> vec{ 0,1 };
	for (size_t i = 2; i < n; ++i) {
		vec.push_back(vec[i - 2] + vec[i - 1]);
	}
	return vec[n - 1];
}

int main() {
	std::cout << FibonacciNumber(1) << std::endl;
	std::cout << FibonacciNumber(2) << std::endl;
	std::cout << FibonacciNumber(3) << std::endl;
	std::cout << FibonacciNumber(4) << std::endl;
	std::cout << FibonacciNumber(5) << std::endl;
	std::cout << FibonacciNumber(1000) << std::endl;
}