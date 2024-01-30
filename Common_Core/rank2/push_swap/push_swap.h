/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:00:51 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/30 21:34:09 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "./libft/ft_printf.h"

void	swap(t_list **lst, char stack);
void	swap_ss(t_list **lst_a, t_list **lst_b);
void	rotate(t_list **lst, char stack);
void	rotate_ss(t_list **lst_a, t_list **lst_b);
void	rev_rotate(t_list **lst, char stack);
void	rev_rotate_ss(t_list **lst_a, t_list **lst_b);
void	push(t_list **lst_rec, t_list **lst_giv, char stack);
void	print_error(t_list **lst_a, t_list **lst_b);
int		ft_nb_len(int nb);
void	division(t_list **stc_a, t_list **stc_b, int size);
void	order_stc(t_list **stc_a, t_list **stc_b, int size);
void	rev_division(t_list **stc_a, t_list **stc_b, int size);
int		checker(t_list **stc, char c);
