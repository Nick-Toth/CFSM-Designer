/* ***************************************************************
\\ File Name:  QVertex.cpp
// Created By: Nick G. Toth
\\ E-Mail:     ntoth@pdx.edu
// Date:       Aug 9th, 2017
\\
// Overview: This file contains the implementation for a drawable
\\ vertex - especially for use in the CFSM Designer.
//
\\ ***************************************************************/

#include "QVertex.h"


/* *****************************************************
\\ Initialize a new QVertex. See QVertex.h for default
// member values.
\\
// *****************************************************/
QVertex :: QVertex( QWidget * parent,
		    int radius,
		    std::string data,
		    QColor color ): QWidget(parent),
				    data(data),
				    radius(radius),
				    color(color)
{ return; }


/* *****************************************************
\\ Copy constructor. Note that this does not copy data
// from QVertex's parent class (QWidget).
\\
// *****************************************************/
QVertex :: QVertex(const QVertex & qvtex_src): data(qvtex_src.data),
					       radius(qvtex_src.radius),
					       color(qvtex_src.color)
{ return; }


/* *****************************************************
\\ Destructor for convenient use at a later date.
//
\\
// *****************************************************/
QVertex :: ~QVertex()
{ return; }


/* *****************************************************
\\ Copies the data in qvtex_src. Note that this, like
// the copy constructor, does not copy data from
\\ QVertex's parent class (QWidget).
//
\\ *****************************************************/
void QVertex :: operator=(const QVertex & qvtex_src)
{
	data = qvtex_src.data;
	radius = qvtex_src.radius;
	color = qvtex_src.color;
}


/* *****************************************************
\\ Draws the vertex, using one of the paint delegates.
//
\\
// *****************************************************/
void QVertex :: paintEvent(QPaintEvent*)
{	
	// Create QPen and QPainter objects for styling the vertex.
	QPen pen;
	QPainter painter(this);

	// Set the vertex dimensions = diameter.
	resize( 2 * radius, 2 * radius);

	// Use antialiasing for smooth lines.
	painter.setRenderHint(QPainter::Antialiasing);

	// Style the pen specifications.
	pen.setWidth(1);
	pen.setBrush(Qt::black);
	// Set painter to draw with the pen.
	painter.setPen(pen);

	//shadedPaintDelegate(painter); // Style vertex with background color.
	ringPaintDelegate(painter); // Style vertex with colored ring.

	drawText();
}


/* *****************************************************
\\ Delegate of paintEvent for drawing a color-filled
// circle.
\\
// *****************************************************/
void QVertex :: shadedPaintDelegate(QPainter & painter)
{
	// Draw a black ring inside of the vertex radius.
	painter.drawEllipse(1, 1, 2 * radius - 2, 2 * radius - 2);

	// Set the painter to use a brush (fills ellipse)
	// using the color specified by the color member.
	painter.setBrush(color);

	// Draw a shaded circle inside of the previous circle.
	painter.drawEllipse(2, 2, 2 * radius - 4, 2 * radius - 4);
}


/* *****************************************************
\\ Delegate of paintEvent for drawing a circle with a
// color-filled ring.
\\
// *****************************************************/
void QVertex :: ringPaintDelegate(QPainter & painter)
{
	// Draw two black rings of width = 1, and radius difference of 4.
	painter.drawEllipse(1, 1, 2 * radius - 2, 2 * radius - 2);
	painter.drawEllipse(3, 3, 2 * radius - 6, 2 * radius - 6);
	
	// Create a new pen with width = 2, using
	// the color specified by the color member.
	QPen pen;
	pen.setWidth(2);
	pen.setBrush(color);
	painter.setPen(pen);

	// Draw a third circle between the previous 2.
	painter.drawEllipse(2, 2, 2 * radius - 4, 2 * radius - 4);
}



/* *****************************************************
\\ Change the location (from the upper left corner) of
// the vertex.
\\
// *****************************************************/
void QVertex :: relocate(QPoint new_location)
{
	// Update vertex location.
	move(new_location.x(), new_location.y());

	// Redraw the vertex label. (Make Center).
	drawText( QPoint(new_location.x(), new_location.y()));
}
void QVertex :: relocate(int x, int y)
{ return relocate(QPoint(x, y)); }


// Define max function for drawText
#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif // max


/* *****************************************************
\\ Draw the contents of the data field at the center of
// the vertex widget.
\\
// *****************************************************/
void QVertex :: drawText(QPoint new_location)
{
	QPainter painter(this);

	painter.setFont( QFont( "Helevetica",
			// Scale text size, based on the vertex
			// radius, and the length of the data.
		        (radius + (radius / 5) ) / max(1, (0.55 * data.length()))
		       ));

	painter.drawText( QRect(new_location, QSize(width(), height())),
		          Qt::AlignCenter,
			  QString::fromStdString(data)
 			);
}
