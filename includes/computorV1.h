#pragma once
#include <string>
#include <complex>
#include <vector>
#include <map>
#include <iterator>

using namespace	std;

class	ComputorV1 {
	public:
		ComputorV1(const string& polynom);
		const map<int, double>& GetReducedForm() const;
		int GetPolynomialDegree() const;
		//vector<complex<double>> GetSolutions() const;
	private:
		map<int, double>	degree_to_coeff;
};

void	ParsePolynom(const string& polynom,
					map<int, double>& deg_to_coeff);

