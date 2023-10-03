/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:43:06 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:43:08 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int				ft_atoi(char const *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmem, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char    		*ft_itoa(int n);
void    		*ft_memchr(void const *s, int c, size_t n);
int				ft_memcmp(void const *s1, void const *s2, size_t n);
void    		*ft_memcpy(void *dest, void const *src, size_t n);
void    		*ft_memmove(void *dest, void const *src, size_t n);
void    		*ft_memset(void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *str, char c);
char    		*ft_strchr(char const *s, int c);
char			*ft_strdup(char const *src);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
unsigned int	ft_strlcat(char *dest, char const *src, size_t size);
unsigned int	ft_strlcpy(char *dest, char const *src, size_t size);
int				ft_strlen(char const *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(char const *s1, char const *s2, size_t n);
char			*ft_strnstr(char const *big, char const *small, size_t len);
char    		*ft_strrchr(char const *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char    		*ft_substr(char const *s, unsigned int start, size_t len);
int 			ft_tolower(int c);
int 			ft_toupper(int c);

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
