#ifndef HVILDTOMATO_H
#define HVILDTOMATO_H

#include <QMainWindow>

namespace Ui {
class HvildTomato;
}

class HvildTomato : public QMainWindow
{
    Q_OBJECT

public:
    explicit HvildTomato(QWidget *parent = 0);
    ~HvildTomato();

private:
    Ui::HvildTomato *ui;
};

#endif // HVILDTOMATO_H
