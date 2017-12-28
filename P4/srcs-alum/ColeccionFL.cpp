#include "ColeccionFL.hpp"


void ColeccionFL::activar()
{
  for(int i=0; i<fuentes.size();++i)
  {
    glLightfv(GL_LIGHT0+i, GL_POSITION, fuentes[i]->posvec);
    glLightfv(GL_LIGHT0+i, GL_AMBIENT, fuentes[i]->colores[0]);
    glLightfv(GL_LIGHT0+i, GL_DIFFUSE, fuentes[i]->colores[1]);
    glLightfv(GL_LIGHT0+i, GL_SPECULAR, fuentes[i]->colores[2]);
  }
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  for(int i=0; i<fuentes.size();++i)
  {
    fuentes[i]->activar(i);
    std::cout << "Activando fuente de luz " << i << std::endl;
  }
}
