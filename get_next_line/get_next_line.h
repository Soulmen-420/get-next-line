#ifndef __GET_NEXT_LINE_H__
# define __GET_NEXT_LINE_H__

    #include "/Users/tjeerd/Desktop/libft/ft_include.h"
	
	#include <stdio.h>
	#include <sys/types.h>
    #include <sys/uio.h>
    #include <unistd.h>
	#include <stdlib.h>
	#include <fcntl.h>

	#define BUFF_SIZE 10
	#define MAX_FD 1024 + 1
	
	int get_next_line(const int fd, char **line);
	int	append_line(char **stack, char **line);
 	int output(int ret, int fd, char **stack, char **line);

#endif
