// lp little ai c++.cpp : Defines the entry point for the application.
//

#include "lp little ai c++.h"
#include "glut/glut.h"
#include "glfont/GLFont.h"
#include "glfont/FTLabel.h"

using namespace std;

GLfloat normalizeWidth(GLfloat x) {
    return x / 320;
}

GLfloat normalizeHeight(GLfloat y) {
    return y / 320;
}


void drawFont(unique_ptr<FTLabel>* to) {
    shared_ptr<GLFont> glFont = shared_ptr<GLFont>(new GLFont("assets/fonts/roboto_regular.ttf"));
    // Some values we will use to create our labels
    int startX = 100;
    int startY = 100;
    int windowWidth = 320;
    int windowHeight = 320;

    unique_ptr<FTLabel> label = unique_ptr<FTLabel>(new FTLabel(
        glFont,         // Font face handle
        "Hello world!", // Text to render
        startX,
        startY,
        windowWidth,
        windowHeight
    ));

    label->setPixelSize(24);
    label->setIndentation(50);
    label->setAlignment(FTLabel::FontFlags::LeftAligned);
    label->setColor(0.89, 0.26, 0.3, 0.9);

    label->render();
}


void drawCircle(float cx, float cy, float r, int numSegments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);  // Get the current angle

        float x = r * cosf(theta);  // Calculate the x component
        float y = r * sinf(theta);  // Calculate the y component

        float distance = sqrt(x * x + y * y);
        float gradient = distance / r;  // Gradient value from 0 to 1

        // Set color based on the gradient (values in the range [0, 1])
        float randomRed = static_cast<float>(rand()) / RAND_MAX;
        float randomGreen = static_cast<float>(rand()) / RAND_MAX;
        float randomBlue = static_cast<float>(rand()) / RAND_MAX;
        float randomAlpha = static_cast<float>(rand()) / RAND_MAX;

        glColor4f(randomRed, randomGreen, randomBlue, randomAlpha);


        glVertex2f(x + cx, y + cy);  // Output normalized vertex
        std::cout << "x: " << x + cx << " y: " << y + cy << " r: " << r << std::endl;
    }
    glEnd();
}


void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

    // Draw a Red 1x1 Square centered at origin
    //glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    //glColor3f(1.0f, 0.0f, 0.0f); // Red
    //glVertex2f(-0.5f, -0.5f);    // x, y
    //glVertex2f(0.5f, -0.5f);
    //glVertex2f(0.5f, 0.5f);
    //glVertex2f(-0.5f, 0.5f);
    //glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(0.5, 0.5, 0.25, 100);
    drawFont();
    glFlush();  // Render now
}

int main(int argc, char** argv)
{
    srand(time(NULL));
    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner

    glutDisplayFunc(display); // Register display callback handler for window re-paint

    gluOrtho2D(0, 1, 1, 0);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glutMainLoop();           // Enter the infinitely event-processing loop
    return 0;
}
