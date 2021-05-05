#Name
NAME = push_swap			

#Compiler
CC = 			gcc
CFLAGS = 		-Wall -Wextra -Werror -g
CFLAG = 		-c
OFLAG =			-o
IFLAG =			-I

#Norm
NORM =			norminette

#Shell
MKDIR =			mkdir -p
RM =			rm -rf

#Directories
SRCDIR = 		./srcs
OBJDIR =  		./objs
INCDIR = 		./incs

#Files
FILES =		ft_lst_utils1.c \
			ft_lst_utils2.c \
			ft_moves_executor.c \
			ft_moves.c \
			ft_parsing_checks.c \
			ft_utils.c \
			get_next_line_utils.c \
			get_next_line.c \
			ft_filler.c \
			push_swap.c

#Srcs
SRCS = 			$(foreach FILE, $(FILES), $(shell find $(SRCDIR) -name $(FILE)))

#Objs
OBJS = 			$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRCS:.c=.o))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(IFLAG) $(INCDIR) $(CFLAG) $(OFLAG) $@ $< 

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(OFLAG) $(NAME)

norminette:
	@$(NORM) $(shell find $(SRCDIR) -name *.c)
	@$(NORM) $(shell find $(INCDIR) -name *.h)

clean:
	@$(RM) $(OBJDIR) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all norminette clean fclean re
