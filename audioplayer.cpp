#include "audioplayer.hpp"
AudioPlayer::AudioPlayer() {
	track = new QMediaPlayer;
	stream = new QAudioOutput;
	track->setAudioOutput(stream);
}
void AudioPlayer::play(const char *path) {
	track->setSource(QUrl::fromLocalFile(path));
	track->play();
}
