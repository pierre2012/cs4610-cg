#include "CircleDialog.h"

#include <QVBoxLayout>

#include <QHBoxLayout>

#include <QPushButton>

#include <QLabel>



CircleDialog::CircleDialog(QWidget *parent) : QDialog(parent)

{

    QPushButton *drawButton, *hideButton;

    drawButton = new QPushButton("Draw", this);

    hideButton = new QPushButton("Hide", this);



    //When the draw buton is clicked the getValues SLOT is called

    connect(drawButton, SIGNAL(clicked()), this, SLOT(getCircleValues()));



    //When the hide button is clicked the hideDialog SLOT is called

    connect(hideButton, SIGNAL(clicked()), this, SLOT(hideDialogCircle()));

//Create a set of labels

    QLabel *labelX,  *labelY, *labelR;

    labelX = new QLabel("X:", this);

    labelY = new QLabel("Y:", this);

    labelR = new QLabel("R:", this);



    //Create a set of LineEdits

    editX = new QLineEdit(this);



    editY = new QLineEdit(this);

    editR = new QLineEdit(this);



    //The QVBoxLayout is like an invisible container for stacking GUI objects vertically

    QVBoxLayout *vLay = new QVBoxLayout(this);



    //The QHBoxLayout is similar but stacks them horizontally

    QHBoxLayout *h1 = new QHBoxLayout();

    h1->addSpacing(10);			 //Add space between widget

    h1->addWidget(labelX);		 //Add label

    h1->addWidget(editX,5);	 //Add lineEdit



    QHBoxLayout *h2 = new QHBoxLayout();

    h2->addSpacing(10);

    h2->addWidget(labelY);

    h2->addWidget(editY,5);



    QHBoxLayout *h3 = new QHBoxLayout();

    h3->addSpacing(10);

    h3->addWidget(labelR);

    h3->addWidget(editR,5);



    QHBoxLayout *h4 = new QHBoxLayout();

    h4->addSpacing(10);

    h4->addWidget(drawButton);  //Add draw button

    h4->addStretch(5);

    h4->addWidget(hideButton);   //Add hide button

    h4->addSpacing(10);



    //Add all the horizontal layouts we created to the vertical layout

    vLay->addLayout(h1);

    vLay->addLayout(h2);

    vLay->addLayout(h3);

    vLay->addLayout(h4);


}



CircleDialog::~CircleDialog()
{

}


void CircleDialog::hideDialogCircle()
{
    hide();
}

void CircleDialog::getCircleValues()
{

   //Whenever then draw button is pushed this signal is called

   emit CirclevaluesUpdated(editX->text().toInt(), editY->text().toInt(), editR->text().toInt());

}








