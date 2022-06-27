//
// Created by yuan on 4/18/22.
//

#ifndef XENGINEMAIN_KEYCODES_H
#define XENGINEMAIN_KEYCODES_H

namespace XEngine
{
    typedef enum class KeyCode : uint16_t
    {
        // From glfw3.h
        Space               = 32,
        Apostrophe          = 39, /* ' */
        Comma               = 44, /* , */
        Minus               = 45, /* - */
        Period              = 46, /* . */
        Slash               = 47, /* / */

        D0                  = 48, /* 0 */
        D1                  = 49, /* 1 */
        D2                  = 50, /* 2 */
        D3                  = 51, /* 3 */
        D4                  = 52, /* 4 */
        D5                  = 53, /* 5 */
        D6                  = 54, /* 6 */
        D7                  = 55, /* 7 */
        D8                  = 56, /* 8 */
        D9                  = 57, /* 9 */

        Semicolon           = 59, /* ; */
        Equal               = 61, /* = */

        A                   = 65,
        B                   = 66,
        C                   = 67,
        D                   = 68,
        E                   = 69,
        F                   = 70,
        G                   = 71,
        H                   = 72,
        I                   = 73,
        J                   = 74,
        K                   = 75,
        L                   = 76,
        M                   = 77,
        N                   = 78,
        O                   = 79,
        P                   = 80,
        Q                   = 81,
        R                   = 82,
        S                   = 83,
        T                   = 84,
        U                   = 85,
        V                   = 86,
        W                   = 87,
        X                   = 88,
        Y                   = 89,
        Z                   = 90,

        LeftBracket         = 91,  /* [ */
        Backslash           = 92,  /* \ */
        RightBracket        = 93,  /* ] */
        GraveAccent         = 96,  /* ` */

        World1              = 161, /* non-US #1 */
        World2              = 162, /* non-US #2 */

        /* Function keys */
        Escape              = 256,
        Enter               = 257,
        Tab                 = 258,
        Backspace           = 259,
        Insert              = 260,
        Delete              = 261,
        Right               = 262,
        Left                = 263,
        Down                = 264,
        Up                  = 265,
        PageUp              = 266,
        PageDown            = 267,
        Home                = 268,
        End                 = 269,
        CapsLock            = 280,
        ScrollLock          = 281,
        NumLock             = 282,
        PrintScreen         = 283,
        Pause               = 284,
        F1                  = 290,
        F2                  = 291,
        F3                  = 292,
        F4                  = 293,
        F5                  = 294,
        F6                  = 295,
        F7                  = 296,
        F8                  = 297,
        F9                  = 298,
        F10                 = 299,
        F11                 = 300,
        F12                 = 301,
        F13                 = 302,
        F14                 = 303,
        F15                 = 304,
        F16                 = 305,
        F17                 = 306,
        F18                 = 307,
        F19                 = 308,
        F20                 = 309,
        F21                 = 310,
        F22                 = 311,
        F23                 = 312,
        F24                 = 313,
        F25                 = 314,

        /* Keypad */
        KP0                 = 320,
        KP1                 = 321,
        KP2                 = 322,
        KP3                 = 323,
        KP4                 = 324,
        KP5                 = 325,
        KP6                 = 326,
        KP7                 = 327,
        KP8                 = 328,
        KP9                 = 329,
        KPDecimal           = 330,
        KPDivide            = 331,
        KPMultiply          = 332,
        KPSubtract          = 333,
        KPAdd               = 334,
        KPEnter             = 335,
        KPEqual             = 336,

        LeftShift           = 340,
        LeftControl         = 341,
        LeftAlt             = 342,
        LeftSuper           = 343,
        RightShift          = 344,
        RightControl        = 345,
        RightAlt            = 346,
        RightSuper          = 347,
        Menu                = 348
    } Key;

    inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
    {
        os << static_cast<int32_t>(keyCode);
        return os;
    }
}

// From glfw3.h
#define XE_KEY_SPACE           ::XEngine::Key::Space
#define XE_KEY_APOSTROPHE      ::XEngine::Key::Apostrophe    /* ' */
#define XE_KEY_COMMA           ::XEngine::Key::Comma         /* , */
#define XE_KEY_MINUS           ::XEngine::Key::Minus         /* - */
#define XE_KEY_PERIOD          ::XEngine::Key::Period        /* . */
#define XE_KEY_SLASH           ::XEngine::Key::Slash         /* / */
#define XE_KEY_0               ::XEngine::Key::D0
#define XE_KEY_1               ::XEngine::Key::D1
#define XE_KEY_2               ::XEngine::Key::D2
#define XE_KEY_3               ::XEngine::Key::D3
#define XE_KEY_4               ::XEngine::Key::D4
#define XE_KEY_5               ::XEngine::Key::D5
#define XE_KEY_6               ::XEngine::Key::D6
#define XE_KEY_7               ::XEngine::Key::D7
#define XE_KEY_8               ::XEngine::Key::D8
#define XE_KEY_9               ::XEngine::Key::D9
#define XE_KEY_SEMICOLON       ::XEngine::Key::Semicolon     /* ; */
#define XE_KEY_EQUAL           ::XEngine::Key::Equal         /* = */
#define XE_KEY_A               ::XEngine::Key::A
#define XE_KEY_B               ::XEngine::Key::B
#define XE_KEY_C               ::XEngine::Key::C
#define XE_KEY_D               ::XEngine::Key::D
#define XE_KEY_E               ::XEngine::Key::E
#define XE_KEY_F               ::XEngine::Key::F
#define XE_KEY_G               ::XEngine::Key::G
#define XE_KEY_H               ::XEngine::Key::H
#define XE_KEY_I               ::XEngine::Key::I
#define XE_KEY_J               ::XEngine::Key::J
#define XE_KEY_K               ::XEngine::Key::K
#define XE_KEY_L               ::XEngine::Key::L
#define XE_KEY_M               ::XEngine::Key::M
#define XE_KEY_N               ::XEngine::Key::N
#define XE_KEY_O               ::XEngine::Key::O
#define XE_KEY_P               ::XEngine::Key::P
#define XE_KEY_Q               ::XEngine::Key::Q
#define XE_KEY_R               ::XEngine::Key::R
#define XE_KEY_S               ::XEngine::Key::S
#define XE_KEY_T               ::XEngine::Key::T
#define XE_KEY_U               ::XEngine::Key::U
#define XE_KEY_V               ::XEngine::Key::V
#define XE_KEY_W               ::XEngine::Key::W
#define XE_KEY_X               ::XEngine::Key::X
#define XE_KEY_Y               ::XEngine::Key::Y
#define XE_KEY_Z               ::XEngine::Key::Z
#define XE_KEY_LEFT_BRACKET    ::XEngine::Key::LeftBracket   /* [ */
#define XE_KEY_BACKSLASH       ::XEngine::Key::Backslash     /* \ */
#define XE_KEY_RIGHT_BRACKET   ::XEngine::Key::RightBracket  /* ] */
#define XE_KEY_GRAVE_ACCENT    ::XEngine::Key::GraveAccent   /* ` */
#define XE_KEY_WORLD_1         ::XEngine::Key::World1        /* non-US #1 */
#define XE_KEY_WORLD_2         ::XEngine::Key::World2        /* non-US #2 */

/* Function keys */
#define XE_KEY_ESCAPE          ::XEngine::Key::Escape
#define XE_KEY_ENTER           ::XEngine::Key::Enter
#define XE_KEY_TAB             ::XEngine::Key::Tab
#define XE_KEY_BACKSPACE       ::XEngine::Key::Backspace
#define XE_KEY_INSERT          ::XEngine::Key::Insert
#define XE_KEY_DELETE          ::XEngine::Key::Delete
#define XE_KEY_RIGHT           ::XEngine::Key::Right
#define XE_KEY_LEFT            ::XEngine::Key::Left
#define XE_KEY_DOWN            ::XEngine::Key::Down
#define XE_KEY_UP              ::XEngine::Key::Up
#define XE_KEY_PAGE_UP         ::XEngine::Key::PageUp
#define XE_KEY_PAGE_DOWN       ::XEngine::Key::PageDown
#define XE_KEY_HOME            ::XEngine::Key::Home
#define XE_KEY_END             ::XEngine::Key::End
#define XE_KEY_CAPS_LOCK       ::XEngine::Key::CapsLock
#define XE_KEY_SCROLL_LOCK     ::XEngine::Key::ScrollLock
#define XE_KEY_NUM_LOCK        ::XEngine::Key::NumLock
#define XE_KEY_PRINT_SCREEN    ::XEngine::Key::PrintScreen
#define XE_KEY_PAUSE           ::XEngine::Key::Pause
#define XE_KEY_F1              ::XEngine::Key::F1
#define XE_KEY_F2              ::XEngine::Key::F2
#define XE_KEY_F3              ::XEngine::Key::F3
#define XE_KEY_F4              ::XEngine::Key::F4
#define XE_KEY_F5              ::XEngine::Key::F5
#define XE_KEY_F6              ::XEngine::Key::F6
#define XE_KEY_F7              ::XEngine::Key::F7
#define XE_KEY_F8              ::XEngine::Key::F8
#define XE_KEY_F9              ::XEngine::Key::F9
#define XE_KEY_F10             ::XEngine::Key::F10
#define XE_KEY_F11             ::XEngine::Key::F11
#define XE_KEY_F12             ::XEngine::Key::F12
#define XE_KEY_F13             ::XEngine::Key::F13
#define XE_KEY_F14             ::XEngine::Key::F14
#define XE_KEY_F15             ::XEngine::Key::F15
#define XE_KEY_F16             ::XEngine::Key::F16
#define XE_KEY_F17             ::XEngine::Key::F17
#define XE_KEY_F18             ::XEngine::Key::F18
#define XE_KEY_F19             ::XEngine::Key::F19
#define XE_KEY_F20             ::XEngine::Key::F20
#define XE_KEY_F21             ::XEngine::Key::F21
#define XE_KEY_F22             ::XEngine::Key::F22
#define XE_KEY_F23             ::XEngine::Key::F23
#define XE_KEY_F24             ::XEngine::Key::F24
#define XE_KEY_F25             ::XEngine::Key::F25

/* Keypad */
#define XE_KEY_KP_0            ::XEngine::Key::KP0
#define XE_KEY_KP_1            ::XEngine::Key::KP1
#define XE_KEY_KP_2            ::XEngine::Key::KP2
#define XE_KEY_KP_3            ::XEngine::Key::KP3
#define XE_KEY_KP_4            ::XEngine::Key::KP4
#define XE_KEY_KP_5            ::XEngine::Key::KP5
#define XE_KEY_KP_6            ::XEngine::Key::KP6
#define XE_KEY_KP_7            ::XEngine::Key::KP7
#define XE_KEY_KP_8            ::XEngine::Key::KP8
#define XE_KEY_KP_9            ::XEngine::Key::KP9
#define XE_KEY_KP_DECIMAL      ::XEngine::Key::KPDecimal
#define XE_KEY_KP_DIVIDE       ::XEngine::Key::KPDivide
#define XE_KEY_KP_MULTIPLY     ::XEngine::Key::KPMultiply
#define XE_KEY_KP_SUBTRACT     ::XEngine::Key::KPSubtract
#define XE_KEY_KP_ADD          ::XEngine::Key::KPAdd
#define XE_KEY_KP_ENTER        ::XEngine::Key::KPEnter
#define XE_KEY_KP_EQUAL        ::XEngine::Key::KPEqual

#define XE_KEY_LEFT_SHIFT      ::XEngine::Key::LeftShift
#define XE_KEY_LEFT_CONTROL    ::XEngine::Key::LeftControl
#define XE_KEY_LEFT_ALT        ::XEngine::Key::LeftAlt
#define XE_KEY_LEFT_SUPER      ::XEngine::Key::LeftSuper
#define XE_KEY_RIGHT_SHIFT     ::XEngine::Key::RightShift
#define XE_KEY_RIGHT_CONTROL   ::XEngine::Key::RightControl
#define XE_KEY_RIGHT_ALT       ::XEngine::Key::RightAlt
#define XE_KEY_RIGHT_SUPER     ::XEngine::Key::RightSuper
#define XE_KEY_MENU            ::XEngine::Key::Menu

#endif //XENGINEMAIN_KEYCODES_H
