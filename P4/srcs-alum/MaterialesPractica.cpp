
#include "MaterialesPractica.hpp"

MaterialLata::MaterialLata()
{
  textura = new Textura("../imgs/lata-coke.jpg", 0);
  Tupla4f blanco(1, 1, 1, 1);
  color[0] = blanco * 0.8;
  color[1] = blanco * 0.1;
  color[2] = blanco * 0.3;
  color[3] = blanco * 0.7;
  exponente = 1;
}

MaterialTapasLata::MaterialTapasLata()
{
  textura = NULL;

  Tupla4f blanco(0.9, 0.95, 1, 1);
  color[0] = blanco * 0.65;
  color[1] = blanco * 0.05;
  color[2] = blanco * 0.2;
  color[3] = blanco * 0.7;
  exponente = 1;
}

MaterialPeonNegro::MaterialPeonNegro()
{
  textura = NULL;
  Tupla4f blanco(1, 1, 1, 1);
  color[0] = blanco * 0.005;
  color[1] = blanco * 0.0;
  color[2] = blanco * 0.01;
  color[3] = blanco * 0.6;
  exponente = 1;
}

MaterialPeonMadera::MaterialPeonMadera()
{
  textura = new Textura("../imgs/text-madera.jpg", 0);

  Tupla4f blanco(1, 1, 1, 1);
  color[0] = blanco * 0.8;
  color[1] = blanco * 0.1;
  color[2] = blanco * 0.3;
  color[3] = blanco * 0.7;
  exponente = 1;
}

MaterialPeonBlanco::MaterialPeonBlanco()
{
  textura = NULL;
  Tupla4f blanco(1, 1, 1, 1);
  color[0] = blanco * 0.8;
  color[1] = blanco * 0.05;
  color[2] = blanco * 0.2;
  color[3] = blanco * 0.0;
  exponente = 1;
}
