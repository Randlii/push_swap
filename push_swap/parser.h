#ifndef parser_h
#define parser_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_nd
{
	int num;
	int index;
	int flag;
	struct s_nd *next;
	struct s_nd *prev;
}	t_nd;
typedef struct s_all
{
	t_nd *stack_a;
	t_nd *stack_b;
	int size_a;
	int size_b;
	int min;
	int med;
	int max;
	int min_a;
}		t_all;

size_t	ft_strlen(const char *s);
char *ft_substr(char const *s, unsigned int start, size_t len);
char** ft_split(char const *s, char c);
int ft_isdigit(int c);
int	ft_atoi(const char *str);
char* ft_strjoin(char const *s1, char const *s2);
char* ft_strdup(const char *s1);

#endif
