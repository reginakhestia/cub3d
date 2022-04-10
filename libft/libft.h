#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# define GNL_BUFF_SIZE 1024

int		ft_strlen(const char *str);
char	*ft_memcpy(char *dest, const char *src, int n);
char	*ft_strdup(const char *s);
int		ft_gnl(int fd, char **line);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
