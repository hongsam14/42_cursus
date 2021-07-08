/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:15:10 by hopark            #+#    #+#             */
/*   Updated: 2021/07/06 05:15:11 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "head.h"

int			ft_builtin(t_built *built, t_list **env_list);
int			ft_cd(t_built *built, t_list **env_list);
int			ft_echo(t_built *built);
t_list		*ft_init_env_list(char **envp);
int			ft_add_env_list(t_list **list, char *id, char *str);
void		ft_delenv(t_list **list, char *str);
void		ft_show_env_list(t_list *list, char *str);
void		ft_show_env_list_2(t_list *list, char *str);
int			ft_env(t_built *built, t_list *env_list);
int			ft_export(t_built *built, t_list **env_list);
char		*ft_getenv(t_list *list, const char *varname, int varlen);
int			ft_pwd(void);
int			ft_unset(t_built *built, t_list **env_list);

#endif
