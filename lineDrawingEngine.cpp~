#include <iostream>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

struct Line {
    int x0, y0, x1, y1;
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

vector<Line> init(int numOfLines);
Line genRandomLine();
int genRandomInt(int min, int max);
void draw(vector<Line> lines);
void drawLineBasic(int x0, int y0, int x1, int y1);
void drawLineBresenham(int x0, int y0, int x1, int y1);
void drawPixel(int x, int y);

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

vector<Line> init(int numOfLines) {
    vector<Line> lines;

    srand(time(nullptr));
    
    for(int i = 0; i < numOfLines; i++) {
	Line line = genRandomLine();
	
	lines.push_back(line);
    }

    return lines;
}

Line genRandomLine() {
    Line line;
    int x0, y0, x1, y1;

    x0 = genRandomInt(0, WIDTH);
    y0 = genRandomInt(0, HEIGHT);
    x1 = genRandomInt(0, WIDTH);
    y1 = genRandomInt(0, HEIGHT);
    
    while((x0 == x1) && (y0 == y1)) {
	x0 = genRandomInt(0, WIDTH);
	y0 = genRandomInt(0, HEIGHT);
	x1 = genRandomInt(0, WIDTH);
	y1 = genRandomInt(0, HEIGHT);
    }

    line.x0 = x0;
    line.y0 = y0;
    line.x1 = x1;
    line.y1 = y1;
    
    return line;
}

int genRandomInt(int min, int max) {
    return rand() % max + min;
}

void draw(vector<Line> lines) {
    glClear(GL_COLOR_BUFFER_BIT);

    // auto t1 = chrono::high_resolution_clock::now();
    
    for(int i = 0; i < lines.size(); i++) {
    	Line currentLine = lines.at(i);

        drawLineBasic(currentLine.x0, currentLine.y0,
    		      currentLine.x1, currentLine.y1);
        
    	// drawLineBresenham(currentLine.x0, currentLine.y0,
    	// 		  currentLine.x1, currentLine.y1);
    }

    // auto t2 = chrono::high_resolution_clock::now();

    // auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    // cout << "duration: " << duration << " microseconds" << endl;

    // drawLineBasic(0, 0, 10, 5);
    //drawLineBresenham(0, 0, 10, 5);
    // drawLineBresenham(10, 5, 3, 8);
    // drawLineBresenham(0, 0, -10, 5);
    
    // // Octant Test:
    // //drawLineBasic(0 + 400, 0 + 300, (10 * 20) + 400, (5 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (10 * 20) + 400, (5 * 20) + 300);

    // //drawLineBasic(0 + 400, 0 + 300, (8 * 20) + 400, (8 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (8 * 20) + 400, (8 * 20) + 300);
    
    // //drawLineBasic(0 + 400, 0 + 300, (5 * 20) + 400, (10 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (5 * 20) + 400, (10 * 20) + 300);

    // //drawLineBasic(0 + 400, 0 + 300, (-5 * 20) + 400, (10 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (-5 * 20) + 400, (10 * 20) + 300);

    // //drawLineBasic(0 + 400, 0 + 300, (-8 * 20) + 400, (8 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (-8 * 20) + 400, (8 * 20) + 300);
   
    // //drawLineBasic(0 + 400, 0 + 300, (-10 * 20) + 400, (5 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (-10 * 20) + 400, (5 * 20) + 300);

    // //drawLineBasic(0 + 400, 0 + 300, (-10 * 20) + 400, (-5 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (-10 * 20) + 400, (-5 * 20) + 300);

    // //drawLineBasic(0 + 400, 0 + 300, (-8 * 20) + 400, (-8 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (-8 * 20) + 400, (-8 * 20) + 300);
    
    // //drawLineBasic(0 + 400, 0 + 300, (-5 * 20) + 400, (-10 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (-5 * 20) + 400, (-10 * 20) + 300);

    // //drawLineBasic(0 + 400, 0 + 300, (5 * 20) + 400, (-10 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (5 * 20) + 400, (-10 * 20) + 300);

    // //drawLineBasic(0 + 400, 0 + 300, (8 * 20) + 400, (-8 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (8 * 20) + 400, (-8 * 20) + 300);
    
    // //drawLineBasic(0 + 400, 0 + 300, (10 * 20) + 400, (-5 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (10 * 20) + 400, (-5 * 20) + 300);

    // //drawLineBasic(0 + 400, 0 + 300, (0 * 20) + 400, (10 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (0 * 20) + 400, (10 * 20) + 300);

    // //drawLineBasic(0 + 400, 0 + 300, (0 * 20) + 400, (-10 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (0 * 20) + 400, (-10 * 20) + 300);

    // //drawLineBasic(0 + 400, 0 + 300, (10 * 20) + 400, (0 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (10 * 20) + 400, (0 * 20) + 300);

    // //drawLineBasic(0 + 400, 0 + 300, (-10 * 20) + 400, (0 * 20) + 300);
    // drawLineBresenham(0 + 400, 0 + 300, (-10 * 20) + 400, (0 * 20) + 300);

    // From assignment PDF
    //drawLineBasic(10, 10, 30, 10);
    //drawLineBresenham(10, 10, 30, 10);

    //drawLineBasic(10, 10, 10, 30);
    //drawLineBresenham(10, 10, 10, 30);

    //drawLineBasic(30, 10, 10, 10);
    //drawLineBresenham(30, 10, 10, 10);

    //drawLineBasic(10, 30, 10, 10);
    //drawLineBresenham(10, 30, 10, 10);

    //drawLineBasic(10, 10, 20, 30);
    //drawLineBresenham(10, 10, 20, 30);

    //drawLineBasic(10, 30, 20, 10);
    //drawLineBresenham(10, 30, 20, 10);

    //drawLineBasic(20, 30, 10, 10);
    //drawLineBresenham(20, 30, 10, 10);

    //drawLineBasic(20, 10, 10, 30);
    //drawLineBresenham(20, 10, 10, 30);
    
    glFlush();
}

void drawLineBasic(int x0, int y0, int x1, int y1) {
    // cout << "Original coordinates: " << endl;
    // cout << "x0: " << x0 << endl;
    // cout << "y0: " << y0 << endl;
    // cout << "x1: " << x1 << endl;
    // cout << "y1: " << y1 << endl;
    
    float deltaX = x1 - x0;
    // cout << "deltaX: " << deltaX << endl;
    float deltaY = y1 - y0;
    // cout << "deltaY: " << deltaY << endl;
    float slope = deltaY / deltaX;
    // cout << "slope: " << slope << endl;

    if(deltaY == 0) {
	if(deltaX < 0) {
	    int tempX0 = x0;
	    int tempY0 = y0;

	    x0 = x1;
	    y0 = y1;

	    x1 = tempX0;
	    y1 = tempY0;

	    // cout << "Updated coordinates (swapped): " << endl;
	    // cout << "x0: " << x0 << endl;
	    // cout << "y0: " << y0 << endl;
	    // cout << "x1: " << x1 << endl;
	    // cout << "y1: " << y1 << endl;
	}
	
	for(int i = 0; i < abs(deltaX); i++) {
	    int x = x0 + i;
	    // cout << "x: " << x << endl;

	    drawPixel(x, y0);
	}
    }

    else if(deltaX == 0) {
	if(deltaY < 0) {
	    int tempX0 = x0;
	    int tempY0 = y0;

	    x0 = x1;
	    y0 = y1;

	    x1 = tempX0;
	    y1 = tempY0;

	    // cout << "Updated coordinates (swapped): " << endl;
	    // cout << "x0: " << x0 << endl;
	    // cout << "y0: " << y0 << endl;
	    // cout << "x1: " << x1 << endl;
	    // cout << "y1: " << y1 << endl;
	}

	for(int i = 0; i < abs(deltaY); i++) {
	    int y = y0 + i;
	    // cout << "y: " << y << endl;

	    drawPixel(x0, y);
	}
    }
    
    else if(abs(slope) < 1) {
	if(deltaX < 0) {
	    int tempX0 = x0;
	    int tempY0 = y0;

	    x0 = x1;
	    y0 = y1;

	    x1 = tempX0;
	    y1 = tempY0;

	    // cout << "Updated coordinates (swapped): " << endl;
	    // cout << "x0: " << x0 << endl;
	    // cout << "y0: " << y0 << endl;
	    // cout << "x1: " << x1 << endl;
	    // cout << "y1: " << y1 << endl;
	}

	for(int i = 0; i < abs(deltaX); i++) {
	    int x = x0 + i;
	    // cout << "x: " << x << endl;
	    int y = slope * i + y0;
	    // cout << "y: " << y << endl;
	    
	    drawPixel(x, y);
	}
    }

    else {
	if(deltaY < 0) {
	    int tempX0 = x0;
	    int tempY0 = y0;

	    x0 = x1;
	    y0 = y1;

	    x1 = tempX0;
	    y1 = tempY0;

	    // cout << "Updated coordinates (swapped): " << endl;
	    // cout << "x0: " << x0 << endl;
	    // cout << "y0: " << y0 << endl;
	    // cout << "x1: " << x1 << endl;
	    // cout << "y1: " << y1 << endl;
	}

	float intercept = -slope * x0 + y0;
	
    	for(int i = 0; i < abs(deltaY); i++) {
    	    int y = y0 + i;
	    // cout << "y: " << y << endl;
    	    int x = (y - intercept) / slope;
	    // cout << "x: " << x << endl;

    	    drawPixel(x, y);
    	}
    }
}

void drawLineBresenham(int x0, int y0, int x1, int y1) {
    // cout << "Original coordinates: " << endl;
    // cout << "x0: " << x0 << endl;
    // cout << "y0: " << y0 << endl;
    // cout << "x1: " << x1 << endl;
    // cout << "y1: " << y1 << endl;
 
    int deltaX = x1 - x0;
    // cout << "deltaX: " << deltaX << endl;
    int deltaY = y1 - y0;
    // cout << "deltaY: " << deltaY << endl;
    int xInc = 1;
    // cout << "xInc: " << xInc << endl;
    int yInc = 1;
    // cout << "yInc: " << yInc << endl;

    int error = 0;
    int inc1 = 0;
    int inc2 = 0;

    int x = x0;
    int y = y0;

    if(deltaY == 0) {
	// cout << "In (deltaY == 0) block" << endl;
	
	if(x1 < x0) {
	    int tempX0 = x0;
	    int tempY0 = y0;
	
	    x0 = x1;
	    y0 = y1;
	
	    x1 = tempX0;
	    y1 = tempY0;

	    deltaX = x1 - x0;
	    deltaY = y1 - y0;
	
	    // cout << "Updated coordinates (swapped): " << endl;
	    // cout << "x0: " << x0 << endl;
	    // cout << "y0: " << y0 << endl;
	    // cout << "x1: " << x1 << endl;
	    // cout << "y1: " << y1 << endl;

	    // cout << "deltaX (updated): " << deltaX << endl;
	    // cout << "deltaY (updated): " << deltaY << endl;
	}
	
	for(int x = x0; x < x1; x++) {
	    // cout << "x: " << x << endl;
	    
	    drawPixel(x, y0);
	}
    }

    else if(deltaX == 0) {
	// cout << "In (deltaX == 0) block" << endl;
	
	if(y1 < y0) {
	    int tempX0 = x0;
	    int tempY0 = y0;
	
	    x0 = x1;
	    y0 = y1;
	
	    x1 = tempX0;
	    y1 = tempY0;

	    deltaX = x1 - x0;
	    deltaY = y1 - y0;
	
	    // cout << "Updated coordinates (swapped): " << endl;
	    // cout << "x0: " << x0 << endl;
	    // cout << "y0: " << y0 << endl;
	    // cout << "x1: " << x1 << endl;
	    // cout << "y1: " << y1 << endl;

	    // cout << "deltaX (updated): " << deltaX << endl;
	    // cout << "deltaY (updated): " << deltaY << endl;
	}
	
	for(int y = y0; y < y1; y++) {
	    // cout << "y: " << y << endl;
	    
	    drawPixel(x0, y);
	}
    }

    else if(abs(deltaX) > abs(deltaY)) {
	// cout << "In (deltaX > deltaY) block" << endl;
	
 	if(x1 < x0) {
	    int tempX0 = x0;
	    int tempY0 = y0;
	
	    x0 = x1;
	    y0 = y1;
	
	    x1 = tempX0;
	    y1 = tempY0;

	    deltaX = x1 - x0;
	    deltaY = y1 - y0;

	    y = y0;
	    
	    // cout << "Updated coordinates (swapped): " << endl;
	    // cout << "x0: " << x0 << endl;
	    // cout << "y0: " << y0 << endl;
	    // cout << "x1: " << x1 << endl;
	    // cout << "y1: " << y1 << endl;

	    // cout << "deltaX (updated): " << deltaX << endl;
	    // cout << "deltaY (updated): " << deltaY << endl;
	}

	if(deltaY < 0) {
	    yInc = -1;
	    deltaY = -deltaY;

	    // cout << "yInc (updated): " << yInc << endl;
	    // cout << "deltaY (updated): " << deltaY << endl;
	}

	// cout << "Calculating error with deltaX > deltaY" << endl;
	error = (deltaY << 1) - deltaX;
	// cout << "error (initial): " << error << endl;
	inc1 = deltaY << 1;
	// cout << "inc1: " << inc1 << endl;
	inc2 = (deltaY - deltaX) << 1;
	// cout << "inc2: " << inc2 << endl;
	
	for(int x = x0; x < x1; x++) {
	    // cout << "x: " << x << endl;
	    // cout << "y: " << y << endl;
		
	    drawPixel(x, y);

	    if(error < 0)
		error += inc1;

	    else {
		y += yInc;
		error += inc2;
	    }
	}
    }

    else {
	// cout << "In else block" << endl;
	
	if(y1 < y0) {
	    int tempX0 = x0;
	    int tempY0 = y0;
	
	    x0 = x1;
	    y0 = y1;
	
	    x1 = tempX0;
	    y1 = tempY0;

	    deltaX = x1 - x0;
	    deltaY = y1 - y0;

	    x = x0;
	    
	    // cout << "Updated coordinates (swapped): " << endl;
	    // cout << "x0: " << x0 << endl;
	    // cout << "y0: " << y0 << endl;
	    // cout << "x1: " << x1 << endl;
	    // cout << "y1: " << y1 << endl;

	    // cout << "deltaX (updated): " << deltaX << endl;
	    // cout << "deltaY (updated): " << deltaY << endl;
	}

	if(deltaX < 0) {
	    xInc = -1;
	    deltaX = -deltaX;
		
	    // cout << "xInc (updated): " << xInc << endl;
	    // cout << "deltaX (updated): " << deltaX << endl;
	}

	// cout << "Calculating error with deltaY > deltaX" << endl;
	error = (deltaX << 1) - deltaY;
	inc1 = deltaX << 1;
	inc2 = (deltaX - deltaY) << 1;

	for(int y = y0; y < y1; y++) {
	    // cout << "x: " << x << endl;
	    // cout << "y: " << y << endl;
		
	    drawPixel(x, y);

	    if(error < 0)
		error += inc1;

	    else {
		x += xInc;
		error += inc2;
	    }
	}
    }
}

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    
    glVertex2f(x + 0.5, (HEIGHT - y) - 0.5);

    glEnd();
}

int main(int argc, char * argv[]) {
    GLFWwindow* window;
    int numOfLines = 10; // default is 10

    if(argc > 1)
	numOfLines = atoi(argv[1]);
    
    if(!glfwInit()) {
        cerr << "GLFW initialization failed" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(WIDTH, HEIGHT, "Assignment 1 - Austin Schultz", NULL, NULL);
    if(!window) {
        cerr << "OpenGL Context/Window creation failed" << endl;
        glfwTerminate();
        return 0;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        cerr << "GLAD initialization failed" << endl;
        return -1;
    }
        
    //glfwGetFramebufferSize(window, &width, &height);
    
    glViewport(0, 0, WIDTH, HEIGHT);
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    
    glDisable(GL_DEPTH_TEST);

    vector<Line> lines = init(numOfLines);
    
    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 1.0f, 1.0f);
    
	draw(lines);
        
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
