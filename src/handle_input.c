/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:03:34 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/22 13:57:13 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	change_movement(t_data *data)
{
	if (data->player.pos == ONE)
		data->player.pos = TWO;
	else if (data->player.pos == TWO)
		data->player.pos = THREE;
	else if (data->player.pos == THREE)
		data->player.pos = FOUR;
	else if (data->player.pos == FOUR)
		data->player.pos = ONE;
}

void	move_player(t_data *data, int n_x, int n_y, int asset)
{
	int	old_x;
	int	old_y;

	change_movement(data);
	old_x = data->player.x;
	old_y = data->player.y;
	data->map.tab[old_y][old_x] = EMPTY;
	data->map.tab[n_y][n_x] = PLAYER;
	data->player.x = n_x;
	data->player.y = n_y;
	data->move_count += 1;
	if (asset == COINS)
		data->map.coins -= 1;
}

void	get_new_pos(t_data *data, int *n_x, int *n_y, int dir)
{
	*n_x = data->player.x;
	*n_y = data->player.y;
	if (dir == UP)
		*n_y -= 1;
	else if (dir == DOWN)
		*n_y += 1;
	else if (dir == LEFT)
		*n_x -= 1;
	else if (dir == RIGHT)
		*n_x += 1;
	if (dir == LEFT || dir == RIGHT)
		data->player.dir = dir;
}

void	check_move(t_data *data, int direction)
{
	int	new_x;
	int	new_y;

	get_new_pos(data, &new_x, &new_y, direction);
	if (data->map.tab[new_y][new_x] == EMPTY)
		move_player(data, new_x, new_y, EMPTY);
	else if (data->map.tab[new_y][new_x] == COINS)
		move_player(data, new_x, new_y, COINS);
	else if (data->map.tab[new_y][new_x] == ENEMY)
		finish_game(data, ENEMY);
	else if (data->map.tab[new_y][new_x] == EXIT && data->map.coins == 0)
		finish_game(data, EXIT);
	else if (data->map.tab[new_y][new_x] == WALL)
		return ;
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		check_move(data, UP);
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		check_move(data, DOWN);
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		check_move(data, LEFT);
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		check_move(data, RIGHT);
	else if (keysym == XK_Escape)
		exit_game(data);
	moves_input(data);
	return (0);
}
