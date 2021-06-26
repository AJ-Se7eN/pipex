#include "pipex.h"

void	ft_child_handler(int *pipe_fd, char *cmd, char **env, int *fd)
{
	close(pipe_fd[0]);
	dup2(fd[0], 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	ft_exec_cmd(ft_split(cmd, ' '), env);
}

void	ft_parent_handler(int *pipe_fd, char *cmd, char **env, int *fd)
{
	close(pipe_fd[1]);
	dup2(fd[1], 1);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	ft_exec_cmd(ft_split(cmd, ' '), env);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		fd[2];
	int		pipe_fd[2];

	if (argc != 5)
		return (ft_error(RED"Ex.: ./pipex infile cmd1 cmd2 outfile"RESET));
	else if (pipe(pipe_fd) == -1)
		return (ft_error(RED"Er.: Create pipeline failed!"RESET));
	else if (!ft_isvalid(argv[1], argv[4], fd))
		return (ft_error(RED"Er.: Not valid file!"RESET));
	pid = fork();
	if (pid == -1)
		return (ft_error(RED"Er.: Fork failed!"RESET));
	else if (pid == 0)
		ft_child_handler(pipe_fd, argv[2], env, fd);
	else
		ft_parent_handler(pipe_fd, argv[3], env, fd);
	return (0);
}
