#include <cstdlib>
#include <iostream>
#include <cerrno>
#include <cmath>

int main() {
	char szOrbits[] = "         +234234";
	// char* pEnd;
	double f1, f2;

	errno = 0;
	strtof(szOrbits, NULL);
	f1 = atof(szOrbits);
	// std::cout << "pEnd " << pEnd << " \n";
	f2 = atof(szOrbits);
	std::cout << "The orbital period of Mars is " << f1 << " days.\n";
	std::cout << "The orbital period of Earth is " << f2 << " days.\n";
	return 0;
}