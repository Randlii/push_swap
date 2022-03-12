#include "parser.h"
#include <stdio.h>
#include <unistd.h>

void	error(void)
{
	write(1,"Error\n", 6);
	exit(EXIT_SUCCESS);
}

void	free_arr(char **arr, int flag)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	if (flag)
		error();
}

int *check_arg(char **arr, int *len)
{
	int			i;
	int			j;
	int *num;
	num = malloc(sizeof(arr) * sizeof(int *));
	i = -1;
	while (arr[++i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '-')
				j++;
			if (!(ft_isdigit(arr[i][j])))
				free_arr(arr, 1);
			j++;
		}
		num[i] = ft_atoi(arr[i]);
	}
	*len = i;
	return(num);
}

char	**gline(char **str)
{
	int		i;
	char	*line;
	char	*tmp;
	char	**arr;

	i = 1;
	line = ft_strdup(str[i]);
	while (str[++i])
	{
		tmp = line;
		line = ft_strjoin(line, " ");
		free(tmp);
		tmp = line;
		line = ft_strjoin(line, str[i]);
		free(tmp);
	}
	arr = ft_split(line, ' ');
	free(line);
	return (arr);
}

void double_check(int *num, int len)
{
	int i;	
	int j;

	i = 0;
	j = 0;
	while(i < len)
	{
		j = i + 1;
		while(j < len)
		{
			if(num[i] == num[j])
			{
				free(num);
				error();
			}
			j++;
		}
		i++;
	}
}

void addstk(t_all *all, int *num, int len)
{
	int *nsort;
	int *sort;
	int i;

	nsort = malloc(sizeof(int) * len);
	sort = malloc(sizeof(int) * len);
	i = 0;
	while(i < len)
	{

		nsort[i] = num[i];
		sort[i] = num[i];
		i++;
	}
}

void	babblesrt(t_all *all, int *sort, int *nsort, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;

	while (i < len)
	{
		j = 0;
		while (j < (len - 1 - i))
		{
			if (sort[j] > sort[j + 1])
			{
				tmp = sort[j + 1];
				sort[j + 1] = sort[j];
				sort[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

t_nd	*newlst(int num, int index)
{
	t_nd	*list;

	list = malloc(sizeof(t_nd));
	if (list == NULL)
		return (NULL);
	list->num = num;
	list->flag = 0;
	list->index = index;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	lstadd_back(t_nd **stack_a, t_nd *new)
{
	t_nd	*begin;

	if (new == NULL)
		return ;
	begin = *stack_a;
	if (begin)
	{
		if (begin->prev)
		{
			begin->prev->next = new;
			new->prev = begin->prev;
			new->next = begin;
			begin->prev = new;
		}
		else
		{
			begin->prev = new;
			begin->next = new;
			new->prev = begin;
			new->next = begin;
		}
	}
	else
		*stack_a = new;
	return ;
}
void	create_stack(t_all *all, int *sort, int *not_sort, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (not_sort[i] == sort[j])
			{
				lstadd_back(&all->stack_a, newlst(not_sort[i], j + 1));
				j++;
				break ;
			}
			j++;
		}
		i++;
	}
	free(not_sort);
	free(sort);
}


int main(int argc, char *argv[])
{

	int *num;
	char** arr;
	int len;
	arr = gline(argv);
	num = check_arg(arr, &len);
	double_check(num, len);
	int j = 0;
	while(j < len)
	printf("%d", num[j++]);


}
