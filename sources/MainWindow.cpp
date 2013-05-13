#include "../headers/MainWindow.h"
#include "../headers/TrieHandler.h"
#include "../headers/SysCommand.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDir>

using namespace std;

MainWindow::MainWindow()	{
	setupUi(this);
	//We start up the process
	//We first set up some custom signals and stuffs 
	connect(this, SIGNAL(callAddPath), this , SLOT(on_actAddPath_triggered));
	//Now init some variables
	categoryCount = 0;
	pathCount = 0;
	//We set up the Combo box for categorys
	update_Category();
	//Now we have to set
	update_Database();
}

void MainWindow::update_Database()	{
	//This is used to completely delete the existing tries ( if the exist) and recreate them with the contents
	if(THandlers != NULL)	{
		//Already exists. Clear them out first
	}
	THandlers = new TrieHandler * [categoryCount];
	for(int i = 0; i <= categoryCount; i++)	{
		//We take into account the range from 0-9 and a-z including some special charecters
		THandlers[i] = new TrieHandler(50, '0');
	}
	//We now check for the Path's
	if(!QFile::exists(":/resources/pathList.txt"))	{
		//There is a path file. If we dont have this we call the action Add Path
		emit callAddPath();
	} else {
		QFile PathFile(":/resources/pathList.txt");
		if(!PathFile.open(QIODevice::ReadOnly | QIODevice::Text))	{
			//Now we have the file open , we load the stuff into the holders
			QTextStream pathFile(&PathFile);
			if(!pathFile.atEnd())	{
				QString path = pathFile.readLine();
				pathHash.insert(path, pathCount);
				pathCount++;
			}
		} else {
			pathCount = 0;
			emit callAddPath();
		}
		//Now we have all the filenames in the HashMap we use that to read the files
		for(int i = 0 ; i < pathCount; i++)	{
			QString pathFile = pathHash.key(i);
			//We need to get the pdf files from this folder now.
			SysCommand::PerfomDirCommand(pathFile);
			//Now we read the output file.
		}
	}
	//Now that those are setup we starting seeing what files are open.
	if(QFile::exists(":/resources/books.db"))	{
		//There is an exisiting file. So we have a database. We start it.
	}
}

void MainWindow::on_actAddPath_triggered()	{
	//This is used to add a new path to the init Process
	QString folder = QFileDialog::getExistingDirectory();
	//Now we have the folder name in the folder string
	QFile pathFile("../resources/pathList.txt");
	//First we check if this already exists. We dont want duplicates
	bool pathExists = false;
	if(pathFile.open(QIODevice::ReadOnly | QIODevice::Text))	{
		//We read till end and check if it already exists
		QTextStream checkStream(&pathFile);
		while(!checkStream.atEnd())	{
			//We check each line if the path is exist
			QString sPath = checkStream.readLine();
			//We use compare to check if the two are the same or not
			if(sPath.compare(folder) == 0)	{
				//This means it already exists. Getting out.
				pathExists = true;
				break;
			}
		}
		pathFile.close();
	}
	if(!pathExists && pathFile.open(QIODevice::Append | QIODevice::Text))	{
		//We add it to the existing path's and then refresh the database.
		QTextStream outPathFile(&pathFile);
		outPathFile<<folder<<endl;
		pathFile.close();
		update_Database();
	}
}

void MainWindow::update_Category()	{
	/*
	 * This function is used whenever we need to update all the interfaces.
	 * This primarily updates the category combo box and clears the resultWindow
	 */
	//This is used to remove anything from the combo box if it exists
	int countIndex = categoryCombo->count();
	for(; countIndex == 0; countIndex--)	{
		categoryCombo->removeItem(countIndex);
	}
	//We start fresh and add the data if it exists.
	if(QFile::exists(":/resources/category.txt"))	{
		QFile categoryFile(":/resources/category.txt");
		if(!categoryFile.open(QIODevice::ReadOnly | QIODevice::Text))	{
			//We cant Open the file. So we set the ComboBox to None.
			categoryCombo->addItem(QString("All"));
			categoryHash.insert("ALl", 0);
		} else {
			//Now we add everything in that file to this combo box
			QTextStream categoryDB(&categoryFile);
			while(!categoryDB.atEnd())	{
				//Now we read and add everything to the combo box
				QString option = categoryDB.readLine();
				categoryCombo->addItem(option);
				categoryHash.insert(option , categoryCount);
				categoryCount++;
			}
			categoryHash.insert("All", categoryCount++);
			categoryCombo->addItem(QString("All"));
		}
		categoryFile.close();
	} else {
		categoryCombo->addItem(QString("All"));
		categoryHash.insert("All", 0);
	}
}

void MainWindow::on_textInput_textChanged()	{
	//This is the slot for textInput
	
}