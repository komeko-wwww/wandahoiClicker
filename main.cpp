#include<QApplication>
#include<QPixmap>
#include<QVBoxLayout>
#include "audioplayer.hpp"
#include "imagelabel.hpp"
int main(int argc, char **argv) {
	// Init
	QApplication app(argc, argv);
	QWidget window;
	window.resize(600,600);

	QVBoxLayout *layout = new QVBoxLayout(&window);


	auto *player = new AudioPlayer;
	player->setTrack("./wandahoy.mp3");

	auto *img = new ImageLabel();

	QPixmap pixmap("./wonderhoy.png");

	img->setPixmap(pixmap);
	img->setAlignment(Qt::AlignCenter);
	layout->addWidget(img);

	// wandahoi...
	QObject::connect(img, &ImageLabel::clicked, [player]() {
		player->play();
	});
	window.show();
	return app.exec();
}
