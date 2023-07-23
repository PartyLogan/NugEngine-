#include <iostream>
#include <SDL3/SDL.h>
#include <SDL_image.h>

using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main(int argc, char *argv[]){

  SDL_Window* window = NULL;
  SDL_Surface* screenSurface = NULL;

  if(SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
  {
    cout << SDL_GetError() << endl;
    return 0;
  }

  if(IMG_Init(IMG_INIT_PNG) <0)
  {
    cout << SDL_GetError() << endl;
  }
  
  window = SDL_CreateWindow("Nug Engine", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
  
  screenSurface = SDL_GetWindowSurface(window);
  SDL_FillSurfaceRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
  
  SDL_UpdateWindowSurface(window);

  SDL_Event e;
  int i = 0;
  bool quit = false;
  while(quit == false)
  {
    while(SDL_PollEvent(&e))
    {
      if (e.type == SDL_EVENT_QUIT)
      {
        quit = true;
      }
    }
  }
  
  return 0;
}
