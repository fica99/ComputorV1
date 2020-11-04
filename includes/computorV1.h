/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorV1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:45:06 by aashara-          #+#    #+#             */
/*   Updated: 2020/11/04 19:30:38 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <map>
// #include <complex>
// #include <vector>
// #include <iterator>
// #include <algorithm>
// #include <utility>

class ComputorV1 {
	public:
		ComputorV1(const std::string polynom);
		// const std::map<int, double>&	GetReducedForm() const;
		// int														GetPolynomialDegree() const;
		// std::vector<complex<double>>	GetSolutions() const;
		// void													StepByStepSolution(std::ostream& ss) const;
	private:
		std::map<int, double>		degree_to_coeff;
};

// void													ParsePolynom(const std::string& polynom,
// 																			std::map<int, double>& deg_to_coeff);
// std::vector<complex<double>>	QuadraticEquation(const double a,
// 																			const double b, const double c);

