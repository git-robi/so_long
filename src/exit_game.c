/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:09:52 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/22 14:09:54 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error_and_exit(char *msg, t_data *data)
{
	if (data->is_map_alloc)
		free_map(data->map.tab);
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	exit(1);
}

int	exit_game(t_data *data)
{
	destroy_assets(data);
	free_map(data->map.tab);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (1);
	return (0);
}
