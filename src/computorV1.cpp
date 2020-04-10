#include "computorV1.h"

#include <iostream>

static double	GetCoeff(const string& str, size_t& i) {
	int8_t	sign = 1;
	double	result = 1;

	i = str.find_first_not_of(' ', i);
	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	i = str.find_first_not_of(' ', i);
	if (isdigit(str[i])) {
		size_t	end;
		result = stod(str.substr(i), &end);
		i += end;
	} else if (str[i] != 'x')
		throw invalid_argument("Invalid polynom. Expected: digit or 'x'. See usage!");
	return (result * sign);
}

static int		GetDegree(const string& str, size_t& i) {
	int	result = 1;
	i = str.find_first_not_of(' ', i);
	if (str[i] != '*' && str[i] != 'x')
		return (0);
	if (str[i] == '*')
		++i;
	i = str.find_first_not_of(' ', i);
	if (str[i] != 'x')
		throw invalid_argument("Invalid polynom. Expected: 'x'. See usage!");
	if (str[++i] == '^') {
		if (isdigit(str[++i])) {
			size_t	end;
			result = stoi(str.substr(i), &end);
			i += end;
		}
		else
			throw invalid_argument("Invalid polynom. Expected digit after '^'. See usage!");

	}
	return result;
}


void	ParsePolynom(const string& polynom,
						map<int, double>& deg_to_coeff) {
	size_t	i = 0;
	int8_t	sign = 1;

	if (polynom.empty())
		throw invalid_argument("Invalid polynom. Empty string. See usage!");
	while (true) {
		double	coeff = GetCoeff(polynom, i);
		int		degree = GetDegree(polynom, i);
		deg_to_coeff[degree] += (coeff * sign);
		i = polynom.find_first_not_of(' ', i);
		if (polynom[i] == '\0')
			break ;
		if (polynom[i] == '=') {
			i = polynom.find_first_not_of(' ', ++i);
			if (i == polynom.size())
				throw invalid_argument("Invalid format. No symbols after equals. See usage!");
			sign = -1;
		}
	}
	if (sign != -1)
		throw invalid_argument("Invalid format. No symbol equals. See usage!");
	for (auto& it : deg_to_coeff)
		if (!it.second)
			deg_to_coeff.erase(it.first);
}

ComputorV1::ComputorV1(const string& polynom) {
	ParsePolynom(polynom, degree_to_coeff);
}

int	ComputorV1::GetPolynomialDegree() const {

	int res = 0;
	if (degree_to_coeff.begin() != degree_to_coeff.end())
		res = prev(degree_to_coeff.end())->first;
	return res;
}

const map<int, double>&	ComputorV1::GetReducedForm() const {
	return degree_to_coeff;
}
