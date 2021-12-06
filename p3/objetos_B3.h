//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>

const float AXIS_SIZE=5000;
typedef enum{POINTS,EDGES,SOLID_CHESS,SOLID} _modo;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:

  
	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
void 	draw_aristas(float r, float g, float b, int grosor);
void    draw_solido(float r, float g, float b);
void 	draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

vector<_vertex3i> caras;
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=1.0);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=0.75);
};

//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
   _objeto_ply();

int   parametros(char *archivo);
};

//************************************************************************
// objeto por revolución
//************************************************************************

class _rotacion: public _triangulos3D
{
public:
       _rotacion();
void  parametros(vector<_vertex3f> perfil1, int num1, int tipo);

vector<_vertex3f> perfil; 
int num;
};

//************************************************************************
// clase cono
//************************************************************************

class _cono: public _triangulos3D
{
public:

	_cono(float radio=1.0, float altura=1.5, int num=15);
};

//************************************************************************
// clase cono
//************************************************************************

class _cilindro: public _triangulos3D
{
public:

	_cilindro(float radio=1.0, float altura=1.5, int num=15);

};

//************************************************************************
// clase esfera
//************************************************************************

class _esfera: public _triangulos3D
{
public:

	_esfera(float radio=1.0, int num=10, int num2=10);
};


//************************************************************************
// clase bombilla
//************************************************************************

class _bombilla: public _triangulos3D{

public:

  _bombilla();
  void  draw(_modo modo, float r1, float g1, float b1, 
    float r2, float g2, float b2, float grosor) ;

  float altura; 

private: 
  _esfera *esfera1 = new _esfera(0.4, 10, 10);  
  _esfera *esfera2 = new _esfera(0.2, 10, 10);
  _cono *cono = new _cono(1.2, 1, 10);

};

//************************************************************************
// clase brazo
//************************************************************************

class _brazo: public _triangulos3D{
public:
  _brazo();
  void  draw(_modo modo, float r1, float g1, float b1,
    float r2, float g2, float b2, float grosor) ;

  float altura;

private:
  _cilindro *cilindro = new _cilindro(0.2, 2.0, 5);
  _esfera *esfera = new _esfera(0.2, 10, 10);
  _cono *cono = new _cono(1.2, 1, 10);

};


//************************************************************************
// clase brazo
//************************************************************************

class _cuerpo: public _triangulos3D{
public:
  _cuerpo();
  void  draw(_modo modo, float r1, float g1, float b1,
    float r2, float g2, float b2, float grosor) ;

  float altura;

private:
  _cilindro *cilindro = new _cilindro(1.5,0.2,20);

};


//************************************************************************
// clase lampara
//************************************************************************

class _lampara: public _triangulos3D{
public:
  _lampara();
  void 	draw(_modo modo, float r1, float g1, float b1,
    float r2, float g2, float b2, float grosor) ;

 float giro_cuerpo1;

 float giro_cuerpo2;
 float giro_cuerpo2_min;
 float giro_cuerpo2_max;

 float giro_brazo1;
 float giro_brazo1_min;
 float giro_brazo1_max;

 float giro_brazo2;
 float giro_brazo2_min;
 float giro_brazo2_max;

 float giro_brazo3;
 float giro_brazo3_min;
 float giro_brazo3_max;

 float giro_bombilla;
 float giro_bombilla_min;
 float giro_bombilla_max;



private:
  
  _brazo *brazo = new _brazo();
  _cuerpo *cuerpo = new _cuerpo();
  _bombilla *bombilla = new _bombilla();

};