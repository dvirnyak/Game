Идея игры - пользователь мышкой управляет парусом, а корабль плывёт, исходя из ветра в конкретной точке. Также стреляет во врагов(другие корабли)

Абстрактный класс Interface - Bridge между графикой/сетевыми запросами и остальным кодом

Используется SDL2

Сборка и запуск:
1. Установка SDL2 - https://wiki.libsdl.org/Installation

Для Linux:
git clone https://github.com/libsdl-org/SDL
cd SDL
mkdir build
cd build
../configure
make
sudo make install

2. Установка самой игры - стандартная, через CMake
