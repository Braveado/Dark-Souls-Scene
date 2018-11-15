#ifndef __Niebla
#define __Niebla

#include <gl\GLU.h>
#include <gl\GL.h>

class Niebla
{
public:
	GLfloat Color[4];
	GLfloat densidad;
	void draw() {
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_FOG); 
		glFogi(GL_FOG_MODE, GL_EXP2); 
		glFogfv(GL_FOG_COLOR, Color); 
		glFogf(GL_FOG_DENSITY, densidad);
		glHint(GL_FOG_HINT, GL_NICEST);
		//glFogf(GL_FOG_START, 250);
		//glFogf(GL_FOG_END, -250);
	}
};

#endif