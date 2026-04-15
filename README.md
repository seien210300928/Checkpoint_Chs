# Checkpoint <a href="https://github.com/FlagBrew/Checkpoint/releases/latest"><img src="https://img.shields.io/github/downloads/FlagBrew/Checkpoint/total.svg"></a>

一款针对 3DS 和 Switch 的快速且简洁的自制软件存档管理器，使用 C++ 编写。
## 中文改版特别说明
<span style="font-size:18px;"> **没有安装汉化字体的请先前往[一只火狐的杂物间](https://stray-soul.com/softwares.html)处安装中文字库** </span><br>
<span style="font-size:18px;"> **本中文改版最初版本为3.12.0** </span><br>
<span style="font-size:18px;"> **本中文改版优先专注于3DS版本的汉化** </span><br>
<span style="font-size:18px;"> **Switch版本没有就肯定是没做完** </span><br>
<span style="font-size:18px;"> **但是更新日志都会同步原仓库** </span>
<p align="center"><img src="https://i.imgur.com/adEdJWO.jpeg" />
<img src="https://i.imgur.com/7Z2S0gG.png" /></p>

## 为什么选择 Checkpoint？

Checkpoint 的设计理念是简单和高效。界面经过精心设计，尽量将更多操作选项浓缩到一起，同时保持易于使用。

此外，Checkpoint 体积非常轻量 —— 它带有精美图形界面，并使用了最新可用的库进行构建。

Checkpoint 3DS 版本原生支持 3DS 和 DS 卡带、数字标准标题以及试玩版标题。它还会自动检查并过滤可能没有可备份或还原存档的自制软件标题，该功能无需外部标题列表即可完成过滤。因此，Checkpoint 不需要频繁的用户维护就能保持完整功能。

Checkpoint Switch 版本原生支持你已游玩的游戏的 NAND 存档。标题信息会自动加载。

## 使用方法

你可以在 CFW 和基于 Rosalina 的 Homebrew 启动器下使用 Checkpoint 3DS 版本。*Checkpoint 不支持基于 hax 的 Homebrew 启动器。*

Checkpoint Switch 版本在自制软件启动器上运行。请确保你正在使用最新的 payload。

3DS 版本首次启动时会比平常花费更长时间（通常取决于已安装标题数量，大约 1-2 分钟），因为需要生成工作目录 —— 此后 Checkpoint 启动速度会明显变快。

你可以使用方向键或 L/R 在标题列表中移动，当选择器位于目标标题时按 A 确认。然后，你可以使用方向键或触摸屏选择要还原/覆盖的备份存档。

## 工作路径

Checkpoint 使用以下目录来存储其生成的文件。请注意，所有工作目录会在首次启动时自动生成（或者当 Checkpoint 发现一个尚未存在工作目录的新标题时生成）。

### 3DS

* **`sdmc:/3ds/Checkpoint`**：根路径
* **`sdmc:/3ds/Checkpoint/config.json`**：自定义配置文件
* **`sdmc:/3ds/Checkpoint/logs`**：日志文件
* **`sdmc:/3ds/Checkpoint/saves/<unique id> <game title>`**：通用游戏存档备份根路径
* **`sdmc:/3ds/Checkpoint/extdata/<unique id> <game title>`**：通用游戏扩展数据备份根路径

### Switch

* **`sdmc:/switch/Checkpoint`**：根路径
* **`sdmc:/switch/Checkpoint/logs`**：日志文件
* **`sdmc:/switch/Checkpoint/config.json`**：自定义配置文件
* **`sdmc:/switch/Checkpoint/saves/<title id> <game title>`**：通用游戏存档备份根路径

## 配置文件

你可以编辑 **`config.json`** 配置文件，为 Checkpoint 3DS 版本添加或切换功能。

### 示例配置文件：

```
{
  "filter": [
    "0x000400000011C400",
    "0x000400000014F100"
  ],
  "favorites": [
    "0x000400000011C400"
  ],
  "additional_save_folders": {
    "0x00040000001B5000": {
      "folders": [
        "/3ds/mySaves/1B50",
        "/moreSaves"
      ]
    },
    "0x00040000001B5100": {
      "folders": [
        "/3ds/PKSM/backups"
      ]
    }
  },
  "additional_extdata_folders": {

  },
  "nand_saves": true,
  "version": 3
}
```

## 故障排除

当出现异常或操作失败时，Checkpoint 会显示错误代码。如果你遇到问题，请先确认它是否已有人报告，并提供错误代码和复现步骤摘要。

此外，你还可以加入 FlagBrew 的 Discord 服务器（以下链接）获取实时支持。

## 编译

devkitARM 和 devkitA64 是编译 Checkpoint 3DS 与 Switch 版本所必需的。更多信息请访问 [devkitpro.org](https://devkitpro.org/wiki/Getting_Started)。按以下方式安装或更新依赖项。

### 3DS 版本

`dkp-pacman -S libctru citro3d citro2d tex3ds 3ds-bzip2`

### Switch 版本

`dkp-pacman -S libnx switch-pkg-config switch-freetype switch-libpng switch-libjpeg-turbo switch-sdl2 switch-sdl2_image switch-sdl2_ttf`

## 许可证

本项目采用 GNU GPLv3 许可。GPLv3 的附加条款 7.b 和 7.c 也适用。详情请参阅 [LICENSE.md](https://github.com/FlagBrew/Checkpoint/blob/master/LICENSE)。

## 致谢

* 感谢 [Bernardo](https://github.com/BernardoGiordano/) 创建 Checkpoint。
* 感谢 [J-D-K](https://github.com/J-D-K) 的原始 [JKSM](https://github.com/J-D-K/JKSM) 版本。
* 感谢 [TuxSH](https://github.com/tuxsh) 的 [TWLSaveTool](https://github.com/TuxSH/TWLSaveTool)，其中的 SPI 代码被采用于本项目。
* 感谢 [piepie62](https://github.com/piepie62) 及所有其他 [PKSM](https://github.com/FlagBrew/PKSM) 贡献者，其代码已移植到 Checkpoint。
* 感谢 WinterMute、fincs 以及 [devkitPro](https://devkitpro.org/) 的贡献者，为 devkitARM、devkitA64 和 [dkp-pacman](https://github.com/devkitPro/pacman/releases) 提供支持。
* 感谢 Yellows8 以及所有 [switch-examples](https://github.com/switchbrew/switch-examples) 的维护者。
* 感谢 [rakujira](https://twitter.com/rakujira) 提供出色的 Checkpoint 标志设计。
* 感谢 achinech 帮助调试臭名昭著的 3.8.x 崩溃问题。
* 感谢测试者和故障排查者的帮助。
* 感谢这么多年来所有支持者的厚爱。

没有你们，这个项目不会存在。谢谢你们。

[![Discord](https://discordapp.com/api/guilds/278222834633801728/widget.png?style=banner3&time-)](https://discord.gg/bGKEyfY)
