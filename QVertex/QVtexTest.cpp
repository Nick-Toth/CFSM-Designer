/* ***************************************************************
\\ File Name:  QVertexTest.cpp
// Created By: Nick G. Toth
\\ E-Mail:     ntoth@pdx.edu
// Date:       Aug 9th, 2017
\\
// Overview: Testing file for the QVertex widget.
\\
// ***************************************************************/

#include "QVertex.h"


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Main Window -- TESTING ONLY !!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
class GraphView : public QMainWindow
{
	public:
		GraphView( QWidget * parent = nullptr,
			   Qt::WindowFlags flags = 0,
			   int height = 0, int width = 0 ): QMainWindow(parent, flags)
		{
			setFixedSize(width, height);
			setStyleSheet("background-color: #3c3c3c;");
			tex = new QVertex(this, 25, "999", QColor("#fd625e"));
			tex->relocate(100,100);
		}
		~GraphView() { return; }
		QVertex * tex;
};


int main(int argc, char **argv)
{
	QApplication app (argc, argv);

	GraphView main(0,0,250, 250);
	main.setWindowTitle("QT Testing");
	main.show();

	return app.exec();
}
