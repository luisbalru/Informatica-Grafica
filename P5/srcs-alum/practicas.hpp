// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Declaraciones públicas auxiliares, comunes a todas las prácticas
// **
// *********************************************************************

#ifndef IG_PRACTICAS_HPP
#define IG_PRACTICAS_HPP

// ---------------------------------------------------------------------
// tipo de datos enumerado para los modos de visualización:

typedef enum
{
   modoPuntos,
   modoAlambre,
   modoSolido,
   modoAjedrez,
   modoColorPlano,
   modoIluminacionSombreadoPlano,
   modoIluminacionSombreadoSuave
}
   ModosVisu;

const int numModosVisu = 5 ; // numero de modos distintos

// --------------------------------------------------------------------

class ContextoVis
{
   public:
      ModosVisu modoVisu ; // modo de visualización actual
      bool VBOs=false;
      ContextoVis() { modoVisu = modoAlambre ; } // poner alambre por defecto
};

void FGE_Desocupado ();

#endif
