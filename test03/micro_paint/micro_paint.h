#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

typedef struct	s_canvus
{
	int			w;
	int			h;
	char		bg;
}				t_canvus;

typedef struct	s_shape
{
	char		info;
	float		x;
	float		y;
	float		w;
	float		h;
	char		draw;
}				t_shape;

#endif
