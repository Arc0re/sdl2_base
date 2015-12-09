#ifndef INPUT_H
#define INPUT_H

#include "versions.h"

#if MAC_OX_X
#include <SDL.h>
#elif WIN_32
#include <SDL.h>
#endif

#include <stdbool.h>

bool inputHandler(SDL_Window *window, SDL_Event event);

#endif // INPUT_H
