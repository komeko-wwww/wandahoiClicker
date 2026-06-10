#include "audioplayer.hpp"
AudioPlayer::AudioPlayer() {
	track = new QMediaPlayer;
	stream = new QAudioOutput;
	track->setAudioOutput(stream);
}
void AudioPlayer::setTrack(const char* path) {
	track->setSource(QUrl::fromLocalFile(path));
}
void AudioPlayer::play() {
	track->play();
}
