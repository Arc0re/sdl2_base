#include "main.h"
#include "input.h"

#include <stdio.h>
#include <SDL_image.h>

void freeSDL(SDL_Window *window, SDL_Renderer *renderer,  SDL_Texture *image);

int main(int argc, char **argv)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *image = NULL;
    SDL_Event events;
    bool running = true;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow(WINDOW_TITLE,
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              WINDOW_WIDTH,
                              WINDOW_HEIGHT,
                              0);
    
    if (window)
    {
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        if (renderer)
        {
            // todo
            printf("Renderer created.\n");
            
            SDL_SetRenderDrawColor(renderer, 100, 0, 255, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
            
            image = IMG_LoadTexture(renderer, "purpleblock.png");
            if(image)
            {
                SDL_RenderCopy(renderer, image, NULL, NULL);
                SDL_RenderPresent(renderer);
            }
            else
            {
                printf("Failed to load image : %s", SDL_GetError());
            }
        }
        else
        {
            printf("Failed to create renderer : %s", SDL_GetError());
            SDL_DestroyWindow(window);
            SDL_Quit();
            return -1;
        }
    }
    else
    {
        printf("Failed to create window : %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }
    
    while (running)
    {
        SDL_WaitEvent(&events);
        
        if(!inputHandler(window, events))
        {
            running = false;
        }
    }
    
    freeSDL(window, renderer, image);
    
    return 0;
}

void freeSDL(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *image)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(image);   
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("Nice and clean");
}
