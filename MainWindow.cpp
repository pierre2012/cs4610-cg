/*
	MainWindow.cpp - MainWindow class implementation. 
	Written by:
	Anoop Haridas
*/

#include "MainWindow.h"
#include "Window.h"
//#include "GLWidget.h"

#include <QtGui>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenu>
#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include <QLabel>
#include <QString>
#include <QToolBar>
#include <QPushButton>

MainWindow::MainWindow() 
  {


    childWindow = new Window(this);

    setCentralWidget(childWindow);

   // QWidget * wdg = new QWidget(this);
   // QPushButton *train_button = new QPushButton(wdg);
   // train_button->setText(tr("something"));
   // setCentralWidget(wdg);


    //Creates the actions fired when a menu item is selected
    createActions();

    //Creates all the menus
    createMenus();

    //Creates the toolbar
    createToolBar();
	
    //setCentralWidget(new Window(this));

    statusBar()->showMessage(tr("X: ???, Y: ???"));

    setWindowTitle(tr("CS 4610/7610 Assignment 1 Framework"));
    setMinimumSize(100, 100);
    resize(600, 600);
  }

  void MainWindow::updateStatusLabel(int x, int y)
  {
	  QString statString = QString("X: ") + QString::number(x) + QString(" Y: ") + QString::number(y);
	  statusBar()->showMessage(statString);
  }

  /*<<<<<<<<<<<<<<<<<<<<<<createActions>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
  void MainWindow::createActions()
  {
    printAct = new QAction(tr("Print"), this);
    printAct->setStatusTip(tr("Print the output"));
	//printAct->setCheckable(true);
	//printAct->setChecked(true);
    connect(printAct, SIGNAL(triggered()), childWindow, SIGNAL(printCallFromMW()));
	//connect(printAct, SIGNAL(triggered()), glWindow, SLOT(togglePrintDialog()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

	colorAct = new QAction(tr("Set Color"), this);
    colorAct->setStatusTip(tr("Set the current drawing color"));
    connect(colorAct, SIGNAL(triggered()), childWindow, SIGNAL(chooseColorFromMW()));
	//connect(colorAct, SIGNAL(triggered()), glWindow, SLOT(chooseColor()));




    diagLineAct = new QAction(tr("Linee"), this);
    diagLineAct->setStatusTip(tr("Open dialog for line drawing"));
    connect(diagLineAct, SIGNAL(triggered()), childWindow, SIGNAL(drawDialogLineFromMW()));

    CircleAct = new QAction(tr("Draw Circle"), this);
    CircleAct->setStatusTip(tr("Open dialog for line drawing"));
    connect(CircleAct, SIGNAL(triggered()), childWindow, SIGNAL(drawCircleFromMW()));





    diagHouseAct = new QAction(tr("House"), this);
    diagHouseAct->setStatusTip(tr(" House drawing"));
    connect(diagHouseAct, SIGNAL(triggered()), childWindow, SIGNAL(drawDialogHouseFromMW()));


    mouseLineAct  = new QAction(tr("Line"), this);
	mouseLineAct->setStatusTip(tr("Activate mouse line drawing"));
    connect(mouseLineAct, SIGNAL(triggered()), childWindow, SIGNAL(drawMouseLineFromMW()));
	//connect(mouseLineAct, SIGNAL(triggered()), glWindow, SLOT(drawMouseLine()));



	mousePolylineAct = new QAction(tr("Polyline"), this);
    mousePolylineAct->setStatusTip(tr("Activate mouse polyline drawing"));
    connect(mousePolylineAct, SIGNAL(triggered()), childWindow, SIGNAL(drawMousePolyLineFromMW()));
	//connect(mousePolylineAct, SIGNAL(triggered()), glWindow, SLOT(drawMousePolyline()));

    mousePolygonAct = new QAction(tr("Polygon"), this);
    mousePolygonAct->setStatusTip(tr("Activate mouse polygon drawing"));
    connect(mousePolygonAct, SIGNAL(triggered()), childWindow, SIGNAL(drawMousePolygonFromMW()));
	//connect(mousePolygonAct, SIGNAL(triggered()), glWindow, SLOT(drawMousePolygon()));


  }

  /*<<<<<<<<<<<<<<<<<<<<<<createMenus>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
  void MainWindow::createMenus()
  {
    //The file menu 
    fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(printAct);

    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
	
	//The options menu
    optionsMenu = menuBar()->addMenu(tr("&Options"));
	optionsMenu->addAction(colorAct);

	//The graphics menu
	graphicsMenu = menuBar()->addMenu(tr("&Graphics"));
	drawMenu = graphicsMenu->addMenu(tr("&Draw"));
    drawMenu->addAction(diagLineAct);
    drawMenu->addAction(diagHouseAct);
    drawMenu->addAction(CircleAct);

		
	//The rasterization menu
    rasterizeMenu = graphicsMenu->addMenu(tr("&Rasterize"));
	
	//The transform menu
	transformMenu = graphicsMenu->addMenu(tr("&Transform"));
	
  }

  /*<<<<<<<<<<<<<<<<<<<<<<createToolBar>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
  void MainWindow::createToolBar()
  {
    interactToolBar = addToolBar(tr("Interact"));
    interactToolBar->addAction(mouseLineAct);

    interactToolBar->addAction(mousePolylineAct);
	interactToolBar->addAction(mousePolygonAct);
  }
