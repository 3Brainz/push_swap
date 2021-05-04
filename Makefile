#Name
NAME = checker			

#Compiler
CC = 			gcc
CFLAGS = 		-Wall -Wextra -Werror
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
FILES =		ft_checker.c \
			ft_checker_lst.c \
			ft_moves.c \
			ft_utils.c \
			get_next_line_utils.c \
			get_next_line.c

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
