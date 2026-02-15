from abc import ABC, abstractmethod

# 媒体类型枚举
class MediaType:
    MP3 = 0
    AIFF = 1
    MIDI = 2
    Wave = 3
    MP4 = 4
    MOV = 5
    AVI = 6
    M4V = 7

# 被适配的接口
class IAdvancedMediaPlayer(ABC):
    @abstractmethod
    def play_media(self, file_name, typ):
        pass

# 音频播放器（被适配的类）
class AudioPlayer(IAdvancedMediaPlayer):
    def play_media(self, file_name, typ):
        if typ == MediaType.AIFF:
            print(f"PlayAudio AIFF : {file_name}")
        elif typ == MediaType.MIDI:
            print(f"PlayAudio MIDI : {file_name}")
        elif typ == MediaType.Wave:
            print(f"PlayAudio wave : {file_name}")

# 视频播放器（被适配的类）
class VideoPlayer(IAdvancedMediaPlayer):
    def play_media(self, file_name, typ):
        if typ == MediaType.MP4:
            print(f"PlayVideo mp4 : {file_name}")
        elif typ == MediaType.MOV:
            print(f"PlayVideo mov : {file_name}")
        elif typ == MediaType.AVI:
            print(f"PlayVideo avi : {file_name}")
        elif typ == MediaType.M4V:
            print(f"PlayVideo m4v : {file_name}")
