#ifndef MAINWIDNOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>

class MainWindow : public QMainWindow, public Ui::MainWindow {
	Q_OBJECT
	void updateEverything();
private slots:
	void on_textInput_textChanged();
	//void on_actAddPdf_triggered();
	//void on_actAddPath_triggered();
	//void on_actRemovePath_triggered();
public:
	MainWindow();
};

#endif 