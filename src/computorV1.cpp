#include "computorV1.h"

#include <iostream>

// static size_t	IsValidDelim(const string& delim) {
// 	size_t	i = 0;

// 	if (delim[i] != '*' && delim[i] != 'x') {
// 		if (delim[i] != '+' && delim[i] != '-')
// 			throw invalid_argument("Invalid symbol. It must be +, -, or *. See usage!");
// 		return (i);
// 	}
// 	while (delim[i] == ' ')
// 		++i;
// 	if (i != delim.size()) {
// 		if (delim[i++] != 'x')
// 			throw invalid_argument("Invalid format. See usage!");
// 	}
// 	return (i + 1);
// }

static double	GetCoeff(const string& str, size_t& i) {
	int8_t	sign = 1;
	double	result = 1;

	while (str[i] == ' ')
		++i;
	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	while (str[i] == ' ')
		++i;
	if (isdigit(str[i])) {
		size_t	end;
		result = stod(str.substr(i), &end);
		i += end;
	}
	return (result * sign);
}

static int		GetDegree(const string& str, size_t& i) {
	(void)str;
	(void)i;
	return (0);
}


void	ParsePolynom(const string& polynom,
						map<int, double>& deg_to_coeff) {
	size_t	i = 0;
	int8_t	sign = 1;

	while (i != polynom.size()) {
		while (polynom[i] == ' ')
			++i;
		if (polynom[i] == '=') {
			sign = -1;
			continue ;
		}
		double	coeff = GetCoeff(polynom, i);
		int		degree = GetDegree(polynom, i);
		cout << "coeff = " << coeff << endl;
		cout << "degree = " << degree << endl;
		deg_to_coeff[degree] += (coeff * sign);
		break;
	}
	if (sign != -1)
		throw invalid_argument("Invalid format. No symbol equals. See usage!");
}

ComputorV1::ComputorV1(const string& polynom) {
	ParsePolynom(polynom, degree_to_coeff);
}
