from adaptee import  AudioPlayer, VideoPlayer
from target import Player, IPlayer

# 适配器类
class PlayerAdapter(IPlayer):
    def __init__(self):
        self.player = Player()
        self.audio_player = AudioPlayer()
        self.video_player = VideoPlayer()

    def play(self, file_name, typ):
        # 调用原始播放器
        self.player.play(file_name, typ)
        # 调用音频播放器
        self.audio_player.play_media(file_name, typ)
        # 调用视频播放器
        self.video_player.play_media(file_name, typ)
