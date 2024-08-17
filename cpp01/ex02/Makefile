NAME = brain
COMPILER := c++
FLAGS :=	-Wall -Werror -Wextra -std=c++98

SOURCE_FOLDER := src/
MAIN := main.cpp
SOURCE := $(MAIN)

OBJECTS_FOLDER = bin/
OBJECTS = $(SOURCE:%.cpp=$(OBJECTS_FOLDER)%.o)

$(OBJECTS_FOLDER)%.o:%.cpp
	@mkdir -p $(OBJECTS_FOLDER)
	@$(COMPILER) $(FLAGS) -o $@ -c $< && echo "Compilando: $(notdir $<)"


all: $(NAME)
	@echo "$(NAME) está pronto!"

$(NAME): $(OBJECTS)
	@$(COMPILER) $(FLAGS) -o $(NAME) $(OBJECTS) && echo "Compilando $(NAME)"

clean:
	@rm -rf $(OBJECTS_FOLDER)

fclean: clean
	@rm -f $(NAME)

re: fclean all
