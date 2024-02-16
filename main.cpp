#include <SDL2/SDL.h>
#include <stdio.h>
#include "toRender.h"
#include "mainScreen.h"
#include <exception>
#include "inputForText.h"
#include "textRender.h"

int main(int argc, char *args[]) {
    auto mainscreen = mainScreen();
    auto peopleCount = inputForText();
    auto moneyPerHour = inputForText();
    auto title = textRender();
    auto people = textRender(); 
    auto howMuch = textRender();
    auto peopleCountBox = toRender();
    auto moneyCountBox = toRender();
    try {
        mainscreen.Init();
        mainscreen.getTextures();
        title.Init(mainscreen.getRenderer(),0,0,0,255,"Software Costing Calculator");
        people.Init(mainscreen.getRenderer(),0,0,0,255,"How much persons?");
        howMuch.Init(mainscreen.getRenderer(),0,0,0,255,"How much do they earn?");
        peopleCountBox.Init(mainscreen.getRenderer());
        moneyCountBox.Init(mainscreen.getRenderer());
        peopleCount.Init(mainscreen.getRenderer());
        moneyPerHour.Init(mainscreen.getRenderer());
        while (mainscreen.IsRunning()) {
            mainscreen.clearRenderer();
            mainscreen.Render();
            title.Render(mainscreen.getRenderer(),mainscreen.getWindow(),2,10,0,0);
            peopleCountBox.Render(mainscreen.getRenderer(),mainscreen.getWindow(),2,2,0.1,0.135);
            moneyCountBox.Render(mainscreen.getRenderer(),mainscreen.getWindow(),2,2,0.104,0.3);
            people.Render(mainscreen.getRenderer(),mainscreen.getWindow(),3,3,0,0);
            howMuch.Render(mainscreen.getRenderer(),mainscreen.getWindow(),2,2,-0.105,0);
            moneyPerHour.Render(mainscreen.getRenderer(),mainscreen.getWindow(),500,300);
            peopleCount.Render(mainscreen.getRenderer(),mainscreen.getWindow(),500,190);
            moneyPerHour.HandleEvents(mainscreen.getRenderer(),mainscreen.getWindow(),mainscreen.find(peopleCount.getRect(),moneyPerHour.getRect()));
            // peopleCount.HandleEvents(mainscreen.getRenderer(),mainscreen.getWindow(),mainscreen.find());
            mainscreen.HandleEvents();
            mainscreen.Update();
        }
    

        mainscreen.Exit();
    } catch (std::exception &exception) {
        fprintf(stderr, exception.what());
        SDL_Quit();
        return -1;
    }

    return 0;
}
