// -*- C++ -*-
/*!
 * @file  graphicsview.cpp
 * @brief 画像表示ウィジェット
 */

#include "graphicsview.h"
#include "PresentationView.h"
#include "ImageDataCom.h"


extern PresentationView* comp;

#include <QAction>
#include <QLayout>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextEdit>
#include <QFile>
#include <QDataStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QSignalMapper>
#include <QApplication>
#include <QPainter>
#include <QMouseEvent>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <qdebug.h>
#include <QtWidgets>



GraphicsView::GraphicsView(QWidget *parent) : QGraphicsView(parent)
{
	saveVideo = false;

	

	my_timer = new QTimer();
	connect(my_timer, SIGNAL(timeout()), this, SLOT(show_time()));
    //startTimer(10);
	m_rate = 30;
	file_path = "sample.avi";
	my_timer->start(m_rate);

	iplimage = NULL;
	vw = NULL;
	
}

GraphicsView::~GraphicsView()
{
	if(my_timer)delete my_timer;
}

void GraphicsView::show_time()
{
	
	//update();
	//repaint();
	if(comp != NULL)
	{
		
		if(comp->imageIsNew)
		{
			viewport()->update();
		}
	}

	if(vw != NULL && iplimage != NULL)
	{
		cvWriteFrame(vw, iplimage);

	}
}

void GraphicsView::paintEvent(QPaintEvent *)
{
	if(vw != NULL && !saveVideo)
	{
		cvReleaseVideoWriter(&vw);
	}
	
	if(comp != NULL)
	{
		
		if(comp->imageIsNew)
		{
			CameraImage *m_image = comp->getImage();
			comp->imageIsNew = false;
			if(iplimage != NULL)
			{
				if(saveVideo)
				{
					if(vw == NULL)
					{
						vw = cvCreateVideoWriter (file_path.c_str(), CV_FOURCC ('X', 'V', 'I', 'D'), m_rate, cvSize((int) iplimage->width, (int) iplimage->height));
					}
					


				}

				cvReleaseImage(&iplimage);
			}
			iplimage = GetCameraImage(m_image);
			setMinimumSize(m_image->width, m_image->height);
			setMaximumSize(m_image->width, m_image->height);			

		}
	}

	if(iplimage != NULL)
	{
		cv::Mat src, dst;
		src = cv::cvarrToMat(iplimage);
		//src = cv::imread("sample.jpg");
		cv::cvtColor(src, dst, CV_RGB2BGR);
		QImage img(dst.data, dst.cols, dst.rows, dst.step, QImage::Format_RGB888);

	

		QPainter qPainter(viewport());
		qPainter.drawImage(0, 0, img);

		
	}
		
    
}

void GraphicsView::startSaveVideo(int fps, const char* fn)
{
	m_rate = fps;
	file_path = fn;
	saveVideo = true;
	my_timer->start(m_rate);
}