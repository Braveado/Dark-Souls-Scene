#ifndef __Escena
#define __Escena

#include <gl\GLU.h>
#include <gl\GL.h>
#include "SkyDome.h"
#include "Terreno.h"
#include "Model.h"
#include "Water.h"
#include "Billboard.h"
#include "Niebla.h"
#include "Animaciones.h"

class Camara
{
public:
	GLdouble px, py, pz, dx, dy, dz, ux, uy, uz;
	int camind = 2;
	bool auxy = false, sswalkaux = false;
	float escang = 70, espang = 120, auxang = 0, sswalk = 0;

	Camara()
	{
	}

	void CamaraI()
	{
		px = -168, py = 23, pz = 235, dx = -168, dy = 20, dz = 250;
		ux = 0, uy = 1, uz = 0;
		gluLookAt(px, py, pz, dx, dy, dz, ux, uy, uz);
	}

	void CamaraU()
	{
		gluLookAt(px, py, pz, dx, dy, dz, ux, uy, uz);
	}

	void MoverDerecha()
	{
		//debe empezar viendo a z negativa, si no camina al reves, el if es para no salirse del terreno
		//inicio cuenca
		if (pz >= 225 && pz <= 250 && px > -175)
		{
			px -= 1;
			dx -= 1;
		}
		//zona de golems 1
		else if (pz >= 110 && pz <= 225 && px > -150)
		{
			px -= 1;
			dx -= 1;
		}
		//zona de golems 2
		else if (pz >= 80 && pz <= 110 && px > -125)
		{
			px -= 1;
			dx -= 1;
		}
		//zona de golems 3
		else if (pz >= 60 && pz <= 80 && px > -95)
		{
			px -= 1;
			dx -= 1;
		}
		//zona de hydra 1
		else if (pz >= 5 && pz <= 60 && px > -70)
		{
			px -= 1;
			dx -= 1;
		}
		//zona de hydra 2
		else if (pz >= -15 && pz <= 5 && px > -80 && auxy == false && py < 55)
		{
			px -= 1;
			dx -= 1;
		}
		//zona de hydra 3
		else if (pz >= -40 && pz <= -15 && px > -85 && auxy == false)
		{
			px -= 1;
			dx -= 1;
		}
		//zona de hydra 4 y espadon
		else if (pz >= -65 && pz <= -40 && px > -210 && auxy == false)
		{
			px -= 1;
			dx -= 1;
		}
		//zona de hydra 5 y escalera
		else if (pz >= -160 && pz <= -65 && px > -80)
		{
			auxy = false;
			px -= 1;
			dx -= 1;
		}
		//escalera 1
		else if (pz <= -91 && pz >= -95 && px <= -80 && py < 63)
		{
			auxy = true;
			px -= 0.5;
			dx -= 0.5;
			py += 2;
			dy += 2;
		}
		//escalera 2
		else if (pz >= -95 && pz <= -91 && px > -96)
		{
			auxy = true;
			px -= 1;
			dx -= 1;
		}
		//entre escalera y puente
		else if (pz >= -108 && pz <= -89 && px > -128 && py > 60)
		{
			auxy = false;
			px -= 1;
			dx -= 1;
		}
		//puente
		else if (pz >= -89 && pz <= -13 && px > -114 && py > 60)
		{
			auxy = true;
			px -= 1;
			dx -= 1;
		}
		//zona del lagarto
		else if (pz >= -13 && pz <= -2 && px > -235 && py > 55)
		{
			auxy = false;
			px -= 1;
			dx -= 1;
		}
		//inicio AL
		else if (pz >= 251 && pz <= 264 && px > -3)
		{
			px -= 1;
			dx -= 1;
		}
		//escaleras gigantes
		else if (pz >= 264 && pz <= 363 && px > -9)
		{
			px -= 1;
			dx -= 1;
		}// entre las mini escaleras
		else if (pz >= 363 && pz <= 384 && px > -3)
		{
			px -= 1;
			dx -= 1;
		}//area antes de la entrada principal
		else if (pz >= 384 && pz <= 395 && px > -30)
		{
			px -= 1;
			dx -= 1;
		}
		//entrada principal
		else if (pz >= 395 && pz <= 434 && px > -6 && py < 87)
		{
			px -= 1;
			dx -= 1;
		}
		//salon principal 1
		else if (pz >= 434 && pz <= 538 && px > -6 && py < 62)
		{
			px -= 1;
			dx -= 1;
		}
		//salon principal 2
		else if (pz >= 538 && pz <= 546 && px > -27 && py < 62)
		{
			px -= 1;
			dx -= 1;
		}
		//salon principal 3
		else if (pz >= 546 && pz <= 587 && px > -6 && py < 62)
		{
			px -= 1;
			dx -= 1;
		}
		//entrada al jefe
		else if (pz >= 587 && pz <= 624 && px > -6 && px < 31)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere izq 1
		else if (pz >= 495 && pz <= 537 && px > 23 && px < 31 && px > 1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere der 1
		else if (pz >= 495 && pz <= 537 && px < -22 && px > -27 && px < -1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere izq 2
		else if (pz >= 495 && pz <= 507 && px <= 31 && px >= 27 && px > 1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere der 2
		else if (pz >= 495 && pz <= 577 && py >= 73 && px > -35 && px < 23 && px < -1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere izq 3
		else if (pz >= 495 && pz <= 577 && px > 31 && px < 40 && px > 1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere der 3
		else if (pz >= 538 && pz <= 577 && py >= 87 && px > -43 && px < -1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere izq 4
		else if (pz >= 538 && pz <= 577 && py >= 87 && px > 35 && px > 1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere der 4
		else if (pz >= 434 && pz <= 538 && py >= 87 && px > -43 && px < -1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere izq 5
		else if (pz >= 434 && pz <= 538 && py >= 87 && px > 40 && px > 1)
		{
			px -= 1;
			dx -= 1;
		}
	}

	void MoverIzquierda()
	{
		//debe empezar viendo a z negativa, si no camina al reves, el if es para no salirse del terreno
		//inicio cuenca
		if (pz >= 225 && pz <= 250 && px < 180)
		{
			px += 1;
			dx += 1;
		}
		//zona de golems 1
		else if (pz >= 80 && pz <= 225 && px < 150)
		{
			px += 1;
			dx += 1;
		}
		//zona de golems 2 e hydra 1
		else if (pz >= 25 && pz <= 80 && px < 170)
		{
			px += 1;
			dx += 1;
		}
		//zona de hydra 2
		else if (pz >= 5 && pz <= 25 && px < 25)
		{
			px += 1;
			dx += 1;
		}
		//zona de hydra 3
		else if (pz >= -15 && pz <= 5 && px < 0 && auxy == false && py < 60)
		{
			px += 1;
			dx += 1;
		}
		//zona de hydra 4
		else if (pz >= -40 && pz <= -15 && px < -25 && auxy == false)
		{
			px += 1;
			dx += 1;
		}
		//zona de hydra 5 y espadon
		else if (pz >= -65 && pz <= -40 && px < -45 && auxy == false)
		{
			px += 1;
			dx += 1;
		}
		//zona de hydra 6 y escalera
		else if (pz >= -160 && pz <= -65 && px < -55 && px >= -80)
		{
			auxy = false;
			px += 1;
			dx += 1;
		}
		//escalera 1
		else if (pz >= -95 && pz <= -91 && px < -90)
		{
			auxy = true;
			px += 1;
			dx += 1;
		}
		//escalera 2
		else if (pz <= -91 && pz >= -95 && px <= -80 && py > 24)
		{
			auxy = true;
			px += 0.5;
			dx += 0.5;
			py -= 2;
			dy -= 2;
		}
		//entre escalera y puente
		else if (pz >= -108 && pz <= -89 && px < -96)
		{
			auxy = false;
			px += 1;
			dx += 1;
		}
		//puente
		else if (pz >= -89 && pz < -13 && px < -110)
		{
			auxy = true;
			px += 1;
			dx += 1;
		}
		//zona del lagarto
		else if (pz >= -13 && pz <= -2 && px < -106)
		{
			auxy = false;
			px += 1;
			dx += 1;
		}
		//inicio AL
		else if (pz >= 251 && pz <= 264 && px < 3)
		{
			px += 1;
			dx += 1;
		}
		//escalera gigante
		else if (pz >= 264 && pz <= 363 && px < 9)
		{
			px += 1;
			dx += 1;
		}
		//entre las mini escaleras
		else if (pz >= 363 && pz <= 384 && px < 3)
		{
			px += 1;
			dx += 1;
		}
		//area antes de la entrada principal
		else if (pz >= 384 && pz <= 395 && px < 30)
		{
			px += 1;
			dx += 1;
		}
		//entrada principal
		else if (pz >= 395 && pz <= 434 && px < 6 && py < 87)
		{
			px += 1;
			dx += 1;
		}
		//salon principal 1
		else if (pz >= 434 && pz <= 538 && px < 6 && py < 62)
		{
			px += 1;
			dx += 1;
		}
		//salon principal 2
		else if (pz >= 538 && pz <= 546 && px < 27 && py < 62)
		{
			px += 1;
			dx += 1;
		}
		//salon principal 3
		else if (pz >= 546 && pz <= 587 && px < 6 && py < 62)
		{
			px += 1;
			dx += 1;
		}
		//entrada al jefe
		else if (pz >= 587 && pz <= 624 && px < 6)
		{
			px += 1;
			dx += 1;
		}
		//escalere izq 1
		else if (pz >= 495 && pz <= 537 && px < 27 && px > 22 && px > 1)
		{
			px += 1;
			dx += 1;
		}
		//escalere der 1
		else if (pz >= 495 && pz <= 537 && px < -23 && px > -31 && px < -1)
		{
			px += 1;
			dx += 1;
		}
		//escalere izq 2
		else if (pz >= 495 && pz <= 577 && py >= 73 && px < 35 && px > -23 && px > 1)
		{
			px += 1;
			dx += 1;
		}
		//escalere der 2
		else if (pz >= 495 && pz <= 507 && px >= -31 && px <= -27 && px < -1)
		{
			px += 1;
			dx += 1;
		}
		//escalere izq 3
		else if (pz >= 538 && pz <= 577 && py >= 87 && px < 43 && px > 1 && px > 1)
		{
			px += 1;
			dx += 1;
		}
		//escalere der 3
		else if (pz >= 495 && pz <= 577 && px < -31 && px > -40 && px < -1)
		{
			px += 1;
			dx += 1;
		}
		//escalere izq 4
		else if (pz >= 434 && pz <= 538 && py >= 87 && px < 43 && px > 1 && px > 1)
		{
			px += 1;
			dx += 1;
		}
		//escalere der 4
		else if (pz >= 538 && pz <= 577 && py >= 87 && px < -35 && px < -1)
		{
			px += 1;
			dx += 1;
		}
		//escalere der 5
		else if (pz >= 434 && pz <= 538 && py >= 87 && px < -40 && px < -1)
		{
			px += 1;
			dx += 1;
		}
	}

	void MoverAdelante()
	{
		//debe empezar viendo a z negativa, si no camina al reves, el if es para no salirse del terreno
		//inicio cuenca
		if (pz >= 225 && pz < 250 && px <= 180 && px >= -175)
		{
			pz += 1;
			dz += 1;
		}
		//zona de golems 1
		else if (pz >= 110 && pz < 225 && px <= 150 && px >= -150)
		{
			pz += 1;
			dz += 1;
		}
		//zona de golems 2
		else if (pz >= 80 && pz < 110 && px <= 150 && px >= -125)
		{
			pz += 1;
			dz += 1;
		}
		//zona de golems 3
		else if (pz >= 60 && pz < 80 && px <= 170 && px >= -95)
		{
			pz += 1;
			dz += 1;
		}
		//zona de hydra 1
		else if (pz >= 25 && pz < 60 && px <= 170 && px >= -70)
		{
			pz += 1;
			dz += 1;
		}
		//zona de hydra 2
		else if (pz >= 5 && pz < 25 && px <= 25 && px >= -70)
		{
			pz += 1;
			dz += 1;
		}
		//zona de hydra 3
		else if (pz >= -15 && pz < 5 && px <= 0 && px >= -80)
		{
			pz += 1;
			dz += 1;
		}
		//zona de hydra 4
		else if (pz >= -40 && pz < -15 && px <= -25 && px >= -85)
		{
			pz += 1;
			dz += 1;
		}
		//zona de hydra 5 y espadon
		else if (pz >= -65 && pz < -40 && px <= -45 && px >= -210 && auxy == false)
		{
			pz += 1;
			dz += 1;
		}
		//zona de hydra 6 y escalera
		else if (pz >= -160 && pz < -65 && px <= -55 && px >= -80)
		{
			auxy = false;
			pz += 1;
			dz += 1;
		}
		//entre escalera y puente
		else if (pz >= -108 && pz < -89 && px <= -96 && px >= -128)
		{
			auxy = false;
			pz += 1;
			dz += 1;
		}
		//puente
		else if (pz >= -89 && pz < -13 && px <= -110 && px >= -114)
		{
			auxy = true;
			pz += 1;
			dz += 1;
		}
		//zona del lagarto
		else if (pz >= -13 && pz < -2 && px <= -106 && px >= -235)
		{
			auxy = false;
			pz += 1;
			dz += 1;
		}
		//inicio AL
		else if (pz >= 250 && pz < 264 && px <= 3 && px >= -3)
		{
			pz += 1;
			dz += 1;
		}
		//entre inicio AL y escaleras gigante
		else if (pz >= 264 && pz < 308 && px <= 9 && px >= -9)
		{
			pz += 1;
			dz += 1;
		}
		//escalera gigante
		else if (pz >= 308 && pz < 363 && px <= 9 && px >= -9)
		{
			if (py < 54)
			{
				py += 0.6;
				dy += 0.6;
			}
			pz += 1;
			dz += 1;
		}
		//entre las mini escaleras
		else if (pz >= 363 && pz < 384 && px <= 3 && px >= -3)
		{
			pz += 1;
			dz += 1;
		}
		//area antes de la entrada principal
		else if (pz >= 384 && pz < 395 && px <= 30 && px >= -30)
		{
			pz += 1;
			dz += 1;
		}
		//entrada principal
		else if (pz >= 395 && pz < 434 && px <= 6 && px >= -6)
		{
			if (py < 61)
			{
				py += 0.6;
				dy += 0.6;
			}
			pz += 1;
			dz += 1;
		}
		//salon principal 1
		else if (pz >= 434 && pz < 538 && px <= 6 && px >= -6)
		{
			pz += 1;
			dz += 1;
		}
		//salon principal 2
		else if (pz >= 538 && pz < 546 && px <= 27 && px >= -27)
		{
			pz += 1;
			dz += 1;
		}
		//salon principal 3
		else if (pz >= 546 && pz < 587 && px <= 6 && px >= -6)
		{
			pz += 1;
			dz += 1;
		}
		//entrada al jefe
		else if (pz >= 587 && pz < 624 && px <= 6 && px >= -6)
		{
			if (py < 74 && pz >= 591)
			{
				py += 0.55;
				dy += 0.55;
			}
			pz += 1;
			dz += 1;
		}
		//escalera izq 1
		else if (pz >= 495 && pz < 538 && px <= 27 && px >= 23)
		{
			if (py > 61 && pz >= 508)
			{
				py -= 0.5;
				dy -= 0.5;
			}
			pz += 1;
			dz += 1;
		}
		//escalera der 1
		else if (pz >= 495 && pz < 538 && px >= -27 && px <= -23)
		{
			if (py > 61 && pz >= 508)
			{
				py -= 0.5;
				dy -= 0.5;
			}
			pz += 1;
			dz += 1;
		}
		//escalera izq 2
		else if (pz >= 495 && pz < 507 && px <= 31 && px >= 27)
		{
			pz += 1;
			dz += 1;
		}
		//escalera der 2
		else if (pz >= 495 && pz < 507 && px >= -31 && px <= -27)
		{
			pz += 1;
			dz += 1;
		}
		//escalera izq 3
		else if (pz >= 495 && pz < 577 && px <= 35 && px >= 31)
		{
			if (py < 87 && pz >= 509)
			{
				py += 0.5;
				dy += 0.5;
			}
			pz += 1;
			dz += 1;
		}
		//escalera der 3
		else if (pz >= 495 && pz < 577 && px >= -35 && px <= -31)
		{
			if (py < 87 && pz >= 509)
			{
				py += 0.5;
				dy += 0.5;
			}
			pz += 1;
			dz += 1;
		}
		//escalera izq 4
		else if (pz >= 538 && pz < 577 && px <= 39 && px >= 36)
		{
			pz += 1;
			dz += 1;
		}
		//escalera der 4
		else if (pz >= 538 && pz < 577 && px >= -39 && px <= -36)
		{
			pz += 1;
			dz += 1;
		}
		//escalera izq 5
		else if (pz >= 434 && pz < 577 && px <= 43 && px >= 40)
		{
			pz += 1;
			dz += 1;
		}
		//escalera izq 5
		else if (pz >= 434 && pz < 577 && px >= -43 && px <= -40)
		{
			pz += 1;
			dz += 1;
		}
	}

	void MoverAtras()
	{
		//debe empezar viendo a z negativa, si no camina al reves, el if es para no salirse del terreno
		//inicio cuenca
		if (pz > 225 && pz <= 250 && px <= 180 && px >= -175)
		{
			pz -= 1;
			dz -= 1;
		}
		//zona de golems 1
		else if (pz > 110 && pz <= 225 && px <= 150 && px >= -150)
		{
			pz -= 1;
			dz -= 1;
		}
		//zona de golems 2
		else if (pz > 80 && pz <= 110 && px <= 150 && px >= -125)
		{
			pz -= 1;
			dz -= 1;
		}
		//zona de golems 3
		else if (pz > 60 && pz <= 80 && px <= 170 && px >= -95)
		{
			pz -= 1;
			dz -= 1;
		}
		//zona de hydra 1
		else if (pz > 25 && pz <= 60 && px <= 170 && px >= -70)
		{
			pz -= 1;
			dz -= 1;
		}
		//zona de hydra 2
		else if (pz > 5 && pz <= 25 && px <= 25 && px >= -70)
		{
			pz -= 1;
			dz -= 1;
		}
		//zona de hydra 3
		else if (pz > -15 && pz <= 5 && px <= 0 && px >= -80)
		{
			pz -= 1;
			dz -= 1;
		}
		//zona de hydra 4
		else if (pz > -40 && pz <= -15 && px <= -25 && px >= -85)
		{
			pz -= 1;
			dz -= 1;
		}
		//zona de hydra 5 y espadon
		else if (pz > -65 && pz <= -40 && px <= -45 && px >= -210 && auxy == false)
		{
			pz -= 1;
			dz -= 1;
		}
		//zona de hydra 6 y escalera
		else if (pz > -160 && pz <= -65 && px <= -55 && px >= -80)
		{
			auxy = false;
			pz -= 1;
			dz -= 1;
		}
		//entre escalera y puente
		else if (pz > -108 && pz <= -89 && px <= -96 && px >= -128)
		{
			auxy = false;
			pz -= 1;
			dz -= 1;
		}
		//puente
		else if (pz > -89 && pz <= -13 && px <= -110 && px >= -114)
		{
			auxy = true;
			pz -= 1;
			dz -= 1;
		}
		//zona del lagarto
		else if (pz > -13 && pz <= -2 && px <= -106 && px >= -235)
		{
			auxy = false;
			pz -= 1;
			dz -= 1;
		}
		//inicio AL
		else if (pz > 250 && pz <= 264 && px <= 3 && px >= -3)
		{
			pz -= 1;
			dz -= 1;
		}
		//entre inicio AL y escaleras gigantes
		else if (pz > 264 && pz <= 308 && px <= 9 && px >= -9)
		{
			pz -= 1;
			dz -= 1;
		}
		//escalera gigante
		else if (pz > 308 && pz <= 363 && px <= 9 && px >= -9)
		{
			if (py > 24 && pz <= 356)
			{
				py -= 0.6;
				dy -= 0.6;
			}
			pz -= 1;
			dz -= 1;
		}
		//entre las mini escaleras
		else if (pz > 363 && pz <= 384 && px <= 3 && px >= -3)
		{
			pz -= 1;
			dz -= 1;
		}
		//area antes de la entrada principal
		else if (pz > 384 && pz <= 395 && px <= 30 && px >= -30)
		{
			pz -= 1;
			dz -= 1;
		}
		//entrada principal
		else if (pz > 395 && pz <= 434 && px <= 6 && px >= -6)
		{
			if (py > 54 && pz <= 406)
			{
				py -= 0.6;
				dy -= 0.6;
			}
			pz -= 1;
			dz -= 1;
		}
		//salon principal 1
		else if (pz > 434 && pz <= 538 && px <= 6 && px >= -6)
		{
			pz -= 1;
			dz -= 1;
		}
		//salon principal 2
		else if (pz > 538 && pz <= 546 && px <= 27 && px >= -27)
		{
			pz -= 1;
			dz -= 1;
		}
		//salon principal 3
		else if (pz > 546 && pz <= 587 && px <= 6 && px >= -6)
		{
			pz -= 1;
			dz -= 1;
		}
		//entrada el jefe
		else if (pz > 587 && pz <= 624 && px <= 6 && px >= -6)
		{
			if (py > 61 && pz <= 619)
			{
				py -= 0.55;
				dy -= 0.55;
			}
			pz -= 1;
			dz -= 1;
		}
		//escalera izq 1
		else if (pz > 495 && pz <= 538 && px <= 27 && px >= 23)
		{
			if (py < 74 && pz <= 535)
			{
				py += 0.5;
				dy += 0.5;
			}
			pz -= 1;
			dz -= 1;
		}
		//escalera der 1
		else if (pz > 495 && pz <= 538 && px >= -27 && px <= -23)
		{
			if (py < 74 && pz <= 535)
			{
				py += 0.5;
				dy += 0.5;
			}
			pz -= 1;
			dz -= 1;
		}
		//escalera izq 2
		else if (pz > 495 && pz <= 577 && px <= 35 && px >= 23)
		{
			if (py > 74 && pz <= 535)
			{
				py -= 0.5;
				dy -= 0.5;
			}
			pz -= 1;
			dz -= 1;
		}
		//escalera der 2
		else if (pz > 495 && pz <= 577 && px >= -35 && px <= -23)
		{
			if (py > 74 && pz <= 535)
			{
				py -= 0.5;
				dy -= 0.5;
			}
			pz -= 1;
			dz -= 1;
		}
		//escalera izq 3
		else if (pz > 538 && pz <= 577 && px <= 39 && px >= 36)
		{
			pz -= 1;
			dz -= 1;
		}
		//escalera der 3
		else if (pz > 538 && pz <= 577 && px >= -39 && px <= -36)
		{
			pz -= 1;
			dz -= 1;
		}
		//escalera izq 4
		else if (pz > 445 && pz <= 577 && px <= 43 && px >= 40)
		{
			pz -= 1;
			dz -= 1;
		}
		//escalera der 4
		else if (pz > 445 && pz <= 577 && px >= -43 && px <= -40)
		{
			pz -= 1;
			dz -= 1;
		}
	}

	void VoltearDerecha()
	{
		//debe empezar viendo a z negativa, si no gira al reves
		if (dx < 15 + px && camind == 0)
			dx += 1;
		else if (dx == 15 + px && camind == 0)
			camind = 1;
		if (dx == -15 + px && camind == 1 && dz > -15 + pz)
			dz -= 1;
		else if (dx == -15 + px && camind == 1 && dz == -15 + pz)
			camind = 0;
		else if (dz < 15 + pz && camind == 1)
			dz += 1;
		else if(dz == 15 + pz && camind == 1)
			camind = 2;
		if(dx > -15 + px && camind == 2)
			dx -= 1;
		else if(dx == -15 + px && camind == 2)
			camind = 3;
		if (dx == 15 + px && camind == 3 && dz < 15 + pz)
			dz += 1;
		else if (dx == 15 + px && camind == 3 && dz == 15 + pz)
			camind = 2;
		else if(dz > -15 + pz && camind == 3)
			dz -= 1;
		else if(dz == -15 + pz && camind == 3)
			camind = 0;

		escang += 3;
		espang += 3;
		auxang -= 3;
	}

	void VoltearIzquierda()
	{
		//debe empezar viendo a z negativa, si no gira al reves
		if (dx > -15 + px && camind == 0)
			dx -= 1;
		else if (dx == -15 + px && camind == 0)
			camind = 1;
		if (dx == 15 + px && camind == 1 && dz > -15 + pz)
			dz -= 1;
		else if (dx == 15 + px && camind == 1 && dz == -15 + pz)
			camind = 0;
		else if (dz < 15 + pz && camind == 1)
			dz += 1;
		else if (dz == 15 + pz && camind == 1)
			camind = 2;
		if (dx < 15 + px && camind == 2)
			dx += 1;
		else if (dx == 15 + px && camind == 2)
			camind = 3;
		if (dx == -15 + px && camind == 3 && dz < 15 + pz)
			dz += 1;
		else if (dx == -15 + px && camind == 3 && dz == 15 + pz)
			camind = 2;
		else if (dz > -15 + pz && camind == 3)
			dz -= 1;
		else if (dz == -15 + pz && camind == 3)
			camind = 0;

		escang -= 3;
		espang -= 3;
		auxang += 3;
	}

	void VoltearArriba()
	{
		if (dy < 50 + py)
		{
			dy += 1;
		}
	}

	void VoltearAbajo()
	{
		if (dy > -50 + py)
		{
			dy -= 1;
		}
	}
};

class Escena : public Camara
{
public:

	SkyDome *dia, *noche;
	Terreno *cuenca, *aux;
	Water *lago;
	Billboard *billBoard[100];
	Niebla niebla;
	Animaciones animacion;
	EDXFramework::Model *DS_AL, *DS_BK[3], *DS_Bonfire, *DS_Hollow[3], *DS_CG[3], *DS_CL[3], *DS_Stone, *DS_Stair, *DS_Hydra[3], *DS_Bridge, *DS_Mimic[2], *DS_Chest[3], *DS_Greatsword, *Tree[3], *Shield, *Sword;
	float piso, clposX = -115, clposZ = -6, bkposZ = 573, hydraposY = 20, cg4posX = -65, cg4posZ = 25, cg3posZ = 125, cg2posX = -80, cgposX = 0, cgposZ = 175, cgang = 0, posescudoX = 0, posescudoZ = 0, posespadaX = 0, posespadaZ = 0;
	bool AL = false, chest = false, mimic = false, cl = false, clip = false, hollow = true, bk = true, hydra = true, cg4 = true, cg3 = true, cg2 = true, musica = false;
	int chesti = 0, mimici = 0, clim, hollowi = 0, bki = 0, cg4i = 0, cg3i = 0, cg2i = 0, cgi = 0, bonfire = 1, hydrai = 0;

	Escena(HWND hWnd)
	{
		GLfloat AmbMat[] = { 1, 1, 1, 1 };
		GLfloat AmbPos[] = { 0, 400, 400, 1 };
		//GLfloat DifMat[] = { 1, 1, 1, 1 };
		//GLfloat DifInt[] = { 1, 1, 1, 1 };
		//GLfloat DifPos[] = { 50, 50, 0, 1 };
		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);
		//glMaterialfv(GL_FRONT, GL_DIFFUSE, DifMat);
		glEnable(GL_NORMALIZE);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, AmbPos);
		//glEnable(GL_LIGHT1);
		//glLightfv(GL_LIGHT1, GL_DIFFUSE, DifInt);
		//glLightfv(GL_LIGHT1, GL_POSITION, DifPos);
		noche = new SkyDome(hWnd, 32, 32, 500, L"Imagenes//Night.jpg");
		dia = new SkyDome(hWnd, 32, 32, 500, L"Imagenes//Day.jpg");
		cuenca = new Terreno(hWnd, L"Imagenes//Darkroot Basin Heightmap.jpg", L"Imagenes//floor.jpg", L"Imagenes//water.jpg", 512, 512);
		aux = new Terreno(hWnd, L"Imagenes//Aux Heightmap.jpg", L"Imagenes//rock.jpg", L"Imagenes//water.jpg", 512, 512);
		lago = new Water(hWnd, NULL, L"Imagenes//water.bmp", 300, 300);
		Billboards(billBoard, hWnd);
		niebla.densidad = 0.0025;
		DS_AL = new EDXFramework::Model("Modelos//DS_AL//DS_AL.obj", "Modelos//DS_AL//DS_AL.bmp", 0);
		DS_BK[0] = new EDXFramework::Model("Modelos//DS_BK//DS_BK.obj", "Modelos//DS_BK//DS_BK.bmp", 0);
		DS_BK[1] = new EDXFramework::Model("Modelos//DS_BK//DS_BK_Walking01.obj", "Modelos//DS_BK//DS_BK.bmp", 0);
		DS_BK[2] = new EDXFramework::Model("Modelos//DS_BK//DS_BK_Walking02.obj", "Modelos//DS_BK//DS_BK.bmp", 0);
		DS_Bonfire = new EDXFramework::Model("Modelos//DS_Bonfire//DS_Bonfire.obj", "Modelos//DS_Bonfire//DS_Bonfire.bmp", 1);
		DS_Hollow[0] = new EDXFramework::Model("Modelos//DS_Hollow//DS_Hollow.obj", "Modelos//DS_Hollow//DS_Hollow.bmp", 1);
		DS_Hollow[1] = new EDXFramework::Model("Modelos//DS_Hollow//DS_Hollow_Sentandose.obj", "Modelos//DS_Hollow//DS_Hollow.bmp", 1);
		DS_Hollow[2] = new EDXFramework::Model("Modelos//DS_Hollow//DS_Hollow_Sentado.obj", "Modelos//DS_Hollow//DS_Hollow.bmp", 1);
		Tree[0] = new EDXFramework::Model("Modelos//Tree//Tree_Fat.obj", "Modelos//Tree//Tree_Fat.bmp", 1);
		Tree[1] = new EDXFramework::Model("Modelos//Tree//Tree_Tall.obj", "Modelos//Tree//Tree_Tall.bmp", 1);
		Tree[2] = new EDXFramework::Model("Modelos//Tree//Tree_Spiky.obj", "Modelos//Tree//Tree_Spiky.bmp", 1);
		DS_CG[0] = new EDXFramework::Model("Modelos//DS_CG//DS_CG.obj", "Modelos//DS_CG//DS_CG.bmp", 1);
		DS_CG[1] = new EDXFramework::Model("Modelos//DS_CG//DS_CG_Walking01.obj", "Modelos//DS_CG//DS_CG.bmp", 1);
		DS_CG[2] = new EDXFramework::Model("Modelos//DS_CG//DS_CG_Walking02.obj", "Modelos//DS_CG//DS_CG.bmp", 1);
		DS_CL[0] = new EDXFramework::Model("Modelos//DS_CL//DS_CL.obj", "Modelos//DS_CL//DS_CL.bmp", 1);
		DS_CL[1] = new EDXFramework::Model("Modelos//DS_CL//DS_CL_Running01.obj", "Modelos//DS_CL//DS_CL.bmp", 1);
		DS_CL[2] = new EDXFramework::Model("Modelos//DS_CL//DS_CL_Running02.obj", "Modelos//DS_CL//DS_CL.bmp", 1);
		DS_Stone = new EDXFramework::Model("Modelos//DS_Stone//DS_Stone.obj", "Modelos//DS_Stone//DS_Stone.bmp", 1);
		DS_Stair = new EDXFramework::Model("Modelos//DS_Stair//DS_Stair.obj", "Modelos//DS_Stair//DS_Stair.bmp", 0);
		DS_Hydra[0] = new EDXFramework::Model("Modelos//DS_Hydra//DS_Hydra.obj", "Modelos//DS_Hydra//DS_Hydra.bmp", 1);
		DS_Hydra[1] = new EDXFramework::Model("Modelos//DS_Hydra//DS_Hydra_Flotando01.obj", "Modelos//DS_Hydra//DS_Hydra.bmp", 1);
		DS_Hydra[2] = new EDXFramework::Model("Modelos//DS_Hydra//DS_Hydra_Flotando02.obj", "Modelos//DS_Hydra//DS_Hydra.bmp", 1);
		DS_Bridge = new EDXFramework::Model("Modelos//DS_Bridge//DS_Bridge.obj", "Modelos//DS_Bridge//DS_Bridge.bmp", 0);
		DS_Mimic[0] = new EDXFramework::Model("Modelos//DS_Mimic//DS_Mimic.obj", "Modelos//DS_Mimic//DS_Mimic.bmp", 1);
		DS_Mimic[1] = new EDXFramework::Model("Modelos//DS_Mimic//DS_Mimic_Opening.obj", "Modelos//DS_Mimic//DS_Mimic.bmp", 1);
		DS_Chest[0] = new EDXFramework::Model("Modelos//DS_Chest//DS_Chest.obj", "Modelos//DS_Chest//DS_Chest.bmp", 0);
		DS_Chest[1] = new EDXFramework::Model("Modelos//DS_Chest//DS_Chest_Opening.obj", "Modelos//DS_Chest//DS_Chest.bmp", 0);
		DS_Chest[2] = new EDXFramework::Model("Modelos//DS_Chest//DS_Chest_Open.obj", "Modelos//DS_Chest//DS_Chest.bmp", 0);
		DS_Greatsword = new EDXFramework::Model("Modelos//DS_Greatsword//DS_Greatsword.obj", "Modelos//DS_Greatsword//DS_Greatsword.bmp", 0);
		Shield = new EDXFramework::Model("Modelos//Sword & Shield//Shield.obj", "Modelos//Sword & Shield//Shield.bmp", 0);
		Sword = new EDXFramework::Model("Modelos//Sword & Shield//Sword.obj", "Modelos//Sword & Shield//Sword.bmp", 0);
		CamaraI();
	}

	void Billboards(Billboard *bills[], HWND hWnd)
	{
		int bx, by, bz;
		for (int i = 0; i <= 99; i++)
		{
			do
			{
				bx = rand() % 490 + 1;
				bx -= 245;
				bz = rand() % 490 + 1;
				bz -= 245;
				by = cuenca->Superficie(bx, bz) * 4;
			} while (by > 70 || by < 15);
		bills[i] = new Billboard(hWnd, L"Imagenes//grass7alt.png", 5, 3, bx, by, bz);
		}
	}

	void arbol(int x, int z, int r, EDXFramework::Model *modelo)
	{
		int y = cuenca->Superficie(x, z) * 4;
		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(r, 0, 1, 0);
		glScalef(0.5, 0.5, 0.5);
		modelo->Draw();
		glPopMatrix();
	}

	void movimiento(int &cont, int vel, EDXFramework::Model *modelo[3])
	{
		cont++;
		if (cont <= vel)
			modelo[1]->Draw();
		else if (cont <= vel*2)
			modelo[0]->Draw();
		else if (cont <= vel*3)
			modelo[2]->Draw();
		else if (cont <= vel*4)
			modelo[0]->Draw();
		else if (cont > vel*4)
		{
			cont = 0;
			modelo[1]->Draw();
		}
	}

	void render(HDC hDC)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glLoadIdentity();
		if (pz <= 250)
		{
			GLfloat AmbInt[] = { 0.05, 0.05, 0.1, 1 };
			glLightfv(GL_LIGHT0, GL_AMBIENT, AmbInt);
			if (auxy == false)
				py = cuenca->Superficie(px, pz) * 4 + 4;
			AL = false;
		}
		if (pz >= 251 && px <= 3 && px >= -3 && AL == false)
		{
			GLfloat AmbInt[] = { 0.35, 0.3, 0.3, 1 };
			glLightfv(GL_LIGHT0, GL_AMBIENT, AmbInt);
			py = 24;
			AL = true;
		}
		CamaraU();

		//Skydome
		glPushMatrix();
		glTranslatef(0, 8, 0);
		glRotatef(90, 0, 1, 0);
		if (AL == false)
			noche->Draw();
		else
			dia->Draw();
		glPopMatrix();

		//Terreno
		glPushMatrix();
		glScalef(1, 4, 1);
		cuenca->Draw();
		glTranslatef(0, 0, 475);
		glRotatef(180, 0, 1, 0);
		aux->Draw();
		glPopMatrix();

		//Agua
		glPushMatrix();
		glTranslatef(50, 17, -100);
		lago->Draw();
		glPopMatrix();

		//Niebla
		niebla.Color[0] = 0.25;
		niebla.Color[1] = 0.25;
		niebla.Color[2] = 0.25;
		niebla.Color[3] = 1;
		niebla.draw();

		//AL
		glPushMatrix();
		glTranslatef(0, 0, 303);
		glScalef(2, 2, 2);
		glRotatef(180, 0, 1, 0);
		DS_AL->Draw();
		glPopMatrix();

		//espada y escudo
		glPushMatrix();
		posescudoX = px + 1.3 * cos(3.141516f * escang / 180.0f);
		posescudoZ = pz + 1.3 * sin(3.141516f * escang / 180.0f);
		glTranslatef(posescudoX, py-1.2 + sswalk, posescudoZ);
		glRotatef(auxang, 0, 1, 0);
		glScalef(0.5, 0.5, 0.5);
		Shield->Draw();
		glPopMatrix();
		glPushMatrix();
		posespadaX = px + 1.3 * cos(3.141516f * espang / 180.0f);
		posespadaZ = pz + 1.3 * sin(3.141516f * espang / 180.0f);
		glTranslatef(posespadaX, py - 1.2 + sswalk, posespadaZ);
		glRotatef(auxang, 0, 1, 0);
		glScalef(0.5, 0.5, 0.5);
		Sword->Draw();
		glPopMatrix();

		////Stone
		glPushMatrix();
		glTranslatef(170, 24.75, 245);
		glRotatef(90, 0, 1, 0);
		DS_Stone->Draw();
		glPopMatrix();

		//Stair
		glPushMatrix();
		glTranslatef(-86, 26.5, -93);
		glRotatef(90, 0, 1, 0);
		glRotatef(-12, 1, 0, 0);
		glScalef(1.5, 1.5, 1.5);
		DS_Stair->Draw();
		glTranslatef(0, 8, 0);
		DS_Stair->Draw();
		glTranslatef(0, 8, 0);
		DS_Stair->Draw();
		glPopMatrix();

		//Bridge
		glPushMatrix();
		glTranslatef(-112, 64.5, -85);
		glScalef(1, 1, 2);
		DS_Bridge->Draw();
		glPopMatrix();

		////Bonfire
		if (pz <= 250 && pz >= 225 && px >= -160 && bonfire == 2)
			bonfire = 1;
		glPushMatrix();
		glTranslatef(-168, 21.65, 240);
		glScalef(0.4, 0.4, 0.4);
		DS_Bonfire->Draw();
		glPopMatrix();

		////Hydra
		//if (hydra == true)
		//{
		//	hydraposY += 0.0125;
		//	if (hydraposY >= 22)
		//		hydra = false;
		//}
		//else if (hydra == false)
		//{
		//	hydraposY -= 0.0125;
		//	if (hydraposY <= 18)
		//		hydra = true;
		//}
		animacion.flotar(hydra, hydraposY, 0.0125, 22, 18);
		glPushMatrix();
		glTranslatef(50, hydraposY, -50);
		glRotatef(-15, 0, 1, 0);
		glScalef(5, 5, 5);
		movimiento(hydrai, 40, DS_Hydra);
		glPopMatrix();

		////CG's
		//cgposX = 0 + 30 * cos(3.141516f * cgang / 180.0f);
		//cgposZ = 175 + 30 * sin(3.141516f * cgang / 180.0f);
		//piso = cuenca->Superficie(cgposX, cgposZ) * 4;
		//cgang += 0.2;
		//if (cgang >= 360)
		//{
		//	cgang = 0;
		//}
		animacion.vuelta(cgposX, cgposZ, cgang, 0, 175, 30, 0.2);
		glPushMatrix();
		piso = cuenca->Superficie(cgposX, cgposZ) * 4;
		glTranslatef(cgposX, piso + 4.1, cgposZ);
		glRotatef(-cgang, 0, 1, 0);
		glScalef(2, 2, 2);
		movimiento(cgi, 20, DS_CG);
		glPopMatrix();

		//if (cg2 == true && cg2posX > -130)
		//{
		//	cg2posX -= 0.15;
		//}
		//else if (cg2posX <= -130)
		//	cg2 = false;
		//if (cg2 == false && cg2posX < -80)
		//{
		//	cg2posX += 0.15;
		//}
		//else if (cg2posX >= -80)
		//	cg2 = true;
		animacion.recta_mayoramenor(cg2, cg2posX, 0.15, -80, -130);
		glPushMatrix();
		piso = cuenca->Superficie(cg2posX, 110) * 4;
		glTranslatef(cg2posX, piso + 4.1, 110);
		if (cg2 == false)
			glRotatef(90, 0, 1, 0);
		else if (cg2 == true)
			glRotatef(270, 0, 1, 0);
		glScalef(2, 2, 2);
		movimiento(cg2i, 20, DS_CG);
		glPopMatrix();

		//if (cg3 == true && cg3posZ < 180)
		//{
		//	cg3posZ += 0.15;
		//}
		//else if (cg3posZ >= 180)
		//	cg3 = false;
		//if (cg3 == false && cg3posZ > 125)
		//{
		//	cg3posZ -= 0.15;
		//}
		//else if (cg3posZ <= 125)
		//	cg3 = true;
		animacion.recta_menoramayor(cg3, cg3posZ, 0.15, 180, 125);
		glPushMatrix();
		piso = cuenca->Superficie(140, cg3posZ) * 4;
		glTranslatef(140, piso + 4.1, cg3posZ);
		if (cg3 == false)
			glRotatef(180, 0, 1, 0);
		glScalef(2, 2, 2);
		movimiento(cg3i, 20, DS_CG);
		glPopMatrix();

		//if (cg4 == true && cg4posZ < 75)
		//{
		//	cg4posZ += 0.15;
		//	cg4posX += 0.15;
		//}
		//else if (cg4posZ >= 75)
		//	cg4 = false;
		//if (cg4 == false && cg4posZ > 25)
		//{
		//	cg4posZ -= 0.15;
		//	cg4posX -= 0.15;
		//}
		//else if (cg4posZ <= 25)
		//	cg4 = true;
		animacion.diagonal_menoramayor(cg4, cg4posX, cg4posZ, 0.15, 75, 25);
		glPushMatrix();
		piso = cuenca->Superficie(cg4posX, cg4posZ) * 4;
		glTranslatef(cg4posX, piso + 4.1, cg4posZ);
		if (cg4 == true)
			glRotatef(45, 0, 1, 0);
		else if (cg4 == false)
			glRotatef(225, 0, 1, 0);
		glScalef(2, 2, 2);
		movimiento(cg4i, 20, DS_CG);
		glPopMatrix();

		////Hollow
		if (hollow == true && hollowi < 264)
			hollowi++;
		else if (hollow == false && hollowi > 0)
			hollowi--;
		glPushMatrix();
		glTranslatef(-168, 22.75, 245);
		glRotatef(180, 0, 1, 0);
		//if (hollowi <= 66 && hollow == true)
		//	DS_Hollow[0]->Draw();
		//else if (hollowi <= 99 && hollow == true)
		//{
		//	glTranslatef(0, -0.3, 0);
		//	DS_Hollow[1]->Draw();
		//}
		//else if (hollowi < 264 && hollow == true)
		//{
		//	glTranslatef(0, -2.4, 0);
		//	DS_Hollow[2]->Draw();
		//}
		//else if (hollowi >= 264)
		//{
		//	hollow = false;
		//	glTranslatef(0, -2.4, 0);
		//	DS_Hollow[2]->Draw();
		//}
		//else if (hollowi <= 264 && hollowi > 99)
		//{
		//	glTranslatef(0, -2.4, 0);
		//	DS_Hollow[2]->Draw();
		//}
		//else if (hollowi <= 99 && hollowi > 66)
		//{
		//	glTranslatef(0, -0.3, 0);
		//	DS_Hollow[1]->Draw();
		//}
		//else if (hollowi <= 66 && hollowi > 0)
		//	DS_Hollow[0]->Draw();
		//else if (hollowi <= 0)
		//{
		//	hollow = true;
		//	DS_Hollow[0]->Draw();
		//}
		animacion.sentarse(hollow, hollowi, DS_Hollow);
		glPopMatrix();

		//BK
		//if (bk == true && bkposZ > 442)
		//	bkposZ -= 0.2;
		//else if (bkposZ <= 442)
		//	bk = false;
		//if (bk == false && bkposZ < 573)
		//	bkposZ += 0.2;
		//else if (bkposZ >= 573)
		//	bk = true;
		animacion.recta_mayoramenor(bk, bkposZ, 0.2, 573, 442);
		glPushMatrix();
		glTranslatef(0, 59.35, bkposZ);
		if (bk == true)
			glRotatef(180, 0, 1, 0);
		glScalef(0.8, 0.8, 0.8);			
		movimiento(bki, 15, DS_BK);
		glPopMatrix();

		//CL
		if (pz >= -15 && pz <= 5 && py >= 63 && clposX > -235)
			cl = true;
		else if (clposX <= -235)
			cl = false;
		if (cl == true)
		{
			//if (clip == false)
			//{
			//	clposX -= 0.2;
			//	clposZ += 0.1;
			//	if (clposZ >= -2)
			//		clip = true;
			//}
			//else if (clip == true)
			//{
			//	clposX -= 0.2;
			//	clposZ -= 0.1;
			//	if (clposZ <= -10)
			//		clip = false;
			//}
			animacion.zigzag_mayoramenor(clip, clposX, clposZ, 0.2, 0.1, -2, -10);
		}
		glPushMatrix();
		piso = cuenca->Superficie(clposX, clposZ) * 4;
		glTranslatef(clposX, piso + 0.4, clposZ);
		glRotatef(270, 0, 1, 0);
		if (clposX <= -235)
		{
			glRotatef(180, 0, 1, 0);
			glRotatef(180, 1, 0, 0);
		}
		glScalef(0.4, 0.4, 0.4);
		if (cl == false)
			DS_CL[0]->Draw();
		else if (cl == true)
		{
			movimiento(clim, 10, DS_CL);
		}
		glPopMatrix();

		//Greatsword
		glPushMatrix();
		glTranslatef(-205, 22.75, -57);
		glRotatef(180, 1, 0, 0);
		glRotatef(90, 0, 1, 0);
		glScalef(0.5, 0.5, 0.5);
		DS_Greatsword->Draw();
		glPopMatrix();

		////Chest
		if (pz <= 445 && py >= 87 && px > 1)
			chest = true;
		glPushMatrix();
		glTranslatef(41.5, 82, 438);
		glScalef(1.2, 1.2, 1.2);
		if (chest == false)
			DS_Chest[0]->Draw();
		else if (chest == true)
		{
			if (chesti < 66)
				chesti++;
			if (chesti <= 33)
				DS_Chest[1]->Draw();
			else if (chesti <= 66)
				DS_Chest[2]->Draw();
		}
		glPopMatrix();

		//Mimic
		if (pz <= 445 && py >= 87 && px < -1)
			mimic = true;
		glPushMatrix();
		if (mimic == false)
		{
			glTranslatef(-41.5, 82, 438);
			glScalef(1.2, 1.2, 1.2);
			DS_Chest[0]->Draw();
		}
		else if (mimic == true)
		{
			if (mimici < 66)
				mimici++;
			if (mimici <= 33)
			{
				glTranslatef(-41.5, 85, 438);
				glScalef(1.2, 1.2, 1.2);
				DS_Mimic[1]->Draw();
			}
			else if (chesti <= 66)
			{
				glTranslatef(-41.5, 89.1, 438);
				glScalef(1.2, 1.2, 1.2);
				DS_Mimic[0]->Draw();
			}
		}
		glPopMatrix();

		//Arboles zona de golems
		arbol(60, 210, 30, Tree[1]);
		arbol(40, 140, 120, Tree[1]);
		arbol(50, 75, 90, Tree[2]);
		arbol(125, 65, 120, Tree[2]);
		arbol(130, 105, 150, Tree[0]);
		arbol(110, 175, 180, Tree[1]);
		arbol(70, 100, 210, Tree[0]);
		arbol(100, 120, 240, Tree[0]);
		arbol(-115, 195, 270, Tree[1]);
		arbol(-45, 150, 300, Tree[1]);
		arbol(-60, 40, 330, Tree[2]);
		arbol(-105, 75, 360, Tree[0]);
		arbol(-90, 140, 30, Tree[1]);
		arbol(-135, 120, 60, Tree[1]);
		arbol(-50, 105, 180, Tree[0]);
		//arboles en las montañas
		arbol(-225, 175, 30, Tree[0]);
		arbol(-205, 95, 60, Tree[0]);
		arbol(-205, 30, 90, Tree[0]);
		arbol(-155, 33, 120, Tree[0]);
		arbol(-155, -135, 150, Tree[0]);
		arbol(-130, -200, 180, Tree[0]);
		arbol(-205, -130, 210, Tree[0]);
		arbol(200, 140, 240, Tree[0]);
		//atras cuenca
		for (int i = -280; i <= 280; i += 40)
		{
			glPushMatrix();
			glTranslatef(i, 102, -250);
			glRotatef(i, 0, 1, 0);
			glScalef(0.5, 0.5, 0.5);
			Tree[0]->Draw();
			glPopMatrix();
		}
		for (int i = -280; i <= 280; i += 20)
		{
			glPushMatrix();
			glTranslatef(i, 102, -280);
			glRotatef(i, 0, 1, 0);
			glScalef(0.5, 0.5, 0.5);
			Tree[1]->Draw();
			glPopMatrix();
		}
		//derecha cuenca
		for (int i = -250; i <= 200; i += 50)
		{
			glPushMatrix();
			glTranslatef(-260, 102, i);
			glRotatef(i, 0, 1, 0);
			glScalef(0.5, 0.5, 0.5);
			Tree[0]->Draw();
			glPopMatrix();
		}
		for (int i = -250; i <= 225; i += 25)
		{
			glPushMatrix();
			if (i < 225)
				glTranslatef(-280, 102, i);
			else if (i == 225)
				glTranslatef(-280, 95, i);
			glRotatef(i, 0, 1, 0);
			glScalef(0.5, 0.5, 0.5);
			Tree[1]->Draw();
			glPopMatrix();
		}
		//izquierda cuenca
		for (int i = -250; i <= 200; i += 50)
		{
			glPushMatrix();
			glTranslatef(260, 102, i);
			glRotatef(i, 0, 1, 0);
			glScalef(0.5, 0.5, 0.5);
			Tree[0]->Draw();
			glPopMatrix();
		}
		for (int i = -250; i <= 225; i += 25)
		{
			glPushMatrix();
			glTranslatef(280, 102, i);
			glRotatef(i, 0, 1, 0);
			glScalef(0.5, 0.5, 0.5);
			Tree[1]->Draw();
			glPopMatrix();
		}
		//atras montaña
		for (int i = -280; i <= 280; i += 40)
		{
			glPushMatrix();
			glTranslatef(i, 102, 750);
			glRotatef(i, 0, 1, 0);
			glScalef(0.5, 0.5, 0.5);
			Tree[2]->Draw();
			glPopMatrix();
		}
		for (int i = -280; i <= 280; i += 20)
		{
			glPushMatrix();
			glTranslatef(i, 102, 780);
			glRotatef(i, 0, 1, 0);
			glScalef(0.5, 0.5, 0.5);
			Tree[2]->Draw();
			glPopMatrix();
		}
		//derecha montaña
		for (int i = 250; i <= 750; i += 50)
		{
			glPushMatrix();
			if (i >= 300)
				glTranslatef(-260, 102, i);
			else if (i < 300)
				glTranslatef(-260, 95, i);
			glRotatef(i, 0, 1, 0);
			glScalef(0.5, 0.5, 0.5);
			Tree[2]->Draw();
			glPopMatrix();
		}
		for (int i = 250; i <= 750; i += 25)
		{
			glPushMatrix();
			if (i >= 300)
				glTranslatef(-280, 102, i);
			else if (i < 300)
				glTranslatef(-280, 97, i);
			glRotatef(i, 0, 1, 0);
			glScalef(0.5, 0.5, 0.5);
			Tree[2]->Draw();
			glPopMatrix();
		}
		//izquierda montaña
		for (int i = 250; i <= 750; i += 50)
		{
			glPushMatrix();
			if (i >= 450)
				glTranslatef(260, 102, i);
			else if (i < 450)
				glTranslatef(260, 87, i);
			glRotatef(i, 0, 1, 0);
			glScalef(0.5, 0.5, 0.5);
			Tree[2]->Draw();
			glPopMatrix();
		}
		for (int i = 250; i <= 750; i += 25)
		{
			glPushMatrix();
			if (i >= 450)
				glTranslatef(280, 102, i);
			else if (i < 450)
				glTranslatef(280, 87, i);
			glRotatef(i, 0, 1, 0);
			glScalef(0.5, 0.5, 0.5);
			Tree[2]->Draw();
			glPopMatrix();
		}

		//vegetacion aleatoria
		for (int i = 0; i <= 99; i++)
			billBoard[i]->Draw(px, py, pz);

		SwapBuffers(hDC);
	}
};
#endif
