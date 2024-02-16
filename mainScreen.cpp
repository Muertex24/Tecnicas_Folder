#include <SDL2/SDL.h>
#include "mainScreen.h"
#include "SDL_Exception.h"
#include "SDL2/SDL_image.h"
#include <SDL2/SDL_ttf.h>


void mainScreen::Init() {
            InitSDL();
            CreateWindowAndRender();
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            isRunning = true;
            SDL_SetWindowMinimumSize(window, 650, 650);

}



void mainScreen::InitSDL() {
            auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

            if (!isInitialized) {
                throw SDL_Exception(SDL_GetError());
            }
            if (TTF_Init() != 0) {
                SDL_Log("Error al inicializar SDL_ttf: %s", TTF_GetError());
                SDL_Quit();
            }
}

void mainScreen::CreateWindowAndRender() {
             window = SDL_CreateWindow("Calc", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,650, 650, SDL_WINDOW_SHOWN);
             renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (window == NULL || renderer == NULL) {
                throw SDL_Exception(SDL_GetError());
            }
}

bool mainScreen::IsRunning(){
    return isRunning;
}

void mainScreen::Render(){
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void mainScreen::Update(){
    
    SDL_RenderPresent(renderer);
}

void mainScreen::clearRenderer(){
    SDL_RenderClear(renderer);
};



SDL_Rect mainScreen :: find(SDL_Rect rect1, SDL_Rect rect2){
    SDL_GetMouseState(&mouseX,&mouseY);
    SDL_Rect nullRect = {0,0,0,0};
    rects[0] = rect1;
    rects[1] = rect2;

    bool finded = false;
    for (size_t i = 0; i <= sizeof(rects); i++)
    {
        if(mouseX >= rect1.x && mouseY >= rect1.y &&mouseX <= (rect1.w+rects[i].x) && mouseY <= rect1.y+rects->h){
            finded = true;
        };
        if(mouseX >= rect2.x && mouseY >= rect2.y &&mouseX <= (rect2.w+rects[i].x) && mouseY <= rect2.y+rects->h){
            finded = true;
        };
        if(finded){
            nullRect.x = rects[i].x;
            nullRect.y = rects[i].y;
            nullRect.w = rects[i].w;
            nullRect.h = rects[i].h;
        }
    }
    return rects[0];
}


void mainScreen::HandleEvents() {
    SDL_Event event;
    SDL_GetMouseState(&mouseX,&mouseY);


    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            break;
        default:
            break;
        };
    }
}

void mainScreen::Exit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void mainScreen::getTextures(){
    texture = IMG_LoadTexture(renderer, "./src/textures/background.png");
    if(texture == nullptr){
        throw SDL_Exception(SDL_GetError());
    }
};