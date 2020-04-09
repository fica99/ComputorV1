#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include "computorV1.h"

#define USAGE "Usage: ./computorV1 \"5 * x^2 - 3 * x + 5 = 0\""

using namespace	std;

static void	CalcPolynom(const string polynom) {
	ComputorV1	computor(polynom);

	cout << "Reduced form: " <<\
		computor.GetReducedForm() << endl;
	cout << "Polynomial degree: " << \
		computor.GetPolynomialDegree() << endl;
	vector<double>	results = computor.GetSolutions();

	if (results.size() == 1)
		cout << "The solution is:" << endl \
			<< results[0] << endl;
	else {
		cout << "Solutions are:" << endl;
		for (const auto r : results)
			cout << r << endl;
	}
}

int	main(int argc, char **argv) {
	if (argc != 2) {
		cout << USAGE << endl;
		return (1);
	}
	try {
		CalcPolynom({argv[0]});
	} catch (exception& ex) {
		cout << ex.what() << endl;
		return (1);
	}
	return (0);
}
