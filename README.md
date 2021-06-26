# pipex
Learn more about UNIX mechanisms

## Usage
<pre>
<code>
./pipex file1 cmd1 cmd2 file2
</code>
</pre>

## Example
<pre>
<code>
./pipex infile ``ls -l'' ``wc -l'' outfile
</code>
</pre>

##### pipe()
A method of communication used to communicate between processes
Because the child process must send data to the parent process, it requires a pipe connected to the standard output of the child process and the standard input of the parent process
Create a pipe and connect the descriptor that was created
Returns 0 on successful call, -1 on failure
<pre>
<code>
// descriptors stored in array
//fd[1]is the descriptor that writes to the pipe, and fd[0]is the descriptor that reads from the pipe
int pipe_fd[2];
if (pipe(pipe_fd) == -1)
return (0);
</code>
</pre>

##### fork()
Create process
The process that calls the fork function becomes the parent process, and the newly created process is the child process
The child process copies the memory of the parent process as it is
Execute using their own memory from code after fork function call
On successful calls, the parent process returns the PID value of the child process, and the child process returns the value of 0
-1 return on failure


##### int dup2(int old_fd1, int new_fd2)
If the newfd file descripter is already an open file, close it and copy oldfd to newfd
At this time, newfd and oldfd behave the same, although the file descripter number is different.
However, the two file descriptors are different descriptors, so closing one does not close together.



##### Other
| Title| Description|
|------|---|
| int execve (const char *filename, char *const argv[], char *const envp[])|run another program and exit yourself|
| int dup (int fd)|Duplicate file identifiers |
