#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

bool isWindowHasIssue(GLFWwindow* window) {
	return window == NULL;
}

void showError() {
	std::cout << "Failed to create GLFW Window" << std::endl;
	glfwTerminate();
	return;
}

int main() 
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(400, 225, "Small rainbow window", NULL, NULL);

	if (isWindowHasIssue(window)) {
		showError();
	}
	
	// Set the window active
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL
	gladLoadGL();

	// Specify the viewport (from x = 0, y = 0 to x = 400,y = 225)
	glViewport(0, 0, 400, 225);

	glClearColor(1.0f, 0.50f, 0.50f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	float prev_time = float(glfwGetTime());
	float a = 0.0f;

	while (!glfwWindowShouldClose(window)) {
		float time = float(glfwGetTime());
		if (time - prev_time >= 0.1f) {
			a += 0.1f;
			prev_time = time;
		}
		glClearColor(float(sin(a)), float(cos(a)), float(tan(a)), 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

