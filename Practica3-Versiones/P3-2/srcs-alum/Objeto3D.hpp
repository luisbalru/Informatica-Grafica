#ifndef IG_OBJETO3D
#define IG_OBJETO3D

using namespace std;
#include <string>
#include "practicas.hpp"


class Objeto3D
{
  protected:
    string nombre_obj; // nombre asignado al objeto
  public:
    virtual void visualizarGL(ContextoVis & cv)=0;
    //devuelve el nombre del objeto
    string nombre();
};

#endif
