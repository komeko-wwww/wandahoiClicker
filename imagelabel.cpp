#include "imagelabel.hpp"
ImageLabel::ImageLabel(QWidget *parent) : QLabel(parent) {}
void ImageLabel::mousePressEvent(QMouseEvent *event) {
	emit clicked();
}
