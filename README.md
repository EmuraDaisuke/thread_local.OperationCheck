# thread_local.OperationCheck

thread_local変数の生成/破棄の動作確認

||Construct|Destruct|
|-|:-:|:-:|
|Msvc|スレッド生成時|スレッド消滅時|
|g++|thread_local変数初回アクセス時|実行されない|
