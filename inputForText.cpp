#include <SDL2/SDL.h>
#include "inputForText.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>



void inputForText::Render(SDL_Renderer* renderer,SDL_Window* window, int xAxis, int yAxis){
    SDL_QueryTexture(textImage, NULL, NULL, &textWidth, &textHeight);
    position = {xAxis,yAxis,textWidth,textHeight};

    SDL_RenderCopy(renderer,textImage,NULL,&position);
}

SDL_Rect inputForText :: getRect(){
    return position;
}

void inputForText::Init(SDL_Renderer * renderer){
    SDL_StopTextInput();
    textTyped = "";
    typing = TTF_RenderText_Solid(font,textTyped.c_str(),color);
    textImage = SDL_CreateTextureFromSurface(renderer,typing);


    font = TTF_OpenFont("./src/fonts/OpenSans-Regular.ttf",30);
    if(font==NULL){
        SDL_Quit();
    }
    color = {255,0,0,255};
    typing = TTF_RenderText_Solid(font,"",color);
    isRunning=true;

}

void inputForText::Exit(){
    SDL_StopTextInput();
}

void inputForText::HandleEvents(SDL_Renderer* renderer,SDL_Window* window , SDL_Rect rect){
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_TEXTINPUT:
                for (char c : event.text.text){
                    if(!isdigit(c)){
                        break;
                    }else{
                        textTyped +=event.text.text;
                    }
                };
                if(textImage){
                    SDL_DestroyTexture(textImage);
                    textImage = NULL;
                }
                typing = TTF_RenderText_Solid(font,textTyped.c_str(),color);
                if(typing){
                    textImage = SDL_CreateTextureFromSurface(renderer,typing);
                }
                break;
            case SDL_QUIT:
                SDL_Quit();
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(position.x == rect.x && position.y == rect.y){
                    SDL_StartTextInput();
                }else{
                    // SDL_StopTextInput();
                }
                break;
            default:
                break;
            }
        }
}
