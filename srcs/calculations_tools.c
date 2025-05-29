/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <iait-ouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:51:56 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/05/29 11:08:26 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/fractol.h"

// ---------- What is a complex number ? ----------------
// A complex number is composed by real numbers and an imaginary number
// The operation to get a complex number is :
// z = a + bi
// |z| is the complex number, |a| and |b| are the real numbers, and |i|
// is the imaginary number which represents i^2 = -1 so i*i = -1
// The complex number is somewhere between imaginary and real
//
// ----------- Mandelbrot Fractal -----------------------
// Mandelbrot fractal is composed like this :
// zn = zn * zn + c
// |z| and |c| are both complex numbers
//
// ---------- Magnitude ---------------------------------
//
// how calculate a complex number magnitude ?
// make the square of a and b which are the reals
// sum it and calculate the square root
// square root of (a * a) + (b * b)
//
// double magnitude = sqrt(a * a + b * b);

t_complex	add(t_complex a, t_complex b)
{
	t_complex	c;

	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return (c);
}

t_complex	square(t_complex a)
{
	t_complex	c;

	c.real = a.real * a.real - a.imag * a.imag;
	c.imag = 2 * a.real * a.imag;
	return (c);
}

double	magnitude(t_complex a)
{
	return (a.real * a.real + a.imag * a.imag);
}

int	mandelbrot(t_complex c, t_data *data)
{
	int			n;
	t_complex	z;

	z.real = 0;
	z.imag = 0;
	n = 0;
	while (n < data->img.max_iter)
	{
		if (magnitude(z) > 4.0)
			return (n);
		z = add(square(z), c);
		n++;
	}
	return (data->img.max_iter);
}

int	julia(t_complex z, t_data *data)
{
	int	n;

	n = 0;
	while (n < data->img.max_iter)
	{
		if (magnitude(z) > 4)
			return (n);
		z = add(square(z), data->c);
		n++;
	}
	return (data->img.max_iter);
}
