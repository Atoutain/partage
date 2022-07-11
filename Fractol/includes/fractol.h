#ifndef FRACTOL_H_
# define FRACTOL_H_

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"

#define Buf_SIZE 20

typedef struct s_data t_data;
typedef struct s_name t_name;

struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;

	int			stahp;
	int			bpp;
	int			size_line;
	int			endian;
	int			i;
	int			color_degrade;
	int			way;

	char		*data;
	char		*name;

	double			h;
	double		max_iter;
	double		zoom;
	double		x;
	double		x1;
	double		x2;
	double		y;
	double		y1;
	double		y2;
	double		image_x;
	double		image_y;
	double		tmp;
	double		c_r;
	double		z_r;
	double		c_i;
	double		z_i;


	pthread_t	thread;
};

t_data		init_data_mandelbrot(t_data *data);
t_data		degrade(t_data *data, int color, int max, int min);

int			motion_hook(int x, int y, t_data *data);
int			key_hook_all(int keycode, t_data *data);
int			key_hook_1(int keycode, t_data *data);
int			mouse_hook(int keycode);
int			rgb(int x, int y, int z);
int			ft_strcmp(const char *s1, const char *s2);
int			expose_julia(t_data *data);
int			expose_mandelbrot(t_data *data);
int			mouse_hook_all(int button,int x,int y,t_data *data);

void		ft_put_pixel_to_image(t_data *data, int x, int y, int color);
void		*check_1(void *data);
void		is_julia(t_data *data, char *name);
void		is_mandelbrot(t_data *data, char *name);
void		draw_julia(t_data *data);
void		draw_mandelbrot(t_data *data);
void		ft_putendl(const char *s);

#endif
