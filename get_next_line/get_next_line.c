#include "get_next_line.h"


int		append_line(char **stack, char **line)
{
	int len = 0;
	char *tmp = NULL;

	while(((*stack)[len] != '\n') && ((*stack)[len] != '\0'))
			len++;
		if((*stack)[len] == '\n'){
			*line = ft_strsub(*stack, 0, len);
			tmp = ft_strdup(&((*stack)[len+1]));
			ft_strdel(stack);
			*stack = tmp;
			if((*stack)[0] == '\0'){
				ft_strdel(stack);
			}
		} else {
			*line = ft_strdup(*stack);
			ft_strdel(stack);
		}
	return(1);
}

int 	output(int ret, int fd, char **stack, char **line)
{
	if(ret < 0){
		return(-1);
	} else if((ret == 0) && (stack[fd] == NULL)){
		return(0);
	} else {
		return(append_line(&stack[fd], line));
	}
}

int		get_next_line(const int fd, char **line)
{
	static char *stack[MAX_FD];
	char heap[BUFF_SIZE + 1];
	char *tmp = NULL;
	int ret = 0;

	if(ret < 0 || line[fd] == NULL){
		return(-1);
	} while((ret = read(fd, heap, BUFF_SIZE)) > 0){
		heap[ret] = '\0';
		if(stack[fd] == NULL){
			stack[fd] = ft_strdup(heap);
		} else {
			tmp = ft_strjoin(stack[fd], heap);
			free(stack[fd]);
			stack[fd] = tmp;
		}
	if(ft_strchr(stack[fd], '\n')){
			break;
		}
	}
	return(output(ret, fd, stack, line));
}

int		main(int argc, char **argv)
{
	int		fd;
	char 	*line;
	
	if(argc != 2){
		printf("one file");
		exit(1);
	} else {
		fd = open(argv[1], O_RDONLY);
//		while(fd != 3 || fd != -1){
			get_next_line(fd, &line);
			printf("%s\n", line);
			get_next_line(fd, &line);
			printf("%s\n", line);
			get_next_line(fd, &line);
			printf("%s\n", line);
			get_next_line(fd, &line);
			printf("%s\n", line);
			get_next_line(fd, &line);
			printf("%s\n", line);
			get_next_line(fd, &line);
			printf("%s\n", line);
			get_next_line(fd, &line);
			printf("%s\n", line);
//		}
	}
	return(0);
}
