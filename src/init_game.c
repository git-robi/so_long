#include "../includes/so_long.h"

void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		print_error_and_exit("mlx_ptr allocation failed", data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	(data->map.cols - 1) * PX, data->map.rows * PX, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		print_error_and_exit("win_ptr allocation failed", data);
	}
	init_asset(data);
	data->move_count = 0;
	data->is_ready = 0;  //I don't know what this is for 
	data->player.pos = DOWN;
}

void	init_asset(t_data *data)
{
	data->background = make_sprite(BACKGROUND_PATH, data);
	data->wall = make_sprite(WALL_PATH, data);
	data->coins = make_sprite(COINS_PATH, data);
	data->enemy = make_sprite(ENEMY_PATH, data);
	data->player_f = make_sprite(PLAYER_F_PATH, data);
	data->player_b = make_sprite(PLAYER_B_PATH, data);
	data->player_r = make_sprite(PLAYER_R_PATH, data);
	data->player_l = make_sprite(PLAYER_L_PATH, data);
	data->exit_o = make_sprite(EXIT_0_PATH, data);
	data->exit_c = make_sprite(EXIT_C_PATH, data);
}

t_sprite	make_sprite(char *sprite_path, t_data *data)
{
		t_sprite	sprite;
		int		px;

		px = PX;
		sprite.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, sprite_path, \
		&px, &px);
		if (sprite.xpm_ptr == NULL)
			print_error_and_exit("Sprite not found\n", data);
		return (sprite);
}
