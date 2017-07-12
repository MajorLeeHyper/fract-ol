/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:16:44 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/12 16:48:37 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	background(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < 230)
	{
		y = 0;
		while (y < 380)
		{
			mlx_pixel_put(env->mlx, env->win, x, y, 0xC7D2D6);
			y++;
		}
		x++;
	}
}

void	show_help_window(t_env *env)
{
	background(env);
	mlx_string_put(env->mlx, env->win, 10, 10, HELP, "KEYS:");
	mlx_string_put(env->mlx, env->win, 10, 40, HELP, "1 = Mandelbrot");
	mlx_string_put(env->mlx, env->win, 10, 60, HELP, "2 = Julia");
	mlx_string_put(env->mlx, env->win, 10, 80, HELP, "3 = Burning Ship");
	mlx_string_put(env->mlx, env->win, 10, 100, HELP, "4 = Sierpinskis Carpet");
	mlx_string_put(env->mlx, env->win, 10, 120, HELP, "5 = Tricorn");
	mlx_string_put(env->mlx, env->win, 10, 140, HELP, "______________________");
	mlx_string_put(env->mlx, env->win, 10, 160, HELP, "Page Up = Iterations+");
	mlx_string_put(env->mlx, env->win, 10, 180, HELP, "Page Dwn = Iterations-");
	mlx_string_put(env->mlx, env->win, 10, 200, HELP, "+/- = Zoom in/out");
	mlx_string_put(env->mlx, env->win, 10, 220, HELP, "R = Reset Fractol");
	mlx_string_put(env->mlx, env->win, 10, 240, HELP, "esc = Quit");
	mlx_string_put(env->mlx, env->win, 10, 260, HELP, "H = Show/Hide Help");
	mlx_string_put(env->mlx, env->win, 10, 280, HELP, "Ctrl/alt/com = colors");
}
