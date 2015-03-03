#ifndef CIRCLEDIALOG_H
#define CIRCLEDIALOG_H

#include <QDialog>
#include <QLineEdit>



class CircleDialog : public QDialog
{
    Q_OBJECT

public:
    CircleDialog(QWidget *parent = 0);

    ~CircleDialog();

signals:
  /*
  A signal to indicate when the values are updated
  */
  void CirclevaluesUpdated(int x, int y, int r);

private:
  QLineEdit *editX, *editY, *editR;

private slots:
  /*<
  Hide this dialog
  */
  void hideDialogCircle();

  /*
  Gets the values from the LineEdits and sends the valuesUpdated signal
  */
  void getCircleValues();
};



#endif // CIRCLEDIALOG_H
