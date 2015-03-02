#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
    QString str = "OTDR-ACTIVE::1:2:PORT=10,POWER=10;OTDR-ACTIVE::1:2:PORT=10,POWER=10;";
    QRegExp rx("OTDR-ACTIVE::1:2:PORT=(\\d+),POWER=\\1;"); // primitive floating point matching

    QStringList qStringList;
    int pos = 0;
    while ((pos = rx.indexIn(str, pos)) != -1) {
      qStringList << rx.cap(1);
      pos += rx.matchedLength();
    }

  qDebug() << qStringList << endl;
}
