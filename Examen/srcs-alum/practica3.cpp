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
#include <vector>

int num_obj=2;
int objeto_activo_practica3=0;
bool animaciones=false;


std::vector<int> grado_libertad_actual;
std::vector<int> grados_libertad;


grado_libertad_actual.reserve(2);
grado_libertad_actual.push_back(0);
grado_libertad_actual.push_back(0);


grados_libertad.reserve(2);
// Objeto 0 = grua, objeto 1 = figura
grados_libertad.push_back(4);
grados_libertad.push_back(2);

static Grua* grua = NULL;
static Figura* figura = NULL;
void P3_Inicializar()
{
  grua = new Grua();
  figura = new Figura();
}


void P3_DibujarObjetos(ContextoVis & cv)
{
  grua ->visualizarGL(cv);
  figura -> visualizarGL(cv);
}

bool P3_FGE_Desocupado()
{
  if(!animaciones)
    return false;

  grua->siguienteCuadro();
  glutPostRedisplay ();
  return true;

}

bool P3_FGE_PulsarTeclaNormal(unsigned char tecla)
{
  if(tecla =='g' || tecla== 'G')
  {
    grado_libertad_actual[objeto_activo_practica3]=(grado_libertad_actual[objeto_activo_practica3]+1)%grados_libertad[objeto_activo_practica3];
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
      glutIdleFunc ( FGE_Desocupado );
    }
    return true;
  }
  else if(tecla=='r' || tecla=='R')
  {
    animaciones=false;
    if(objeto_activo_practica3==0){
      for(int i=0; i<grua->numParametros();++i)
      {
        (grua->leerPtrParametro(i))->reset();
      }
    }
    else
    {
      for(int j=0; i<figura->numParametros();++j)
        (figura ->leerPtrParametro(j))->reset();
    }
    return true;
  }
  if(tecla=='<')
  {
    if(objeto_activo_practica3==0)
    {
      if(animaciones)
      {
        (grua->leerPtrParametro(grado_libertad_actual))->decelerar();
        cout << "El nombre del grado de libertad actual es " << (grua->leerPtrParametro(grado_libertad_actual[objeto_activo_practica3]))->leer_descripcion() << " y la velocidad es " << (grua->leerPtrParametro(grado_libertad_actual[objeto_activo_practica3]))->leer_velocidad_actual() << endl;
      }
      else
      {
        (grua->leerPtrParametro(grado_libertad_actual[objeto_activo_practica3]))->decrementar();
      }
    }
    else
    {
      if(animaciones)
      {
        (figura->leerPtrParametro(grado_libertad_actual))->decelerar();
        cout << "El nombre del grado de libertad actual es " << (figura->leerPtrParametro(grado_libertad_actual[objeto_activo_practica3]))->leer_descripcion() << " y la velocidad es " << (figura->leerPtrParametro(grado_libertad_actual[objeto_activo_practica3]))->leer_velocidad_actual() << endl;
      }
      else
      {
        (figura->leerPtrParametro(grado_libertad_actual[objeto_activo_practica3]))->decrementar();
      }
    }

    return true;
  }
  else if(tecla =='>')
  {
    if(objeto_activo_practica3==0)
    {
      if(animaciones)
      {
        (grua->leerPtrParametro(grado_libertad_actual[objeto_activo_practica3]))->acelerar();
        cout << "El nombre del grado de libertad actual es " << (grua->leerPtrParametro(grado_libertad_actual[objeto_activo_practica3]))->leer_descripcion() << " y la velocidad es " << (grua->leerPtrParametro(grado_libertad_actual[objeto_activo_practica3]))->leer_velocidad_actual() << endl;
      }
      else
      {
        (grua->leerPtrParametro(grado_libertad_actual[objeto_activo_practica3]))->incrementar();
      }
    }
    else{
      if(animaciones)
      {
        (figura->leerPtrParametro(grado_libertad_actual[objeto_activo_practica3]))->acelerar();
        cout << "El nombre del grado de libertad actual es " << (figura->leerPtrParametro(grado_libertad_actual[objeto_activo_practica3]))->leer_descripcion() << " y la velocidad es " << (figura->leerPtrParametro(grado_libertad_actual[objeto_activo_practica3]))->leer_velocidad_actual() << endl;
      }
      else
      {
        (figura->leerPtrParametro(grado_libertad_actual[objeto_activo_practica3]))->incrementar();
      }
    }
          return true;
  }
  else if(tecla=='o' || tecla=='O')
  {
    objeto_activo_practica3=(objeto_activo_practica3+1)%num_obj;
    return true;
  }
  else
    return false;
}
