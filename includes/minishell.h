/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:41:47 by mpytienk          #+#    #+#             */
/*   Updated: 2018/02/08 15:41:50 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct		s_shell
{
	char			**envd;
	char			**envt;
}					t_shell;

char				**mda_copy(char **arr);
void				mda_print(char **arr);
int					mda_len(char **arr);
void				mda_clear(char **arr);
void				mda_trim(char **arr);
char				*env_trim(char *str);
int					get_env_pos(char **env, char *str);
void				display_prompt(void);
int					parse(t_shell *tmp, char *str);
void				exacute(t_shell *tmp, char **cml, char *s);
void				env_replace(char **sd, char *s1, char *s2);
char				**ft_newsplit(char const *s, char c);
void				ft_sig_int(int sig);
void				ft_sig_proc(int sig);
void				sig_try(void);
int					bi_setenv(t_shell *tmp, char **arg);
char				*env_combine(char *s1, char *s2);
int					bi_unsetenv(t_shell *s, char **arg);
int					bi_cd(t_shell *s, char **arg);
int					bi_echo(t_shell *st, char **arg);
char				*env_get_name(char *str);
int					is_qoted(char *s);
void				epprint_sup(char *s, char *tmp, int flag);
char				*solv_home(t_shell *st, char *s);
int					is_space(char c);
void				path_change(t_shell *s, char *path, int i, int k);
void				cderr(char *path);
void				ft_putpwd(t_shell *s, char *pwd);
int					bi_env(t_shell *s, char **arg);
void				mod_env(t_shell *tmp, char *str);
char				**mda_alloc(int size);
void				to_fork(char *path, char **argc, char **envd);
char				*path_join(char *path);
int					cd_unsetenv(t_shell *s, char *arg);
void				print_help(void);
void				bi_exit(void);
int					is_walidsimbol(char *l);

#endif
