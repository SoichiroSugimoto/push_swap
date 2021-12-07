/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:48:55 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/08 00:45:55 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_NUMBER_H
# define SORT_NUMBER_H

# include "push_swap.h"

int		get_lstmin(t_list *lst);
int		get_lstsecond(t_list *lst);
int		get_lstthird(t_list *lst);
int		get_lstmax(t_list *lst);
int		get_bottom_num(t_list *lst);
int		confirm_sorted(t_list *lst);
int		confirm_sort_3num(t_list *lst);
int		check_sorted(t_list *lst_a, t_list *lst_b);
void	sort_3num(t_list **lst, t_ps *info);
void	sort_2num(t_list **lst, t_ps *info);
void	under3_sort(t_list **lst, t_ps *info);
void	sort_3num_b(t_list **lst, t_ps *info);
void	sort_2num_b(t_list **lst, t_ps *info);
int		under3_sort_b(t_list **lst, t_ps *info);
void	rver_sort_3num_b(t_list **lst, t_ps *info);
void	under6_sort(t_list **lst_a, t_list **lst_b, t_ps *info);
void	swap(int *x, int *y);
int		partition(int array[], int left, int right);
void	quick_sort(int array[], int left, int right);
void	lst_to_array(t_list *lst, int array[]);
int		get_median(t_list *lst);
int		get_median_2nd(t_list *lst);
int		not_sorted(t_list *lst);
void	sort_number(t_list **lst_a, t_list **lst_b);

//  arrange_output.c
char	*join_char(char *dst, char src);
int		arrange_marge_output(char *str, int i);
void	arrange_output(char *str, int i);
void	print_output(char *str);

//  get_struct.c
void	catch_lstmax(t_list **lst, t_ps *info);
int		get_cnt_sorted(t_list **lst_a, t_ps *info);
void	init_struct_ps(t_list *lst_a, t_ps *info);

//  over7_sort.c
void	over7_sort(t_list **lst_a, t_list **lst_b, t_ps *info);
int		get_median_new(t_list *lst);
void	set_marks_array(int med, int **meds_array, t_ps *info);
void	pa_med_first(t_list **lst_a, t_list **lst_b, int med, t_ps *info);
void	prepare_toleave(t_list **lst_a, t_list **lst_b, t_ps *info);
void	pa_toleave_three(t_list **lst_a, t_list **lst_b, t_ps *info);
void	pa_toleave_half(t_list **lst_a, t_list **lst_b, t_ps *info);
void	sortb_n_set(t_list **lst_a, t_list **lst_b, t_ps *info);
int		get_proper_mark(t_list **lst_a, t_ps *info);
void	pb_till_mark(t_list **lst_a, t_list **lst_b, t_ps *info);
int		cnt_to_marks(t_list **lst_a, t_ps *info);
void	first_divi(t_list **lst_a, t_list **lst_b, t_ps *info);
int		cnt_tofix_intarray(t_ps *info, int pb_mark);
void	fix_pbmarks_array(t_ps *info, int **marks_array, int pb_mark);

//  check_sorted.c
int		check_sorted(t_list *lst_a, t_list *lst_b);

#endif