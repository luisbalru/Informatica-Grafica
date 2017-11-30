#ifndef IG_OBJETO3D
#define IG_OBJETO3D

using namespace std;
#include <string>
#include "practicas.hpp"


class Objeto3D
{
  protected:
    string nombre_obj; // nombre asignado al objeto
    unsigned color_x; // Modo color plano práctica 3
    unsigned color_y;
    unsigned color_z;
  public:
    virtual void visualizarGL(ContextoVis & cv)=0;
    //devuelve el nombre del objeto
    string nombre();
    void rellenar_color(unsigned x, unsigned y, unsigned z)
    {
      color_x=x;
      color_y=y;
      color_z=z;
    }

};

#endif
