// -*- C++ -*-
/*!
 * @file  mainwindow.h
 * @brief ���C���E�C���h�E
 */



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QtWidgets>

#include "graphicsview.h"


class ToolBar;
QT_FORWARD_DECLARE_CLASS(QMenu)
QT_FORWARD_DECLARE_CLASS(QSignalMapper)


/*!
 * @class MainWindow
 * @brief ���C���E�C���h�E
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	/*!
     * @brief �R���X�g���N�^
     */
    MainWindow();
	QPushButton *PageGB;	/**<�@@brief  */
	QPushButton *PageRB;	/**<�@@brief  */
	QPushButton *EffGB;	/**<�@@brief  */
	QPushButton *EffRB;	/**<�@@brief  */
	QPushButton *SaveSB;	/**<�@@brief  */
	QPushButton *SaveEB;	/**<�@@brief  */
	QSpinBox *fpsSB;	/**<�@@brief  */
	QPushButton *UpdateB;	/**<�@@brief  */
	QPushButton *ConnectB;	/**<�@@brief  */
	QTableWidget *grtcTable;	/**<�@@brief  */
	

//protected:
    
signals:
	
public slots:
	/*!
     * @brief �X���C�h��i�߂�{�^�����������Ƃ��̃X���b�g
     */
    void PageGclickedSlot();
	/*!
     * @brief �X���C�h��߂�{�^�����������Ƃ��̃X���b�g
     */
	void PageRclickedSlot();
	/*!
     * @brief �A�j���[�V������i�߂�{�^�����������Ƃ��̃X���b�g
     */
	void EffGclickedSlot();
	/*!
     * @brief �A�j���[�V������߂�{�^�����������Ƃ��̃X���b�g
     */
	void EffRclickedSlot();
	/*!
     * @brief �����ۑ�����{�^�����������Ƃ��̃X���b�g
     */
	void SaveSclickedSlot();
	/*!
     * @brief ����̕ۑ����I������{�^�����������Ƃ��̃X���b�g
     */
	void SaveEclickedSlot();
	/*!
     * @brief ���惊�X�g�̍X�V�{�^�����������Ƃ��̃X���b�g
     */
	void UpdateclickedSlot();
	/*!
     * @brief �f�[�^�|�[�g�ڑ��{�^�����������Ƃ��̃X���b�g
     */
	void ConnectclickedSlot();
	

private:
	QTextCodec* tc;	/**<�@@brief  */
	GraphicsView *gv;	/**<�@@brief  */
	std::vector<std::vector<std::string>> m_result;	/**<�@@brief  */
    
};


#endif
