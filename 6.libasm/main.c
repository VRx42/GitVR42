 
#include "libasm.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int		fd;
	int 	ret;
	char 	b[100];
	char	b2[100];
	char	*str11 = "Bonjour";
	char	*str22 = "Ok";

	fd = open("text.txt", O_RDONLY);

	printf("\033[1;31m");
	printf("      ft_read\n\n");
	printf("\033[0m");
	ret = read(fd, b, 99);
	b[ret] = 0;
	printf("ret %d: %s\n", ret, b);
	close(fd);
	fd = open("text.txt", O_RDONLY);
	ret = ft_read(fd, b2, 99);
	b2[ret] = 0;
	printf("ft_ret %d: %s\n", ret, b2);
	close(fd);
	
	char	c[100];


	fflush(0);
	printf("\n");
	fd = open("fail.txt", O_RDONLY);
	ret = read(fd, c, 99);
	c[ret] = 0;
	printf("ret %d: %s\n", ret, c);
	ret = ft_read(fd, c, 99);
	c[ret] = 0;
	printf("ft_ret %d: %s\n", ret, c);
	close(fd);

	fd = open("text.txt", O_RDONLY);
	ret = ft_read(fd, b, 3);
	b[ret] = 0;
	printf("\nret %d: %s\n", ret, b);
	close(fd);

	fflush(0);
	printf("\n\n------------------------\n\n");
	printf("\033[1;31m");
	printf("      ft_write\n\n");
	printf("\033[0m");
	fd = open("text2.txt", O_WRONLY);
	ft_write(fd, "a", 1);
	ft_write(fd, "\ntestde4", 4);
	close(fd);
	printf("\n");
	ft_write(1, "Bon\n", 4);
	ft_write(1, "Hello world!\n", 13);
	
	fflush(0);
	printf("\n\n------------------------\n\n");
	printf("\033[1;31m");
	printf("      ft_strlen\n\n");
	printf("\033[0m");
	printf("strlen de %s = %li\n", str11, (strlen(str11)));
	printf("ft_strlen de %s = %li\n", str11, (ft_strlen(str11)));
	printf("strlen de %s = %li\n", str22, (strlen(str22)));
	printf("ft_strlen de %s = %li\n", str22, (ft_strlen(str22)));
	printf("strlen de %s = %li\n", "Bonjour a tous", (strlen("Bonjour a tous")));
	printf("ft_strlen de %s = %li\n", "Bonjour a tous", (ft_strlen("Bonjour a tous")));


	fflush(0);
	printf("\n\n------------------------\n\n");
	printf("\033[1;31m");
	printf("      ft_strcpy\n\n");
	printf("\033[0m");
	char str1[]="Hello world !"; 
    char str2[] = "GeeksforGeeks"; 
    char str3[40]; 
    char str4[40]; 
    char str5[] = "GfG"; 
	char str6[40];
    ft_strcpy(str2, str1); 
    ft_strcpy(str3, "Copy successful"); 
    ft_strcpy(str4, str5);
	ft_strcpy(str6, "Bonjour a tous, lorem ipsum dolor sit amet");
    printf ("str1: %s\nstr2: %s\nstr3: %s\nstr4: %s\nstr6: %s\n", str1, str2, str3, str4, str6);
	
	fflush(0);
	printf("\n\n------------------------\n\n");
	printf("\033[1;31m");
	printf("      ft_strcmp\n");
	printf("\033[0m");
	printf("ret: %i\n", strcmp("", ""));  
	printf("ft_ret: %i\n", ft_strcmp("", ""));
    printf("ret: %i\n", strcmp("", "ABCD"));
    printf("ft_ret: %i\n", ft_strcmp("", "ABCD"));
    printf("ret: %i\n", strcmp("ABCD", ""));  
    printf("ft_ret: %i\n", ft_strcmp("ABCD", ""));  
    printf("ret: %i\n", strcmp("ABCD", "abcdEghe")); 
    printf("ft_ret: %i\n", ft_strcmp("ABCD", "abcdEghe"));
    printf("ret: %i\n", strcmp("GeeksForGeeks", "GeeksForGeeks"));
    printf("ft_ret: %i\n", ft_strcmp("GeeksForGeeks", "GeeksForGeeks"));
    printf("ret: %i\n", strcmp("GeeksForGeeks", "GeeksForGedks"));  
    printf("ft_ret: %i\n", ft_strcmp("GeeksForGeeks", "GeeksForGedks"));  

	fflush(0);
	printf("\n\n------------------------\n\n");
	printf("\033[1;31m");
	printf("      ft_strdup\n\n");
	printf("\033[0m");
	char *dest;
	dest = ft_strdup("Bonjour a tous");
	printf("%s\n", dest);
	free(dest);
	dest = ft_strdup("Bonjour");
	printf("%s\n", dest);
	free(dest);
	dest = ft_strdup("Bonjour a tous, lorem ipsum dolor sit amet");
	printf("%s\n", dest);
	free(dest);
	dest = ft_strdup("T");
	printf("%s\n", dest);
	free(dest);

	return(0);
}
