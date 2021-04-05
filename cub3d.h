/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:54:44 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/12 13:50:47 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx/mlx.h"

typedef struct		s_vec
{
	int				x;
	int				y;
}					t_vec;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				len;
	int				end;
}					t_data;

typedef struct		s_plr
{
	float			planex;
	float			planey;
	float			posx;
	float			posy;
	float			dirx;
	float			diry;
}					t_plr;

typedef struct		s_screen
{
	float			camera;
	float			rdirx;
	float			rdiry;
	float			deldistx;
	float			deldisty;
	int				stepx;
	int				stepy;
	float			sidedistx;
	float			sidedisty;
	int				dend;
	int				dstart;
	int				line_h;
	float			perpwdist;

}					t_screen;

typedef struct		s_map
{
	char			**map;
	int				mapx;
	int				mapy;
	int				size;
	int				res_x;
	int				res_y;
}					t_map;

typedef struct		s_tex
{
	void			*img[5];
	char			*addr[5];
	char			*path[5];
	int				texx;
	int				texy;
	float			wallx;
	float			step;
	float			textpos;
	int				t_w[4];
	int				t_h[4];
	int				bpp[4];
	int				len[4];
	int				end[4];
}					t_tex;

typedef struct		s_sprite
{
	float			*smapx;
	float			*smapy;
	int				num;
	int				drawsx;
	int				drawsy;
	int				drawex;
	int				drawey;
	float			trsformy;
	float			trsformx;
	int				s_w;
	int				s_h;
	int				bpp;
	int				len;
	int				end;
	float			*zb;
}					t_sprite;

typedef struct		s_bmp
{
	unsigned int	file_size;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	pixeldataoffset;
	unsigned int	header_size;
	unsigned int	img_w;
	unsigned int	img_h;
	unsigned short	planes;
	unsigned short	bpp;
	unsigned int	compression;
	unsigned int	img_size;
	unsigned int	xpixelspermeter;
	unsigned int	ypixelspermeter;
	unsigned int	totalcolors;
	unsigned int	importantcolors;
}					t_bmp;

typedef struct		s_all
{
	int				flag;
	int				color_f;
	int				color_c;
	int				num;
	char			pl;
	void			*mlx;
	void			*win;
	float			coef_res;
	t_data			*data;
	t_plr			*plr;
	t_map			*map;
	t_screen		*scr;
	t_tex			*tex;
	t_sprite		*sp;
}					t_all;

int					get_next_line(int fd, char **line);
int					parser(int argc, char **argv, t_all *a);
int					get_color_c(t_all *a, char *line);
int					get_color_f(t_all *a, char *line);
int					resolution(t_all *a, char *line, int i);
int					check_textures(t_all *a, char *line, int i);
int					parser_map(t_all *a, int fd);
int					check_map(char **map, t_all *a);
int					check_empty_space(t_all *a, int y, int x);
int					get_texture_img(t_all *a, int error);
int					parse_sprites(t_all *a, int y, int x);
void				print_sprites(t_all *a);
void				render(t_all *a);
void				draw_walls(t_all *a, int side, int x);
void				draw_sprites(t_all *a, int spscreenx);
void				move_up(t_all *all, float ms);
void				move_down(t_all *all, float ms);
void				move_left(t_all *all, float ms);
void				move_right(t_all *all, float ms);
void				rot(t_all *all, int key, float rs);
int					save(t_all *a);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
void				delete_list(t_list *head);
int					error(int flag, t_all *a);
void				free_all(t_all *a);

#endif
