/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:55:53 by lwang             #+#    #+#             */
/*   Updated: 2017/05/19 17:55:58 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	get_location_sa(t_plst *lst, t_pinfo *info)
{
	info->counta = count_nbr(lst);
	info->sa = get_smallest_a(lst);
	info->times = get_times(lst, info);
}

void	do_sort_three(t_plst **lst, t_pinfo *info)
{
	int	last_data;

	last_data = get_last_data(*lst);
	if ((*lst)->data > (*lst)->next->data && (*lst)->next->data > last_data)//10 5 2
	{
		ft_printf("ra\n");
		ft_printf("sa\n");
		rotate(lst, 1);
		swap_data(*lst);
		info->steps = info->steps + 2;
	}
	if ((*lst)->data > last_data  && last_data > (*lst)->next->data)//10 2 5
	{
		ft_printf("ra\n");
		rotate(lst, 1);
		info->steps = info->steps + 1;
	}
	if ((*lst)->next->data > (*lst)->data && (*lst)->data > last_data)//5 10 2
	{
		ft_printf("rra\n");
		rotate(lst, 2);
		info->steps = info->steps + 1;
	}
	if ((*lst)->next->data > last_data && last_data > (*lst)->data)//2 10 5
	{
		ft_printf("sa\n");
		ft_printf("ra\n");
		swap_data(*lst);
		rotate(lst, 1);
		info->steps = info->steps + 2;
	}
	if (last_data > (*lst)->data && (*lst)->data > (*lst)->next->data)//5 2 10
	{
		ft_printf("sa\n");
		swap_data(*lst);
		info->steps = info->steps + 1;
	}
}

void	do_sort(t_plst **lst, t_plst **lstb, t_pinfo *info)
{
	int total;

	total = 0;
	total = count_nbr(*lst);
	info->steps = 0;
	info->countb =0;
	while (total - 3)
	{
		info->top = 0;
		get_location_sa(*lst, info);
		info->steps = info->steps + info->times + 1;
		while (info->times)
		{
			ft_printf("%s\n", info->top == 1 ? "ra" : "rra");
			info->times--;
		}
		rotate(lst, info->sa_loc);
		ft_printf("pb\n");
		push_b(lst, lstb);
		if (info->at_middle == 2)
		{
			ft_printf("sb\n");
			swap_data(*lstb);
			info->at_middle = 0;
			info->steps = info->steps + 1;
		}
		total--;
	}
	if (total == 3)
		do_sort_three(lst, info);
	info->countb = count_nbr(*lstb);
	info->steps = info->steps + info->countb;
	while (info->countb)
	{
		ft_printf("pa\n");
		push_a(lst, lstb);
		info->countb--;
	}
}