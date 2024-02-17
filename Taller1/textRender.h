#ifndef textOnScreen
#define textOnScreen
#include "toRender.h"

class textRender : public toRender{

    public:

    void Init(SDL_Renderer *renderer,uint8_t r , uint8_t g, uint8_t b, uint8_t a, const char* text);

    void Render(SDL_Renderer *renderer,SDL_Window* window, float xAxis , float yAxis, float fixXAxis, float fixYAxis);

    bool IsRunning();

    void getTextures();


private:
    bool isRunning;

    SDL_Rect* rect;
    SDL_Texture *texture;
    SDL_Surface *surface;
    int windowWidth, windowHeight;
    int textWidth, textHeight;

};











#endif