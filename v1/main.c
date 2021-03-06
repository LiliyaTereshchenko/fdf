/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:42:20 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/13 15:19:56 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int deal_key(int key, t_mlx *param, t_rotation ang, t_point **map)
{
	if (key == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit (0);
	}
	if (key == 124)
	{
		mlx_clear_window(param->mlx, param->win);
		ang.alpha += 15; 

		ft_draw_figure(map, param, ang);
		
	}
	return (0);
}

void printFromHead(t_list *list) 
{
	while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
}

int		main(int argc, char **argv)
{
	t_point	**map;
	t_mlx	*param;
	t_rotation ang;

	ang.alpha = 15 * M_PI / 180;
	ang.beta = 45;
	ang.gamma = 45;

	map = NULL;
	if (argc == 2)
	{
		if ((ft_read_map(argv[1], &map)))
		{
			param = (t_mlx *)malloc(sizeof(t_mlx));
			param->mlx = mlx_init();
			param->win = mlx_new_window(param->mlx, 1200, 1200, "fdf");
			mlx_key_hook(param->win, deal_key, param);
			mlx_loop_hook(param->mlx, deal_key, param);
			ft_draw_figure(map, param, ang);
			mlx_loop(param->mlx);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fdf file_name\n");
	return (0);
}
