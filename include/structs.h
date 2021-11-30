/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:49:01 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/29 19:49:01 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define DONE 1

# define MATCH 0

# define SA 'a'
# define SB 'b'
# define SS 'c'
# define PA 'd'
# define PB 'e'
# define RA 'f'
# define RB 'g'
# define RR 'h'
# define RRA 'i'
# define RRB 'j'
# define RRR 'k'

typedef struct s_list
{
	char			*value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_ps
{
	int				*sorted_array;
	int				net_lst;
	int				min;
	int				max;
	int				median;
	int				*meds_array;
	int				num_of_meds;
	int				cnt_sorted;
	char			*result;
}					t_ps;

#endif
