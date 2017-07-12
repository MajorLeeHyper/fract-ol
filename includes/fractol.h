/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:08:10 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/12 11:49:08 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <math.h>
# include <mlx.h>

# define WIN_X 500
# define WIN_Y 500

/*
** Keyboad input number definitions
*/

# define KEY_H 4
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_R 15
# define KEY_ESC 53
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_PAGE_UP 116
# define KEY_PAGE_DOWN 121
# define KEY_SPACE 49



typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		frac;
	double	minx;
	double	miny;
	double	maxx;
	double	maxy;
	int		zc;
	double	iter;
	int		iter_max;
	double	pr;
	double	pi;
	double	cr;
	double	ci;
	double	mx;
	double	my;
	double	zr;
	double	zi;
	double	dx;
	double	dy;
	double	tmp;
	int		i;
	int		x;
	int		y;
	int		help;
	int		mouse;
	int		r;
	int		g;
	int		b;
}				t_env;

void			draw(t_env *env);
void			relaunch_fract(int fract, t_env *env);
void			start_fract(int fract, t_env *env);
void			mandelbrot(t_env *e);
void			begin_mandelbrot(t_env *env);
void			julia(t_env *env);
void			begin_julia(t_env *env);
void			burning_ship(t_env *env);
void			begin_burning_ship(t_env *env);
void			begin_carpet(t_env *env);
void			sierpinski_carpet(t_env *env);
void			begin_tricorn(t_env *env);
void			tricorn(t_env *env);
int				color(t_env *env);
int				mouse_zoom(int b, int x, int y, t_env *env);
int				mouse_zoom_cont(int b, int x, int y, t_env *env);
int				julia_mouse(int x, int y, t_env *env);
int				key_press_hook(int keycode, t_env *env);
int				more_keys(int keycode, t_env *env);
int				even_more_keys(int keycode, t_env *env);
int				help_window_checks(int keycode, t_env *env);
void			key_zoom(t_env *env, int zoom);
void			increase_carpet(t_env *env);
void			decrease_carpet(t_env *env);

#endif
