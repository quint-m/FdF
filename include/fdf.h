#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <stdlib.h>
# include <stdio.h>
# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point *grid;
	int		z_max;
	int		z_min;
}	t_map;

typedef struct s_cam
{
	float	x_angle;
	float	y_angle;
	float	z_angle;
	int		x_offset;
	int		y_offset;
	int		zoom;
}	t_cam;

typedef struct s_env
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_map		*map;
	t_cam		*cam;
	int			steep;
	int			w_width;
	int			w_height;
}	t_env;

/*
 * Utils
 */
int		ft_validate_map(const char *file, t_map *map);
int	ft_program_error(const char *err, int system_error);
void	ft_close_window(void *param);
void	ft_keypress(mlx_key_data_t keydata, void *param);
void	ft_translate(int k_code, t_env *env);
void	ft_draw(t_env	*env);
void	ft_rotate(key_t k_code, t_env *env);
t_point	project(int x, int y, t_env *env);

float	ft_rfpart(float n);
float	ft_fpart(float n);
int		ft_ipart(float n);
void	ft_draw_line(t_point s, t_point e, t_env *env);
void	ft_clear(t_env *env);
void	ft_swap(int *a, int *b);
void	ft_scroll(double xdelta, double ydelta, void *param);
int		ft_get_default_color(int x, int y, t_env *env);
void	ft_resize(int widht, int height, void *param);
uint32_t	ft_getcolor(int x, t_point s, t_point e, float brightness);
void	ft_putpixel(int xp, int yp, uint32_t color, t_env *env);
void	draw_line(t_point start, t_point end, t_env *env);
#endif
