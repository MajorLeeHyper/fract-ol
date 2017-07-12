/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 11:44:06 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/12 11:50:45 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	increase_carpet(t_env *env)
{
	if (env->iter_max < 19)
	{
		env->maxx *= 3;
		env->maxy *= 3;
		env->iter_max++;
	}
	draw(env);
}

void	decrease_carpet(t_env *env)
{
	if (env->iter_max > 0)
	{
		env->maxx /= 3;
		env->maxy /= 3;
		env->iter_max--;
	}
	draw(env);
}
