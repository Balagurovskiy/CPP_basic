//
// Created by Olexiy BALAGUROVSKIY on 2019-07-07.
//

#ifndef SDL_HANDLER_HPP
#define SDL_HANDLER_HPP

//Using SDL, SDL_image, standard IO, and strings
# include <curses.h>
# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
# include <sstream>
# include <vector>
# include <map>
# include <list>
# include <algorithm>
# include <ncurses.h>
# include <curses.h>
# include <thread>
# include <unistd.h>
# include <limits.h>
# include <ctime>
# include <sys/utsname.h>
# include <numeric>
# include <stdio.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/sysctl.h>

# include "SDL2/SDL.h"
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"

# include "time.h"

#define W  1280
#define H  720

class SDL_Handler {
	public:
		SDL_Handler(void);
		SDL_Handler(SDL_Handler const & src);
		SDL_Handler		&operator=(SDL_Handler const & src);
		~SDL_Handler(void);

		SDL_Window* getWin() const;
		SDL_Renderer* getRender() const;
		SDL_Texture* getTexture() const;

		void loadMedia(std::string path);
		SDL_Texture* loadTexture( std::string path );

		bool isInited(void) const;
		bool isLoaded(void) const;

		void initCat();

		SDL_Texture* getCat();

	private:
		//The window we'll be rendering to
		SDL_Window* gWindow;
		//The window renderer
		SDL_Renderer* gRenderer;
		//Current displayed texture
		SDL_Texture* gTexture;

		SDL_Texture* cat[2];


		bool init;
		bool load_media;

		int catId;
};


#endif
