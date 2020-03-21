//
// Created by Olexiy BALAGUROVSKIY on 2019-07-07.
//

#include "SDL_Handler.hpp"

SDL_Handler::SDL_Handler(){
	gWindow = NULL;
	gRenderer = NULL;
	gTexture = NULL;
	init = true;
	load_media = true;
	catId = 0;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		std::cout << "SDL could not initialize! SDL Error: "<< SDL_GetError() << std::endl;
		init = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
		}

		//Create window
		gWindow = SDL_CreateWindow( "ft_gkrellm", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W, H, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			std::cout << "Window could not be created! SDL Error: "<< SDL_GetError() << std::endl;
			init = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				std::cout << "Renderer could not be created! SDL Error: "<< SDL_GetError() << std::endl;
				init = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					std::cout << "SDL_image could not initialize! SDL_image Error: "<< IMG_GetError() << std::endl;
					init = false;
				}
			}
		}
	}

}

SDL_Handler::SDL_Handler(SDL_Handler const & src){
	*this = src;
}
SDL_Handler & SDL_Handler::operator=(SDL_Handler const & src){
	//Free loaded image
	SDL_DestroyTexture( gTexture );
	gTexture = NULL;
	SDL_DestroyTexture( cat[0] );
	cat[0] = NULL;
	SDL_DestroyTexture( cat[1] );
	cat[1] = NULL;
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

	gTexture = src.gTexture;
	cat[0] = src.cat[0] ;
	cat[1] = src.cat[1] ;
	gWindow = src.gWindow;
	gRenderer = src.gRenderer;
	return (*this);
}

void SDL_Handler::loadMedia( std::string path)
{

	//Load texture
	gTexture = loadTexture(path);
	if( gTexture == NULL )
	{
		std::cout << "Failed to load texture image!\n" <<std::endl;
		load_media = false;
	}
}

SDL_Handler::~SDL_Handler()
{
	//Free loaded image
	SDL_DestroyTexture( gTexture );
	gTexture = NULL;
	SDL_DestroyTexture( cat[0] );
	cat[0] = NULL;
	SDL_DestroyTexture( cat[1] );
	cat[1] = NULL;
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void SDL_Handler::initCat()
{
	cat[0] = loadTexture("textures/cat1.png");
	cat[1] = loadTexture("textures/cat2.png");
}

SDL_Texture * SDL_Handler::getCat(){

	SDL_Texture* currCat = NULL;

	if (catId < 2 && catId >= 0)
		currCat = cat[catId];
	catId++;
	if (catId >= 2)
		catId = 0;
	return (currCat);
}

SDL_Texture* SDL_Handler::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		std::cout << "Unable to load image ! SDL_image Error: " << path.c_str() << IMG_GetError()  << std::endl;
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			std::cout << "Unable to create texture from ! SDL Error: " << path.c_str() << SDL_GetError() << std::endl;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	return newTexture;
}

SDL_Window * SDL_Handler::getWin() const{
	return (gWindow);
}
SDL_Renderer * SDL_Handler::getRender() const{
	return (gRenderer);
}

bool SDL_Handler::isInited(void) const{
	return(init);
}
bool SDL_Handler::isLoaded(void) const{
	return(load_media);
}
SDL_Texture* SDL_Handler::getTexture() const{
	return(gTexture);
}