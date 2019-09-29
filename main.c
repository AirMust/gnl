/*#include <stdio.h>
#include "libft.h"

int main()
{
	char **s;
	int i;
	
	s = ft_strsplit("2", '9');
	i = 0;
	
	while (s[i][0])
	{
		printf("%s|\n", s[i]);
		free(s[i++]);
	}
	free(s[i]);
	free(s);
	
	return (0);
}

*/

#include "get_next_line.h"


#include <fcntl.h>
#include <stdio.h>

//# define BUFF_SIZE 50000


/*int check_n(char *str)
{
	int i;

	i = 0;
	while(*(str + i))
		if(*(str + i++) == '\n')
			return (i);
	return (-1);
}

void gnl(int fd)
{
	char *line = "";
	int i;
	int fd2;
	
	int status;
	char	buf[BUFF_SIZE + 1];
	size_t ret;
	char *temp;
	static char *str;
	
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp = str;
		str = ft_strjoin(str, buf);
		//free(temp);
		if (check_n(str) != -1)
			break;
	}
	printf("|");
	i = 0;
	while (i < check_n(str))
		printf("%c", *(str + i++));
	str = str + check_n(str);
}*/

int main (int argc, char **argv)
{
	int fd1;
	fd1 = argc;
	char *lin;

	printf("%s %s\n", argv[1], argv[2]);
	fd1 = open(argv[1], O_RDONLY);
	
	printf("%d, %s", get_next_line(fd1, &lin), lin);
	printf("%d, %s", get_next_line(fd1, &lin), lin);
	printf("%d, %s", get_next_line(fd1, &lin), lin);
	printf("%d, %s", get_next_line(fd1, &lin), lin);
	printf("%d, %s", get_next_line(fd1, &lin), lin);
	printf("%d, %s", get_next_line(fd1, &lin), lin);
	printf("%d, %s", get_next_line(fd1, &lin), lin);
	/*gnl(fd1);
	gnl(fd1);
	gnl(fd1);
	gnl(fd1);
	gnl(fd1);
	gnl(fd1);
	fd2 = open(argv[2], O_RDONLY);
	printf("%d %d\n", fd1, fd2);
	int i = 0;
	//printf("%d - %s\n", get_next_line(fd1, &line), line);
	while ( i <= 40)
	{
		status = get_next_line(fd1, &line);
		//printf("--------------\n");
		printf("%d %d - %s\n", fd1,  status, line);
		//free(line);
		if ((status = get_next_line(fd2, &line)) == 1)
		{
		status = get_next_line(fd2, &line);
		//printf("*************\n");
		//printf("%d %d - %s\n", fd2,  status, line);
		//free(line);
		//}
		i++;
	}
	close(fd2);*/
	close(fd1);
	return (0);
}
