#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;

int xc,yc,r;
void display();
void init();
void midcircle();

int main(int argc,char** argv)
{
    cout<<"enter coordinates x and y : ";
    cin>>xc>>yc;
    cout<<"enter radius: ";
    cin>>r;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB| GLUT_SINGLE);

    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);

    glutCreateWindow("Midpoint circle");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

}

void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glViewport(0,0,640,480);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300,300,-300,300);
    glMatrixMode(GL_MODELVIEW);


}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1,0,0);
    midcircle();
    glutSwapBuffers();
    glFlush();


}
void midcircle()
{
    int x,y;
    x=0;
    y=r;
    float pk=(5.0/4.0)-r;

    glBegin(GL_POINTS);
    glVertex2f(xc+x,yc+y);
    glVertex2f(xc-x,yc+y);
    glVertex2f(xc+x,yc-y);
    glVertex2f(xc-x,yc-y);
    glVertex2f(xc+y,yc+x);
    glVertex2f(xc+y,yc-x);
    glVertex2f(xc-y,yc+x);
    glVertex2f(xc-y,yc-x);
    glEnd();


    while(x < y)
    {
        glBegin(GL_POINTS);
        glVertex2f(xc+x,yc+y);
        glVertex2f(xc-x,yc+y);
        glVertex2f(xc+x,yc-y);
        glVertex2f(xc-x,yc-y);
        glVertex2f(xc+y,yc+x);
        glVertex2f(xc+y,yc-x);
        glVertex2f(xc-y,yc+x);
        glVertex2f(xc-y,yc-x);
        glEnd();

        x = x + 1;
        if(pk < 0)
            pk = pk + 2*x+1;
        else
        {
            y = y - 1;
            pk = pk + 2*(x - y) + 1;
        }
        cout<<count++<<" "<<x<<" "<<y<<endl;

    }
    glBegin(GL_POINTS);
    glVertex2f(xc,yc);
    glEnd();

}
