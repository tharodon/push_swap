#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define A 1
# define B 0
# define MAX 1
# define MIN 0
# define ALL -999
# define BUFFER_SIZE 10

typedef struct s_stack
{
	int				count;
	struct s_stack	*next;
	struct s_stack	*back;
	struct s_stack	*next_order;
	struct s_stack	*back_order;
	_Bool			ab;
	int				divs;
	int				index;
}					t_stack;

typedef struct s_number
{
	int			first;
	int			second;
	int			third;
}				t_num;

int			ft_atoi (const char *str);
int			ft_strlen (const char *str);
int			llen(t_stack *lst, int div);
int			*pars_argc (char **argv, int *argc, _Bool is_to_fresh);
int			push_swap_check (t_stack **list_a, t_stack **list_b, \
int *stack, int args);
int			push_swap_validate (int argc, char **argv);
int			get_current_index(t_stack *el);
int			sort_three_for_a (t_stack **a, t_stack **b);
int			count_tab_chars(char **tabs);
int			check_of_valid (char **argv);
int			check_duplicate (int *stack, int size);
int			check_to_sort(t_stack **a);
int			ft_strncmp (char *s1, char *s2, size_t n);
int			utils_sort_three_for_a (t_stack **a, t_stack **b, t_num num);
int			get_next_line(int fd, char **line);
long int	ft_atoi_long (const char *str);
int			check_maxmin_int (char **argv);

char		**ft_split (char const *s, char c);
char		*ft_substr (char const *s, int start, int len);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *src);
char		*ft_strjoin (char const *s1, char const *s2);

t_stack		*lnew_el(int count);
t_stack		*get_up_neighbour(t_stack *tmp, int div);
t_stack		*get_maxmin_count_el(t_stack *lst, int div, _Bool max_or_min);
t_stack		*ul_finder_of_mid_updown(t_stack *lst, t_stack *mid);
t_stack		*ul_getmin_div(t_stack *lst);
t_stack		*ul_getmax_div(t_stack *lst);
t_stack		*ul_getmid_elcnt(t_stack *lst, int div);
t_stack		*ul_get_last(t_stack *lst);

void		*ft_calloc (size_t n, size_t len);
void		ft_bzero(void *s, size_t n);
void		ladd_to_list(t_stack **lst, t_stack *el);
void		linit(t_stack *lst);
void		ul_come_to_me(t_stack **lst, t_stack *el);
void		list_sasb(t_stack **lst, _Bool flag);
void		list_rarb(t_stack **ab, _Bool flag);
void		list_pp(t_stack **a, t_stack **b, _Bool flag);
void		list_ss(t_stack **list_a, t_stack **list_b, _Bool flag);
void		list_rrab(t_stack **lst, _Bool flag);
void		list_rrr(t_stack **list_a, t_stack **list_b, _Bool flag);
void		list_rr(t_stack **list_a, t_stack **list_b, _Bool flag);
void		sort_three (t_stack **lst_a);
void		sort_five (t_stack **lst_a, t_stack **lst_b);
void		sort_three_for_b (t_stack **lst_a, t_stack **lst_b);
void		sort_two (t_stack **a);
void		sort_two_for_b (t_stack **a, t_stack **b);
void		sort_two_for_a (t_stack **a);
void		ul_sortig_stack_b (t_stack **b, t_stack **a);
void		algorithm(t_stack **a, t_stack **b);
void		magic_algorithm(t_stack **a, t_stack **b);
void		to_complete_short_sort_by_max_div(t_stack **a);
void		run_commands(char *line, t_stack **a, t_stack **b);
void		ut_s_three (t_stack **lst_a, t_stack **lst_b, t_num num);
void		utils_five_sort (t_stack **lst_a, t_stack **lst_b, int b);
void		utils_five_sort_two (t_stack **lst_a, t_stack **lst_b);

#endif