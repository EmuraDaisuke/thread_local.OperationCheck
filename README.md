# thread_local.OperationCheck

thread_local変数(class)の生成/破棄の動作確認

## Windows10
||Construct|Destruct|
|-|:-:|:-:|
|Microsoft(R) C/C++ Optimizing Compiler Version 19.16.27025.1 for x64|スレッド生成時|スレッド消滅時|
|clang version 7.0.0 (tags/RELEASE_700/final)|コンパイル不可|n/a|
|gcc version 8.2.0 (Rev3, Built by MSYS2 project)|thread_local変数初回アクセス時|実行されない|

## debian  
||Construct|Destruct|
|-|:-:|:-:|
|clang version 3.8.1-24 (tags/RELEASE_381/final)|thread_local変数初回アクセス時|スレッド消滅時|
|gcc version 6.3.0 20170516 (Debian 6.3.0-18+deb9u1)|thread_local変数初回アクセス時|スレッド消滅時|
