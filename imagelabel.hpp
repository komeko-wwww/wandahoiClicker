#ifndef IMAGE_LABEL_H
#define IMAGE_LABEL_H
#include<QLabel>
#include<QMouseEvent>
class ImageLabel : public QLabel {
	Q_OBJECT
	public:
		explicit ImageLabel(QWidget *parent = nullptr);
	signals:
		void clicked();
	protected:
		void mousePressEvent(QMouseEvent *event) override;
};
#endif
