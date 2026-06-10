#include<QApplication>
#include<QLabel>
#include<QPixmap>
#include<QVBoxLayout>
#include "audioplayer.hpp"
#include "imagelabel.hpp"
// Vars????
int counter {};

// Main
int main(int argc, char **argv) {
	// Init
	QApplication app(argc, argv);
	QWidget window, wcounter;

	// Setup
	wcounter.resize(300,300);
	window.resize(600,600);

	auto *layout = new QVBoxLayout(&window);
	auto *layoutW = new QVBoxLayout(&wcounter);

	auto *player = new AudioPlayer;
	player->setTrack("./wandahoy.mp3");

	auto *img = new ImageLabel();
	QPixmap pixmap("./wonderhoy.png");
	img->setPixmap(pixmap);
	img->setAlignment(Qt::AlignCenter);
	layout->addWidget(img);

	auto *counterText = new QLabel("W..wandahoi?");
	layoutW->addWidget(counterText);

	// wandahoi...
	QObject::connect(img, &ImageLabel::clicked, [player, &counterText]() {
		counter++; counterText->setText(QString("Wandahoi Count: %1").arg(counter));
		player->play();
	});

	// Window Logic
	window.show();
	wcounter.show();

	window.setAttribute(Qt::WA_DeleteOnClose);
	wcounter.setAttribute(Qt::WA_DeleteOnClose);

	QObject::connect(&window, &QWidget::destroyed, &app, &QCoreApplication::quit);
	QObject::connect(&wcounter, &QWidget::destroyed, &app, &QCoreApplication::quit);
	return app.exec();
}
