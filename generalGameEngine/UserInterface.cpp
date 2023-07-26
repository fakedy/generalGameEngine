#include "UserInterface.h"
#include"imgui.h"
#include"imgui_impl_glfw.h"
#include"imgui_impl_opengl3.h"
#include <glm/gtx/string_cast.hpp>
#include "SceneManager.h"

unsigned int selectedObject = 0;

SceneManager& scenemanager = SceneManager::get_instance();

void ui_render(std::unordered_map<unsigned int, GameObject> &gameobjects) {


	// feed inputs to dear imgui, start new frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();



	// Used to set the position and size of the next ui you render
	//ImGui::SetNextWindowSize(ImVec2(static_cast<float>(64), static_cast<float>(64)), ImGuiCond_Always);
	//ImGui::SetNextWindowPos(ImVec2(static_cast<float>(64), static_cast<float>(64)), ImGuiCond_Always);

	// render your GUI
	ImGui::Begin("Scene manager", NULL, ImGuiWindowFlags_MenuBar);

	if (ImGui::BeginMenuBar()) {

		if (ImGui::BeginMenu("File")) {
			if (ImGui::MenuItem("New Scene")) {

				std::cout << "New scene button pressed" << std::endl;
				scenemanager.new_scene();

			}
			if (ImGui::MenuItem("Save Scene")) {

				

			}
			if (ImGui::MenuItem("Load Scene")) {



			}
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Add")) {
			if (ImGui::MenuItem("GameObject")) {

				scenemanager.scene->new_gameobject();
				std::cout << "New Gameobject Created." << std::endl;
			}
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();

		
	}


	ImGui::TextColored(ImVec4(1, 0, 0, 1), "GameObjects");
	ImGui::BeginChild("Scrolling");


	for (int i = 0; i < gameobjects.size(); i++) {

		// temporary hack
		if (ImGui::Button((gameobjects[i].objectName + " " + std::to_string(i)).c_str())) {

			selectedObject = i;
			std::cout << "Gameobject: " << i << " selected." << std::endl;
		}
	}

	ImGui::EndChild();
	ImGui::End();


	ImGui::Begin("GameObject");

	ImGui::Text(gameobjects[selectedObject].objectName.c_str());
	ImGui::DragFloat3("Translation", &gameobjects[selectedObject].position.x);
	ImGui::DragFloat3("Scale", &gameobjects[selectedObject].scale.x);

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
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

}

void ui_destroy() {

	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();


}
