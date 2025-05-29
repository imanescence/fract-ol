/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:51:07 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/05/29 11:10:10 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/fractol.h"

void	data_init(t_data *data, char **argv)
{
	data->zoom.zoom_factor = 1.0;
	data->zoom.max_x = 2;
	data->zoom.max_y = 2;
	data->zoom.min_x = -2;
	data->zoom.min_y = -2;
	data->img.max_iter = 30;
	data->fractal = argv[1];
}

int	main(int argc, char **argv)
{
	t_data		data;

	data.mlx = mlx_init();
	data_init(&data, argv);
	if (args_handler(argc, argv) == MANDELBROT)
		data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Mandelbrot");
	if (args_handler(argc, argv) == JULIA)
	{
		data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Julia");
		data.c.real = ft_atof(argv[2]);
		data.c.imag = ft_atof(argv[3]);
	}
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, X_PRESSED, 0, close_window, &data);
	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = (int *)mlx_get_data_addr(data.img.img,
			&data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	if (args_handler(argc, argv) == MANDELBROT)
		draw_mandel(&data, data.img, data.color);
	if (args_handler(argc, argv) == JULIA)
		draw_julia(&data, data.img, data.color);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
