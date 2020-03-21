
# include <iostream>

# include "RamModule.hpp"
# include "CpuModule.hpp"
# include "UserModule.hpp"
# include "CatModule.hpp"
# include "BonusModule.hpp"

# include "RamDisplay.hpp"
# include "CpuDisplay.hpp"
# include "PonyDisplay.hpp"
# include "UserDisplay.hpp"
# include "BonusDisplay.hpp"

# include "NcursesDisplay.hpp"

#include  "SDL_Handler.hpp"

void renderBackGround(SDL_Handler *sdl_Handler){
	SDL_Rect bottomViewport;
	bottomViewport.x = 0;
	bottomViewport.y = 0;
	bottomViewport.w = W;
	bottomViewport.h = H;
	SDL_RenderSetViewport( sdl_Handler->getRender(), &bottomViewport );
	//Render texture to screen
	SDL_RenderCopy( sdl_Handler->getRender(), sdl_Handler->getTexture(), NULL, NULL );
}

void renderCat(SDL_Handler *sdl_Handler){
	SDL_Rect catViewport;
	catViewport.x = W / 2 + W / 4;
	catViewport.y = H / 3 - 14;
	catViewport.w = 250;
	catViewport.h = 250;
	SDL_RenderSetViewport( sdl_Handler->getRender(), &catViewport );
	//Render texture to screen
	SDL_RenderCopy( sdl_Handler->getRender(), sdl_Handler->getCat(), NULL, NULL );
}

int main( int argc, char* args[] )
{
	if(argc > 1)
	{
		IMonitorModule * ramModule = new RamModule();
		IMonitorModule * cpuModule = new CpuModule();
		IMonitorModule * userModule = new UserModule();
		IMonitorModule * catModule = new CatModule();
		IMonitorModule * bonModule = new BonusModule();
		IMonitorDisplay *ncursesDisplay = new NcursesDisplay();

		int exit = 0;

		while(!exit){
			erase();
				/***********************************GET TOP***************************************/
			char		buffer[32];
			std::string	output;
			FILE		*stream = popen("/usr/bin/top -l 1 | sed '11, 333d'", "r");
			if (stream)
			{
				while (!feof(stream))
					if (fgets(buffer, 32, stream) != NULL)
						output.append(buffer);
				pclose(stream);
			}
			/*************************************PARSING *************************************/
			ramModule->setData(output);
			cpuModule->setData(output);
			userModule->setData(output);
			catModule->setData(output);
			bonModule->setData(output);
		    /*************************************RENDER TEXT*************************************/
			ncursesDisplay->draw(ramModule->getData(), 0);
			ncursesDisplay->draw(cpuModule->getData(), 10);
			ncursesDisplay->draw(userModule->getData(), 20);
			ncursesDisplay->draw(bonModule->getData(), 30);

				
			refresh();
			
		}

		delete ncursesDisplay;
		delete  ramModule;
		delete  cpuModule;
		delete  userModule ;
		delete  catModule;
		delete  bonModule ;
	}
	else
	{
		SDL_Handler sdl_Handler = SDL_Handler();
		//Start up SDL and create window
		if( !sdl_Handler.isInited() )
		{
			std::cout << "Failed to initialize!\n" << std::endl;
		}
		else
		{


			sdl_Handler.loadMedia("textures/back.jpg");
			sdl_Handler.initCat();

			//Load media
			if( !sdl_Handler.isLoaded() )
			{
				std::cout << "Failed to load media!\n"  << std::endl;
			}
			else
			{
				//Main loop flag
				bool quit = false;

				//Event handler
				SDL_Event		e;
				unsigned int	sym;

				//While application is running

				IMonitorModule * ramModule = new RamModule();
				IMonitorModule * cpuModule = new CpuModule();
				IMonitorModule * userModule = new UserModule();
				IMonitorModule * catModule = new CatModule();
				IMonitorModule * bonModule = new BonusModule();
				TTF_Init();
				TTF_Font *font = TTF_OpenFont("font/Roboto-Black.ttf", 16);


				SDL_Texture 	*texture;

				IMonitorDisplay * ram = new RamDisplay();
				IMonitorDisplay *cpu = new CpuDisplay();
				IMonitorDisplay *pony = new PonyDisplay();
				IMonitorDisplay *user = new UserDisplay();
				IMonitorDisplay *bonus = new BonusDisplay();
				/////////////////////////////////////////////////////////////
				cpu->setRenderer(sdl_Handler.getRender(), font, texture);
				user->setRenderer(sdl_Handler.getRender(), font, texture);
				ram->setRenderer(sdl_Handler.getRender(), font, texture);
				pony->setRenderer(sdl_Handler.getRender(), font, texture);
				bonus->setRenderer(sdl_Handler.getRender(), font, texture);

				while( !quit )
				{
					/***********************************CLEAR SURFACE***************************************/
					//Clear screen
					SDL_SetRenderDrawColor( sdl_Handler.getRender(), 0xFF, 0xFF, 0xFF, 0xFF );
					SDL_RenderClear( sdl_Handler.getRender() );
					/***********************************BACKGROUND***************************************/
					renderBackGround(&sdl_Handler);
					/***********************************GET TOP***************************************/
					char		buffer[32];
					std::string	output;
					FILE		*stream = popen("/usr/bin/top -l 1 | sed '11, 333d'", "r");
					if (stream)
					{
						while (!feof(stream))
							if (fgets(buffer, 32, stream) != NULL)
								output.append(buffer);
						pclose(stream);
					}
					if (!output.empty()){
						/*************************************PARSING *************************************/
						ramModule->setData(output);
						cpuModule->setData(output);
						userModule->setData(output);
						catModule->setData(output);
						bonModule->setData(output);
					    /*************************************RENDER TEXT*************************************/
						ram->draw(ramModule->getData(), ramModule->getIntData());
						cpu->draw(cpuModule->getData(), cpuModule->getIntData());
						user->draw(userModule->getData(), 0);
						pony->draw(catModule->getData(), 0);
						bonus->draw(bonModule->getData(), 0);
						/*************************************RENDER TEXT*************************************/
					}
					renderCat(&sdl_Handler);
					/**************************************SDL EVENT************************************/
					//Handle events on queue
					while (SDL_PollEvent(&e))
					{

						sym = e.key.keysym.sym;
						if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
						{
							if (sym == SDLK_ESCAPE)
								quit = true;
						}
						if (e.type == SDL_QUIT)
							quit = true;
					}
					//Update screen
					SDL_RenderPresent( sdl_Handler.getRender() );

					SDL_Delay(300);
				}

				delete  ramModule;
				delete  cpuModule;
				delete  userModule ;
				delete  catModule;
				delete  bonModule ;

				TTF_CloseFont(font);
				SDL_DestroyTexture( texture );
				delete  ram ;
				delete cpu ;
				delete pony ;
				delete user ;
				delete bonus  ;
			}

		}
	}	
	return 0;
}

