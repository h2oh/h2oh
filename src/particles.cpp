/* Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "H2oH!"
 *
 * "H2oH!" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * "H2oH!" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "H2oH!" If not, see <http://www.gnu.org/licenses/>.
 */

#include "particles.hpp"
#include "misc.hpp"
#include "textures.hpp"
#include <math.h>
#include <GL/gl.h>

extern image_type    image;
extern texture_type  texture[MAX_TEXTURES];
       particle_type particle[MAX_PARTICLES];

int init_particles(void)
{
  	for (int count = 0; count < MAX_PARTICLES; count++)
	{
		particle[count].active = true;					// Make All The Particles Active
		particle[count].life = 1.0f;					// Give All The Particles Full Life
		particle[count].r = 1.0f;		                // Select Red Value
		particle[count].g = 1.0f;		                // Select Green Value
		particle[count].b = 1.0f;		                // Select Blue Value
		particle[count].x = sin(float(count));	        // random X Axis
		particle[count].y = 1.0f;					    // max On Y Axis
		particle[count].z = 0.0f - (count * 0.001f);	// Center On Z Axis
		particle[count].xv = float(random(60)-2.0f);	// X Axis Speed And Direction
		particle[count].yv = float(random(70)-65.0f);	// Y Axis Speed And Direction
		particle[count].zv = float(random(60)-20.0f);	// Z Axis Speed And Direction
		particle[count].xg =  0.0f;						// Set Horizontal Pull To Zero
		particle[count].yg = -0.2f;				     	// Set Vertical Pull Downward
		particle[count].zg =  0.0f;						// Set Pull On Z Axis To Zero
	}
    return(1);
}

int process_particles(void)
{
	for (int count = 0; count < MAX_PARTICLES; count++)		    // count Through All The Particles
	{
		particle[count].fade = float(random(100))/1500.0f;	    // Random Fade Value
 		if (particle[count].active)					            // If The Particle Is Active
		{
			particle[count].x += particle[count].xv/15000;	    // Move On The X Axis By X Speed
			particle[count].y += particle[count].yv/15000;  	// Move On The Y Axis By Y Speed
			particle[count].z += particle[count].zv/15000;  	// Move On The Z Axis By Z Speed

			particle[count].xv += particle[count].xg;		    // Take Pull On X Axis Into Account
			particle[count].yv += particle[count].yg;		    // Take Pull On Y Axis Into Account
			particle[count].zv += particle[count].zg;		    // Take Pull On Z Axis Into Account
			particle[count].life -= particle[count].fade - 0.0285f;	// Reduce Particles Life By 'Fade'
			if (particle[count].life < 0.0f)				    // If Particle Is Burned Out
			{
				particle[count].life = 1.0f;			        // Give It New Life
				particle[count].fade = float(random(100));	    // Random Fade Value
			    particle[count].r = 1;
     		    particle[count].g = 1;
       		    particle[count].b = 1;
				particle[count].x = sin(float(count));	        // random X Axis
				particle[count].y = 1.0f;	    				// max On Y Axis
                particle[count].z = 0.0f - (count * 0.001f);	// Center On Z Axis
				particle[count].xv = float(random(60)-2.0f);	// X Axis Speed And Direction
				particle[count].yv = float(random(70)-65.0f);	// Y Axis Speed And Direction
				particle[count].zv = float(random(60)-20.0f);	// Z Axis Speed And Direction
			}
		}
	}
    return(1);
}

int draw_particles(void)
{
    glPushMatrix();
    glDisable(GL_DEPTH_TEST);
    glBindTexture(GL_TEXTURE_2D, texture[image.particle_flake].texture);
	for (int count = 0; count < MAX_PARTICLES; count++)
	{
 		if (particle[count].active)
		{
			// Draw The Particle Using Our RGB Value
			glColor4f(particle[count].r,particle[count].g,particle[count].b,particle[count].life);
			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(particle[count].x+0.025f,particle[count].y+0.02f,particle[count].z); // Top Right
			glTexCoord2f(0.0f, 1.0f); glVertex3f(particle[count].x-0.025f,particle[count].y+0.02f,particle[count].z); // Top Left
			glTexCoord2f(1.0f, 0.0f); glVertex3f(particle[count].x+0.025f,particle[count].y-0.02f,particle[count].z); // Bottom Right
			glTexCoord2f(0.0f, 0.0f); glVertex3f(particle[count].x-0.025f,particle[count].y-0.02f,particle[count].z); // Bottom Left
			glEnd();
		}
	}
    glColor4f(1.0f,1.0f,1.0f,1.0f);
    glPopMatrix();
    return(1);
}
