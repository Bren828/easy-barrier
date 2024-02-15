# easy-barrier 
Creating gates doors in samp\
105 ready-made objects for movement

![Crosshair](https://raw.githubusercontent.com/Bren828/easy-barrier/main/preview.png)

## Reference
* [Installation](https://github.com/Bren828/easy-barrier#installation)
* [Example](https://github.com/Bren828/easy-barrier#example)
* [Functions](https://github.com/Bren828/easy-barrier#functions)
* [Callback](https://github.com/Bren828/easy-barrier#callback)
* [Barrier statuses](https://github.com/Bren828/easy-barrier#barrier-statuses)
* [Definition](https://github.com/Bren828/easy-barrier#definition)

## Installation

Include in your code and begin using the library:
```pawn
#include <easy-barrier>
```

## Example

```pawn
new barrierid = BarrierCreate("Police_Department", 10.0, 0.05, 8,  968, 15.0, -10.0, 3.0,  0.0, -90.0, 0.0,  0, 0); // create a barrier
SetBarrierState(barrierid, BARRIER_STATE_PLAYER_ONLY); // change status only for players

barrierid = BarrierCreate("Police_Department", 3.0, 0.5, 0,  19302, 24.637180, -8.755125, 3.397187, 0.000000, 0.000000, 86.175994); // create a door
SetBarrierTypeOpening(barrierid, BARRIER_MOVEMENT_TYPE_RIGHT, 80.0); // optional

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

//optional

forward OnBarrierObjectCreated(barrierid, objectid, modelid);
public OnBarrierObjectCreated(barrierid, objectid, modelid)
{
    switch(modelid)
    {
        case 968:
        {
            SetDynamicObjectMaterial(objectid, 1, 3306, "cunte_house1", "sw_patiodoors", 0);
        }
    }
    return 1;
}
```

## Functions

#### BarrierCreate(const function[], Float:zone_size, Float:move_speed, closing_seconds, modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, barrier_state = BARRIER_STATE_PLAYER_AND_DRIVER, const text3d[] = "", color = -1, Float:text3d_distance = 3.0, Float:trigger_x = 0.0, Float:trigger_y = 0.0, Float:trigger_z = 0.0)
> Create a barrier
> * `function[]` - Function name
> * `Float:zone_size` - Trigger distance
> * `Float:move_speed` - The speed at which to move the object (units per second)
> * `closing_seconds` - Closing time (use the value 0, for manual opening/closing)
> * `modelid` - The model
> * `Float:x` - The x coordinate to create the object
> * `Float:y` - The y coordinate to create the object
> * `Float:z` - The z coordinate to create the object
> * `Float:rx` - The x rotation of the object
> * `Float:ry` - The y rotation of the object
> * `Float:rz` - The z rotation of the object
> * `worldid` - The virtual world ID
> * `interiorid` - The interior ID
> * `barrier_state` - Barrier status
> * `text3d[]` - 3DText
> * `color` - 3DText color
> * `Float:text3d_distance` - 3DText draw distance
> * `Float:trigger_x` - The x coordinate to trigger zone
> * `Float:trigger_y` - The y coordinate to trigger zone
> * `Float:trigger_z` - The z coordinate to trigger zone
> * Returns (-1) on failure or (barrier id)

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

#### SetBarrierTypeOpening(barrierid, type, Float:percent = 100.0)
> Set the type of movement
> * `barrierid` - The ID of the barrier
> * `type` - Type of movement
> * `percent` - Prcentage of movement
> * Returns (-1) on failure or (1) on success

#### SetBarrierMovementX(barrierid, Float:x)
> Set the movement by the x coordinate
> * `barrierid` - The ID of the barrier
> * `Float:x` - The x coordinate
> * Returns (-1) on failure or (1) on success

#### SetBarrierMovementY(barrierid, Float:y)
> Set the movement by the y coordinate
> * `barrierid` - The ID of the barrier
> * `Float:y` - The y coordinate
> * Returns (-1) on failure or (1) on success

#### SetBarrierMovementZ(barrierid, Float:z)
> Set the movement by the z coordinate
> * `barrierid` - The ID of the barrier
> * `Float:z` - The z coordinate
> * Returns (-1) on failure or (1) on success

#### SetBarrierMovementRX(barrierid, Float:rx)
> Set the movement by the rx coordinate
> * `barrierid` - The ID of the barrier
> * `Float:rx` - The rx coordinate
> * Returns (-1) on failure or (1) on success

#### SetBarrierMovementRY(barrierid, Float:ry)
> Set the movement by the ry coordinate
> * `barrierid` - The ID of the barrier
> * `Float:ry` - The ry coordinate
> * Returns (-1) on failure or (1) on success

#### SetBarrierMovementRZ(barrierid, Float:rz)
> Set the movement by the rz coordinate
> * `barrierid` - The ID of the barrier
> * `Float:rz` - The x coordinate
> * Returns (-1) on failure or (1) on success

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

#### AttachBarrierToBarrier(barrierid, attachid)
> Attach barrier to barrier
> * `barrierid` - The ID of the barrier
> * `attachid` - The ID of the barrier to attach

#### UnAttachBarrierFromBarrier(barrierid)
> UnAttach the barrier from the barrier
> * `barrierid` - The ID of the barrier

#### SetBarrierText(barrierid, const text[], color = 0)
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

#### SetBarrierTextColor(barrierid, color)
> Set 3D text color
> * `barrierid` - The ID of the barrier
> * `color` - Color
> * Returns (-1) on failure or (1) on success

#### GetBarrierTextColor(barrierid)
> Get 3D text color
> * `barrierid` - The ID of the barrier
> * Returns (-1) on failure or (color) on success

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

#### DeleteBarrierExtraObject(barrierid)
> Delete an extra barrier object
> * `barrierid` - The ID of the barrier

## Callback

#### BarrierResponse:const function[](playerid, barrierid)
> Called when interacting with a barrier
> * `const function[]` - Function name
> * `playerid` - The ID of the player
> * `barrierid` - The ID of the barrier
> * NOTE: Always use 'return 0;' if you need to activate the barrier

#### public OnBarrierObjectCreated(barrierid, objectid, modelid)
> Called when creating a barrier
> * `barrierid` - The ID of the barrier
> * `objectid` - Object ID
> * `modelid` - Object model

## Barrier statuses
```pawn
BARRIER_STATE_PLAYER_AND_DRIVER = -1
BARRIER_STATE_DRIVER_ONLY = 2
BARRIER_STATE_PLAYER_ONLY = 1

BARRIER_MOVEMENT_TYPE_OUTSIDE = 0
BARRIER_MOVEMENT_TYPE_INSIDE = 1
BARRIER_MOVEMENT_TYPE_RIGHT = 2
BARRIER_MOVEMENT_TYPE_LEFT = 3
BARRIER_MOVEMENT_TYPE_UP = 4
BARRIER_MOVEMENT_TYPE_DOWN = 5
```

## Definition
```pawn
#define MAX_BARRIERS                200

#define BARRIER_MAX_FUNCTION_NAME   32

#define BARRIER_KEY_STATE_ONFOOT    KEY_WALK

#define BARRIER_KEY_STATE_DRIVER    KEY_CROUCH

#define BARRIER_3DTEXT_LENGTH       144

#define BARRIER_OBJECT_DISTANCE     200.0

#define BARRIER_NOT_CREATE_EXTRA_OBJECT // only for the object model 968
```
