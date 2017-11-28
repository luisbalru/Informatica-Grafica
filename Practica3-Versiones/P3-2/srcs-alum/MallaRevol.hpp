
#ifndef IG_MALLAREVOL
#define IG_MALLAREVOL

#include "MallaInd.hpp"
#include "matrices-tr.hpp"


class MallaRevol : public MallaInd
{
  public:
  // constructor: crea una malla de revolución
    MallaRevol(const string & nombre_arch, const unsigned nperfiles, const bool crear_tapas, const bool cerrar_malla);
    vector<Tupla3f> Rotar(Matriz4f& m, vector<Tupla3f>& vector);
};

#endif
