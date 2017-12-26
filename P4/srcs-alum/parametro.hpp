#ifndef IG_PARAMETRO_HPP
#define IG_PARAMETRO_HPP


#include <functional>
#include "matrices-tr.hpp"
#include <cmath>
#include <string>

typedef std::function< Matriz4f(float)> TFuncionCMF;

class Parametro
{
  private:
    float incremento;
    float aceleracion;
    float velocidad_inicial;
    const std::string descripcion; // descripción del grado de libertad
    const bool acotado; // true si el valor oscila entre dos valores, false si no
    const TFuncionCMF fun_calculo_matriz; // función que produce una nueva matriz a partir de un flotante
    const float
      c,  // valor inicial (y central para los acotados)
      s, // semiamplitud (si acotado), o factor de escala (si no acotado)
      f;  // si acotado: frecuencia(ciclos por unidad del valor normalizado)
    Matriz4f* ptr_mat; // puntero a la matriz dentro del modelo
    float
      p, // valor actual, normalizado, no acotado (crece desde 0)
      velocidad; // velocidad actual (se suma al valor_norm)

  public:
    // crear grado de libertad no acotado
    Parametro(const std::string & p_descripcion, Matriz4f* p_ptr_mat, const TFuncionCMF p_fcm,const bool p_acotado,const float p_c,const float p_s,const float p_f);

    // actualizar valor y matriz al siguiente frame
    void siguiente_cuadro();

    // vuelve al estado inicial
    void reset();

    // incrementa el valor
    void incrementar();

    // decrementar el valor
    void decrementar();

    float getP()
    {
      return p;
    }
    // acelerar (aumentar velocidad)
    void acelerar();

    // disminuir velocidad
    void decelerar();

    // devuelve valor de q
    float leer_valor_actual();

    // devuelve velocidad actual
    float leer_velocidad_actual();

    // devuelve descripción
    std::string leer_descripcion();
};

#endif
