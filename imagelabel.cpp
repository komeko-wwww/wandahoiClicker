#include "imagelabel.hpp"
#define MLT 10 // mulitiplier value
// Animation Parameters
#define C_START 350 // Starting Duration
#define C_END 200 // Ending Duration
ImageLabel::ImageLabel(QWidget *parent) : QLabel(parent) {
	// Initialize
	shrink = new QPropertyAnimation(this, "geometry", this);
	shrink->setDuration(C_START);

	grow = new QPropertyAnimation(this, "geometry", this);
	grow->setDuration(C_END);

	QObject::connect(shrink, &QPropertyAnimation::finished, [this]() {
		// Grow configuration
		grow->setStartValue(geometry());
		grow->setEndValue(this->original);
		grow->start();
	});
}

void ImageLabel::mousePressEvent(QMouseEvent *event) {
	// Check if its first click
	if (firstClick) {
		original = geometry(); firstClick = false;
	}

	// Shrink Configuration
	shrink->setStartValue(original);
	shrink->setEndValue(original.adjusted(10 * MLT ,10 * MLT,-10 * MLT, -10 * MLT));
	shrink->start();
	emit clicked();
}
