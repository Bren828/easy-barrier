Language: **English** or [Russian](https://github.com/Bren828/easy-barrier/blob/main/README.md)

# easy-barrier 
Упрощенное создание движущихся объектов, таких как ворота, двери и шлагбаумы. С возвращением на прошлое положение через определенное время.

## Reference
* [Download](https://github.com/Bren828/easy-barrier#download)
* [Installation](https://github.com/Bren828/easy-barrier#installation)
* [Example](https://github.com/Bren828/easy-barrier#example)
* [Functions](https://github.com/Bren828/easy-barrier#functions)
* [Barrier statuses](https://github.com/Bren828/easy-barrier#barrier-statuses)
* [Definition](https://github.com/Bren828/easy-barrier#definition)

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

    SendClientMessage(playerid, -1, "barrier for police open");
    return 0;
}
```

## Functions

#### BarrierCreate(const function[], Float:zone_size, Float:move_speed, closing_seconds, object_model, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, barrier_state = BARRIER_STATE_DRIVER_ONLY, const text3D[] = BARRIER_3DTEXT_TEXT, color = -1, Float:text3D_distance = BARRIER_3DTEXT_DISTANCE, Float:trigger_x = 0.0, Float:trigger_y = 0.0, Float:trigger_z = 0.0)
> Create a barrier
> * `function[]` - Function name
> * `Float:zone_size` - Trigger distance
> * `Float:move_speed` - The speed at which to move the object (units per second)
> * `closing_seconds` - Closing time (use the value 0, for manual opening/closing)
> * `object_model` - The model
> * `Float:x` - The x coordinate to create the object
> * `Float:y` - The y coordinate to create the object
> * `Float:z` - The z coordinate to create the object
> * `Float:rx` - The x rotation of the object
> * `Float:ry` - The y rotation of the object
> * `Float:rz` - The z rotation of the object
> * `worldid` - The virtual world ID
> * `interiorid` - The interior ID
> * `barrier_state` - Barrier status
> * `text3D[]` - 3DText
> * `color` - 3DText color
> * `Float:text3D_distance` - 3DText draw distance
> * `Float:trigger_x` - The x coordinate to trigger zone
> * `Float:trigger_y` - The y coordinate to trigger zone
> * `Float:trigger_z` - The z coordinate to trigger zone
> * Вернет (-1) при неудачи (BARRIER_INVALID) или (ID) барьера при успехе

#### BarrierResponse:const function[](playerid, barrierid)
> Callback
> * `playerid` - The ID of the player
> * `barrierid` - The ID of the barrier
> * ВОЗВРАЩАЕТ: Всегда используйте 'return 0;', если нужно активировать барьер

#### BarrierDelete(barrierid)
> Remove the barrier
> * `barrierid` - The ID of the barrier
> * Вернет (-1) при неудачи (BARRIER_INVALID) или (ID) барьера при успехе

#### BarrierOpen(barrierid)
> Open the barrier
> * `barrierid` - The ID of the barrier
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

#### BarrierClose(barrierid)
> Close the barrier
> * `barrierid` - The ID of the barrier
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

#### IsBarrierOpen(barrierid)
> Узнать состояние барьера
> * `barrierid` - The ID of the barrier
> * Вернет 0 (false) если барьер закрыт или 1 (true) если барьер открыт или (-1) при неудачи (BARRIER_INVALID)

#### SetBarrierMove(barrierid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
> Изменить положения движущегося объекта
> * `barrierid` - The ID of the barrier
> * `Float:x` - The x coordinate
> * `Float:y` - The y coordinate
> * `Float:z` - The z coordinate
> * `Float:rx` - The x rotation of the object
> * `Float:ry` - The y rotation of the object
> * `Float:rz` - The z rotation of the object
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

#### SetBarrierText(barrierid, const text[], color)
> Change 3D Text
> * `barrierid` - The ID of the barrier
> * `text[]` - text
> * `color` - Color
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

#### GetBarrierText(barrierid, text[], size = sizeof(text))
> Узнать текст 3DText
> * `barrierid` - The ID of the barrier
> * `&text` - text
> * `size = sizeof(text)` - sizeof
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

#### GetBarrierTextColor(barrierid, &color)
> Узнать цвет 3D текста
> * `barrierid` - The ID of the barrier
> * `&color` - Color
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

#### SetBarrierTextPosition(barrierid, Float:x, Float:y, Float:z)
> Change the position of 3D text
> * `barrierid` - The ID of the barrier
> * `Float:x` - The x coordinate
> * `Float:y` - The y coordinate
> * `Float:z` - The z coordinate
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

#### SetBarrierSecondsClose(barrierid, seconds)
> Change the barrier closing time
> * `barrierid` - The ID of the barrier
> * `seconds[]` - Closing time (use the value 0, for manual opening/closing)
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

#### GetBarrierSecondsCloses(barrierid)
> Узнать время закрытия барьера
> * `barrierid` - The ID of the barrier
> * Вернет -1 при неудачи (BARRIER_INVALID) или количество секунд

#### SetBarrierMoveSpeed(barrierid, Float:speed)
> Change the speed of a moving object
> * `barrierid` - The ID of the barrier
> * `Float:speed` - The speed at which to move the object (units per second)
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

#### GetBarrierMoveSpeed(barrierid, &Float:speed)
> Узнать скорость движущегося объекта
> * `barrierid` - The ID of the barrier
> * `&Float:speed` - The speed at which to move the object (units per second)
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

#### SetBarrierTrigger(barrierid, Float:x, Float:y, Float:z)
> Change the trigger zone
> * `barrierid` - The ID of the barrier
> * `Float:x` - The x coordinate to trigger zone
> * `Float:y` - The y coordinate to trigger zone
> * `Float:z` - The z coordinate to trigger zone
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

#### GetBarrierTrigger(barrierid, &Float:x, &Float:y, &Float:z)
> Узнать зону срабатывания
> * `barrierid` - The ID of the barrier
> * `&Float:x` - The x coordinate to trigger zone
> * `&Float:y` - The y coordinate to trigger zone
> * `&Float:z` - The z coordinate to trigger zone
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

#### GetBarrierSlotID(const function[])
> Get barrier slot ID
> * `function[]` - Function name
> * Вернет (-1) при неудачи (BARRIER_INVALID) или (ID) барьера при успехе
> * ПРИМЕЧАНИЕ: При использовании одинаковых названий 'function[]' вернет ближайший ID барьера!

#### SetBarrierState(barrierid, barrier_state)
> Change barrier status
> * `barrierid` - The ID of the barrier
> * `barrier_state` - Barrier status
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

#### GetBarrierState(barrierid)
> Узнать статус барьера
> * `barrierid` - The ID of the barrier
> * Вернет -1 при неудачи (BARRIER_INVALID) или статус барьера

#### GetBarrierObjectID(barrierid, &moveid, &extraid = 0)
> Get barrier object ID
> * `barrierid` - The ID of the barrier
> * `&moveid` - Вернет id движущегося объекта
> * `&extraid` - Вернет id дополнительного объекта
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

#### BarrierCreateExtraObject(barrierid, object_model, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1)
> Create a second static object
> * `barrierid` - The ID of the barrier
> * `object_model` - The model
> * `Float:x` - The x coordinate to create the object
> * `Float:y` - The y coordinate to create the object
> * `Float:z` - The z coordinate to create the object
> * `Float:rx` - The x rotation of the object
> * `Float:ry` - The y rotation of the object
> * `Float:rz` - The z rotation of the object
> * `worldid` - The virtual world ID
> * `interiorid` - The interior ID
> * Вернет -1 при неудачи (BARRIER_INVALID) или (1) при успехе

## Barrier statuses
```pawn
BARRIER_STATE_PLAYER_AND_DRIVER = -1
BARRIER_STATE_DRIVER_ONLY = 2
BARRIER_STATE_PLAYER_ONLY = 1
```

## Definition
```pawn
#define MAX_BARRIERS                200

#define BARRIER_MAX_FUNCTION_NAME   30

#define BARRIER_KEY_STATE_ONFOOT    KEY_WALK // кнопка взаимодействия с барьером на ногах

#define BARRIER_KEY_STATE_DRIVER    KEY_CROUCH // кнопка взаимодействия с барьером в транспорте

#define BARRIER_3DTEXT_TEXT         "Посигнальте чтобы открыть шлагбаум"

#define BARRIER_3DTEXT_DISTANCE     18.0 // 3dtext distance

#define BARRIER_3DTEXT_LENGTH       144 // Length of the 3dtext

#define BARRIER_OBJECT_DISTANCE     200.0 // barrier drawing distance
```
