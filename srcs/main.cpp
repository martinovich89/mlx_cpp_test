#include "../includes/test.hpp"
#include <mlx.h>

void    ft_clear_vars(t_vars *vars)
{
    if (vars)
    {
        if (vars->mlx && vars->win && vars->img.img)
            mlx_destroy_image(vars->mlx, vars->img.img);
        if (vars->mlx && vars->win)
            mlx_destroy_window(vars->mlx, vars->win);
        if (vars->mlx)
        {
            mlx_destroy_display(vars->mlx);
            mlx_loop_end(vars->mlx);
            free(vars->mlx);
        }
        free(vars);
    }   
}

int close_window(int key, void *recup)
{
    (void)key;
    t_vars *vars = (t_vars *)recup;
    ft_clear_vars(vars);
    exit(0);
}

int key_press(int keycode, void *recup)
{
    t_vars *vars = (t_vars *)recup;
    if (keycode == 97) 
        vars->left = 1;
    if (keycode == 100)
        vars->right = 1;
    if (keycode == 119)
        vars->up = 1;
    if (keycode == 115)
        vars->down = 1;
    return (0);
}

int key_release(int keycode, void *recup)
{
    t_vars *vars = (t_vars *)recup;
    if (keycode == 65307)
        close_window(keycode, vars);
    if (keycode == 119)
        vars->up = 0;
    if (keycode == 97) 
        vars->left = 0;
    if (keycode == 100)
        vars->right = 0;
    if (keycode == 115)
        vars->down = 0;
    return (0);
}

int    render_next_frame(void *vars)
{
    (void)vars;
    return (0);
}

int main(void)
{
    char title[] = "test";
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, RES_W, RES_H, title);
	vars.img.img = mlx_new_image(vars.mlx, RES_W, RES_H);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bpp, &vars.img.line_length, &vars.img.endian);

	mlx_hook(vars.win, 2, 1L << 0, key_press, (void *)&vars);
    mlx_hook(vars.win, 3, 1L << 1, key_release, (void *)&vars);
    mlx_hook(vars.win, 17, 1L << 17, close_window, (void *)&vars);
    mlx_loop_hook(vars.mlx, render_next_frame, (void *)&vars);
    mlx_loop(vars.mlx);
	return (0);
}
