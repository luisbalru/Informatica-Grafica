
#include "FuenteLuz.hpp"
#include "cmath"


void FuenteLuz::activar(int i)
{
  glEnable(GL_LIGHT0+i);
}


FuenteDireccional::FuenteDireccional(float alpha_inicial, float beta_inicial)
{
  latitud=alpha_inicial;
  longitud=beta_inicial;
  posvec=Tupla4f(sin(latitud)*cos(longitud),sin(latitud)*sin(longitud),cos(latitud),0.0);
  colores[0] = Tupla4f(0.4 ,0.4 ,0.4 , 1.0);
  colores[1] = Tupla4f(0.3, 0.3, 0.3 , 1.0);
  colores[2] = Tupla4f(0.7, 0.7, 0.7 , 1.0);
}

void FuenteDireccional::variarAngulo(unsigned angulo, float incremento)
{
  if(angulo==0)
    latitud=latitud+incremento;
  else if(angulo==1)
    longitud=longitud+incremento;
  posvec=Tupla4f(sin(latitud)*cos(longitud),sin(latitud)*sin(longitud),cos(latitud),0.0);
}

FuentePosicional::FuentePosicional(const Tupla3f& posicion)
{
  posvec=Tupla4f(posicion[0],posicion[1],posicion[2],1.0);
  colores[0] = Tupla4f(0.4 ,0.4 ,0.4 , 1.0);
  colores[1] = Tupla4f(0.3, 0.3, 0.3 , 1.0);
  colores[2] = Tupla4f(0.7, 0.7, 0.7 , 1.0);
}
