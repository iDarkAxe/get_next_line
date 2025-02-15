.PHONY : all clean fclean re bonus clean-lib clean-bin clean-obj debug debug-cc debug-print
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPENDANCIES = -MMD -MP
NO_DIR = --no-print-directory
MAKE := $(MAKE) -j $(NO_DIR)
NAME = libgnl.a
NAME_BONUS = libgnl_bonus.a

# Debugging flags
CFLAGS_DEBUG = -Wall -Wextra -g3 -D DEBUG=1
CC_DEBUG = clang
CC_DEBUG_CFLAGS = -g3 -D DEBUG=1 -Weverything -Wno-padded -pedantic -O2 -Wwrite-strings -Wconversion -fsanitize=address -fsanitize=leak
#############################################################################################
#                                                                                           #
#                                         DIRECTORIES                                       #
#                                                                                           #
#############################################################################################
# Source directories
P_SRC = ./

# Object directories
P_OBJ = .obj/

# Include directories
P_INC = ./

# Libraries directories
P_LIB = lib/

#############################################################################################
#                                                                                           #
#                                           FILES                                           #
#                                                                                           #
#############################################################################################
# Headers
INC = \
	get_next_line.h \
	get_next_line_bonus.h

# Source files
SRC = \
	get_next_line.c \
	get_next_line_utils.c

BONUS = \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c

#############################################################################################
#                                                                                           #
#                                        MANIPULATION                                       #
#                                                                                           #
#############################################################################################
SRCS =	\
	$(addprefix $(P_SRC), $(SRC)) 

BONUSS =	\
	$(addprefix $(P_SRC), $(BONUS)) 

# List of object files (redirect to P_OBJ)
OBJS = $(subst $(P_SRC), $(P_OBJ), $(SRCS:.c=.o))
OBJS_BONUS = $(subst $(P_SRC), $(P_OBJ), $(BONUSS:.c=.o))
P_OBJS = $(subst $(P_SRC), $(P_OBJ), $(SRCS))

# List of depedencies
DEPS = $(OBJS:%.o=%.d) $(OBJS_BONUS:%.o=%.d)

# List of header files
INCS = $(addprefix $(P_INC), $(INC))

#############################################################################################
#                                                                                           #
#                                          RULES                                            #
#                                                                                           #
#############################################################################################
all: $(NAME)

# Create push_swap executable
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(NAME_BONUS): $(OBJS_BONUS)
	ar -rcs $(NAME_BONUS) $(OBJS_BONUS)

bonus : $(NAME_BONUS)

# Custom rule to compilate all .c with there path
$(P_OBJ)%.o: $(P_SRC)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPENDANCIES) $(DEBUG_STATE) -I $(P_INC) -c $< -o $@

#############################################################################################
#                                                                                           #
#                                      Other RULES                                          #
#                                                                                           #
#############################################################################################
# Rules for clean up
clean:
	rm -rfd $(P_OBJ)

clean-lib:
	rm -rfd $(P_LIB)

clean-bin:
	rm -f $(NAME)

clean-obj:
	@$(MAKE) clean

fclean:
	@$(MAKE) clean-obj
	@$(MAKE) clean-lib
	@$(MAKE) clean-bin

re:
	@$(MAKE) fclean
	@$(MAKE) all

# Aliases
clear: clean
fclear: fclean
flcean: fclean
flcear: fclean

#############################################################################################
#                                                                                           #
#                                           DEBUG                                           #
#                                                                                           #
#############################################################################################
# Debugging rules
debug:
	@$(MAKE) $(NAME) CFLAGS="$(CFLAGS_DEBUG)"

debug-checker:
	@$(MAKE) checker CFLAGS="$(CFLAGS_DEBUG)"

debug-cc:
	@$(MAKE) $(NAME) CFLAGS="$(CC_DEBUG_CFLAGS)" CC="$(CC_DEBUG)"
	@$(MAKE) checker CFLAGS="$(CC_DEBUG_CFLAGS)" CC="$(CC_DEBUG)"

# Debugging print
debug-print:
	@$(MAKE) debug-print-project
	@$(MAKE) debug-print-separator

debug-print-separator:
	@echo ""
	@echo "$(On_Yellow)____________________$(Color_Off)"
	@echo ""

debug-print-project:
	@echo "$(Red)Project:\n\t$(Blue)$(NAME)$(Color_Off)"
	@echo ""
	@echo "$(Red)SRCS:\n\t$(Blue)$(SRCS)$(Color_Off)"
	@echo ""
	@echo "$(Red)OBJS:\n\t$(Blue)$(OBJS)$(Color_Off)"
	@echo ""
	@echo "$(Red)INCS:\n\t$(Blue)$(INCS)$(Color_Off)"

#############################################################################################
#                                                                                           #
#                                         COSMETIC                                          #
#                                                                                           #
#############################################################################################
# Reset
Color_Off=\033[0m       # Text Reset

# Regular Colors
Red=\033[0;31m
Blue=\033[0;34m
White=\033[0;37m

-include $(DEPS)% 