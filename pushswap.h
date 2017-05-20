/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:43:00 by lwang             #+#    #+#             */
/*   Updated: 2017/05/16 10:43:02 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"

typedef struct		s_plst
{
	int data;
	int group;
	struct s_plst *next;
}					t_plst;

typedef struct		s_pinfo
{
	int steps;
	double counta;
	int countb;
	// int lasta;
	// int lastb;
	int sa;
	// int tmp_sa;
	int at_middle;
	int sa_loc;
	int top;
	int times;
}					t_pinfo;


/*
** check_arg.c 
*/
int		ck_is_nbr(char *s);
int		ck_is_int(char *s);
int		ck(int i, char *s, char **av);
int		ck_dup(char **argv);
int		check_arg(char **argv);

/*
** handle_data.c
*/
void	swap_data(t_plst *lst);
void	rotate(t_plst **lst, int n);
void	push_b(t_plst **lst, t_plst **lstb);
void	push_a(t_plst **lst, t_plst **lstb);

/*
** handle_lst.c 
*/
void	intert_lst_front(t_plst **lst, t_plst *new);
// void	intert_lst_end(t_plst **lst, t_plst *new);
t_plst	*new_lst_nbr(int data);
t_plst	*new_lst(char *s);
void	print_lst(t_plst *lst);

/*
** helper.c
*/
int		count_nbr(t_plst *lst);
int		get_last_data(t_plst *lst);
int		get_smallest_a(t_plst *lst);
int		get_location(t_plst *lst, int tmp_sa);
void	deep_free(t_plst *lst);

/*
** parse_arg.c
*/
int		check_all_inorder(t_plst *lst);
int		parse_arg(char **argv, t_plst **lst);

/*
** sort.c
*/
void	do_sort(t_plst **lst, t_plst **lstb, t_pinfo *info);
void	do_sort_three(t_plst **lst, t_pinfo *info);
void	get_location_sa(t_plst *lst, t_pinfo *info);

/*
** sort_helper.c
*/
int		get_times(t_plst *lst, t_pinfo *info);
int		check_at_middle(int count, t_plst *lst, t_pinfo *info);


#endif
