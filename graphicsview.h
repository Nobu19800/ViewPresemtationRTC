// -*- C++ -*-
/*!
 * @file  graphicsview.h
 * @brief �摜�\���E�B�W�F�b�g
 */


#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QImage>
#include <QRect>
#include <QWidget>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/imgproc/imgproc.hpp>



/*!
 * @class QGraphicsView
 * @brief �摜�\���E�B�W�F�b�g
 *
 */
class GraphicsView : public QGraphicsView {
	Q_OBJECT
private:
	class QTimer * my_timer;	/**<�@@brief  */
	IplImage* iplimage;	/**<�@@brief  */
	CvVideoWriter *vw;	/**<�@@brief  */

public:
	/*!
     * @brief �R���X�g���N�^
     */
	GraphicsView(QWidget *parent);
	/*!
     * @brief �f�X�g���N�^
     */
	~GraphicsView();

	/*!
     * @brief ����̕ۑ����J�n
	 * @param fps FPS
	 * @param fn �t�@�C���p�X
     */
	void startSaveVideo(int fps, const char* fn);

	bool saveVideo;	/**<�@@brief  */
	int m_rate;	/**<�@@brief  */
	std::string file_path;	/**<�@@brief  */
	
	/*!
     * @brief �`��C�x���g
     */
	void paintEvent(QPaintEvent *);
	

public slots:
	/*!
     * @brief �������ŌĂяo�����X���b�g
     */
	 void show_time();
};

#endif