#include <iostream>
#include <vector>
#include <exception>
#include <complex>
#include <string>
#include "computorV1.h"

#define USAGE "Usage: ./computorV1 \"5 * x^2 + 3 * x + 5 = 0\""

using namespace	std;

static void	PrintReducedForm(const ComputorV1& computor) {
	cout << "Reduced form: ";
	const map<int, double>&	degree_to_coeff = computor.GetReducedForm();
	for (auto it = rbegin(degree_to_coeff); it != rend(degree_to_coeff);
															++it) {
		if (it != rbegin(degree_to_coeff)) {
			if (it->second < 0)
				cout << " - " << -1 * it->second;
			else
				cout << " + " << it->second;
		} else
			cout << it->second;
		cout << " * x^" << it->first;
	}
	if (!degree_to_coeff.size())
		cout << "0";
	cout << " = 0" << endl;
}

static void	PrintSolution(const ComputorV1& computor) {
	vector<complex<double>>	results = computor.GetSolutions();
	if (results.size() == 1)
		cout << "The solution is: " << results[0].real() << endl;
	else if (results.size() == 2) {
		cout << "Solutions are:" << endl;
		for (const auto r : results) {
			if (r.imag()) {
				cout << r.real() << " ";
				if (r.imag() < 0)
					cout << "- i * " << (-1) * r.imag() << endl;
				else
					cout << "+ i * " << r.imag() << endl;
			} else
				cout << r.real() << endl;
		}
	} else if (results.empty())
		cout << "All numbers are solutions" << endl;

}

static void	CalcPolynomResult(string polynom) {
	ComputorV1	computor(polynom);
	int			degree;

	cout << "Polynomial degree: ";
	degree = computor.GetPolynomialDegree();
	cout << degree << endl;
	PrintReducedForm(computor);
	if (degree > 2 || degree < 0)
		throw out_of_range("The polynomial degree must not be greater than 2 and not less than 0, I can't solve.");
	PrintSolution(computor);
}

int	main(int argc, char **argv) {
	if (argc != 2) {
		cout << USAGE << endl;
		return (1);
	}
	try {
		CalcPolynomResult(string(argv[1]));
	} catch (exception& ex) {
		cout << ex.what() << endl;
		return (1);
	}
	return (0);
}
