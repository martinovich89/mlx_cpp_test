#pragma once

#include <mlx.h>
#include <iostream>
#include <cstdlib>

#define RES_W 1600
#define RES_H 1200

typedef struct	s_data
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
    int     w;  
    int     h;  
}               t_data;

typedef struct	s_vars
{
	void    *mlx;
	void    *win;
	t_data  img;
    bool    up;
    bool    down;
    bool    left;
    bool    right;
}				t_vars;