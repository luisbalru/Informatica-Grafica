#ifndef IG_PARAMETRO_HPP
#define IG_PARAMETRO_HPP


#include <functional>
#include "matrices-tr.hpp"
#include <math.h>

typedef std::function< Matriz4f(float)> TFuncionCMF;

class Parametro
{
  private:
    const float incremento=2;
    const float aceleracion=2;
    const float velocidad_inicial=1;
    const std::string descripcion=""; // descripción del grado de libertad
    const bool acotado=false; // true si el valor oscila entre dos valores, false si no
    const TFuncionCMF fun_calculo_matriz; // función que produce una nueva matriz a partir de un flotante
    const float
      c=0,  // valor inicial (y central para los acotados)
      s=0, // semiamplitud (si acotado), o factor de escala (si no acotado)
      f=0;  // si acotado: frecuencia(ciclos por unidad del valor normalizado)
    Matriz4f* const ptr_mat; // puntero a la matriz dentro del modelo
    float
      p=0, // valor actual, normalizado, no acotado (crece desde 0)
      velocidad=velocidad_inicial; // velocidad actual (se suma al valor_norm)
    
  public:
    // crear grado de libertad no acotado
    Parametro(const std::string & p_descripcion, Matriz4f* p_ptr_mat, TFuncionCMF p_fcm, bool p_acotado, float p_c, float p_s, float p_f);

    // actualizar valor y matriz al siguiente frame
    void siguiente_cuadro();

    // vuelve al estado inicial
    void reset();

    // incrementa el valor
    void incrementar();

    // decrementar el valor
    void decrementar();

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
