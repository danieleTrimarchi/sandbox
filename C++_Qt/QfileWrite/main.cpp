#include<iostream>

#include <QFile>

int main(int argc, char *argv[])
{

	QFile f("testFile");
	f.setFileName("myTestFile.txt");
	if (!f.open(QIODevice::WriteOnly)) {
		qWarning("Couldn't open save file.");
		return 1;
	}
	f.write("foobar3");
	f.close();

  return 0;
}

