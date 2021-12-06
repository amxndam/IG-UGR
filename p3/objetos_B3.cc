//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos_B3.h"
#include "file_ply_stl.hpp"


//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0;i<vertices.size();i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();
}


//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
  glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
  glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
  glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
  }
glEnd();


}

//*************************************************************************
// dibujar en modo sólido con apariencia de ajedrez
//*************************************************************************

void _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_TRIANGLES);
  for (int i=0;i<caras.size();i++){
    if(i%2 == 0){
      glColor3f(r1, g1, b1);
    }else{
      glColor3f(r2, g2, b2);
    }
    glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
    glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
    glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
    }
  glEnd();

}

//*************************************************************************
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
switch (modo){
	case POINTS:draw_puntos(r1, g1, b1, grosor);break;
	case EDGES:draw_aristas(r1, g1, b1, grosor);break;
	case SOLID_CHESS:draw_solido_ajedrez(r1, g1, b1, r2, g2, b2);break;
	case SOLID:draw_solido(r1, g1, b1);break;
	}
}

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
//vertices
vertices.resize(8);
vertices[0].x=0;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=0;
vertices[3].x=0;vertices[3].y=0;vertices[3].z=0;
vertices[4].x=0;vertices[4].y=tam;vertices[4].z=tam;
vertices[5].x=tam;vertices[5].y=tam;vertices[5].z=tam;
vertices[6].x=tam;vertices[6].y=tam;vertices[6].z=0;
vertices[7].x=0;vertices[7].y=tam;vertices[7].z=0;

//triangulo
caras.resize(12);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
caras[1]._0=1;caras[1]._1=5;caras[1]._2=4;
caras[2]._0=1;caras[2]._1=2;caras[2]._2=5;
caras[3]._0=2;caras[3]._1=6;caras[3]._2=5;
caras[4]._0=2;caras[4]._1=3;caras[4]._2=6;
caras[5]._0=3;caras[5]._1=7;caras[5]._2=6;
caras[6]._0=3;caras[6]._1=0;caras[6]._2=7;
caras[7]._0=0;caras[7]._1=4;caras[7]._2=7;
caras[8]._0=4;caras[8]._1=5;caras[8]._2=6;
caras[9]._0=4;caras[9]._1=6;caras[9]._2=7;
caras[10]._0=3;caras[10]._1=1;caras[10]._2=0;
caras[11]._0=3;caras[11]._1=2;caras[11]._2=1;

}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

//vertices 
vertices.resize(5); 
vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

caras.resize(6);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;
}

//*************************************************************************
// clase objeto ply
//*************************************************************************


_objeto_ply::_objeto_ply() 
{
   // leer lista de coordenadas de vértices y lista de indices de vértices
 
}



int _objeto_ply::parametros(char *archivo)
{
int n_ver,n_car;

vector<float> ver_ply ;
vector<int>   car_ply ;
 
_file_ply::read(archivo, ver_ply, car_ply );

n_ver=ver_ply.size()/3;
n_car=car_ply.size()/3;

printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

vertices.resize(n_ver);
caras.resize(n_car);


for(int i=0; i < n_ver; i++){
  vertices[i].x=ver_ply[3*i];
  vertices[i].y=ver_ply[3*i+1];
  vertices[i].z=ver_ply[3*i+2];
}


for(int i=0; i < n_car; i++){
  caras[i]._0=car_ply[3*i];
  caras[i]._1=car_ply[3*i+1];
  caras[i]._2=car_ply[3*i+2];
}



return(0);
}


//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion()
{

}



void _rotacion::parametros(vector<_vertex3f> perfil, int num, int tipo)
{

  _vertex3f vertice_aux;  // vértices auxiliares
  _vertex3i cara_aux;   // caras auxiliares
  int num_aux;         
  float radio;  //radio de la esfera (tipo 2)
  float altura; //altura del cono (tipo 1)
  int c = 0;


  /// TRATAMIENTO DE LOS VÉRTICES ///

  num_aux = perfil.size();
  vertices.resize(num_aux * num + 2); // Redimensionamos los vértices dependiendo 
                                      //de la resolución más dos para los vértices iniciales que se repiten

  // si es un cono, cogemos la altura y 

  if (tipo == 1){

    altura = perfil[1].y;
    num_aux = 1; //Ya que perfil tiene 2 vértices pero 
                //el vértice de altura no se rota
  }

  // si es una esfera, se obtiene el radio
  if (tipo == 2)
    radio = sqrt(perfil[0].x * perfil[0].x + perfil[0].y * perfil[0].y);

  // se rotan los vértices del perfil (num_aux) 
  //el número de la resolución (num)
  for (int j = 0; j < num; j++){
    for (int i = 0; i < num_aux; i++){

      vertice_aux.x = perfil[i].x * cos(2.0 * M_PI * j / (1.0 * num))+
                      perfil[i].z * sin(2.0 * M_PI * j / (1.0 * num));

      vertice_aux.y = perfil[i].y;

      vertice_aux.z = -perfil[i].x * sin(2.0 * M_PI * j / (1.0 * num))+
                      perfil[i].z * cos(2.0 * M_PI*j / (1.0 * num));
      
      vertices[i + j * num_aux] = vertice_aux;

    }
  }


  /// TRATAMIENTO DE LAS CARAS ///

  // Redimensionamos las caras con la resolución y el número de vértices del perfil
  caras.resize(2 * (num_aux - 1) * num + 2 * num); 

  //si es una esfera o otro tipo que no sea el cono
  if (tipo == 0 || tipo == 2){
    for (int j = 0; j < num; j++){

      for (int i = 0; i < num_aux - 1; i++){
        caras[c]._0 = num_aux * j + 1 + i;
        caras[c]._1 = num_aux * j + i;
        caras[c]._2 = num_aux *((j + 1) % num) + 1 + i; // módulo num para que la última sea de nuevo 0
        c++;

        caras[c]._0 = num_aux *((j + 1) % num) + i;
        caras[c]._1 = num_aux *((j + 1) % num) + 1 + i;
        caras[c]._2 = num_aux * j + i;
        c++;
      }
    }
  }


  /// Tapa inferior ///
  if (fabs(perfil[0].x) > 0.0){

    // añadimos un nuevo vértice que será el centro de la tapa
    vertices[num_aux * num]._0 = 0.0;
    if (tipo == 0) vertices[num_aux * num]._1 = perfil[0].y;
    if (tipo == 1) vertices[num_aux * num]._1 = 0.0;
    if (tipo == 2) vertices[num_aux * num]._1 = -radio;
    vertices[num_aux * num]._2 = 0.0;

    //creamos las caras de la tapa
    for (int j = 0; j < num; j++){

      caras[c]._0 = num_aux * num; //punto central
      caras[c]._1 = num_aux * j; 
      caras[c]._2 = num_aux * ((j + 1) % num);
      c++;
    }
  }

  /// Tapa superior  ///
  if (fabs(perfil[num_aux-1].x) > 0.0){

    // añadimos un nuevo vértice que será el centro de la tapa
    vertices[num_aux * num+1]._0 = 0.0;
    if (tipo == 0) vertices[num_aux * num + 1]._1 = perfil[num_aux - 1].y;
    if (tipo == 1) vertices[num_aux * num + 1]._1 = altura;
    if (tipo == 2) vertices[num_aux * num + 1]._1 = radio;
    vertices[num_aux * num + 1]._2 = 0.0;

    //creamos las caras de la tapa
    for (int j = 0; j < num; j++){

      caras[c]._0 = num_aux * num + 1;  //punto central
      caras[c]._1 = num_aux * j + num_aux - 1;
      caras[c]._2 = num_aux * ((j + 1) % num) + num_aux - 1;
      c++;
    }
  }

}

_cono::_cono(float radio, float altura, int num)
{
  
  vector<_vertex3f> perfil;
  _vertex3f vertice_aux;
  _rotacion cono;

  //añadimos el vértice inferior al perfil
  vertice_aux.x = radio;
  vertice_aux.y = 0.0;
  vertice_aux.z = 0.0;
  perfil.push_back(vertice_aux);

  //añadimos el pico como vértice al perfil
  vertice_aux.x = 0.0;
  vertice_aux.y = altura;
  vertice_aux.z = 0.0;
  perfil.push_back(vertice_aux);

  //rotamos el cono
  cono.parametros(perfil, num, 1);

  //añadimos los vértices y las caras resultantes a las variables
  vertices = cono.vertices;
  caras = cono.caras;
  
}

_cilindro::_cilindro(float radio, float altura, int num)
{
  vector<_vertex3f> perfil;
  _vertex3f vertice_aux;
  _rotacion cilindro;

  //añadimos el vértice inferior al perfil
  vertice_aux.x = radio;
  vertice_aux.y = 0.0;
  vertice_aux.z = 0.0;
  perfil.push_back(vertice_aux);

  //añadimos el vértice superior al perfil
  vertice_aux.x = radio;
  vertice_aux.y = altura;
  vertice_aux.z = 0.0;
  perfil.push_back(vertice_aux);

  //rotamos el cilindro
  cilindro.parametros(perfil,num,0);

  //añadimos los vértices y las caras resultantes a las variables
  vertices = cilindro.vertices;
  caras = cilindro.caras;
  
}


_esfera::_esfera(float radio, int num, int num2)
{
  vector<_vertex3f> perfil;
  _vertex3f vertice_aux;
  _rotacion esfera;

  //añadimos los vértices  de una semicircunferencia al perfil
  for (int i=1; i<num; i++)
  {
    vertice_aux.x = radio * cos(i * M_PI / num - M_PI / 2);
    vertice_aux.y = radio * sin(i * M_PI / num - M_PI / 2);
    vertice_aux.z = 0.0;
    perfil.push_back(vertice_aux);
  }

  //rotamos la esfera
  esfera.parametros(perfil,num2, 2);

  //añadimos los vértices y las caras resultantes a las variables
  vertices = esfera.vertices;
  caras = esfera.caras;
  
}

//*************************************************************************
// clase bombilla
//*************************************************************************
_bombilla::_bombilla(){
  altura = 1.8;

}

void _bombilla::draw(_modo modo, float r1, float g1, float b1,
  float r2, float g2, float b2, float grosor)
  {

    glPushMatrix();

      glPushMatrix();

        glTranslatef(0.0,0.2,0.0);
        esfera2->draw(modo,1.0,0.0,0.0,0.0,1.0,0.0,2);

      glPopMatrix();

      glPushMatrix();

        glRotatef(180,0.0,0.0,1.0);
        glTranslatef(0.0,-1.2,0.0);
        cono->draw(modo,1.0,0.0,0.0,0.0,1.0,0.0,2);

      glPopMatrix();

      glPushMatrix();

        glTranslatef(0.0,1.6,0.0);
        esfera1->draw(modo,1.0,0.0,0.0,0.0,1.0,0.0,2);

      glPopMatrix();

    glPopMatrix();


  }


//*************************************************************************
// clase brazo
//*************************************************************************
_brazo::_brazo(){
  altura = 2.4;

}

void _brazo::draw(_modo modo, float r1, float g1, float b1,
  float r2, float g2, float b2, float grosor)
  {

    glPushMatrix();

      glPushMatrix();

        glTranslatef(0.0,0.2,0.0);

        esfera->draw(modo,1.0,0.0,0.0,0.0,1.0,0.0,2);

      glPopMatrix();

      glTranslatef(0.0,0.4,0.0);

      cilindro->draw(modo,0.0,0.0,1.0,0.0,1.0,0.0,2);

      
    glPopMatrix();


  }

//*************************************************************************
// clase cuerpo
//*************************************************************************
_cuerpo::_cuerpo(){
  
  altura = 0.2;

}

void _cuerpo::draw(_modo modo, float r1, float g1, float b1,
  float r2, float g2, float b2, float grosor){

  glPushMatrix();
  cilindro->draw(modo,1.0,0.0,1.0,0.0,1.0,0.0,2);
 
  glPopMatrix();

  }

//*************************************************************************
// clase lámpara
//*************************************************************************
_lampara::_lampara(){

  giro_cuerpo1 = 0.0;

  giro_brazo1 = 0.0;
  giro_brazo1_min = -40.0;
  giro_brazo1_max = 40.0;

  giro_brazo2 = 0.0;
  giro_brazo2_min = -40.0;
  giro_brazo2_max = 40.0;

  giro_brazo3 = 0.0;
  giro_brazo3_min = -40.0;
  giro_brazo3_max = 40.0;

  giro_bombilla = 0.0;
  giro_bombilla_min = -40.0;
  giro_bombilla_max = 40.0;


}

void _lampara::draw(_modo modo, float r1, float g1, float b1,
  float r2, float g2, float b2, float grosor)
  {

   glPushMatrix();

     cuerpo->draw(modo,5.0,4.0,3.0,0.0,1.0,0.0,2);

     glRotatef(giro_cuerpo1,0.0,1.0,0.0);

     glPushMatrix();

       glTranslatef(0.0,(cuerpo->altura),0.0);
       glRotatef(giro_brazo1,0.0,0.0,1.0);
       brazo->draw(modo,1.0,0.0,0.0,0.0,1.0,0.0,2);
     
       glPushMatrix();

         glTranslatef(0.0,(brazo->altura),0.0);
         glRotatef(giro_brazo2,0.0,0.0,1.0);
         brazo->draw(modo,1.0,0.0,0.0,0.0,1.0,0.0,2);

         glPushMatrix();

            glTranslatef(0.0,(brazo->altura),0.0);
            glRotatef(giro_brazo3,0.0,0.0,1.0);
            brazo->draw(modo,1.0,0.0,0.0,0.0,1.0,0.0,2);

            glPushMatrix();

              
              glTranslatef(0.0,(brazo->altura),0.0);
              glRotatef(giro_bombilla,0.0,0.0,1.0);
              bombilla->draw(modo,1.0,0.0,0.0,0.0,1.0,0.0,2);

            glPopMatrix();

         glPopMatrix();

       glPopMatrix();

     glPopMatrix();



     
   

     

   glPopMatrix();
        
  }

