# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alhelson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/17 19:59:31 by alhelson          #+#    #+#              #
#    Updated: 2018/05/17 19:59:34 by alhelson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc -Wall -Wextra -Werror
INC=include
NAME= ft_nm

SRC_PATH=srcs
OBJ_PATH=srcs

INCLUDES =     ./include/corrupted_checker.h ./include/generic_nm.h        ./include/nm_manage.h         ./include/otool_manage.h      ./include/utilities.h
INCLUDES_GCH = ./include/corrupted_checker.h.gch ./include/generic_nm.h.gch        ./include/nm_manage.h.gch         ./include/otool_manage.h.gch      ./include/utilities.h.gch

SRC_M_CORRUPTED_CHECKER_PATH = corrupted_checker
SRC_M_GENERIC_NM_PATH        = generic_nm
SRC_M_NM_MANAGE_PATH         = nm_manage
SRC_M_OTOOL_MANAGE_PATH      = otool_manage
SRC_M_UTILITIES_PATH         = utilities
SRC_M_MAIN_PATH		     = m_main

#################################################
### COLOR
##################################################
COL_BLACK       = \033[1;30m
COL_RED         = \033[1;31m
COL_GREEN       = \033[1;32m
COL_YELLOW      = \033[1;33m
COL_BLUE        = \033[1;34m
COL_PURPLE      = \033[1;35m
COL_WHITE       = \033[1;37m

################################################
### SOURCES
###############################################
SRC_M_CORRUPTED_CHECKER = beatiful_checker.c check_32bits.c     check_64bits.c     check_fat.c        checker.c          spe_return_error.c
SRC_M_GENERIC_NM      = display_cpu_type.c nm.c               nm_64.c            nm_fat_cigam_64.c  nm_r_64.c manage_type_arch.c nm_32.c            nm_fat_cigam_32.c  nm_r_32.c
SRC_M_NM_MANAGE         = display_elem.c       handle32.c           handler64.c          nm_free_in.c display_nm.c         handle64.c           init_sect.c          sort_tab_interface.c get_n_type_symbol.c  handler32.c          make_nm_elem.c
SRC_M_OTOOL_MANAGE      = cigam_fat_otool_32.c display_cpu_otool.c  otool.c              otool_32.c           otool_64.c
SRC_M_UTILITIES         = error_file.c  ft_nbdigit.c  ft_putstr.c   ft_strlen.c   swap_if.c fake_global.c ft_putnbr.c   ft_strcmp.c   swap.c
SRC_M_MAIN		= main_nm.c main_otool.c

SRC_M_CC = $(addprefix ./$(SRC_M_CORRUPTED_CHECKER_PATH)/, $(SRC_M_CORRUPTED_CHECKER))
SRC_M_GN = $(addprefix ./$(SRC_M_GENERIC_NM_PATH)/,        $(SRC_M_GENERIC_NM))
SRC_M_NM = $(addprefix ./$(SRC_M_NM_MANAGE_PATH)/,         $(SRC_M_NM_MANAGE))
SRC_M_OM = $(addprefix ./$(SRC_M_OTOOL_MANAGE_PATH)/,      $(SRC_M_OTOOL_MANAGE))
SRC_M_U =  $(addprefix ./$(SRC_M_UTILITIES_PATH)/,         $(SRC_M_UTILITIES))
SRC_M_M =  $(addprefix ./$(SRC_M_MAIN_PATH)/,              $(SRC_M_MAIN))

###############################################
### OBJECT
##############################################

OBJ_M_CORRUPTED_CHECKER = $(patsubst %.c, %.o, $(SRC_M_CORRUPTED_CHECKER))
OBJ_M_GENERIC_NM = $(patsubst %.c, %.o, $(SRC_M_GENERIC_NM))
OBJ_M_NM_MANAGE = $(patsubst %.c, %.o, $(SRC_M_NM_MANAGE))
OBJ_M_OTOOL_MANAGE = $(patsubst %.c, %.o, $(SRC_M_OTOOL_MANAGE))
OBJ_M_UTILITIES = $(patsubst %.c, %.o, $(SRC_M_UTILITIES))
OBJ_M_MAIN = $(patsubst %.c, %.o, $(SRC_M_MAIN))

OBJ_M_CC = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_CORRUPTED_CHECKER))
OBJ_M_GN = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_GENERIC_NM))
OBJ_M_NM = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_NM_MANAGE))
OBJ_M_OM = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_OTOOL_MANAGE))
OBJ_M_U  = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_UTILITIES))
OBJ_M_M = $(addprefix ./$(OBJ_PATH)/,  $(OBJ_M_MAIN))

OBJ_ALL = $(OBJ_M_CC) $(OBJ_M_GN) $(OBJ_M_NM) $(OBJ_M_OM) $(OBJ_M_U)

####################################################
#################### RULES ########################
all: $(NAME)

$(NAME): $(OBJ_M_CC) $(OBJ_M_GN) $(OBJ_M_NM) $(OBJ_M_OM) $(OBJ_M_U) $(OBJ_M_M)
	$(CC) ./srcs/main_nm.o $(OBJ_ALL) -I$(INC) -o ft_nm
	$(CC) ./srcs/main_otool.o $(OBJ_ALL) -I$(INC) -o ft_otool

$(OBJ_M_M): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_MAIN_PATH)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_M_CC) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_CORRUPTED_CHECKER_PATH)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_M_GN) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_GENERIC_NM_PATH)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_M_NM) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_NM_MANAGE_PATH)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_M_OM) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_OTOOL_MANAGE_PATH)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_M_U) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_UTILITIES_PATH)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ_ALL) $(OBJ_M_M) $(INCLUDES_GCH)

fclean: clean
	rm -rf ft_nm ft_otool

re : fclean $(NAME)
