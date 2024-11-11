NAME = array
COMPILER := c++
FLAGS :=	-Wall -Werror -Wextra -std=c++98

SOURCE_FOLDER :=
MAIN := main.cpp
CLASS_FOLDER := class/
CLASSES := $(addprefix $(CLASS_FOLDER), )
FUNCTIONS :=
SOURCE := $(addprefix $(SOURCE_FOLDER), $(MAIN) $(CLASSES) $(FUNCTIONS))

OBJECTS_FOLDER = bin/
OBJECTS = $(SOURCE:$(SOURCE_FOLDER)%.cpp=$(OBJECTS_FOLDER)%.o)

$(OBJECTS_FOLDER)%.o:$(SOURCE_FOLDER)%.cpp $(SOURCE_FOLDER)Array.hpp $(SOURCE_FOLDER)Array.tpp
	@mkdir -p $(OBJECTS_FOLDER)
	@$(COMPILER) $(FLAGS) -o $@ -c $< && echo "Compilando: $(notdir $<)"


all: $(NAME)
	@echo "$(NAME) está pronto!"

teste: $(OBJECTS)
	@echo "Entrou aqui $(OBJECTS)"

$(NAME): $(OBJECTS)
	@$(COMPILER) $(FLAGS) -o $(NAME) $(OBJECTS) && echo "Compilando $(NAME)"

clean:
	@rm -rf $(OBJECTS_FOLDER)

fclean: clean
	@rm -f $(NAME)

re: fclean all