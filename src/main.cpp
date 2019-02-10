#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QSystemTrayIcon>

class HvildQWidget : public QWidget {

public:
  HvildQWidget(QWidget *parent = 0);
};

HvildQWidget::HvildQWidget(QWidget *parent)
  : QWidget(parent) {

  QSystemTrayIcon *trayIcon;
  trayIcon = new QSystemTrayIcon(this);
  trayIcon -> show();
  
}

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);  
    
  HvildQWidget window;

  window.resize(350, 150);
  window.setWindowTitle("HvildQWidget");

  return app.exec();
}
