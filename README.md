# easy-barrier 
Упрощенное создание движущихся объектов, таких как ворота, двери и шлагбаумы. С возвращением на прошлое положение через определенное время.

## Reference
* [Download](https://github.com/Bren828/easy-barrier#download)
* [Installation](https://github.com/Bren828/easy-barrier#installation)
* [Example](https://github.com/Bren828/easy-barrier#example)
* [Functions](https://github.com/Bren828/easy-barrier#functions)
* [Barrier statuses]([https://github.com/Bren828/](https://github.com/Bren828/easy-barrier#barrier-statuses))
* [Definition]([https://github.com/Bren828/](https://github.com/Bren828/easy-barrier#definition))

## Download
[Releases page](https://github.com/Bren828/easy-barrier/releases)

## Installation

Include in your code and begin using the library:
```pawn
#include <easy-barrier>
```

## Example

```pawn
new barrierid = BarrierCreate("Police_Department", 10.0, 0.1, 8,  968, 15.0, -10.0, 3.0,  0.0, -90.0, 0.0,  0, 0); // create a barrier
SetBarrierState(barrierid, BARRIER_STATE_PLAYER_ONLY); // change status only for players

PickupResponse:Police_Department(playerid, barrierid)
{
    if(GetPlayerSkin(playerid) != 283) 
    {
        SendClientMessage(playerid, 0xFF0000AA, "Only for cops");
        retrun 1;
    }
    if(IsBarrierOpen(barrierid)) return 1; // if the barrier was open

    SendClientMessage(playerid, -1, "barrier for police open");
    return 0;
}
```

## Functions

#### BarrierCreate(const function[], Float:zone_size, Float:move_speed, closing_seconds, object_model, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, barrier_state = BARRIER_STATE_DRIVER_ONLY, const text3D[] = BARRIER_3DTEXT_TEXT, color = -1, Float:text3D_distance = BARRIER_3DTEXT_DISTANCE, Float:trigger_x = 0.0, Float:trigger_y = 0.0, Float:trigger_z = 0.0);
> Создать барьер
> * `function[]` - Название функции
> * `Float:zone_size` - Размер зоны срабатывания
> * `Float:move_speed` - Скорость движения объекта
> * `closing_seconds` - Время закрытия (используйте значение 0, для ручного открытия/закрытия)
> * `object_model` - The model
> * `Float:x` - Координата x
> * `Float:y` - Координата y
> * `Float:z` - Координата z
> * `Float:rx` - Координата x вращение объекта
> * `Float:ry` - Координата y вращение объекта
> * `Float:rz` - Координата z вращение объекта
> * `worldid` - ID виртуального мира
> * `interiorid` - ID интерьера 
> * `barrier_state` - Состояние барьера
> * `text3D[]` - 3DText
> * `color` - Цвет 3DText 
> * `Float:text3D_distance` - Дистанция отображения 3DText
> * `Float:trigger_x` - Координата x зоны срабатывания
> * `Float:trigger_y` - Координата y зоны срабатывания 
> * `Float:trigger_z` - Координата z зоны срабатывания
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: ID барьера при успехе

#### BarrierResponse:const function[](playerid, barrierid)
> Обратный вызов
> * `playerid` - игрок id
> * `barrierid` - ID барьера
> * ВОЗВРАЩАЕТ: Всегда используйте 'return 0;', если нужно активировать барьер

#### BarrierDelete(barrierid)
> Удалить барьер
> * `barrierid` - ID барьера
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: ID барьера при успехе

#### BarrierOpen(barrierid)
> Открыть барьер
> * `barrierid` - ID барьера
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: 1 при успехе

#### BarrierClose(barrierid)
> Закрыть барьер
> * `barrierid` - ID барьера
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: 1 при успехе

#### IsBarrierOpen(barrierid)
> Узнать состояние барьера
> * `barrierid` - ID барьера
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: 1 (true)  если барьер открыт
> * Вернет: 0 (false) если барьер закрыт

#### SetBarrierMove(barrierid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
> Изменить положения движущегося объекта
> * `barrierid` - ID барьера
> * `Float:x` - Координата x
> * `Float:y` - Координата y
> * `Float:z` - Координата z
> * `Float:rx` - Координата x вращение объекта
> * `Float:ry` - Координата y вращение объекта
> * `Float:rz` - Координата z вращение объекта
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: 1 при успехе

#### SetBarrierText(barrierid, const text[], color)
> Изменить 3D текст
> * `barrierid` - ID барьера
> * `text[]` - Текст
> * `color` - Цвет
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: 1 при успехе

#### GetBarrierText(barrierid, text[], size = sizeof(text))
> Узнать текста 3D текста
> * `barrierid` - ID барьера
> * `&text` - Текст
> * `size = sizeof(text)` - sizeof
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: 1 при успехе

#### GetBarrierTextColor(barrierid, &color)
> Узнать цвет 3D текста
> * `barrierid` - ID барьера
> * `&color` - Цвет
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: 1 при успехе

#### SetBarrierTextPosition(barrierid, Float:x, Float:y, Float:z)
> Изменить положение 3D текста
> * `barrierid` - ID барьера
> * `Float:x` - Координата x
> * `Float:y` - Координата y
> * `Float:z` - Координата z
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: 1 при успехе

#### SetBarrierSecondsClose(barrierid, seconds)
> Изменить время закрытия барьера
> * `barrierid` - ID барьера
> * `seconds[]` - Секунды (используйте значение 0, для ручного открытия/закрытия)
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: 1 при успехе

#### GetBarrierSecondsCloses(barrierid)
> Узнать время закрытия барьера
> * `barrierid` - ID барьера
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: Количество секунд

#### SetBarrierMoveSpeed(barrierid, Float:speed)
> Изменить скорость движущегося объекта
> * `barrierid` - ID барьера
> * `Float:speed` - Скорость движения
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: 1 при успехе

#### GetBarrierMoveSpeed(barrierid, &Float:speed)
> Узнать скорость движущегося объекта
> * `barrierid` - ID барьера
> * `&Float:speed` - Скорость движения
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: 1 при успехе

#### SetBarrierTrigger(barrierid, Float:x, Float:y, Float:z)
> Изменить зону срабатывания
> * `barrierid` - ID барьера
> * `Float:x` - Координата x зоны срабатывания
> * `Float:y` - Координата y зоны срабатывания
> * `Float:z` - Координата z зоны срабатывания
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: 1 при успехе

#### GetBarrierTrigger(barrierid, &Float:x, &Float:y, &Float:z)
> Узнать зону срабатывания
> * `barrierid` - ID барьера
> * `&Float:x` - Координата x зоны срабатывания
> * `&Float:y` - Координата y зоны срабатывания
> * `&Float:z` - Координата z зоны срабатывания
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: 1 при успехе

#### GetBarrierSlotID(const function[])
> Узнать ID барьера
> * `function[]` - Название функции
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: ID барьера при успехе
> * ПРИМЕЧАНИЕ: При использовании одинаковых названий 'function[]' вернет ближайший ID барьера!

#### SetBarrierState(barrierid, barrier_state)
> Изменить статус барьера
> * `barrierid` - ID барьера
> * `barrier_state` - Статус барьера
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: 1 при успехе

#### GetBarrierState(barrierid)
> Узнать статус барьера
> * `barrierid` - ID барьера
> * Вернет: -1 при неудачи (BARRIER_INVALID)
> * Вернет: статус барьера

## Barrier statuses
```pawn
BARRIER_STATE_PLAYER_AND_DRIVER = -1 // доступен для игроков и транспорта
BARRIER_STATE_DRIVER_ONLY = 2 // доступен только для транспорта
BARRIER_STATE_PLAYER_ONLY = 1 // доступен только для игроков
```

## Definition
```pawn
#define MAX_BARRIERS                200

#define BARRIER_KEY_STATE_ONFOOT    KEY_WALK // кнопка взаимодействия с барьером на ногах

#define BARRIER_KEY_STATE_DRIVER    KEY_CROUCH // кнопка взаимодействия с барьером в транспорте

#define BARRIER_3DTEXT_TEXT         "Посигнальте чтобы открыть шлагбаум"

#define BARRIER_3DTEXT_DISTANCE     18.0 // дистанция открытия

#define BARRIER_3DTEXT_LENGTH       144 // Длина 3d текста

#define BARRIER_OBJECT_DISTANCE     200.0 // дистанция прорисовки барьера
```
