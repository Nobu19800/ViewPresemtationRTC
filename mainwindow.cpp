// -*- C++ -*-
/*!
 * @file  mainwindow.cpp
 * @brief メインウインドウ
 */

#include "mainwindow.h"
#include "PresentationView.h"


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


extern PresentationView* comp;


MainWindow::MainWindow()
{
    tc = QTextCodec::codecForLocale();
    setWindowTitle("Presentation View Component");

    QHBoxLayout *layout = new QHBoxLayout;

	QWidget *widget = new QWidget;
    widget->setLayout(layout);

	setCentralWidget(widget);

	menuBar()->addMenu(tr("&File"));

	gv = new GraphicsView(this);
	
	layout->addWidget(gv);

	QVBoxLayout *b_layout = new QVBoxLayout;
	PageGB = new QPushButton(tc->toUnicode("ページを進める"));
	b_layout->addWidget(PageGB);
	connect(PageGB, SIGNAL(clicked()), this, SLOT(PageGclickedSlot()));
	PageRB = new QPushButton(tc->toUnicode("ページを戻す"));
	b_layout->addWidget(PageRB);
	connect(PageRB, SIGNAL(clicked()), this, SLOT(PageRclickedSlot()));
	EffGB = new QPushButton(tc->toUnicode("アニメーションを実行"));
	b_layout->addWidget(EffGB);
	connect(EffGB, SIGNAL(clicked()), this, SLOT(EffGclickedSlot()));
	EffRB = new QPushButton(tc->toUnicode("アニメーションを戻す"));
	b_layout->addWidget(EffRB);
	connect(EffRB, SIGNAL(clicked()), this, SLOT(EffRclickedSlot()));

	SaveSB = new QPushButton(tc->toUnicode("動画を保存を開始"));
	b_layout->addWidget(SaveSB);
	connect(SaveSB, SIGNAL(clicked()), this, SLOT(SaveSclickedSlot()));

	SaveEB = new QPushButton(tc->toUnicode("動画の保存を終了"));
	b_layout->addWidget(SaveEB);
	connect(SaveEB, SIGNAL(clicked()), this, SLOT(SaveEclickedSlot()));
	

	QVBoxLayout *fpsLayout = new QVBoxLayout();
	QLabel *Label = new QLabel(tc->toUnicode("FPS"));
	fpsLayout->addWidget(Label);
	fpsSB = new QSpinBox();
	fpsSB->setMaximum(1000);
	fpsSB->setMinimum(1);
	fpsSB->setValue(30);
	fpsLayout->addWidget(fpsSB);
	b_layout->addLayout(fpsLayout);


	layout->addLayout(b_layout);


	

	grtcTable = new QTableWidget();
	
	/*QTableWidgetItem *iName = new QTableWidgetItem(tc->toUnicode("FPS"));
	//grtcTable->insertRow(0);
	grtcTable->setColumnCount( 1 );
	grtcTable->setRowCount( 1 );
	grtcTable->setItem(0, 0, iName);
	grtcTable->setRowCount( 2 );
	QList<QTableWidgetItem*> twis = grtcTable->selectedItems();
	grtcTable->clear();*/

	b_layout->addWidget(grtcTable);

	UpdateB = new QPushButton(tc->toUnicode("更新"));
	b_layout->addWidget(UpdateB);
	connect(UpdateB, SIGNAL(clicked()), this, SLOT(UpdateclickedSlot()));

	ConnectB = new QPushButton(tc->toUnicode("接続"));
	b_layout->addWidget(ConnectB);
	connect(ConnectB, SIGNAL(clicked()), this, SLOT(ConnectclickedSlot()));

	

}

void MainWindow::PageGclickedSlot()
{
	if(comp != NULL)
	{
		comp->writeSlideNumberOut(1);
	}
}

void MainWindow::PageRclickedSlot()
{
	if(comp != NULL)
	{
		comp->writeSlideNumberOut(-1);
	}
}

void MainWindow::EffGclickedSlot()
{
	if(comp != NULL)
	{
		comp->writeEffectNumberOut(1);
	}
}

void MainWindow::EffRclickedSlot()
{
	if(comp != NULL)
	{
		comp->writeEffectNumberOut(-1);
	}
}


void MainWindow::SaveSclickedSlot()
{
	if(!gv->saveVideo)
	{
		QString fileName = QFileDialog::getSaveFileName(this,
								tc->toUnicode("保存"), "",
								tr("AVI File (*.avi);;All Files (*)"));
		if (fileName.isEmpty())
			return;

		QByteArray ba = fileName.toLocal8Bit();
		gv->startSaveVideo(fpsSB->value(), ba);
	}
}

void MainWindow::SaveEclickedSlot()
{
	if(gv->saveVideo)
	{
		gv->saveVideo = false;
		QMessageBox msgBox(this);
		msgBox.setText(tc->toUnicode("動画の保存を完了しました。"));
		msgBox.exec();
	}
}

void MainWindow::UpdateclickedSlot()
{
	grtcTable->clear();
	
	if(comp)
	{
		m_result = comp->getList();
		grtcTable->setRowCount( m_result.size() );
		grtcTable->setColumnCount( 1 );

		for(int i=0;i < m_result.size();i++)
		{
			if(m_result[i].size() >= 2)
			{
				QTableWidgetItem *iName = new QTableWidgetItem(tc->toUnicode(m_result[i][0].c_str()));
				grtcTable->setItem(i, 0, iName);
			}
		}
	}

}

void MainWindow::ConnectclickedSlot()
{
	if(comp)
	{
		QList<QTableWidgetItem*> twis = grtcTable->selectedItems();
		if(twis.size() > 0)
		{
			QTableWidgetItem *twi = twis[0];
			QByteArray ba = twi->text().toLocal8Bit();
			
			comp->connectDPort(ba, m_result);
		}
		else
		{
			QMessageBox msgBox(this);
			msgBox.setText(tc->toUnicode("RTCが選択されていません"));
			msgBox.exec();
		}
	}
}