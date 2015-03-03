/*
	DrawingAlgorithms.h - DrawingAlgorithms class implementation. 
	Written by:
	Anoop Haridas
*/

#include "DrawingAlgorithms.h"
#include <math.h>
#include <stdlib.h>
#include <qgl.h>
#include <iostream>

QVector<QString> DrawingAlgorithms::dda(int xa, int ya, int xb, int yb) 
{
   QVector<QString> output;
   float xIncrement, yIncrement, x, y;
   int dx, dy, steps, k;
   
   // Find the distance from the start and end points in the x and y direction
   dx = xb - xa;
   dy = yb - ya;
   
   // Initialize the start point
   x = xa;
   y = ya;

   // If the absolute distance in the x direction is greater than the y direction
   // then take x number of steps otherwise take dy steps
   if (abs(dx) > abs(dy))
      steps = abs(dx);
   else  
      steps = abs(dy);
   
   // Determine the increments needed for the number of steps
   xIncrement = dx / (float)steps;
   yIncrement = dy / (float)steps;
   
   glBegin(GL_POINTS);
     //Convert the coords to a string and add to the output list
     output.append(DrawingAlgorithms::convertCoordsToString(0, roundf2(x), roundf2(y)));
     glVertex2i( roundf2(x),  roundf2(y));
   glEnd();
   
   for ( k=0; k<steps; k++) 
   {
      //Increase a little in the x and y direction each step
      //By rounding the values then you get the result of staying
      //At the current pixel coord or moving to the next pixel coord
	  x += xIncrement;
      y += yIncrement;
      
      glBegin(GL_POINTS);
	    //Convert the coords to a string and add to the output list
	    output.append(DrawingAlgorithms::convertCoordsToString(k+1, roundf2(x), roundf2(y)));
        glVertex2i( roundf2(x),  roundf2(y));
      glEnd();
   }

   output.append("----------\n");

   return output;
}

/*<<<<<<<<<<<<<<<<<<<<<drawLine>>>>>>>>>>>>>>>>>>>>>>>>*/
QVector<QString> DrawingAlgorithms::drawLine(double xa, double ya, double xb, double yb)
{
  QVector<QString> output;

  double dx, dy, two_dx, two_dy, po , x, y;
  double m;

  // Find the distance from the start and end points in the x and y direction
  dx = abs(xb - xa);
  dy = abs(yb - ya);
  two_dx = 2*dx;
  two_dy = 2*dy;
  po = two_dy -dx;
  m = (yb - ya) / (xb - xa);




  // Initialize the start point
  x = xa;
  y = ya;

  glBegin(GL_POINTS);
    //Convert the coords to a string and add to the output list
    output.append(DrawingAlgorithms::convertCoordsToString(0, x, y));
    glVertex2i(x, y);
  glEnd();

// special case

  if ((xa == xb) && (ya < yb))
  {
      for(int k= 0; k < dy; k++)
      {
          glBegin(GL_POINTS);
            //Convert the coords to a string and add to the output list
            output.append(DrawingAlgorithms::convertCoordsToString(k+1, x, y+1));
            glVertex2i( x,  y+1);
          glEnd();
          y++;
      }

  }
  else if ((xa == xb) && (ya > yb))
  {
      for(int k= 0; k < dy; k++)
      {
          glBegin(GL_POINTS);
            //Convert the coords to a string and add to the output list
            output.append(DrawingAlgorithms::convertCoordsToString(k+1, x, y-1));
            glVertex2i( x,  y-1);
          glEnd();
          y--;
      }

  }
  else if( xa < xb)
  {

      if((0.0 <= m) && (m<=1.0))
      {
          for(int k= 0; k < dx; k++)
          {

                  if ( po > 0)
                  {


                     glBegin(GL_POINTS);
                       //Convert the coords to a string and add to the output list
                       output.append(DrawingAlgorithms::convertCoordsToString(k+1, x+1, y+1));
                       glVertex2i( x+1,  y+1);
                     glEnd();
                     po = po + two_dy - two_dx;
                     x++;
                     y++;
                  }
                  else if (po <= 0)
                  {
                      glBegin(GL_POINTS);
                        //Convert the coords to a string and add to the output list
                        output.append(DrawingAlgorithms::convertCoordsToString(k+1, x+1, y));
                        glVertex2i( x+1,  y);
                      glEnd();
                      po = po + two_dy;
                      x++;

                  }

         }
      }

      else if( m > 1.0)
      {
          for(int k = 0; k < dy; k++)
          {

                            if ( po > 0)
                            {


                               glBegin(GL_POINTS);
                                 //Convert the coords to a string and add to the output list
                                 output.append(DrawingAlgorithms::convertCoordsToString(k+1, x, y+1));
                                 glVertex2i( x,  y+1);
                               glEnd();
                               po = po - two_dx;
                               y++;

                            }
                            else if (po <= 0)
                            {
                                glBegin(GL_POINTS);
                                  //Convert the coords to a string and add to the output list
                                  output.append(DrawingAlgorithms::convertCoordsToString(k+1, x+1, y+1));
                                  glVertex2i( x+1,  y+1);
                                glEnd();
                                po = po + two_dy - two_dx;
                                x++;
                                y++;


                            }

            }

      }
      else if((m >= -1.0) && (m < 0.0))
      {
          for(int k= 0; k < dx; k++)
          {

                  if ( po > 0)
                  {


                     glBegin(GL_POINTS);
                       //Convert the coords to a string and add to the output list
                       output.append(DrawingAlgorithms::convertCoordsToString(k+1, x+1, (y-1)));
                       glVertex2i( x+1,  (y-1));
                     glEnd();
                     po = po + two_dy - two_dx;
                     x++;
                     y--;
                  }
                  else if (po <= 0)
                  {
                      glBegin(GL_POINTS);
                        //Convert the coords to a string and add to the output list
                        output.append(DrawingAlgorithms::convertCoordsToString(k+1, x+1, y));
                        glVertex2i( x+1,  y);
                      glEnd();
                      po = po + two_dy;
                      x++;

                  }

          }
      }
      else if(( m < -1.0) && (yb < ya))
      {
          for(int k = 0; k < dy; k++)
          {

                            if ( po > 0)
                            {


                               glBegin(GL_POINTS);
                                 //Convert the coords to a string and add to the output list
                                 output.append(DrawingAlgorithms::convertCoordsToString(k+1, x, y-1));
                                 glVertex2i( x,  y-1);
                               glEnd();
                               po = po - two_dx;
                               y--;

                            }
                            else if (po <= 0)
                            {
                                glBegin(GL_POINTS);
                                  //Convert the coords to a string and add to the output list
                                  output.append(DrawingAlgorithms::convertCoordsToString(k+1, x+1, y-1));
                                  glVertex2i( x+1,  y-1);
                                glEnd();
                                po = po + two_dy - two_dx;
                                x++;
                                y--;


                            }

            }
      }
      else if( (m < -1.0) && (ya<yb))
      {
          for(int k = 0; k < dy; k++)
          {

                            if ( po > 0)
                            {


                               glBegin(GL_POINTS);
                                 //Convert the coords to a string and add to the output list
                                 output.append(DrawingAlgorithms::convertCoordsToString(k+1, x, y+1));
                                 glVertex2i( x,  y+1);
                               glEnd();
                               po = po - two_dx;
                               y++;

                            }
                            else if (po <= 0)
                            {
                                glBegin(GL_POINTS);
                                  //Convert the coords to a string and add to the output list
                                  output.append(DrawingAlgorithms::convertCoordsToString(k+1, x-1, y+1));
                                  glVertex2i( x-1,  y+1);
                                glEnd();
                                po = po + two_dy - two_dx;
                                x--;
                                y++;


                            }

            }

      }
  }
  else
  {
      if((0.0 >= m) && (m>=-1.0))
      {
          for(int k= 0; k < dx; k++)
          {

                  if ( po > 0)
                  {


                     glBegin(GL_POINTS);
                       //Convert the coords to a string and add to the output list
                       output.append(DrawingAlgorithms::convertCoordsToString(k+1, x-1, y+1));
                       glVertex2i( x-1,  y+1);
                     glEnd();
                     po = po + two_dy - two_dx;
                     x--;
                     y++;
                  }
                  else if (po <= 0)
                  {
                      glBegin(GL_POINTS);
                        //Convert the coords to a string and add to the output list
                        output.append(DrawingAlgorithms::convertCoordsToString(k+1, x-1, y));
                        glVertex2i( x-1,  y);
                      glEnd();
                      po = po + two_dy;
                      x--;

                  }

         }
      }
      else if( -1 > m)
      {
          for(int k = 0; k < dy; k++)
          {

                            if ( po > 0)
                            {


                               glBegin(GL_POINTS);
                                 //Convert the coords to a string and add to the output list
                                 output.append(DrawingAlgorithms::convertCoordsToString(k+1, x, y+1));
                                 glVertex2i( x,  y+1);
                               glEnd();
                               po = po - two_dx;
                               y++;

                            }
                            else if (po <= 0)
                            {
                                glBegin(GL_POINTS);
                                  //Convert the coords to a string and add to the output list
                                  output.append(DrawingAlgorithms::convertCoordsToString(k+1, x-1, y+1));
                                  glVertex2i( x-1,  y+1);
                                glEnd();
                                po = po + two_dy - two_dx;
                                x--;
                                y++;


                            }

            }

      }
      else if((0 < m) && (m <= 1.0))
      {
          for(int k= 0; k < dx; k++)
          {

                  if ( po > 0)
                  {


                     glBegin(GL_POINTS);
                       //Convert the coords to a string and add to the output list
                       output.append(DrawingAlgorithms::convertCoordsToString(k+1, x-1, (y-1)));
                       glVertex2i( x-1,  (y-1));
                     glEnd();
                     po = po + two_dy - two_dx;
                     x--;
                     y--;
                  }
                  else if (po <= 0)
                  {
                      glBegin(GL_POINTS);
                        //Convert the coords to a string and add to the output list
                        output.append(DrawingAlgorithms::convertCoordsToString(k+1, x-1, y));
                        glVertex2i( x-1,  y);
                      glEnd();
                      po = po + two_dy;
                      x--;

                  }

          }
      }
      else if(( m > 1.0) && (yb < ya))
      {
          for(int k = 0; k < dy; k++)
          {

                            if ( po > 0)
                            {


                               glBegin(GL_POINTS);
                                 //Convert the coords to a string and add to the output list
                                 output.append(DrawingAlgorithms::convertCoordsToString(k+1, x, y-1));
                                 glVertex2i( x,  y-1);
                               glEnd();
                               po = po - two_dx;
                               y--;

                            }
                            else if (po <= 0)
                            {
                                glBegin(GL_POINTS);
                                  //Convert the coords to a string and add to the output list
                                  output.append(DrawingAlgorithms::convertCoordsToString(k+1, x-1, y-1));
                                  glVertex2i( x-1,  y-1);
                                glEnd();
                                po = po + two_dy - two_dx;
                                x--;
                                y--;


                            }

            }
      }
  }


  return output;
}

/*<<<<<<<<<<<<<<<<<<<<<<<<<round2f>>>>>>>>>>>>>>>>>>>*/
int DrawingAlgorithms::roundf2(float f)
{
  if (f >= 0)
    return ( ((int) (f+0.5)));
  else 
    return ( ((int) (f-0.5)));
}

/*<<<<<<<<<<<<<<<<<<convertCoordsToString>>>>>>>>>>>>>>>*/
QString DrawingAlgorithms::convertCoordsToString(int num, int x, int y)
{
	return QString::number(num) + ": X: " + QString::number(x) + ", Y: " + QString::number(y);  
}

QVector<QString> DrawingAlgorithms::drawCircle(double xc, double yc, double r)
{
   QVector<QString> output;
   double x, y , p;


   x = 0;
   y = r;
    p =  5/4- r;

   glBegin(GL_POINTS);
     //Convert the coords to a string and add to the output list
     output.append(DrawingAlgorithms::convertCoordsToString(0, roundf2(x), roundf2(y)));
     glVertex2i( roundf2(xc),  roundf2(yc+r));

   glEnd();



   std::cout << "xc: " << xc << "  yc: " << yc << std::endl;
   while(y >= x)
    {
       if (p < 0)
       {
           p += 2*x + 3;
           x++;
       }
       else
       {
           p+= 2*(x-y) + 5;
           x++;
           y--;
       }
       std::cout << "x: " << x << "  y: " << y << std::endl;
       drawCircleHelper( xc, yc , x, y);

   }




   output.append("----------\n");

   return output;
}

void DrawingAlgorithms::drawCircleHelper(float xc, float yc, float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2i( (xc + x), (yc + y));

    glVertex2i( (xc - x), (yc - y));
    glVertex2i( (xc - x), (yc + y));
    glVertex2i( (xc + x), (yc - y));

    glVertex2i( (xc + y), (yc - x));
    glVertex2i( (xc + y), (yc + x));

    glVertex2i( (xc - y), (yc - x));

    glVertex2i( (xc - y), (yc + x));


    glEnd();

}
