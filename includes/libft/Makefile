NAME	=	libft.a
FLAGS	= -Wall -Wextra -Werror
CC	=	gcc
HEADER = includes/libft/libft.h
DIRBUILD = dirbuild
SOURCE	= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat \
		  ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_strdup ft_substr ft_strjoin ft_strtrim ft_split \
		  ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd  ft_calloc ft_toupper ft_tolower ft_lstlast ft_lstnew ft_lstadd_back

OBJ = $(addprefix $(DIRBUILD)/, $(SOURCE:=.o))

SO_BONUS = ft_lstadd_front ft_lstsize   ft_lstclear ft_lstiter ft_lstmap ft_lstdelone

BO_OBJ = $(addprefix $(DIRBUILD)/, $(SO_BONUS:=.o))

$(DIRBUILD)/%.o :  %.c $(HEADERS)
	@mkdir -p $(@D)
	@gcc $(CFLAGS) $(INC) -c $< -o $@


all : $(NAME)

$(NAME): $(OBJ)
	@ar	-rcs $(NAME) $(OBJ)

bonus:	$(BO_OBJ)
	@ar -rcs $(NAME) $(BO_OBJ)

clean:
	@rm	-rf	$(DIRBUILD)
fclean:	clean
	@rm -rf	$(NAME)
	@echo "\033[0;95m Everything is fcleaned in libft!\033[m"

re: fclean	all

.PHONY: all clean fclean re 
