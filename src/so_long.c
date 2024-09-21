#include "../includes/so_long.h"
#include <stdio.h>

void	moves_input(t_data *data)
{
	char	*move_count;

	move_count = ft_itoa(data->move_count);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr,
                        data->win_ptr, data->paw.xpm_ptr, (data->map.cols * PX) / 2 - 60, data->map.rows * PX);
//	mlx_string_put(data->mlx_ptr, data->win_ptr,
//		(data->map.cols * PX) / 2 - 60, data->map.rows * PX + 20, 0xff0000, "Moves: ");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		(data->map.cols * PX) / 2, data->map.rows * PX + 30, 0x00ff00, move_count);
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
