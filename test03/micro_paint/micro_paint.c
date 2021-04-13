#include "micro_paint.h"

int		ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		print_err(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}

int		clean_exit(FILE *file, char *canvus, char const *str)
{
	if (file)
		fclose(file);
	if (canvus)
		free(canvus);
	return (print_err(str));
}

char		*init_canvus(FILE *file, t_canvus *info)
{
	char	*tmp;
	int		i;

	i = 0;
	if (fscanf(file, "%d %d %c\n", &info->w, &info->h, &info->bg) != 3)
		return (0);
	if (info->w <= 0 || info->w > 300 || info->h <= 0 || info->h > 300)
		return (0);
	if (!(tmp = (char *)malloc(info->w * info->h)))
		return (0);
	while (i < info->w * info->h)
		tmp[i++] = info->bg;
	return (tmp);
}

int			in_shape(t_shape shape, int x, int y)
{
	if (x < shape.x || x > (shape.x + shape.w) || y < shape.y || y > (shape.y + shape.h))
		return (0);
	if (x - shape.x < 1.0 || (shape.x + shape.w) - x < 1.0 || y - shape.y < 1.0 || (shape.y + shape.h) - y < 1.0)
		return (2);
	return (1);
}

void		draw_shape(t_shape shape, t_canvus info, char *canvus)
{
	int		x;
	int		y;
	int		result;

	y = 0;
	while (y < info.h)
	{
		x = 0;
		while (x < info.w)
		{
			result = in_shape(shape, x, y);
			if (result)
				if ((result == 2 && shape.info == 'R') || shape.info == 'r')
					canvus[info.w * y + x] = shape.draw;
			x++;
		}
		y++;
	}
}

int			draw_shapes(FILE *file, t_canvus *info, char *canvus)
{
	t_shape	shape;
	int		count;
	while ((count = fscanf(file, "%c %f %f %f %f %c\n", &shape.info, &shape.x, &shape.y, &shape.w, &shape.h, &shape.draw)) == 6)
	{
		if (shape.w <= 0.00000000 || shape.h <= 0.00000000 || (shape.info != 'R' && shape.info != 'r'))
			return (0);
		draw_shape(shape, *info, canvus);
	}
	if (count == EOF)
		return (1);
	return (0);
}

void		print_screen(t_canvus info, char *canvus)
{
	int		i;

	i = 0;
	while (i < info.h)
	{
		write(1, &canvus[i * info.w], info.w);
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	FILE	*file;
	t_canvus	info;
	char	*canvus;

	canvus = 0;
	file = 0;
	if (argc < 2 || argc > 2)
		return (print_err("Error: argument"));
	if (!(file = fopen(argv[1], "r")))
		return (print_err("Error: No valid Operation file"));
	if (!(canvus = init_canvus(file, &info)))
		return (clean_exit(file, canvus, "Error: No valid Operation file"));
	if (!draw_shapes(file, &info, canvus))
		return (clean_exit(file, canvus, "Error: No valid Operation file"));
	print_screen(info, canvus);
	fclose(file);
	free(canvus);
	return (0);
}
