#ifndef	SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define EMPTY	'0'
# define WALL	'1'
# define COINS	'C'
# define EXIT	'E'
# define PLAYER	'P'
# define ENEMY	'X'

# define UP	1
# define DOWN	2
# define LEFT	3
# define RIGHT	4

# define BACKGROUND_PATH	"./img/background"
# define WALL_PATH		"./img/wall"
# define COINS_PATH		"./img/food"
# define ENEMY_PATH		"./img/bottle"
# define PLAYER_F_PATH		"./img/dog"
# define PLAYER_B_PATH		"./img/dog"
# define PLAYER_R_PATH		"./img/dog"
# define PLAYER_L_PATH		"./img/dog"
# define EXIT_0_PATH		"./img/open"
# define EXIT_C_PATH		"./img/closed"

# define PX 30

typedef struct s_list
{
	char			content[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

typedef struct s_copy
{
	char	**tab;
	int	coins;
	int	exit;
}	t_copy;

typedef struct s_player
{
	int	pos;
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char	**tab;
	int	rows;
	int	cols;
	int	exit;
	int	player;
	int	coins;
}	t_map;

typedef struct s_sprite
{
	void	*xpm_ptr;
	int	height;
	int	width;
}	t_sprite;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	int		is_map_alloc;
	int		move_count;
	int		is_ready;
	t_player	player;
	t_sprite	background;
	t_sprite	wall;
	t_sprite	coins;
	t_sprite	enemy;
	t_sprite	player_f;
	t_sprite	player_b;
	t_sprite	player_r;
	t_sprite	player_l;
	t_sprite	exit_c;
	t_sprite	exit_o;
}	t_data;



//initialize_map
void	initialize_map(int argc, char **argv, t_data *data);
void	check_argv(int argc, char **argv, t_data *data);
int	get_rows_count(char *map, t_data *data);
void	store_map(char **argv, t_data *data);
//error_check
void    check_map(t_data *data);
void    check_characters(t_data *data);
int     there_is_wrong_char(t_data *data);
int     is_wall_surrounded(t_data *data);
int     is_right_shape(t_data *data);
//path check
int     path_check(t_data *data);
void    init_map_copy(t_data *data, t_copy *map_copy);
void    flood_fill_algorithm(t_data *data, t_copy *map_copy, int y, int x);
//initialize_game
void    init_game(t_data *data);
void    init_asset(t_data *data);
t_sprite        make_sprite(char *sprite_path, t_data *data);
//make screen
int     make_screen(t_data *data);
void    player_view(t_data *data, int i, int j);
void    put_assets_on_screen(t_data *data, int i, int j);
//handle input
int	handle_input(int keysim, t_data *data);
void    check_move(t_data *data, int direction);
void    get_new_pos(t_data *data, int *n_x, int *n_y, int dir);
void    move_player(t_data *data, int n_x, int n_y, int asset);
void    moves_input(t_data *data);
//free_memory
void    free_map(char **map);
void    destroy_assets(t_data *data);
//exit_game
void     finish_game(t_data *data, int result);
int     exit_game(t_data *data);
void    print_error_and_exit(char *msg, t_data *data);
//libft utils
char    *ft_strchr(const char *string, int c);
int	ft_strlen(const char *string);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
char            *get_next_line(int fd);
int	count_len(t_list **list);
void	read_and_putnode(int fd, t_list **list);
int	new_line(t_list **list);
t_list	*add_new_node(t_list **list, int is_new_list);
void    fill_new_list(t_list *tmp, t_list *new_list);
void    reset_list(t_list **list);
void    remove_last_node(t_list **list);
void    fill_line(t_list *list, char *line, int line_len);
void    free_all(t_list **list);
int     ft_strcmp(char *s1, char *s2);
char    *ft_strdup(const char *s);

#endif
