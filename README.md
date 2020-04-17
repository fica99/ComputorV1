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

Polynom must be written in form:

```math
P(x) = \sum\limits_{k = 0}^{n}a_{k}x^{k}
```

Program that solves a polynomial equation of degree less than or equal to 2 and higher or equal to 0. Program display:
* The reduced form of the equation.
* The degree of the equation.
* Its solution(s).
* Display the solution(s) under the form of irrational fractions when it is interesting.
* Display intermediate steps (flag `-l`).

## Usage

1. Clone project
2. cd computorV1
3.  ```console
	$> make
	$> ./computorV1
	Usage: ./computorV1 [-l] "a * x^n + b * x^m + c = d"
	```

## Examples

```console
$> ./computorV1 -l "5x^2+3"
Invalid format. No symbol equals. See usage!

$> ./computorV1 "5x^0 + 4x^1 - 9.3x^2 = 1x^0"
Polynomial degree: 2
Reduced form: -9.3 * x^2 + 4 * x^1 + 4 * x^0 = 0
Solutions are:
-0.475131
0.905239

$> ./computorV1 -l "5 + 4 * x + x^2= x^2"
Polynomial degree: 1
Reduced form: 4 * x^1 + 5 * x^0 = 0
a * x ^ 2 + b * x + c = 0
a = 0
b = 4
c = 5
-c / b = -5 / 4 = -1.25
The solution is: -1.25

$> ./computorV1 -l "4x^2 + 5 =0"
Polynomial degree: 2
Reduced form: 4 * x^2 + 5 * x^0 = 0
a * x ^ 2 + b * x + c = 0
a = 4
b = 0
c = 5
D = b^2 - 4 * a * c = 0*0 - 4 *4*5 = -80
x1 = (-b + sqrt(D)) / (2 * a) = (-0 + (0,8.94427)) / 8 = (0,1.11803)
x2 = (-b - sqrt(D)) / (2 * a) = (-0 - (0,8.94427)) / 8 = (-0,-1.11803)
Solutions are:
0 + i * 1.11803
-0 - i * 1.11803
```
