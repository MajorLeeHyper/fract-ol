/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:08:30 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/12 11:41:25 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	relaunch_fract(int fract, t_env *env)
{
	if (fract == 1)
		begin_mandelbrot(env);
	else if (fract == 2)
		begin_julia(env);
	else if (fract == 3)
		begin_burning_ship(env);
	else if (fract == 4)
		begin_carpet(env);
	else if (fract == 6 || fract == 5)
		begin_tricorn(env);
}

void	draw(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	if (env->frac == 1)
		mandelbrot(env);
	else if (env->frac == 2)
		julia(env);
	else if (env->frac == 3)
		burning_ship(env);
	else if (env->frac == 4)
			sierpinski_carpet(env);
	else if (env->frac == 5)
		tricorn(env);
}

void	start_fract(int fract, t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, "fract'ol");
	if (fract == 1)
		begin_mandelbrot(env);
	else if (fract == 2)
		begin_julia(env);
	else if (fract == 3)
		begin_burning_ship(env);
	else if (fract == 4)
		begin_carpet(env);
	else if (fract == 5 || fract == 6)
		begin_tricorn(env);
	draw(env);
	mlx_mouse_hook(env->win, mouse_zoom, env);
	mlx_hook(env->win, 6, 1L<<6, julia_mouse, env);
	mlx_hook(env->win, 2, 1L<<0, key_press_hook, env);
	mlx_loop(env->mlx);
}


int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
	{
		ft_putendl("usage: ./fractol <fractal#>");
		ft_putendl("1 = Mandelbrot");
		ft_putendl("2 = Julia");
		ft_putendl("3 = something");
		ft_putendl("4 = something");
		ft_putendl("5 = something");
	}
	else
	{
		env = (t_env*)ft_memalloc(sizeof(t_env));
		if (ft_atoi(av[1]) >= 1 && ft_atoi(av[1]) <= 5)
			start_fract(ft_atoi(av[1]), env);
		else
			ft_putendl("Please enter a number between 1 & 5");
	}
	return (0);
}
