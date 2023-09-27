# KU_RPG
香川大学を舞台としたRPGゲームのチーム開発_2023


## ディレクトリ構成の概説
開発において編集していくのは以下のファイル
```md

.
└── rpg_prototype
    ├── Main.cpp           // 実行を制御するメインファイル
    ├── CourceFile         // マップ配置のテキストファイルを保存するフォルダ
    │   └── WorldMap.txt
    ├── Picture            // 使用する画像を保存するディレクトリの親
    │   ├── Backgrounds    // 背景画像を保存するフォルダ
    │   │   └── pure_forest.png
    │   ├── Enemys         // 敵画像を保存するフォルダ
    │   │   ├── Slime.png
    │   │   └── SlimeBeth.png
    │   ├── Maps           // マップチップを保存するフォルダ
    │   │   ├── Fill_grass.png
    │   │   ├── MapChip.png
    │   │   ├── grass_near_river.png
    │   │   └── grass_near_river2.png
    │   └── Players        // プレイヤーに関する画像を保存するフォルダ
    │       ├── Player.png
    │       ├── akane.png
    │       └── akane2.png
<font color="DeepPink">
    ├── Battle.h   // 戦闘におけるコマンド表示やダメージに関する記述を行うファイル
    ├── Enemy.h    // 敵の表示に関する記述を行うファイル
    ├── Picture.h  // 用意した画像をプログラム上に読み込む記述を行うファイル
    ├── Player.h   // 主人公の移動や表示関する記述を行うファイル
    ├── Stage.h    // ステージ情報の入出力に関する記述を行うファイル
    ├── Status.h   // HPやMPなどキャラクターのステータスに関する記述を行うファイル
    ├── Sub.h      // フォントやキー入力などメタ的な要素に関する記述を行うファイル
    ├── Title.h    // タイトル画面の制御に関する記述を行うファイル
</font>
    :
    etc
```
