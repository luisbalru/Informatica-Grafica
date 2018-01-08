
#ifndef IG_MALLAPLY
#define IG_MALLAPLY

#include "MallaInd.hpp"
#include "file_ply_stl.hpp"


class MallaPLY : public MallaInd
{
  public:
    // constructor
    // se debe especificar el nombre completo del archivo a leer
    MallaPLY(const string & nombre_arch);
};

#endif
