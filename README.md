# easy-barrier 
Creating barriers and other objects in SAMP

## Reference
* [Installation](https://github.com/Bren828/easy-barrier#installation)
* [Example](https://github.com/Bren828/easy-barrier#example)
* [Functions](https://github.com/Bren828/easy-barrier#functions)
* [Barrier statuses](https://github.com/Bren828/easy-barrier#barrier-statuses)
* [Definition](https://github.com/Bren828/easy-barrier#definition)

## Installation

Include in your code and begin using the library:
```pawn
#include <easy-barrier>
```

## Example

```pawn
new barrierid = BarrierCreate("Police_Department", 10.0, 0.1, 8,  968, 15.0, -10.0, 3.0,  0.0, -90.0, 0.0,  0, 0); // create a barrier
SetBarrierState(barrierid, BARRIER_STATE_PLAYER_ONLY); // change status only for players

BarrierResponse:Police_Department(playerid, barrierid)
{
    if(GetPlayerSkin(playerid) != 283) 
    {
        SendClientMessage(playerid, 0xFF0000AA, "Only for cops");
        return 1;
    }

    SendClientMessage(playerid, -1, "barrier for police open");
    return 0;
}
```

## Functions

#### BarrierCreate(const function[], Float:zone_size, Float:move_speed, closing_seconds, object_model, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, barrier_state = BARRIER_STATE_DRIVER_ONLY, const text3D[] = "", color = -1, Float:text3D_distance = BARRIER_3DTEXT_DISTANCE, Float:trigger_x = 0.0, Float:trigger_y = 0.0, Float:trigger_z = 0.0)
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
> * Returns (-1) on failure or (barrier id)

#### BarrierResponse:const function[](playerid, barrierid)
> Callback
> * `playerid` - The ID of the player
> * `barrierid` - The ID of the barrier
> * NOTE: Always use 'return 0;' if you need to activate the barrier

#### BarrierDelete(barrierid)
> Remove the barrier
> * `barrierid` - The ID of the barrier
> * Returns (-1) on failure or barrier id

#### BarrierOpen(barrierid)
> Open the barrier
> * `barrierid` - The ID of the barrier
> * Returns (-1) on failure or (1) on success

#### BarrierClose(barrierid)
> Close the barrier
> * `barrierid` - The ID of the barrier
> * Returns (-1) on failure or (1) on success

#### IsBarrierOpen(barrierid)
> Get the barrier status
> * `barrierid` - The ID of the barrier
> * Returns (0) if closed, (1) if open, (-1) if failed

#### SetBarrierMove(barrierid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
> Set the positions of the moving object
> * `barrierid` - The ID of the barrier
> * `Float:x` - The x coordinate
> * `Float:y` - The y coordinate
> * `Float:z` - The z coordinate
> * `Float:rx` - The x rotation of the object
> * `Float:ry` - The y rotation of the object
> * `Float:rz` - The z rotation of the object
> * Returns (-1) on failure or (1) on success

#### SetBarrierText(barrierid, const text[], color)
> Set 3D Text
> * `barrierid` - The ID of the barrier
> * `text[]` - text
> * `color` - Color
> * Returns (-1) on failure or (1) on success

#### GetBarrierText(barrierid, text[], size = sizeof(text))
> Get Text 3D text
> * `barrierid` - The ID of the barrier
> * `&text` - text
> * `size = sizeof(text)` - sizeof
> * Returns (-1) on failure or (1) on success

#### GetBarrierTextColor(barrierid, &color)
> Get 3D text color
> * `barrierid` - The ID of the barrier
> * `&color` - Color
> * Returns (-1) on failure or (1) on success

#### SetBarrierTextPosition(barrierid, Float:x, Float:y, Float:z)
> Set position of 3D text
> * `barrierid` - The ID of the barrier
> * `Float:x` - The x coordinate
> * `Float:y` - The y coordinate
> * `Float:z` - The z coordinate
> * Returns (-1) on failure or (1) on success

#### SetBarrierSecondsClose(barrierid, seconds)
> Set barrier closing time
> * `barrierid` - The ID of the barrier
> * `seconds[]` - Closing time (use the value 0, for manual opening/closing)
> * Returns (-1) on failure or (1) on success

#### GetBarrierSecondsCloses(barrierid)
> Get barrier closing time
> * `barrierid` - The ID of the barrier
> * Returns (-1) on failure or (second)

#### SetBarrierMoveSpeed(barrierid, Float:speed)
> Set the speed of a moving object
> * `barrierid` - The ID of the barrier
> * `Float:speed` - The speed at which to move the object (units per second)
> * Returns (-1) on failure or (1) on success

#### GetBarrierMoveSpeed(barrierid, &Float:speed)
> Get the speed of a moving object
> * `barrierid` - The ID of the barrier
> * `&Float:speed` - The speed at which to move the object (units per second)
> * Returns (-1) on failure or (1) on success

#### SetBarrierTrigger(barrierid, Float:x, Float:y, Float:z)
> Set trigger zone
> * `barrierid` - The ID of the barrier
> * `Float:x` - The x coordinate to trigger zone
> * `Float:y` - The y coordinate to trigger zone
> * `Float:z` - The z coordinate to trigger zone
> * Returns (-1) on failure or (1) on success

#### GetBarrierTrigger(barrierid, &Float:x, &Float:y, &Float:z)
> Get trigger zone
> * `barrierid` - The ID of the barrier
> * `&Float:x` - The x coordinate to trigger zone
> * `&Float:y` - The y coordinate to trigger zone
> * `&Float:z` - The z coordinate to trigger zone
> * Returns (-1) on failure or (1) on success

#### GetBarrierSlotID(const function[])
> Get barrier ID
> * `function[]` - Function name
> * Returns (-1) on failure or barrier id
> * NOTE: При использовании одинаковых названий 'function[]' вернет ближайший ID барьера!

#### SetBarrierState(barrierid, barrier_state)
> Set the barrier status
> * `barrierid` - The ID of the barrier
> * `barrier_state` - Barrier status
> * Returns (-1) on failure or (1) on success

#### GetBarrierState(barrierid)
> Get Barrier status
> * `barrierid` - The ID of the barrier
> * Returns (-1) on failure or (status)

#### GetBarrierObjectID(barrierid, &moveid, &extraid = 0)
> Get the barrier object ID
> * `barrierid` - The ID of the barrier
> * `&moveid` - moving object id
> * `&extraid` - additional object id
> * Returns (-1) on failure or (1) on success

#### BarrierCreateExtraObject(barrierid, object_model, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1)
> Create a second extra object
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
> * Returns (-1) on failure or (1) on success

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

#define BARRIER_KEY_STATE_ONFOOT    KEY_WALK

#define BARRIER_KEY_STATE_DRIVER    KEY_CROUCH

static BARRIER_3DTEXT_TEXT[] =      "Посигнальте чтобы открыть шлагбаум";

#define BARRIER_3DTEXT_DISTANCE     18.0

#define BARRIER_3DTEXT_LENGTH       144

#define BARRIER_OBJECT_DISTANCE     200.0
```
