#include "computorV1.h"

static double	GetCoeff(const string& str, size_t& i) {
	int8_t	sign = 1;
	double	result = 1;

	i = str.find_first_not_of(' ', i);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
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

static void	RemoveZeroCoeff(map<int, double>& deg_to_coeff) {
	for (const auto& v : deg_to_coeff)
		if (v.second == 0)
			deg_to_coeff.erase(v.first);
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
	RemoveZeroCoeff(deg_to_coeff);
}

ComputorV1::ComputorV1(const string& polynom) {
	ParsePolynom(polynom, degree_to_coeff);
}

int	ComputorV1::GetPolynomialDegree() const {
	int res = 0;

	if (!degree_to_coeff.empty())
		res = prev(degree_to_coeff.end())->first;
	return res;
}

const map<int, double>&	ComputorV1::GetReducedForm() const {
	return degree_to_coeff;
}

vector<complex<double>>	QuadraticEquation(const double a,
								const double b, const double c) {
	vector<complex<double>>	result;

	if (!a) {
		if (b)
			result.push_back(complex<double>(-c / b, 0));
		else if (c)
			throw out_of_range("No solution");
	}
	else {
		double dis = b * b - 4 * a * c;
		if (!dis)
			result.push_back(complex<double>(-b / 2 * a, 0));
		else {
			complex<double>	dsqrt = sqrt(complex<double>(dis, 0));
			result.push_back((-b + dsqrt) / (2 * a));
			result.push_back((-b - dsqrt) / (2 * a));
		}
	}
	return result;
}

vector<complex<double>>	ComputorV1::GetSolutions() const {
	double a = 0;
	double b = 0;
	double c = 0;
	auto ita = degree_to_coeff.find(2);
	if (ita != degree_to_coeff.end())
		a = ita->second;
	auto itb = degree_to_coeff.find(1);
	if (itb != degree_to_coeff.end())
		b = itb->second;
	auto itc = degree_to_coeff.find(0);
	if (itc != degree_to_coeff.end())
		c = itc->second;
	return (QuadraticEquation(a, b, c));
}
