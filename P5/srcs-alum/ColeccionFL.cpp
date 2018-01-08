#include "ColeccionFL.hpp"


void ColeccionFL::activar()
{
  glEnable(GL_LIGHTING);
  glEnable(GL_NORMALIZE);
  glDisable(GL_COLOR_MATERIAL);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
  glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

  for (unsigned f = 0; f < fuentes.size(); ++f) {
    fuentes.at(f)->activar(f);
  }
}

ColeccionFuentesP4::ColeccionFuentesP4() {
  fuentes.push_back(
    new FuenteDireccional(0,0)
  );
  fuentes.push_back(
    new FuentePosicional(Tupla3f(5, 5, 0))
  );
}
