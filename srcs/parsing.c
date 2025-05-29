/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:29:13 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/05/29 11:10:30 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/fractol.h"

char	args_handler(int argc, char **argv)
{
	if (argc == 1)
		ft_errors(MISSING_NAME);
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 10
			&& name_cmp(argv[1], "Mandelbrot") == CORRECT_NAME)
			return (MANDELBROT);
		if (ft_strlen(argv[1]) == 5
			&& name_cmp(argv[1], "Julia") == CORRECT_NAME)
			ft_errors(MISSING_VALUES);
		else
			ft_errors(INCORRECT_NAME);
	}
	if (ft_strlen(argv[1]) == 5 && argc == 4
		&& name_cmp(argv[1], "Julia") == CORRECT_NAME)
		return (JULIA);
	else if (ft_strlen(argv[1]) == 10 && argc >= 3
		&& name_cmp(argv[1], "Mandelbrot") == CORRECT_NAME)
		ft_errors(TOO_MUCH_ARGS_M);
	else if (ft_strlen(argv[1]) == 5 && (argc == 3 || argc >= 5)
		&& name_cmp(argv[1], "Julia") == CORRECT_NAME)
		ft_errors(WRONG_NB_ARGS_J);
	return ('a');
}

char	name_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			ft_errors(INCORRECT_NAME);
		i++;
	}
	if (s1[i] == '\0' )
		return (CORRECT_NAME);
	return (INCORRECT_NAME);
}

void	ft_errors(char flag)
{
	if (flag == MISSING_NAME)
		ft_putstr_fd("Please enter a name of fractal\n\n", 2);
	if (flag == INCORRECT_NAME)
		ft_putstr_fd("Please enter a valid name of fractal\n\n", 2);
	if (flag == TOO_MUCH_ARGS_M)
		ft_putstr_fd("Mandelbrot no needs values or whatever else\n\n", 2);
	if (flag == WRONG_NB_ARGS_J)
		ft_putstr_fd("Julia needs exactly 2 values, no more or less\n\n", 2);
	if (flag == MISSING_VALUES)
		ft_putstr_fd
			("Please enter 2 values of your choice between 2 and -2\n\n",
			2);
	if (flag == WRONG_VALUES)
		ft_putstr_fd("I said between 2 and -2 ! \n\n", 2);
	if (flag == INVALID_ARG)
		ft_putstr_fd
			("Values are only digits, please read the following lines\n\n", 2);
	ft_putstr_fd("Here are the choice of 2 fractals :\n\n", 2);
	ft_putstr_fd("-------- Mandelbrot --------\n\n", 2);
	ft_putstr_fd("---------- Julia -----------\n", 2);
	ft_putstr_fd("For Julia, add 2 values of your choice between 2 and -2,", 2);
	ft_putstr_fd(" here is an example : Julia 0,285 0,01\n", 2);
	exit (EXIT_FAILURE);
}

void	float_creation(double *nb, int i, char *str)
{
	double	base;
	double	rslt;

	base = 10;
	while (ft_isdigit(str[i]))
	{
		rslt = (str[i] - '0') / base;
		*nb += rslt;
		base *= 10;
		i++;
		if (ft_isdigit(str[i]) == 0 && str[i] != '\0')
			ft_errors(INVALID_ARG);
	}
}

double	ft_atof(char *str)
{
	int		i;
	double	nb;
	int		ng;

	i = 0;
	nb = 0;
	ng = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			ng *= -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		ft_errors(INVALID_ARG);
	while (ft_isdigit(str[i]) == 1)
		nb = nb * 10 + (str[i++] - '0');
	if (str[i] == ',' || str[i] == '.')
	{
		i++;
		float_creation(&nb, i, str);
	}
	if (nb > 2 || nb < -2)
		ft_errors(WRONG_VALUES);
	return (nb * ng);
}
