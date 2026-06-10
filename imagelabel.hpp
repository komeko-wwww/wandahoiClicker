#ifndef IMAGE_LABEL_H
#define IMAGE_LABEL_H
#include<QLabel>
#include<QMouseEvent>
#include<QPropertyAnimation>
class ImageLabel : public QLabel {
	Q_OBJECT
	private:
		QPropertyAnimation *grow, *shrink;
		QRect original;
		bool firstClick = true;
	public:
		explicit ImageLabel(QWidget *parent = nullptr);
	signals:
		void clicked();
	protected:
		void mousePressEvent(QMouseEvent *event) override;
};
#endif
