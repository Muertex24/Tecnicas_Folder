#include <SDL2/SDL.h>
#include "toRender.h"
#include "SDL_Exception.h"
#include "SDL2/SDL_image.h"

void toRender::Init(SDL_Renderer * renderer) {
            SDL_SetRenderDrawColor(renderer, 250, 250, 250, 250);
            isRunning = true;
            getTextures(renderer);
}


bool toRender::IsRunning(){
    return isRunning;
}

void toRender::Render(SDL_Renderer *renderer,SDL_Window *window, float xAxis , float yAxis , float fixXAxis , float fixYAxis){

    SDL_QueryTexture(texture, NULL, NULL, &textWidth, &textHeight);
    float rectTextX = (windowWidth - textWidth)/xAxis;
    float rectTextY = (windowHeight- textHeight)/yAxis;
    float auxX = fixXAxis*windowWidth;
    float auxY = fixYAxis*windowHeight;
    int posX = rectTextX + auxX;
    int posY = rectTextY + auxY;
    SDL_Rect position = {posX+500,posY,100,50};
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    SDL_RenderCopy(renderer , texture, NULL, &position);

}

void toRender::Update(){
}

void toRender::HandleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            SDL_Quit();
            break;
    
        default:
            break;
        };
    }
}

void toRender::getTextures(SDL_Renderer* renderer){
    texture = IMG_LoadTexture(renderer, "./src/textures/inputBox.png");
    if(texture == nullptr){
        throw SDL_Exception(SDL_GetError());
    }
};