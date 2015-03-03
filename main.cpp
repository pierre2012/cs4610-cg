/*
	main.cpp - Main program start. 
	Written by:
	Anoop Haridas
*/

#include <QApplication>
#include "MainWindow.h"

int main(int argc, char **argv)
{  
  QApplication app(argc, argv);
  MainWindow window;

  window.show();					// Display the MainWindow

  return app.exec();				// Gets the GUI event loop going
}
