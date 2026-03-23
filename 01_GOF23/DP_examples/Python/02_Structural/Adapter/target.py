from abc import ABC, abstractmethod
from adaptee import MediaType


# 目标接口
class IPlayer(ABC):
    @abstractmethod
    def play(self, file_name, typ):
        pass

# 具体目标类
class Player(IPlayer):
    def play(self, file_name, typ):
        if typ == MediaType.MP3:
            print(f"PlayAudio mp3 : {file_name}")