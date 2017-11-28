#ifndef IG_NODOGRAFOESCENAPARAM_HPP
#define IG_NODOGRAFOESCENAPARAM_HPP

#include "NodoGrafoEscena.hpp"
#include "parametro.hpp"

class NodoGrafoEscenaParam : public NodoGrafoEscena
{
  protected:
    std::vector<Parametro> parametros; // vector de parámetros

  public:
    // devuelve el número de parámetros
    int numParametros();

    // devuelve puntero i-ésimo parámetro ( i<numParametros())
    Parametro* leerPtrParametro(unsigned i);

    //actualiza el objeto para ir al siguiente cuadro (con animaciones)
    void siguienteCuadro();
};

#endif
