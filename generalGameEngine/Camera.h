#pragma once

#include "logger.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include<iostream>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;



class Camera {
public:

	std::string cameraName;

	glm::mat4 projection;
	
	// camera Attributes
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	float yaw;
	float pitch;

	float movSpeed;
	float mouseSensitivity;
	float zoom;

	double deltaTime;


	Camera (std::string name, glm::vec3 Position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f), float Yaw = YAW, float Pitch = PITCH) : front(glm::vec3(0.0f, 0.0f, -1.0f)), movSpeed(SPEED), mouseSensitivity(SENSITIVITY), zoom(ZOOM) {

		cameraName = name;
		projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
		position = Position;
		worldUp = Up;
		yaw = Yaw;
		pitch = Pitch;
		updateCameraVectors();
	}


	glm::mat4 GetViewMatrix() {
		return glm::lookAt(position, position + front, up);
	}

	// processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
	void ProcessKeyboard(Camera_Movement direction)
	{
		float velocity = movSpeed * deltaTime;
		if (direction == FORWARD)
			position += front * velocity;
		if (direction == BACKWARD)
			position -= front * velocity;
		if (direction == LEFT)
			position -= right * velocity;
		if (direction == RIGHT)
			position += right * velocity;
	}

	// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true)
	{
		xoffset *= mouseSensitivity;
		yoffset *= mouseSensitivity;

		yaw += xoffset;
		pitch += yoffset;

		// make sure that when pitch is out of bounds, screen doesn't get flipped
		if (constrainPitch)
		{
			if (pitch > 89.0f)
				pitch = 89.0f;
			if (pitch < -89.0f)
				pitch = -89.0f;
		}

		// update Front, Right and Up Vectors using the updated Euler angles
		updateCameraVectors();
	}

	// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
	void ProcessMouseScroll(float yoffset)
	{
		zoom -= (float)yoffset;
		if (zoom < 1.0f)
			zoom = 1.0f;
		if (zoom > 45.0f)
			zoom = 45.0f;
	}







private:

	void updateCameraVectors() {

		// calculate the new Front vector
		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		front.y = sin(glm::radians(pitch));
		front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		front = glm::normalize(front);
		// also re-calculate the Right and Up vector
		right = glm::normalize(glm::cross(front, worldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		up = glm::normalize(glm::cross(right, front));
	}

};