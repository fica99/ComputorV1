#pragma once
#include <string>
#include <complex>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <utility>

using namespace	std;

class	ComputorV1 {
	public:
		ComputorV1(const string& polynom);
		const map<int, double>& GetReducedForm() const;
		int GetPolynomialDegree() const;
		vector<complex<double>> GetSolutions() const;
		void	StepByStepSolution(ostream& ss) const;
	private:
		map<int, double>		degree_to_coeff;
};

void					ParsePolynom(const string& polynom,
								map<int, double>& deg_to_coeff);
vector<complex<double>>	QuadraticEquation(const double a,
								const double b, const double c);

