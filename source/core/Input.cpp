#include "core/Input.hpp"

#include <iostream>

Uint8* Input::m_lastKeyboardState;
Uint8* Input::m_currentKeyboardState;
SDL_MouseButtonEvent Input::m_lastMouseState;
SDL_MouseButtonEvent Input::m_currentMouseState;

/// <summary>
/// Updates the keyboard state.
/// </summary>

void Input::UpdateKeyboardState(const Uint8* state)
{
    m_lastKeyboardState = m_currentKeyboardState;
    m_currentKeyboardState = const_cast<Uint8*>(state);
}

/// <summary>
/// Updates the mouse state.
/// </summary>

void Input::UpdateMouseState(const SDL_MouseButtonEvent state)
{
    m_lastMouseState = m_currentMouseState;
    m_currentMouseState = state;
}

/// <summary>
/// Checks if the requested key is a new press.
/// </summary>
/// <param name="key">
/// the key to check.
/// </param>
/// <returns>
/// a bool that indicates whether the selected key is being
/// pressed in the current state and not in the last state.
/// </returns>

bool Input::IsNewPress(SDL_Scancode key)
{
    return
            !m_lastKeyboardState[key] &&
            m_currentKeyboardState[key];
}

/// <summary>
/// Checks if the requested key is a current press.
/// </summary>
/// <param name="key">
/// the key to check.
/// </param>
/// <returns>
/// a bool that indicates whether the selected key is being
/// pressed in the current state and in the last state.
/// </returns>

bool Input::IsCurrentPress(SDL_Scancode key)
{
    return
            m_lastKeyboardState[key] &&
            m_currentKeyboardState[key];
}

/// <summary>
/// Checks if the requested button is an old press.
/// </summary>
/// <param name="key">
/// the key to check.
/// </param>
/// <returns>
/// a bool indicating whether the selectde button is not being
/// pressed in the current state and being pressed in the last state.
/// </returns>

bool Input::IsOldPress(SDL_Scancode key)
{
    return
            m_lastKeyboardState[key] &&
            !m_currentKeyboardState[key];
}

/// <summary>
/// Checks if the requested mouse button is a new press.
/// </summary>
/// <param name="button">
/// the mouse button to check.
/// </param>
/// <returns>
/// a bool indicating whether the selected mouse button is being
/// pressed in the current state but not in the last state.
/// </returns>

bool Input::IsNewPress(MouseButtons button)
{
    if (m_lastMouseState.button != button || m_currentMouseState.button != button) return false;
    return
            m_lastMouseState.type == SDL_MOUSEBUTTONUP &&
            m_currentMouseState.type == SDL_MOUSEBUTTONDOWN;
}

/// <summary>
/// Checks if the requested mouse button is a current press.
/// </summary>
/// <param name="button">
/// the mouse button to be checked.
/// </param>
/// <returns>
/// a bool indicating whether the selected mouse button is being
/// pressed in the current state and in the last state.
/// </returns>

bool Input::IsCurrentPress(MouseButtons button)
{
    if (m_lastMouseState.button != button || m_currentMouseState.button != button) return false;
    return
            m_lastMouseState.type == SDL_MOUSEBUTTONDOWN &&
            m_currentMouseState.type == SDL_MOUSEBUTTONDOWN;
}

/// <summary>
/// Checks if the requested mouse button is an old press.
/// </summary>
/// <param name="button">
/// the mouse button to check.
/// </param>
/// <returns>
/// a bool indicating whether the selected mouse button is not being
/// pressed in the current state and is being pressed in the old state.
/// </returns>

bool Input::IsOldPress(MouseButtons button)
{
    if (m_lastMouseState.button != button || m_currentMouseState.button != button) return false;
    return
            m_lastMouseState.type == SDL_MOUSEBUTTONDOWN &&
            m_currentMouseState.type == SDL_MOUSEBUTTONUP;
}
