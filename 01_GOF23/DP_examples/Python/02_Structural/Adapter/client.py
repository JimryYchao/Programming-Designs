from adapter import PlayerAdapter
from adaptee import MediaType

# 测试代码
if __name__ == "__main__":
    # 创建适配器实例
    player = PlayerAdapter()
    
    # 播放背景音乐
    player.play("BGMusic.wave", MediaType.Wave)

    # 播放 CG 视频
    player.play("CG.mp4", MediaType.MP4)
