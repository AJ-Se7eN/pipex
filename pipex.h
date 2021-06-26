#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>

# define RED   "\x1B[31m"
# define RESET "\x1B[0m"

void	ft_clear_2d(char **array);
void	ft_exec_cmd(char **cmd, char **env);
int		ft_isvalid(char *file1, char *file2, int *fd);

#endif //PIPEX_H
