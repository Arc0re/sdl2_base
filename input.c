#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>

bool inputHandler(SDL_Window *window, SDL_Event event)
{
    bool running = true;
    switch(event.type)
    {
        case SDL_QUIT:
            running = false;
            printf("SDL_QUIT captured.\n");
            break;
        case SDL_MOUSEBUTTONUP:
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                                     "SDL_MOUSEBUTTONUP CAPTURED",
                                     "It works!",
                                      window);
            break;
    }
    
    return running;
}