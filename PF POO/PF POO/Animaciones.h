#ifndef __Animaciones
#define __Animaciones

class Animaciones
{
public:

	void flotar(bool &dir, float &posy, float vel, int ls, int li)
	{
		if (dir == true)
		{
			posy += vel;
			if (posy >= ls)
				dir = false;
		}
		else if (dir == false)
		{
			posy -= vel;
			if (posy <= li)
				dir = true;
		}
	}

	void vuelta(float &posx, float &posz, float &ang, int cx, int cz, int dist, float vel)
	{
		posx = cx + dist * cos(3.141516f * ang / 180.0f);
		posz = cz + dist * sin(3.141516f * ang / 180.0f);
		ang += vel;
		if (ang >= 360)
		{
			ang = 0;
		}
	}

	void recta_mayoramenor(bool &dir, float &pos, float vel, int ls, int li)
	{
		if (dir == true && pos > li)
		{
			pos -= vel;
		}
		else if (pos <= li)
			dir = false;
		if (dir == false && pos< ls)
		{
			pos += vel;
		}
		else if (pos >= ls)
			dir = true;
	}

	void recta_menoramayor(bool &dir, float &pos, float vel, int ls, int li)
	{
		if (dir == true && pos < ls)
		{
			pos += vel;
		}
		else if (pos >= ls)
			dir = false;
		if (dir == false && pos > li)
		{
			pos -= vel;
		}
		else if (pos <= li)
			dir = true;
	}

	void diagonal_menoramayor(bool &dir, float &posx, float &posz, float vel, int ls, int li)
	{
		if (dir == true && posz < ls)
		{
			posz += vel;
			posx += vel;
		}
		else if (posz >= ls)
			dir = false;
		if (dir == false && posz > li)
		{
			posz -= vel;
			posx -= vel;
		}
		else if (posz <= li)
			dir = true;
	}

	void sentarse(bool &dir, int &espera, EDXFramework::Model *modelo[3])
	{
		if (espera <= 66 && dir == true)
			modelo[0]->Draw();
		else if (espera <= 99 && dir == true)
		{
			glTranslatef(0, -0.3, 0);
			modelo[1]->Draw();
		}
		else if (espera < 264 && dir == true)
		{
			glTranslatef(0, -2.4, 0);
			modelo[2]->Draw();
		}
		else if (espera >= 264)
		{
			dir = false;
			glTranslatef(0, -2.4, 0);
			modelo[2]->Draw();
		}
		else if (espera <= 264 && espera> 99)
		{
			glTranslatef(0, -2.4, 0);
			modelo[2]->Draw();
		}
		else if (espera <= 99 && espera > 66)
		{
			glTranslatef(0, -0.3, 0);
			modelo[1]->Draw();
		}
		else if (espera <= 66 && espera > 0)
			modelo[0]->Draw();
		else if (espera <= 0)
		{
			dir = true;
			modelo[0]->Draw();
		}
	}
	
	void zigzag_mayoramenor(bool &dir, float &posx, float &posz, float vel, float velzz, int ls, int li)
	{
		if (dir == false)
		{
			posx -= vel;
			posz += velzz;
			if (posz >= ls)
				dir = true;
		}
		else if (dir == true)
		{
			posx -= vel;
			posz -= velzz;
			if (posz <= li)
				dir = false;
		}
	}

};
#endif