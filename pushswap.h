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
# define FLAG_V 1
# define FLAG_C 2
# define FLAG_O 4
# define FLAG_N 8
# define FLAG_S 16

typedef struct		s_plst
{
	int				data;
	int				mark;
	struct s_plst	*next;
}					t_plst;

typedef struct		s_pinfo
{
	// int		flag;
	char	flag[6];
	int		sign_rr;
	int		sign_rrr;
	int		rotate_a;///
	int		f_rotate_a;

	int		pos;///
	int		f_pos;
	int		diff_nbr;
	int		diff_pos;

	int		steps;
	double	counta;
	int		countb;

	int		test_count;
	int		sa;
	int		at_middle;
	int		sa_loc;
	int		top;
	int		times;
}					t_pinfo;

void				print_lst(t_plst *lst);
void				get_diff_location(int nbr, int diff, t_plst *lstb, t_pinfo *info);
int					get_location_helper(t_plst *lst, int tmp_sa);

/*
** small_sort.c
*/
void		sort_two_in_a(t_plst *lst, t_pinfo *info);
void		sort_two_in_b(t_plst *lstb, t_pinfo *info);
void	do_sort_five(t_pinfo *info, t_plst **lst, t_plst **lstb);

/*
** check_arg.c
*/
void	make_smallest_move_to_b(t_plst **lst, t_plst **lstb, t_pinfo *info);
int		get_right_nbr(t_plst *lst, t_plst *lstb, t_pinfo *info);
void		get_diff_location(int nbr, int diff, t_plst *lstb, t_pinfo *info);
int		get_location(int nbr, t_plst *lstb);
void	do_rotate_a(t_pinfo *info, t_plst **lst);

/*
** sort.c
*/
void		do_sort(t_plst **lst, t_plst **lstb, t_pinfo *info);

/*
** check_arg.c
*/
int					ck_is_nbr(char *s);
int					ck_is_int(char *s);
int					ck(int i, char *s, char **av);
int					ck_dup(char **argv);
int					check_arg(char **argv);

/*
** checker_moves.c
*/
int					start_moves(char *line, t_plst **lst, t_plst **lstb);

/*
** handle_data.c
*/
void				get_location_sa(t_plst *lst, t_pinfo *info);
void				swap_data(t_plst *lst);
void				rotate(t_plst **lst, int n);
void				push_b(t_plst **lst, t_plst **lstb);
void				push_a(t_plst **lst, t_plst **lstb);

/*
** handle_lst.c
*/
void				intert_lst_front(t_plst **lst, t_plst *new);
t_plst				*new_lst_nbr(int data);
t_plst				*new_lst(char *s);

/*
** helper.c
*/
int					count_nbr(t_plst *lst);
int					get_last_data(t_plst *lst);
int					get_smallest_a(t_plst *lst);
// int					get_location(t_plst *lst, int tmp_sa);
void				deep_free(t_plst *lst);

/*
** parse_arg.c
*/
int					check_all_inorder(t_plst *lst);
int		parse_arg(int argc, char **argv, t_plst **lst, t_pinfo *info);

/*
** sort.c
*/
void				do_sort(t_plst **lst, t_plst **lstb, t_pinfo *info);
void				do_sort_three(t_plst **lst, t_pinfo *info);

/*
** sort_helper.c
*/
int					get_times(t_plst *lst, t_pinfo *info);
int					check_at_middle(int count, t_plst *lst, t_pinfo *info);

#endif
