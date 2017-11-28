//**********************************************************************************************//
//                                                                                              //
//                            Implementación practica3.hpp                                      //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//
#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica3.hpp"
#include "MallaPLY.hpp"
#include "MallaRevol.hpp"
#include "Objeto3D.hpp"
#include "Grua.hpp"

int numero_objetos=1;
int objeto_activo_practica3=0;
bool animaciones=false;
int grado_libertad_actual=0;
int grados_libertad=3;

static Grua* grua = NULL;
void P3_Inicializar()
{
  grua = new Grua();
}


void P3_DibujarObjetos(ContextoVis & cv)
{
  //brazo -> visualizarGL(cv);
  grua ->visualizarGL(cv);
}


bool P3_FGE_PulsarTeclaNormal(unsigned char tecla)
{
  if(tecla =='g' || tecla== 'G')
  {
    grado_libertad_actual=(grado_libertad_actual+1)%grados_libertad;
    return true;
  }
  else if(tecla=='a' || tecla=='A')
  {
    if(animaciones)
    {
      animaciones=false;
      cout << "Se ha desactivado la animación" << endl;
    }
    else
    {
      animaciones=true;
      cout << "Se ha activado la animación" << endl;
    }
    return true;
  }
  else if(tecla=='r' || tecla=='R')
  {
    animaciones=false;
    for(int i=0; i<grua->numParametros();++i)
    {
      (grua->leerPtrParametro(i))->reset();
    }
    return true;
  }
  if(tecla=='<')
  {
    if(animaciones)
    {
      (grua->leerPtrParametro(grado_libertad_actual))->decelerar();
    }
    else
    {
      grado_libertad_actual--;
      if(grado_libertad_actual<0)
        grado_libertad_actual=0;
    }
    cout << "El nombre del grado de libertad actual es " << (grua->leerPtrParametro(grado_libertad_actual))->leer_descripcion() << " y la velocidad es " << (grua->leerPtrParametro(grado_libertad_actual))->leer_velocidad_actual() << endl;
    return true;
  }
  else if(tecla =='>')
  {
    if(animaciones)
    {
      (grua->leerPtrParametro(grado_libertad_actual))->acelerar();
    }
    else
    {
      grado_libertad_actual++;
      if(grado_libertad_actual>grados_libertad)
        grado_libertad_actual=0;
    }
    cout << "El nombre del grado de libertad actual es " << (grua->leerPtrParametro(grado_libertad_actual))->leer_descripcion() << " y la velocidad es " << (grua->leerPtrParametro(grado_libertad_actual))->leer_velocidad_actual() << endl;
    return true;
  }
  else if(tecla=='o' || tecla=='O')
  {
    objeto_activo_practica3=(objeto_activo_practica3+1)%numero_objetos;
    return true;
  }
  else
    return false;
}
