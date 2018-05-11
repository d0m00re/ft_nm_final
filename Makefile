CC=gcc
#CFLAGS= -Wall -Wextra -Werror
INC= include
SRC_PATH= srcs
OBJ_PATH = srcs

INCLUDES = ./include/corrupted_checker.h ./include/generic_nm.h        ./include/nm_manage.h         ./include/otool_manage.h      ./include/utilities.h

NAME= nm
NAME2 = otool

SRC_M_MANAGE_NM_PATH = nm_manage
SRC_M_UTILITIES_PATH = utilities
SRC_M_GENERIC_NM_PATH = generic_nm
SRC_M_OTOOL_PATH = otool_manage
SRC_M_CORRUPTED_PATH = corrupted_checker

SRC_M_MANAGE_NM = make_nm_elem.c display_elem.c sort_tab_interface.c init_sect.c get_n_type_symbol.c handle64.c display_nm.c handle32.c\
			handler32.c handler64.c nm_free_in.c
SRC_M_UTILITIES = ft_strcmp.c ft_strlen.c swap.c swap_if.c ft_putnbr.c ft_nbdigit.c ft_putstr.c fake_global.c error_file.c

SRC_M_GENERIC_NM = nm_32.c   nm_64.c   nm_r_32.c nm_r_64.c display_cpu_type.c nm_fat_cigam_32.c manage_type_arch.c nm.c nm_fat_cigam_64.c

SRC_M_OTOOL = otool_64.c otool_32.c cigam_fat_otool_32.c otool.c display_cpu_otool.c

SRC_M_CORRUPTED = beatiful_checker.c check_32bits.c checker.c check_64bits.c check_fat.c spe_return_error.c

###############
##    OBJECT

OBJ_M_MANAGE_NM =	$(patsubst %.c, %.o, $(SRC_M_MANAGE_NM))
OBJ_M_M_NM =		$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_MANAGE_NM))

OBJ_M_UTILITIES =	$(patsubst %.c, %.o, $(SRC_M_UTILITIES))
OBJ_M_UTILI =		$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_UTILITIES))

OBJ_M_GENERIC_NM =	$(patsubst %.c, %.o, $(SRC_M_GENERIC_NM))
OBJ_M_GEN =		$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_GENERIC_NM))

OBJ_M_OTOOL =		$(patsubst %.c, %.o, $(SRC_M_OTOOL))
OBJ_M_OT =		$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_OTOOL))

OBJ_M_CORRUP =		$(patsubst %.c, %.o, $(SRC_M_CORRUPTED))
OBJ_M_COR =		$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_CORRUP))

SRC_M_M_NM =		$(addprefix ./$(SRC_M_MANAGE_NM_PATH)/, $(SRC_M_MANAGE_NM))
SRC_M_UTILI =		$(addprefix ./$(SRC_M_UTILITIES_PATH)/, $(SRC_M_UTILITIES))
SRC_M_GEN =		$(addprefix ./$(SRC_M_GENERIC_NM_PATH)/, $(SRC_M_GENERIC_NM)) 
SRC_M_OT =		$(addprefix ./$(SRC_M_OTOOL_PATH)/, $(SRC_M_OTOOL))
SRC_M_COR =		$(addprefix ./$(SRC_M_CORRUPTED_PATH)/, $(SRC_M_CORRUPTED))

########################################################################

#####		###############################
 ##################### RULES ###             #
#####		#############################

.PHONY: all lib clean $(NAME)

all: $(NAME)

$(NAME): $(OBJ_M_M_NM) $(OBJ_M_UTILI) $(OBJ_M_GEN) $(OBJ_M_OT) $(OBJ_M_COR)
	echo "[FT_NM]"
	echo "[FT_OTOOL]"
	@$(CC) main_nm.c -o ft_nm $(OBJ_M_M_NM) $(OBJ_M_UTILI) $(OBJ_M_GEN) $(OBJ_M_COR) -I ./$(INC)
	@$(CC) main_otool.c -o ft_otool $(OBJ_M_M_NM) $(OBJ_M_UTILI) $(OBJ_M_GEN) $(OBJ_M_OT) $(OBJ_M_COR) -I ./$(INC)
	@$(CC) main_checker.c -o ft_checker $(OBJ_M_M_NM) $(OBJ_M_UTILI) $(OBJ_M_GEN) $(OBJ_M_OT) $(OBJ_M_COR) -I ./$(INC)

$(OBJ_M_M_NM) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_MANAGE_NM_PATH)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@echo "COMPIL [MANAGE]"

$(OBJ_M_UTILI) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_UTILITIES_PATH)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@echo "COMPIL [UTILITIE]"

$(OBJ_M_GEN) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_GENERIC_NM_PATH)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@echo "COMPIL [GENERIC NM]"

$(OBJ_M_OT) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_OTOOL_PATH)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@echo "COMPIL [GENERIC OTOOL]"

$(OBJ_M_COR) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_CORRUPTED_PATH)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	echo "COMPIL [GENERIC CORRUPTED]"

clean:
	@rm -f $(OBJ_M_M_NM) $(OBJ_M_UTILI) $(OBJ_M_GEN) $(OBJ_M_OT) $(OBJ_M_COR)
	@echo "[CLEAN]"

fclean: clean
	@rm -f ft_nm ft_otool ft_checker
	@echo "DELETE [$(NAME)]"

re: fclean all
