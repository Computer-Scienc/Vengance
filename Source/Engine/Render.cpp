#include "Render.h"

#include "Librarys/Library_SDL2.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_sdl.h"

#include "Window.h"

VRender::VRender()
{
//ctor
// Decide GL+GLSL versions
#if __APPLE__
    // GL 3.2 Core + GLSL 150
    glsl_version = "#version 150";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
    // GL 3.0 + GLSL 130
    glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif

        // Create window with graphics context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

}

VRender::~VRender()
{
    //dtor
}

void VRender::Init()
{


    SDL_GL_MakeCurrent(renderWindow->sdl_window, renderWindow->sdl_glcontext);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    ImGui_ImplSDL2_InitForOpenGL(renderWindow->sdl_window, renderWindow->sdl_glcontext);
    ImGui_ImplOpenGL3_Init(glsl_version.c_str());

}

void VRender::Draw()
{
    SDL_GL_MakeCurrent(renderWindow->sdl_window, renderWindow->sdl_glcontext);

    ImGui::Begin("Test");
        ImGui::Text("Test");
    ImGui::End();
}
