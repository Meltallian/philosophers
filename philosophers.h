#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <errno.h>

# define PP ft_printf("prout")
# define DD(xxx) ft_printf("%d", xxx)
# define SS(xxx) ft_printf("%s", xxx)
# define CC(xxx) ft_printf("%c", xxx)

typedef struct s_data
{

}			t_data;

#endif /* PHILOSOPHERS_H */