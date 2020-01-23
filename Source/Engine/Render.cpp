#include "Render.h"

#include "Librarys/Library_SDL2.h"

#include <GL/glew.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_sdl.h"

#include "imgui/addons/imguinodegrapheditor/imguinodegrapheditor.h"

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

ImFontAtlas* context_shared_font_atlas = new ImFontAtlas();

void VRender::Init()
{

    SDL_GL_MakeCurrent(renderWindow->sdl_window, renderWindow->sdl_glcontext);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    IMGUI_CHECKVERSION();
    imguiContext = ImGui::CreateContext(context_shared_font_atlas);
    io = &ImGui::GetIO(); (void)io;
    io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
    io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
    //io->ConfigViewportsNoDecoration = false;
    //io.ConfigViewportsNoAutoMerge = true;
    io->ConfigViewportsNoTaskBarIcon = true;
    io->ConfigViewportsNoDefaultParent = true;

    ImGui_ImplSDL2_InitForOpenGL(renderWindow->sdl_window, renderWindow->sdl_glcontext);
    ImGui_ImplOpenGL3_Init(glsl_version.c_str());



}

void VRender::Draw()
{
    SDL_GL_MakeCurrent(renderWindow->sdl_window, renderWindow->sdl_glcontext);

    glClearColor(0.97f, 0.97f, 0.97f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

        // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(renderWindow->sdl_window);
    ImGui::NewFrame();


    ImGui::ShowDemoWindow();
    ImGui::TestNodeGraphEditor();
    //ImGui::Show


     ImGui::Render();
    //glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        SDL_Window* backup_current_window = SDL_GL_GetCurrentWindow();
        SDL_GLContext backup_current_context = SDL_GL_GetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        SDL_GL_MakeCurrent(backup_current_window, backup_current_context);
    }

    SDL_GL_SwapWindow(renderWindow->sdl_window);
}

void VRender::Shutdown()
{
    ImGui_ImplSDL2_Shutdown();
}
