# ComputorV1
The goal of this project is to get acquainted with handling elementary math tools that may be helpful.

## Introduction

The purpose of this project is to make you code a program that solves simple equations.
The program takes a polynomial equation. That is to say, involving only powers, no
complicated functions. The program should display its solution(s).

Why polynomials? Because it is one of the simplest and most powerful mathematical
tools. It is used in all domains and at all levels to simplify and express many things. For
example, the functions sin, cos, and tan are computed using polynomials.

In fact, there is even one result: the theorem of Stone-Weierstrass,
who says that all “current” functions, (those which are very smooth
and pretty), can be expressed at using polynomials.

## Description

Program that solves a polynomial equation of degree less than or equal to 2. Program display:
* The reduced form of the equation.
* The degree of the equation.
* Its solution(s)
* Display the solution(s) under the form of irrational fractions when it is interesting..
* Display intermediate steps

## Usage

1. Clone project
2. cd computorV1
3.  ```console
	$> make
	$> ./computorV1
	Usage: ./computorV1 [-l] "5 * x^2 - 3 * x + 5 = 0"
	```

## Examples

```console
$> ./computorV1 "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
Reduced form: 4 * X^0 + 4 * X^1 - 9.3 * X^2 = 0
Polynomial degree: 2
Discriminant is strictly positive, the two solutions are:
0.905239
-0.475131

$> ./computorV1 "5 * X^0 + 4 * X^1 = 4 * X^0"
Reduced form: 1 * X^0 + 4 * X^1 = 0
Polynomial degree: 1
The solution is:
-0.25

$> ./computorV1 "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0"
Reduced form: 5 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 0
Polynomial degree: 3
The polynomial degree must not be greater than 2 and not less than 0, I can't solve.

$> ./computorV1 "5 + 4 * X + X^2= X^2"
Reduced form: 5 + 4 * X = 0
Polynomial degree: 1
The solution is:
-1.25
```
