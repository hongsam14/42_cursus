/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:15:26 by hopark            #+#    #+#             */
/*   Updated: 2021/07/06 05:15:27 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "head.h"

char		*ft_add_char(char **str, char c, int pt);
char		*ft_del_char(char **str, int pt);
int			ft_isdigit(int c);
int			ft_sign(int sign);
int			ft_is_num(const char *nptr);
long long	ft_atoi(const char *nptr);
t_built		*ft_builtndup(t_list *list);
t_built		*ft_builtndup2(t_list *list);
void		ft_builtclear(t_built **built);
void		ft_builtdelone(t_built **built);
int			ft_built_cnt(t_built *built);
void		draw(void);
void		draw2(void);
void		test_print_parsing(t_built *built);
void		test_built_list(t_built *built);
void		test_print_list(t_list *list);
void		ft_free(void *memory);
void		ft_free2(char **s, int i);
int			ft_isalpha(int c);
char		*ft_itoa(int n);
t_list		*ft_listnew(char *str, char *id);
t_list		*ft_listnew2(char *str, char *id);
void		ft_listadd_back(t_list **list, t_list **new);
void		ft_listadd_tail(t_list **list, t_list **new);
void		ft_listdelone(t_list **list);
void		ft_listclear(t_list **list);
char		**ft_env_listtochar(t_list *list);
char		**ft_listtochar(t_list *list);
void		ft_listadd_front(t_list **list, t_list **new);
t_list		*ft_listdup(t_list *list);
int			ft_list_cnt(t_list *head);
t_list		*ft_list_join(t_list *first, t_list *second);
int			ft_listjoin(t_built *built);
t_bool		ft_malloc(void *target, int size);
int			ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, int n);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strndup(const char *s, int len);
char		*ft_strchr(const char *s, char c);
int			ft_strncmp(const char *s1, const char *s2, int n);
int			ft_strncmp2(const char *s1, const char *s2, int n);
int			ft_strncmp3(const char *s1, const char *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr2(const char *s, char c);
int			ft_strlen2(char **s);
int			ft_isprint(int n);
int			ft_num_len(int num);
char		**ft_split(char const *s, char c);
int			ft_putchar_fd(char c, int fd, char *color);
int			ft_putstr_fd(char *s, int fd, char *color);
int			ft_putnbr_fd(int n, int fd, char *color);
int			get_next_line(int fd, char **line);
void		*ft_calloc(size_t nmemb, size_t size);

#endif
