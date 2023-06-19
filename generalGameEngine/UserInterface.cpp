#include "UserInterface.h"
#include "Scene.h"
#include"imgui.h"
#include"imgui_impl_glfw.h"
#include"imgui_impl_opengl3.h"
#include <glm/gtx/string_cast.hpp>






void ui_render(std::unordered_map<unsigned int, GameObject> gameobjects) {

	// feed inputs to dear imgui, start new frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	// render your GUI
	ImGui::Begin("Scene manager");
	ImGui::TextColored(ImVec4(1, 0, 0, 1), "GameObjects");
	ImGui::BeginChild("Scrolling");
	for (int i = 0; i < gameobjects.size(); i++) {
		ImGui::Text(gameobjects[i].objectName.c_str());
		ImGui::Text(glm::to_string(gameobjects[i].position).c_str());
	}
	ImGui::EndChild();
	ImGui::End();

	// Render dear imgui into screen
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

}

void ui_setup()
{

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();
	// Setup Dear ImGui style
	ImGui::StyleColorsDark();



}
