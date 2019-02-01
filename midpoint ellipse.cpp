#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;

int xc,yc,rx,ry;
void display();
void init();
void midellipse();

int main(int argc,char** argv)
{
    cout<<"enter coordinates x and y : ";
    cin>>xc>>yc;
    cout<<"enter radius rx and ry: ";
    cin>>rx>>ry;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB| GLUT_SINGLE);

    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);

    glutCreateWindow("midpoint ellipse");
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
    glPointSize(4);
    midellipse();
    glutSwapBuffers();
    glFlush();


}
void midellipse()
{
    float x,y,p;
    p=ry*ry-rx*rx*ry+rx*rx/4;
    x=0;
    y=ry;

    while(2.0*ry*ry*x <= 2.0*rx*rx*y)
    {
        glBegin(GL_POINTS);
        glVertex2f(xc+x,yc+y);
        glVertex2f(xc+x,yc-y);
        glVertex2f(xc-x,yc+y);
        glVertex2f(xc-x,yc-y);
        glEnd();
        if(p < 0)
        {
            x++;
            p = p+2*ry*ry*x+ry*ry;
        }
        else
        {
            x++;
            y--;
            p = p+2*ry*ry*x-2*rx*rx*y-ry*ry;
        }

        cout<<" "<<x<<" "<<y<<endl;
    }

    p=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
    while(y > 0)
    {
        glBegin(GL_POINTS);
        glVertex2f(xc+x,yc+y);
        glVertex2f(xc+x,yc-y);
        glVertex2f(xc-x,yc+y);
        glVertex2f(xc-x,yc-y);
        glEnd();
        if(p <= 0)
        {
            x++;
            y--;
            p = p+2*ry*ry*x-2*rx*rx*y+rx*rx;
        }
        else
        {
            y--;
            p = p-2*rx*rx*y+rx*rx;
        }
        cout<<" "<<x<<" "<<y<<endl;
    }

    glBegin(GL_POINTS);
    glVertex2f(xc,yc);
    glEnd();

}

