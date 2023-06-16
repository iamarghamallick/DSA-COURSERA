#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long EuclidGCD(long long a, long long b)
{
  if(b == 0) return a;
  else return EuclidGCD(b, a%b);
}

long long LCMfast(long long a, long long b) {
  long long gcd = EuclidGCD(a,b);
  return (a*b)/gcd;
}

int main() {
  // int a, b;
  long long a, b;
  std::cin >> a >> b;
  // std::cout << lcm_naive(a, b) << std::endl;
  std::cout << LCMfast(a, b) << std::endl;
  return 0;
}
