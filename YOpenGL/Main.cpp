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

	GLFWwindow* window = glfwCreateWindow(800, 800, "YOpenGL", NULL, NULL);

	if (isWindowHasIssue(window)) {
		showError();
	}
	
	// Set the window active
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL
	gladLoadGL();

	// Specify the viewport (from x = 0, y = 0 to x = 800,y = 800)
	glViewport(0, 0, 800, 800);

	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

