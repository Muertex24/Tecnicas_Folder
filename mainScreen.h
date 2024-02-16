#ifndef SDL_mainScreen
#define SDL_mainScreen
#include "SDL_Exception.h"
#include "toRender.h"
#include <tuple>

class mainScreen : public toRender {
public:
    void Init();
    void HandleEvents();


    void Update();
    void Render();

    void Exit();

    SDL_Rect find(SDL_Rect rect1, SDL_Rect rect2);

    bool IsRunning();

    void getTextures();

    void clearRenderer();


    SDL_Renderer* getRenderer(){
        return renderer;
    };
    SDL_Window* getWindow(){
        return window;
    }

private:
    void InitSDL();

    void CreateWindowAndRender();

    int mouseX,mouseY;
    SDL_Rect rects[2];

    bool isRunning;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
};


#endif