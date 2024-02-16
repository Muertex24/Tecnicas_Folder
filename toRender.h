#ifndef SDL_toRender
#define SDL_toRender
#include "SDL_Exception.h"
#include <SDL2/SDL.h>

class toRender {
public:
    void Init(SDL_Renderer* renderer);
    void HandleEvents();


    void Update();
    void Render(SDL_Renderer *renderer,SDL_Window *window, float xAxis , float yAxis , float fixXAxis , float fixYAxis);


    bool IsRunning();

    void getTextures(SDL_Renderer* renderer);

private:

    bool isRunning;

    int windowWidth, windowHeight;
    int textWidth, textHeight;
    
    SDL_Texture *texture;
    SDL_Rect* position;
};


#endif