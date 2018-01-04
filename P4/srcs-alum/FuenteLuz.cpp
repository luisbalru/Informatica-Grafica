
#include "FuenteLuz.hpp"
#include "cmath"


void FuenteLuz::activar(int i)
{
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0+i);
  glLightfv(GL_LIGHT0+i,GL_AMBIENT,colores[0]);
  glLightfv(GL_LIGHT0+i,GL_DIFFUSE,colores[1]);
  glLightfv(GL_LIGHT0+i,GL_SPECULAR,colores[2]);

  if(posvec[3]==1)
  {
    glLightfv(GL_LIGHT0+i,GL_POSITION,posvec);
  }
  else
  {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glLoadIdentity();
    glMultMatrixf(MAT_Ident());
    glRotatef(longitud,0.0,1.0,0.0);
    glRotatef(latitud,-1.0,0.0,0.0);
    glLightfv(GL_LIGHT0+i,GL_POSITION,posvec);

    glPopMatrix();
  }
}


FuenteDireccional::FuenteDireccional(float alpha_inicial, float beta_inicial)
{
  longitud=alpha_inicial;
  latitud=beta_inicial;
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
}

FuentePosicional::FuentePosicional(const Tupla3f& posicion)
{
  posvec=Tupla4f(posicion[0],posicion[1],posicion[2],1.0);
  colores[0] = Tupla4f(0.4 ,0.4 ,0.4 , 1.0);
  colores[1] = Tupla4f(0.3, 0.3, 0.3 , 1.0);
  colores[2] = Tupla4f(0.7, 0.7, 0.7 , 1.0);
}
