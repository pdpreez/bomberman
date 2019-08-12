# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 13:36:13 by ppreez            #+#    #+#              #
#    Updated: 2019/08/12 10:04:16 by ppreez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bomberman

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
SO_PATH = ./shared/
G_SRC_PATH = $(SRC_PATH)graphics/
DEP_PATH = ./dependencies

SRC_FILE = main.cpp Game.cpp

OBJ_FILE = $(SRC_FILE:%.cpp=%.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))

CCFLAGS = -Wall -Wextra -Werror
CSTD = -std=c++17
CC = clang++ $(CSTD) $(CCFLAGS)
CMAKE = ~/.brew/Cellar/cmake/3.15.1/bin/cmake

GLFW = -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
GLFWA_INC = $(DEP_PATH)/glfw/src/libglfw3.a
GLFW_INC = -I $(DEP_PATH)/glfw/include/
GLAD_INC = -I $(DEP_PATH)/glad/include/
GLM_INC = -I $(DEP_PATH)/glm/

ASSIMP_INC = -I $(DEP_PATH)/assimp/include/

all: $(NAME)

install: $(OBJ_PATH) setup glad

cmake:
	cmake_install

homebrew:
	sh -c "$$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
	reset

$(NAME): $(SRC_PATH) $(OBJ_PATH) $(INC_PATH) $(OBJ) $(SO_PATH) shared_obj
	$(CC) -o $@ $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) -I$(INC_PATH) $(GLFW_INC) $(GLAD_INC) $(GLM_INC) -o $@ -c $<

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(INC_PATH):
	mkdir -p $(INC_PATH)

$(SRC_PATH):
	mkdir -p $(SRC_PATH)

$(DEP_PATH):
	mkdir -p $(DEP_PATH)

$(SO_PATH):
	mkdir -p $(SO_PATH)

setup: $(DEP_PATH)
	git submodule init
	git submodule update

shared_obj: opengl

opengl:
	$(CC) -c $(G_SRC_PATH)OpenGL.cpp -o $(OBJ_PATH)OpenGL.o -I $(INC_PATH) $(GLAD_INC) $(GLFW_INC) $(GLM_INC)
	$(CC) -c $(G_SRC_PATH)Shader.cpp -o $(OBJ_PATH)Shader.o -I $(INC_PATH) $(GLAD_INC) $(GLFW_INC) $(GLM_INC)
	$(CC) -shared $(OBJ_PATH)OpenGL.o $(OBJ_PATH)Shader.o $(OBJ_PATH)glad.o -o $(SO_PATH)OpenGL.so $(GLFWA_INC) $(GLFW)

glad: $(DEP_PATH)/glad/src/glad.c $(OBJ_PATH)
	~/.brew/Cellar/cmake/3.15.1/bin/cmake -S $(DEP_PATH)/glfw/ -B $(DEP_PATH)/glfw/
	make -C $(DEP_PATH)/glfw/
	gcc -I $(DEP_PATH)/glad/include/ -c $(DEP_PATH)/glad/src/glad.c -o ./obj/glad.o

assimp:
	~/.brew/Cellar/cmake/3.15.1/bin/cmake -S $(DEP_PATH)/assimp/ -B $(DEP_PATH)/assimp/
	make install -C $(DEP_PATH)/assimp/

cmake_install:
	~/.brew/bin/brew install cmake

clean:
	/bin/rm -rf $(OBJ)
	/bin/rm -rf obj/glad.o
	/bin/rm -rf $(OBJ_PATH)OpenGL.o
	/bin/rm -rf $(OBJ_PATH)Shader.o
	/bin/rm -rf $(SO_PATH)OpenGL.so

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
