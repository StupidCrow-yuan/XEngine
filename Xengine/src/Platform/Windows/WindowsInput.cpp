//
// Created by yuan on 4/18/22.
//

#include "WindowsInput.h"
#include "Xengine/Application.h"
#include <GLFW/glfw3.h>

namespace XEngine {

    bool WindowsInput::IsKeyPressedImpl(KeyCode key)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, static_cast<int32_t>(key));
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(MouseCode button)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
        return state == GLFW_PRESS;
    }

    std::pair<float, float> WindowsInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return {(float)xpos, (float)ypos };
    }

    float WindowsInput::GetMouseXImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto[x, y] = GetMousePositionImpl();
        return x;
    }

    float WindowsInput::GetMouseYImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto[x, y] = GetMousePositionImpl();
        return y;
    }
}