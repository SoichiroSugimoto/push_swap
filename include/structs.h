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
	char			*result;
	int				median;
	int				*meds;
	int				num_of_meds;
	int				net_lst;
}					t_ps;

#endif
