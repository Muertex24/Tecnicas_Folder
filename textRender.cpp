#include <SDL2/SDL.h>
#include "textRender.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>



void textRender :: Init(SDL_Renderer *renderer,uint8_t b, uint8_t r,uint8_t g,uint8_t a ,const char* text){
    TTF_Font *font = TTF_OpenFont("./src/fonts/OpenSans-bold.ttf", 32);
    SDL_Color color = {b,r,g,a};
    surface = TTF_RenderText_Solid(font, text, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
};

void textRender :: Render(SDL_Renderer *renderer,SDL_Window *window, float xAxis , float yAxis , float fixXAxis , float fixYAxis){
    SDL_QueryTexture(texture, NULL, NULL, &textWidth, &textHeight);
    float rectTextX = (windowWidth - textWidth)/xAxis;
    float rectTextY = (windowHeight- textHeight)/yAxis;
    float auxX = fixXAxis*windowWidth;
    float auxY = fixYAxis*windowHeight;
    int posX = rectTextX + auxX;
    int posY = rectTextY + auxY;
    SDL_Rect position = {posX,posY,textWidth,textHeight};
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    SDL_RenderCopy(renderer , texture, NULL, &position);
};