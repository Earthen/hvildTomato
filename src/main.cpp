#include <QApplication>
#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QSystemTrayIcon>
#include <QIcon>
#include <chrono>
#include <thread>

class HvildQWidget : public QWidget {

public:
  HvildQWidget(QWidget *parent = 0);
};

static void sleep(int delay) {
  std::this_thread::sleep_for(std::chrono::seconds(delay));
}


static void notify() {
  system("notify-send 'Starting pomodoro!' ");
  sleep(5);
  system("notify-send 'Pomodoro finished, take a breack!' ");
}

HvildQWidget::HvildQWidget(QWidget *parent)
  : QWidget(parent) {

  QAction *startAction;
  QAction *quitAction;
  

  startAction = new QAction(tr("&Start"));
  connect(startAction, &QAction::triggered, this, notify);
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
