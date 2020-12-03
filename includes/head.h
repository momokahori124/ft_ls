/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 00:04:50 by mhori             #+#    #+#             */
/*   Updated: 2020/12/04 04:49:05 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include "color.h"
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include "../Libft/libft.h"

typedef struct	s_input
{
	int		option[9];
	int		dirnum;
	char	**dirname;
	int		max_blocks;
	int		total;
	int		count;
	int		is_u_first;
	char	u;
}				t_input;
void			ft_put_dirname(char *dirname, char *inner_dirname, t_input i);
void			sort_dirname(char *dirname, char **inner_dirname, t_input i);
void			ft_swap(char **s, char **t);
void			display_2d(char *dirname, char **inner_dirname, t_input input);
void			ft_putstr(char *s);
int				key(char c);
char			*ft_strjoin3(char *s, char *t);
int				count_inner(char *dirname);
int				input_inner(char **inner_dirname, char *dirname);
void			put_permission(int per);
void			do_ls(char *dirname, t_input input);
void			each_do_ls(t_input input);
void			get_max_total(t_input *input, struct stat buf);
void			put_option(int *option);
void			put_dirname(char **dirname);
int				cmp_by_alpha(char *s, char *t);
int				cmp_by_ctime(char *s, char *t);
int				cmp_by_atime(char *s, char *t);
int				cmp_by_mtime(char *s, char *t);
int				cmp_by_filesize(char *s, char *t);
void			is_u_first(char *save, t_input *input);
int				is_directory(char *dirname, char *inner_dirname);
int				is_regfile(char *dirname, char *inner_dirname);
char			*path_to_filename(char *s);
void			convert_path(char *dirname, char **inner_dirname, char ***p);
void			sort_by(char **dirname, int(*cmp_func)(char *, char *));
long long		ft_nbrlen(long long n);
void			ft_printf_d(char *fmt, int width, long long n);
void			ft_printf_s(char *fmt, int width, char *t);
void			free_2d(char ***s);
void			fsave_2d(char ***tmp, char **s);
void			path_to_filename_2d(char ***s);
void			option_r(char *dirname, t_input input, int index);
int				count_inner(char *dirname);
int				input_inner(char **inner_dirname, char *dirname);
void			input_option(t_input *input, int ac, char *av[]);
void			input_dirname(char *av[], t_input *input);
char			*filename_to_path(char *dirname, char *inner_dirname);

#endif
