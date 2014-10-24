// -*- C++ -*-
/*!
 * @file  mainwindow.h
 * @brief メインウインドウ
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
 * @brief メインウインドウ
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	/*!
     * @brief コンストラクタ
     */
    MainWindow();
	QPushButton *PageGB;	/**<　@brief  */
	QPushButton *PageRB;	/**<　@brief  */
	QPushButton *EffGB;	/**<　@brief  */
	QPushButton *EffRB;	/**<　@brief  */
	QPushButton *SaveSB;	/**<　@brief  */
	QPushButton *SaveEB;	/**<　@brief  */
	QSpinBox *fpsSB;	/**<　@brief  */
	QPushButton *UpdateB;	/**<　@brief  */
	QPushButton *ConnectB;	/**<　@brief  */
	QTableWidget *grtcTable;	/**<　@brief  */
	

//protected:
    
signals:
	
public slots:
	/*!
     * @brief スライドを進めるボタンを押したときのスロット
     */
    void PageGclickedSlot();
	/*!
     * @brief スライドを戻るボタンを押したときのスロット
     */
	void PageRclickedSlot();
	/*!
     * @brief アニメーションを進めるボタンを押したときのスロット
     */
	void EffGclickedSlot();
	/*!
     * @brief アニメーションを戻るボタンを押したときのスロット
     */
	void EffRclickedSlot();
	/*!
     * @brief 動画を保存するボタンを押したときのスロット
     */
	void SaveSclickedSlot();
	/*!
     * @brief 動画の保存を終了するボタンを押したときのスロット
     */
	void SaveEclickedSlot();
	/*!
     * @brief 動画リストの更新ボタンを押したときのスロット
     */
	void UpdateclickedSlot();
	/*!
     * @brief データポート接続ボタンを押したときのスロット
     */
	void ConnectclickedSlot();
	

private:
	QTextCodec* tc;	/**<　@brief  */
	GraphicsView *gv;	/**<　@brief  */
	std::vector<std::vector<std::string>> m_result;	/**<　@brief  */
    
};


#endif
