#ifndef inputsForText
#define inputsForText
#include "toRender.h"
#include <string>
#include <SDL2/SDL_ttf.h>

class inputForText : public toRender{
    
    public:
    
    void Render(SDL_Renderer* renderer, SDL_Window * window, int xAxis,int yAxis);

    void Init(SDL_Renderer * renderer);

    void Exit();

    void HandleEvents(SDL_Renderer* renderer,SDL_Window* window);

    SDL_Rect getRect();

    private:

    bool isRunning;

    std::string textTyped;

    SDL_Texture * texture;

    int numResult;

    SDL_Surface* typing;

    SDL_Texture* textImage;
    
    TTF_Font* font;

    SDL_Color color;

    SDL_Rect position;

    int textHeight,textWidth;

    int windowHeight, windowWidth;

};



#endif