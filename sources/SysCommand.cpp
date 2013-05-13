#include "../headers/SysCommand.h"
#include <QProcess>

using namespace std;

void SysCommand::PerfomDirCommand(QString filePath)	{
	QString command = "cmd /c dir /B " + filePath + " > out.txt";
	QProcess * process = new QProcess(0);
	process->start(command);
	process->waitForFinished(-1);
	delete process;
}