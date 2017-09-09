/* ***************************************************************
\\ File Name:  QVertex.h
// Created By: Nick G. Toth
\\ E-Mail:     ntoth@pdx.edu
// Date:       Aug 9th, 2017
\\
// Overview: This file contains the declaration for a drawable
\\ vertex - especially for use in the CFSM Designer. See
// QVertex.cpp for implementation details.
\\
// ***************************************************************/

#ifndef QVERTEX_H
#define QVERTEX_H

// Import QT lib.
#include <QApplication>
#include <QtWidgets>
#include <QWidget>
#include <QPushButton>
#include <QPainter>

// Import std lib.
#include <iostream>
#include <cmath>


#ifndef nullptr
#define nullptr 0
#endif // nullptr.


class QVertex : public QWidget
{
	public:

		QVertex( QWidget * parent = nullptr,
						 int radius = 25,
						 std::string data = "000",
						 QColor color = Qt::blue );

		QVertex(const QVertex & qvtex_src);

		~QVertex();

		// Display the vertex in the parent qwidget.
		void paintEvent(QPaintEvent*);

		// Change the location (from the upper left corner) of the vertex.
		void relocate(QPoint);
		void relocate(int, int);

	private:

		// Overload the assignment operator for resetting vertex fields.
		void operator=(const QVertex &);

		// Draw the contents of data at the center of the vertex widget.
		void drawText(QPoint new_location = QPoint(0, 0));

		// Vertex styling methods.
		void shadedPaintDelegate(QPainter & painter);
		void ringPaintDelegate(QPainter & painter);


		std::string data; // Data to be displayed at the center of the vertex.
		int radius; // Radius (in pixels) of the vertex.
		QColor color; // Background color of the vertex.
};

#endif // QVERTEX_H
