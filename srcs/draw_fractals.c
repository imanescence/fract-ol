/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:01:25 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/05/29 11:09:53 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/fractol.h"

void	color_handler(t_color *color)
{
	color->red = 25 * color->color_mix / 540;
	color->green = 155 * color->color_mix / 14;
	color->blue = 175 * color->color_mix / 145;
	color->tran = 140 * color->color_mix / 1;
}

// line lenght int = 4octetc RGB + transparence line lenght
// its the number of bytes so i need to / 4 to create the number of pixels

void	ft_mlx_pixel_put(t_data_img *data_img, int x, int y, int color)
{
	int	dst;

	dst = y * (data_img->line_length / 4) + x;
	data_img->addr[dst] = color;
}

void	draw_mandel(t_data *data, t_data_img img, t_color color)
{
	int			x;
	int			y;
	t_complex	c;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c.real = ((x) * (data->zoom.max_x - data->zoom.min_x) / WIDTH)
				+ data->zoom.min_x; 
			c.imag = ((y) * (data->zoom.max_y - data->zoom.min_y) / HEIGHT) 
				+ data->zoom.min_y;
			color.color_mix = mandelbrot(c, data);
			color_handler(&color);
			if (color.color_mix < data->img.max_iter)
				ft_mlx_pixel_put(&img, x, y, ((color.tran) | (color.red << 25)
						| (color.green << 20) | color.blue << 3));
			else
				ft_mlx_pixel_put(&img, x, y, 0);
			y++;
		}
		x++;
	}
}

void	draw_julia(t_data *data, t_data_img img, t_color color)
{
	int			x;
	int			y;
	t_complex	c;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c.real = ((x) * (data->zoom.max_x - data->zoom.min_x) / WIDTH)
				+ data->zoom.min_x;
			c.imag = ((y) * (data->zoom.max_y - data->zoom.min_y) / HEIGHT)
				+ data->zoom.min_y;
			color.color_mix = julia(c, data);
			color_handler(&color);
			if (color.color_mix < data->img.max_iter)
				ft_mlx_pixel_put(&img, x, y, ((color.tran) | (color.red << 25)
						| (color.green << 20) | color.blue << 3));
			else
				ft_mlx_pixel_put(&img, x, y, 0);
			y++;
		}
		x++;
	}
}
