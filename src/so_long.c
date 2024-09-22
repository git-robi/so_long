/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:56:49 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/22 14:24:12 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	moves_input(t_data *data)
{
	char	*move_count;

	move_count = ft_itoa(data->move_count);
	ft_putstr_fd("Number of moves: ", 1);
	ft_putstr_fd(move_count, 1);
	write(1, "\n", 1);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->paw.xpm_ptr,
		(data->map.cols * PX) / 2 - 60, data->map.rows * PX);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		(data->map.cols * PX) / 2, data->map.rows * PX + 30,
		0x00ff00, move_count);
	free (move_count);
}

void	finish_game(t_data *data, int result)
{
	if (result == EXIT)
		ft_putstr_fd("You are a free bimbi now!\n", 1);
	if (result == ENEMY)
		ft_putstr_fd("Don't worry, it's just a water bottle!\n", 1);
	exit_game(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	initialize_map(argc, argv, &data);
	init_game(&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_input, &data);
	mlx_hook(data.win_ptr, DestroyNotify, 0, &exit_game, &data);
	mlx_loop_hook(data.mlx_ptr, &make_screen, &data);
	mlx_loop(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
