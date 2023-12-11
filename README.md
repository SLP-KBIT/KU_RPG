要件定義
===
# ディレクトリ構成（旧）
```md
.
└── rpg_prototype
    ├── Main.cpp           // 実行を制御するメインファイル
    ├── CourceFile         // マップ配置のテキストファイルを保存するフォルダ
    │   └── WorldMap.txt
    ├── Picture            // 使用する画像を保存するディレクトリ
    │   ├── Backgrounds    // 背景画像を保存するフォルダ
    │   │   └── pure_forest.png
    │   ├── Enemys         // 敵画像を保存するフォルダ
    │   │   ├── Slime.png
    │   │   └── SlimeBeth.png
    │   ├── Maps           // マップチップを保存するフォルダ
    │   │   ├── Fill_grass.png
    │   │   ├── MapChip.png
    │   │   ├── grass_near_river.png
    │   │   └── grass_near_river2.png
    │   └── Players        // プレイヤーに関する画像を保存するフォルダ
    │       ├── Player.png
    │       ├── akane.png
    │       └── akane2.png
    ├── Battle.h   // 戦闘におけるコマンド表示やダメージ
    ├── Enemy.h    // 敵の表示
    ├── Picture.h  // 用意した画像をプログラム上に読み込む
    ├── Player.h   // 主人公の移動や表示
    ├── Stage.h    // ステージ情報の入出力
    ├── Status.h   // HPやMPなどキャラクターのステータス
    ├── Sub.h      // フォントやキー入力などメタ的な要素
    ├── Title.h    // タイトル画面の制御
    :
    etc
```