要件定義
===
# 概要
とある香川の大学を舞台としたRPG
## 登場キャラクター
主人公：大学生（見た目はアカネちゃん）  
１階ボス：（なし）  
２階ボス：食堂のおばちゃん  
３階ボス：VR_DANCERS  
４階ボス：夢四国カンパニー  
５階ボス：ミスター・ミスター  
６階ボス：SRL_Injector  
７階ボス：（なし）  
８階ボス：R4-P17  
９階ボス：電王  
１０階ボス：Sキュア愛  
１１階ボス：Unchain
## ストーリー
ある日、主人公が大学へ到着すると、巨大な謎アンテナが1号館の屋上に設置されていることに気づく。  
同時に、スマホやPC等の電子機器が一切使用できない（電源がつかない）ことにも気づく。  
屋上に設置された謎アンテナが怪しいとみた主人公は、1号館の屋上を目指す。
# ゲームで行うことのできる操作
起動直後 -> メニュー画面
## メニュー画面  
タイトル画面表示  
「続きからorはじめから」選択
## マップ画面
移動  
アイテムの取得  
アイテムの使用  
インベントリーの表示
## バトル画面
たたかう  
アイテムを使う  
逃げる  
まもる
# ゲームエンド（ゲーム終了）
1. バトル中、「逃げる」選択でバッドエンド
2. バトル中、`プレイヤーのHP`$<0$ でバッドエンド
3. ラスボス（１１階ボス）撃破でトゥルーエンド

バッドエンドを迎えると、セーブデータは消去（最初からやり直し）。
# クラスの階層化（現段階）
```
main.cpp
└── SystemControl.h
    ├── TitleControl.h
    └── GameControl.h
        ├── Object.h
        ├── Player.h
        ├── Enemy.h
        ├── Item.h
        ├── MapControl.h
        └── BattleControl.h
```
# ディレクトリ構成（現段階）
```
.
└── KURPG
    └── main.cpp
```
# ディレクトリ構成（旧）（参考に必要）
```
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