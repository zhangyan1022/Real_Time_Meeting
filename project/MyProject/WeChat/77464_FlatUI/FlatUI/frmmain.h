#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>

class QPushButton;
class QLineEdit;
class QProgressBar;
class QSlider;

namespace Ui
{
class frmMain;
}

class frmMain : public QWidget
{
	Q_OBJECT

public:
	explicit frmMain(QWidget *parent = 0);
	~frmMain();

private:
	Ui::frmMain *ui;

private slots:
	void initForm();
	void setBtnQss(QPushButton *btn,
	               QString normalColor, QString normalTextColor,
	               QString hoverColor, QString hoverTextColor,
	               QString pressedColor, QString pressedTextColor);
	void setTxtQss(QLineEdit *txt, QString normalColor, QString focusColor);
	void setBarQss(QProgressBar *bar, QString normalColor, QString chunkColor);
    void setSliderQss(QSlider *slider, QString normalColor, QString grooveColor, QString handleColor);
};

#endif // FRMMAIN_H
