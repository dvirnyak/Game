

## **Игра**
Пользователь пытается убить противников, сражаясь на парусных кораблях

## Управление

Мышкой управляется парус, стрелочками на клавиатуре - поворот корабля

Сверху есть стрелка, указывающая текущее направление ветра

## Реализация:

Абстрактный класс Interface - Bridge между графикой/сетевыми запросами и остальным кодом

Используется [SDL2](https://wiki.libsdl.org/)

## **Сборка и запуск:**

### 1. Установка SDL2 - https://wiki.libsdl.org/Installation


**Для Linux:**

`git clone https://github.com/libsdl-org/SDL`

`cd SDL`

`mkdir build`

`cd build`

`../configure`

`make`

`sudo make install`


### 2. Установка игры 
- стандартная, через CMake

**Linux:**

`git clone https://github.com/dvirnyak/Game    #/tree/checkpoint_3`

`cd Game`

`mkdir build`

`cd build`

`cmake ..`

`make`

`./MyCoolGame`


