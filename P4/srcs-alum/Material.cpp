
#include "Material.hpp"

void MaterialEstandar::activar()
{
   glEnable(GL_LIGHTING);
   glEnable(GL_NORMALIZE);
   //glDisable(GL_COLOR_MATERIAL);

   glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
   glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
   glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

   glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color[0]);
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color[1]);
   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color[2]);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color[3]);
   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, exponente);

   /*glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION);
   glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
   glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
   glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
   glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);*/

   if (textura != NULL) {
     textura->activar();
   }
   else {
     glDisable(GL_TEXTURE_2D);
   }
}
