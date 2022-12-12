#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>


class Input
{
public:
    enum MouseButtons {
        LeftButton = SDL_BUTTON_LEFT,
        RightButton = SDL_BUTTON_RIGHT,
        MiddleButton = SDL_BUTTON_MIDDLE,
        ExtraButton1 = SDL_BUTTON_X1,
        ExtraButton2 = SDL_BUTTON_X2
    };

    static void UpdateKeyboardState(const Uint8* state);
    static void UpdateMouseState(SDL_MouseButtonEvent state);

    static bool IsNewPress(SDL_Scancode key);
    static bool IsCurrentPress(SDL_Scancode key);
    static bool IsOldPress(SDL_Scancode key);

    static bool IsNewPress(MouseButtons button);
    static bool IsCurrentPress(MouseButtons button);
    static bool IsOldPress(MouseButtons button);
private:
    static Uint8* m_lastKeyboardState;
    static Uint8* m_currentKeyboardState;

    static SDL_MouseButtonEvent m_lastMouseState;
    static SDL_MouseButtonEvent m_currentMouseState;
};
