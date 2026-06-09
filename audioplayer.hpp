#ifndef AUDIO_PLAYER_HPP
#define AUDIO_PLAYER_HPP
#include<QMediaPlayer>
#include<QAudioOutput>
class AudioPlayer {
	private:
		QMediaPlayer *track;
		QAudioOutput *stream;
	public:
		AudioPlayer();
		void play(const char *input);
};
#endif
