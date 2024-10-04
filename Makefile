# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 14:28:54 by trsmith           #+#    #+#              #
#    Updated: 2024/10/04 09:28:52 by trsmith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(addsuffix .c, ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit \
		ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset \
		ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_split ft_strchr ft_strdup ft_striteri \
		ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr \
		ft_strtrim ft_substr ft_tolower ft_toupper ft_atol ft_wordcount ft_strcmp)

OBJS := $(SRC:%.c=%.o)

BONUS_SRC = $(addsuffix .c, ft_lstnew ft_lstadd_front ft_lstadd_back ft_lstsize ft_lstlast \
		ft_lstdelone ft_lstclear ft_lstiter ft_lstmap)

BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

INC_DIR = .

CPPFLAGS = -I$(INC_DIR)

RM = rm -f

$(NAME): $(OBJS) 
		ar rcs $(NAME) $(OBJS)

%.o: %.cc
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

all: $(NAME)

clean:
	$(RM) $(NAME) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
		ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all re fclean clean
