#include "../includes/so_long.h"

void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		print_error_and_exit("mlx_ptr allocation failed", data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	(data->map.cols - 1) * PX, data->map.rows * PX + 50, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		print_error_and_exit("win_ptr allocation failed", data);
	}
	init_asset(data);
	data->move_count = 0;
	data->is_ready = 0;  //I don't know what this is for 
	data->player.pos = TWO;
	data->player.dir = RIGHT;
}

void	init_asset(t_data *data)
{
	data->background = make_sprite(BACKGROUND_PATH, data);
	data->wall = make_sprite(WALL_PATH, data);
	data->coins = make_sprite(COINS_PATH, data);
	data->enemy = make_sprite(ENEMY_PATH, data);
	data->player_one = make_sprite(PLAYER_R_ONE, data);
	data->player_two = make_sprite(PLAYER_R_TWO, data);
	data->player_three = make_sprite(PLAYER_R_THREE, data);
	data->player_four = make_sprite(PLAYER_R_FOUR, data);
	data->player_five = make_sprite(PLAYER_L_ONE, data);
	data->player_six = make_sprite(PLAYER_L_TWO, data);
	data->player_seven = make_sprite(PLAYER_L_THREE, data);
	data->player_eight = make_sprite(PLAYER_L_FOUR, data);
	data->exit_o = make_sprite(EXIT_0_PATH, data);
	data->exit_c = make_sprite(EXIT_C_PATH, data);
	data->paw = make_sprite(PAW_PATH, data);
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
