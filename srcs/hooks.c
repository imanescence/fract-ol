/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:42:35 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/05/29 11:10:02 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/fractol.h"

void	zoom_in(double x, double y, t_data *data)
{
	double	zoom_x;
	double	zoom_y;

	zoom_x = (data->zoom.max_x - data->zoom.min_x)
		* (1 - data->zoom.zoom_factor);
	zoom_y = (data->zoom.max_y - data->zoom.min_y)
		* (1 - data->zoom.zoom_factor);
	data->zoom.max_x -= zoom_x * (1 - x / WIDTH); 
	data->zoom.min_x += zoom_x * (x / WIDTH);
	data->zoom.max_y -= zoom_y * (1 - y / HEIGHT);
	data->zoom.min_y += zoom_y * (y / HEIGHT);
}

void	zoom_out(double x, double y, t_data *data)
{
	double	zoom_x;
	double	zoom_y;

	zoom_x = (data->zoom.max_x - data->zoom.min_x)
		* (data->zoom.zoom_factor - 1);
	zoom_y = (data->zoom.max_y - data->zoom.min_y)
		* (data->zoom.zoom_factor - 1);
	data->zoom.max_x += zoom_x * (1 - x / WIDTH); 
	data->zoom.min_x -= zoom_x * (x / WIDTH);
	data->zoom.max_y += zoom_y * (1 - y / HEIGHT);
	data->zoom.min_y -= zoom_y * (y / HEIGHT);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode == SCROLL_UP)
	{
		data->zoom.zoom_factor *= 0.9;
		zoom_in(x, y, data);
		data->zoom.zoom_factor = 1;
	}
	else if (keycode == SCROLL_DOWN)
	{
		data->zoom.zoom_factor *= 1.1;
		zoom_out(x, y, data);
		data->zoom.zoom_factor = 1;
	}
	if (keycode == ESC_PRESSED)
		close_window (data);
	if (ft_strlen(data->fractal) == 10)
		draw_mandel(data, data->img, data->color);
	if (ft_strlen(data->fractal) == 5)
		draw_julia(data, data->img, data->color);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_PRESSED)
		close_window (data);
	else if (keycode == 69)
		data->img.max_iter += 10;
	else if (keycode == 88)
		data->img.max_iter -= 10;
	if (ft_strlen(data->fractal) == 10)
		draw_mandel(data, data->img, data->color);
	if (ft_strlen(data->fractal) == 5)
		draw_julia(data, data->img, data->color);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
