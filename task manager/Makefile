NAME = ft_gkrellm

CPP_FILES =  main\
			\
			RamModule \
			CpuModule \
			CatModule\
			UserModule\
			BonusModule\
			\
			DisplayClass\
			RamDisplay \
			CpuDisplay \
			UserDisplay \
			PonyDisplay \
			BonusDisplay \
			NcursesDisplay\
			\
			SDL_handler


HPP_FILES = RamModule \
			CpuModule \
			UserModule\
			CatModule\
			IMonitorModule \
			BonusModule\
			\
			IMonitorDisplay \
			DisplayClass\
			RamDisplay \
			CpuDisplay \
			UserDisplay \
			PonyDisplay \
			BonusDisplay \
			NcursesDisplay\
			\
			SDL_handler

HEADERS = -I./inc

HDRS = $(addprefix inc/, $(addsuffix .hpp, $(HPP_FILES)))
SRC = $(addprefix src/, $(addsuffix .cpp, $(CPP_FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(CPP_FILES)))

COMPILER = clang++
FLAGS = -Wall -Wextra -Werror 

INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-F./frameworks/
FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer
 
all:  $(NAME)

$(NAME): $(OBJ)
	@$(COMPILER) -o $(NAME) $(FLAG) $(OBJ) $(FRAMEWORKS) -lncurses


$(OBJ): obj/%.o : src/%.cpp $(HDRS)
	@$(COMPILER) -o $@ $(HEADERS) $(INCLUDES) -c $< 

clean:
	@rm -f $(OBJ)
	 

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ)
	 
re: fclean all