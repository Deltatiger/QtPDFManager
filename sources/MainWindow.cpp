#include "../headers/MainWindow.h"
#include <QFile>
#include <QProcess>
#include <QTextStream>
#include <stdlib.h>

using namespace std;

MainWindow::MainWindow()	{
	setupUi(this);
	//We start up the process
	//We set up the Combo box for categorys
	updateEverything();
}

void MainWindow::updateEverything()	{
	/*
	 * This function is used whenever we need to update all the interfaces.
	 * This primarily updates the category combo box and clears the resultWindow
	 */
	int countIndex = categoryCombo->count();
	for(; countIndex == 0; countIndex--)	{
		categoryCombo->removeItem(countIndex);
	}
	if(QFile::exists(":/resources/category.txt"))	{
		QFile categoryFile(":/resources/category.txt");
		if(!categoryFile.open(QIODevice::ReadOnly | QIODevice::Text))	{
			//We cant Open the file. So we set the ComboBox to None.
			categoryCombo->addItem(QString("All"));
		} else {
			//Now we add everything in that file to this combo box
			QTextStream categoryDB(&categoryFile);
			while(!categoryDB.atEnd())	{
				//Now we read and add everything to the combo box
				QString option = categoryDB.readLine();
				categoryCombo->addItem(option);
			}
			categoryCombo->addItem(QString("All"));
		}
		categoryFile.close();
	} else {
		categoryCombo->addItem(QString("All"));
	}
}

void MainWindow::on_textInput_textChanged()	{
	//This is the slot for textInput
	QProcess * process = new QProcess(0);
	process->start(QString("cmd /c dir C:\\"));
	process->waitForFinished(-1);
	delete process;
}