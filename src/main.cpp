#include <QApplication>
#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QSystemTrayIcon>
#include <QIcon>

class HvildQWidget : public QWidget {

public:
  HvildQWidget(QWidget *parent = 0);
};

HvildQWidget::HvildQWidget(QWidget *parent)
  : QWidget(parent) {

  QAction *startAction;
  QAction *quitAction;

  startAction = new QAction(tr("&Start"));
  quitAction = new QAction(tr("&Quit"));
  connect(quitAction, &QAction::triggered, this, &QCoreApplication::quit);

  QMenu *trayIconMenu;
  trayIconMenu = new QMenu(this);
  trayIconMenu -> addAction(startAction);
  trayIconMenu -> addSeparator();
  trayIconMenu -> addAction(quitAction);

  const QIcon icon = QIcon(":/resources/images/icon.png");


  QSystemTrayIcon *trayIcon;
  trayIcon = new QSystemTrayIcon(this);
  trayIcon -> setContextMenu(trayIconMenu);
  trayIcon -> setIcon(icon);
  trayIcon -> show();
  
}

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);  
    
  HvildQWidget window;

  window.resize(350, 150);
  window.setWindowTitle("HvildQWidget");

  return app.exec();
}
