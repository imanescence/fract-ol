/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:23:04 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/05/29 11:16:17 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"

// +++++++++++++++++++++++++++ MACROS ++++++++++++++++++++++++++++++

// ---------- PARSING MACROS -----------
# define INCORRECT_NAME 97
# define MISSING_NAME 98
# define MISSING_VALUES 99
# define MANDELBROT 109
# define JULIA 106
# define CORRECT_NAME 111
# define TOO_MUCH_ARGS_M 116
# define WRONG_NB_ARGS_J 117
# define INVALID_ARG 105
# define WRONG_VALUES 119 

// ----------- HOOKS MACROS -----------
# define ESC_PRESSED 53
# define X_PRESSED 17
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// ----------- WINDOWS DIMENSIONS ------
# define WIDTH 800
# define HEIGHT 800

// +++++++++++++++++++++++++ STRUCTURES +++++++++++++++++++++++++

// ------------ COMPLEX NB CREATION ------------
typedef struct s_complex {
	double	real;
	double	imag;
}	t_complex;

// ------------ IMG INITIATION AND UTILS ------------
typedef struct s_data_img {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		max_iter;
}t_data_img;

// -------------- COLOR CREATION ------------------
typedef struct s_color {
	int	red;
	int	green;
	int	blue;
	int	tran;
	int	color_mix;
}	t_color;

// -------------- ZOOM CREATION ------------------
typedef struct s_zoom {
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
	double	zoom_factor;
}	t_zoom;

// -------- MAIN STRUCT FOR MINILIBX INTIT ---------
// ------- + POINTERS TO OTHER STRUCTS -------------
typedef struct s_data{
	void		*mlx;
	void		*win;
	t_data_img	img;
	t_zoom		zoom;
	t_complex	c;
	t_color		color;
	char		*fractal;
}	t_data;

// +++++++++++++++++++++++++ FUNCTIONS +++++++++++++++++++++++++

// ------------- HOOKS ------------
int			close_window(struct s_data *data);
int			mouse_hook(int keycode, int x, int y, t_data *data);
void		zoom_in(double x, double y, t_data *data);
void		zoom_out(double x, double y, t_data *data);
int			key_hook(int keycode, t_data *data);

// ------------- RENDERING ------------
void		white_screen(t_data *data, int x, int y);
void		draw_mandel(t_data *data, t_data_img img, t_color color);
void		draw_julia(t_data *data, t_data_img img, t_color color);
void		ft_mlx_pixel_put(t_data_img *data_img, int x, int y, int color);

// ------------- CALCULATION'S TOOLS --------
int			julia(t_complex z, t_data *data);
int			mandelbrot(t_complex c, t_data *data);
double		magnitude(t_complex a);
t_complex	square(t_complex a);
t_complex	add(t_complex a, t_complex b);

// ------------- PARSING ----------------
char		name_cmp(char *s1, char *s2);
void		ft_errors(char flag);
char		args_handler(int argc, char **argv);
void		float_creation(double *nb, int i, char *str);
double		ft_atof(char *str);

// ---------------- UTILS -----------------

void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(char c);
int			ft_strlen(char *s);

#endif
