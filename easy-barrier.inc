/*
*
*
*
*   ---------------------------------------------------
*
*	Creater - @Bren828	
*									6 July 2023
*
*   Version: 1.1
*
*   ---------------------------------------------------
*
*
*	https://github.com/Bren828/easy-barrier
*
*
*
* Create a barrier
*		BarrierCreate(const function[], Float:zone_size, Float:move_speed, closing_seconds, object_model, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, barrier_state = BARRIER_STATE_DRIVER_ONLY, const text3D[] = "", color = -1, Float:text3D_distance = BARRIER_3DTEXT_DISTANCE, Float:trigger_x = 0.0, Float:trigger_y = 0.0, Float:trigger_z = 0.0)
*		* function[] - Function name
*		* Float:zone_size - Trigger distance
*		* Float:move_speed - The speed at which to move the object (units per second)
*		* closing_seconds - Closing time (use the value 0, for manual opening/closing)
*		* object_model - The model
*		* Float:x - The x coordinate to create the object
*		* Float:y - The y coordinate to create the object
*		* Float:z - The z coordinate to create the object
*		* Float:rx - The x rotation of the object
*		* Float:ry - The y rotation of the object
*		* Float:rz - The z rotation of the object
*		* worldid - The virtual world ID
*		* interiorid - The interior ID
*		* barrier_state - Barrier status
*		* text3D[] - 3DText
*		* color - 3DText color
*		* Float:text3D_distance - 3DText draw distance
*		* Float:trigger_x - The x coordinate to trigger zone
*		* Float:trigger_y - The y coordinate to trigger zone
*		* Float:trigger_z - The z coordinate to trigger zone
*
*		* Returns (-1) on failure or barrier id
*
*
* Callback
*       BarrierResponse:const function[](playerid, barrierid)
*       * playerid: The ID of the player
*       * barrierid: The ID of the barrier
*
*		* RETURNS: Always use 'return 0;' if you need to activate the barrier
*
*
* Remove the barrier
*       BarrierDelete(barrierid)
*       * barrierid: The ID of the barrier
*
*		* Returns (-1) on failure or barrier id
*
*
* Open the barrier
*       BarrierOpen(barrierid)
*       * barrierid: The ID of the barrier
*
*		* Returns (-1) on failure or (1) on success
*
*
* Close the barrier
*       BarrierClose(barrierid)
*       * barrierid: The ID of the barrier
*       
*		* Returns (-1) on failure or (1) on success
*
*
* Get the barrier status
*       IsBarrierOpen(barrierid)
*       * barrierid: The ID of the barrier
*       
*		* Returns (0) if closed, (1) if open, (-1) if failed
*
*
* Set the positions of the moving object
*       SetBarrierMove(barrierid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
*       * barrierid: The ID of the barrier
*       * Float:x - The x coordinate
*       * Float:y - The y coordinate
*       * Float:z - The z coordinate
*       * Float:rx - The x rotation of the object
*       * Float:ry - The y rotation of the object
*       * Float:rz - The z rotation of the object
*
*		* Returns (-1) on failure or (1) on success
*
*
* Set 3D Text
*       SetBarrierText(barrierid, const text[], color)
*       * barrierid: The ID of the barrier
*       * text[]: Text
*       * color: Color
* 
*		* Returns (-1) on failure or (1) on success
*
*
* Óçíàòü òåêñòà 3D òåêñòà
*       GetBarrierText(barrierid, text[], size = sizeof(text))
*       * barrierid: The ID of the barrier
*       * &text: Òåêñò
*       * size = sizeof(text): sizeof
*
*		* Returns (-1) on failure or (1) on success
*
*
* Get 3D text color
*       GetBarrierTextColor(barrierid, &color)
*       * barrierid: The ID of the barrier
*       * &color: Color
*
*		* Returns (-1) on failure or (1) on success
*
*
* Set position of 3D text
*       SetBarrierTextPosition(barrierid, Float:x, Float:y, Float:z)
*       * barrierid: The ID of the barrier
*       * Float:x: - The x coordinate
*       * Float:y: - The y coordinate
*       * Float:z: - The z coordinate
*
*		* Returns (-1) on failure or (1) on success
*
*
* Set barrier closing time
*       SetBarrierSecondsClose(barrierid, seconds)
*       * barrierid: - The ID of the barrier
*       * seconds[]: - Closing time (use the value 0, for manual opening/closing)
*
*		* Returns (-1) on failure or (1) on success
*
*
* Get barrier closing time
*       GetBarrierSecondsCloses(barrierid)
*       * barrierid: The ID of the barrier
*
*		* Returns (-1) on failure or (1) on success
*
*
* Set the speed of a moving object
*       SetBarrierMoveSpeed(barrierid, Float:speed)
*       * barrierid: ID áàðüåðà
*       * Float:speed: The speed at which to move the object (units per second)
*
*		* Returns (-1) on failure or (1) on success
*
*
* Get the speed of a moving object
*       GetBarrierMoveSpeed(barrierid, &Float:speed)
*       * barrierid: The ID of the barrier
*       * &Float:speed: The speed at which to move the object (units per second)
*       
*		* Returns (-1) on failure or (1) on success
*
*
* Set trigger zone
*       SetBarrierTrigger(barrierid, Float:x, Float:y, Float:z)
*       * barrierid: The ID of the barrier
*       * Float:x - The x coordinate to trigger zone
*       * Float:y - The y coordinate to trigger zone
*       * Float:z - The z coordinate to trigger zone
*
*		* Returns (-1) on failure or (1) on success
*
*
* Get trigger zone
*       GetBarrierTrigger(barrierid, &Float:x, &Float:y, &Float:z)
*       * barrierid: The ID of the barrier
*       * &Float:x - The x coordinate to trigger zone
*       * &Float:y - The y coordinate to trigger zone
*       * &Float:z - The z coordinate to trigger zone
*
*		* Returns (-1) on failure or (1) on success
*
*
* Get barrier ID
*       GetBarrierSlotID(const function[])
*       * function[]: Function name
*
*		* Returns (-1) on failure or barrier id
*       * ÏÐÈÌÅ×ÀÍÈÅ: ïðè èñïîëüçîâàíèè îäèíàêîâûõ íàçâàíèé 'function[]' âåðíåò áëèæàéøèé ID áàðüåðà!
*
*
* Set the barrier status
*       SetBarrierState(barrierid, barrier_state)
*       * barrierid: The ID of the barrier
*       * barrier_state: Barrier status
*
*		* Returns (-1) on failure or (1) on success
*
*
* Get Barrier status
*       GetBarrierState(barrierid)
*       * barrierid: The ID of the barrier
*
*		* Returns (-1) on failure or status
*
*
* Get the barrier object ID
*       GetBarrierObjectID(barrierid, &moveid, &extraid = 0)
*       * barrierid: The ID of the barrier
*       * &moveid: moving object id
*       * &extraid: additional object id
*
*		* Returns (-1) on failure or (1) on success
*
*
* Create a second extra object
*       BarrierCreateExtraObject(barrierid, object_model, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1)
*       * barrierid - The ID of the barrier
*       * object_model - The model
*       * Float:x - The x coordinate to create the object
*       * Float:y - The y coordinate to create the object
*       * Float:z - The z coordinate to create the object
*       * Float:rx - The x rotation of the object
*       * Float:ry - The y rotation of the object
*       * Float:rz - The z rotation of the object
*       * worldid - The virtual world ID
*       * interiorid - The interior ID
*
*       * Returns (-1) on failure or (1) on success
*
*
*/

#if defined _easy_barrier_included 
	#endinput
#endif
#define _easy_barrier_included


#if !defined MAX_BARRIERS
    #define MAX_BARRIERS                    200
#endif

#if !defined BARRIER_MAX_FUNCTION_NAME
	#define BARRIER_MAX_FUNCTION_NAME       30
#endif

#if !defined BARRIER_KEY_STATE_ONFOOT
    #define BARRIER_KEY_STATE_ONFOOT        KEY_WALK
#endif

#if !defined BARRIER_KEY_STATE_DRIVER
    #define BARRIER_KEY_STATE_DRIVER        KEY_CROUCH 
#endif

#if !defined BARRIER_3DTEXT_TEXT
    static BARRIER_3DTEXT_TEXT[] =          "Press H to open";
#endif

#if !defined BARRIER_3DTEXT_DISTANCE
	#define BARRIER_3DTEXT_DISTANCE         18.0
#endif

#if !defined BARRIER_3DTEXT_LENGTH
	#define BARRIER_3DTEXT_LENGTH   	    144	
#endif

#if !defined BARRIER_OBJECT_DISTANCE
	#define BARRIER_OBJECT_DISTANCE     	200.0 
#endif

#define BarrierResponse:%0(%1) forward %0(%1); public %0(%1)

enum
{
    BARRIER_INVALID = -1,
    BARRIER_STATE_PLAYER_AND_DRIVER = -1,
    BARRIER_STATE_DRIVER_ONLY = 2,
    BARRIER_STATE_PLAYER_ONLY = 1
}

enum barrier_gates_EN
{
    bool:bg_Create,
    bg_Function[BARRIER_MAX_FUNCTION_NAME],
    Float:bg_ZoneSize,
    bg_MoveObject, bg_ExtraObject,
    Float:bg_Object_x,
    Float:bg_Object_y,
    Float:bg_Object_z,
    Float:bg_Object_rx,
    Float:bg_Object_ry,
    Float:bg_Object_rz,
    bg_Worldid,
    bg_Interiorid,
    Float:bg_MoveObject_x,
    Float:bg_MoveObject_y,
    Float:bg_MoveObject_z,
    Float:bg_MoveObject_rx,
    Float:bg_MoveObject_ry,
    Float:bg_MoveObject_rz,
    Float:bg_MoveSpeed,

    Float:bg_trigger_x,
    Float:bg_trigger_y,
    Float:bg_trigger_z,
    Text3D:bg_Text3D,
    bool:bg_Open,
    bg_ClosingTime,
    bg_ClosingTimeStatic,
    bg_BarrierState,
    bg_3DText_Text[BARRIER_3DTEXT_LENGTH],
    bg_3DTextColor,
    Float:bg_3DTextDistance
}
static barrier_gates[MAX_BARRIERS][barrier_gates_EN];


stock BarrierCreate(const function[], Float:zone_size, Float:move_speed, closing_seconds, object_model, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, barrier_state = BARRIER_STATE_DRIVER_ONLY, const text3D[] = "", color = -1, Float:text3D_distance = BARRIER_3DTEXT_DISTANCE, Float:trigger_x = 0.0, Float:trigger_y = 0.0, Float:trigger_z = 0.0)
{
    if(strlen(function) <= 0 || strlen(function) >= BARRIER_MAX_FUNCTION_NAME) return printf("easy-barrier --->>> | BarrierCreate | error, while creating '%s' | wrong name length (length from 1 to %d)", function, BARRIER_MAX_FUNCTION_NAME) & -1;
	new slot = -1;
	for(new i; i < MAX_BARRIERS; i ++)
	{
		if(barrier_gates[i][bg_Create] == true) continue;
		slot = i;
		break;
	}
	if(slot == -1) return printf("easy-barrier --->>> | BarrierCreate | not all barriers were created! | increase the value '#define MAX_BARRIERS'") & -1;

    barrier_gates[slot][bg_Create] = true;
    format(barrier_gates[slot][bg_Function], BARRIER_MAX_FUNCTION_NAME, function);
    barrier_gates[slot][bg_ZoneSize] = zone_size;
    barrier_gates[slot][bg_Object_x] = x;
    barrier_gates[slot][bg_Object_y] = y;
    barrier_gates[slot][bg_Object_z] = z;
    barrier_gates[slot][bg_Object_rx] = rx;
    barrier_gates[slot][bg_Object_ry] = ry;
    barrier_gates[slot][bg_Object_rz] = rz;
    barrier_gates[slot][bg_Worldid] = worldid;
    barrier_gates[slot][bg_Interiorid] = interiorid;

    barrier_gates[slot][bg_MoveObject_x] = x;
    barrier_gates[slot][bg_MoveObject_y] = y;
    barrier_gates[slot][bg_MoveObject_z] = z;
    barrier_gates[slot][bg_MoveObject_rx] = rx;
    barrier_gates[slot][bg_MoveObject_ry] = ry;
    barrier_gates[slot][bg_MoveObject_rz] = rz;
    barrier_gates[slot][bg_MoveSpeed] = move_speed;
    barrier_gates[slot][bg_ClosingTime] = 0;
    barrier_gates[slot][bg_ClosingTimeStatic] = closing_seconds;
    barrier_gates[slot][bg_BarrierState] = barrier_state;
    barrier_gates[slot][bg_Text3D] = Text3D:INVALID_3DTEXT_ID;
    format(barrier_gates[slot][bg_3DText_Text], BARRIER_3DTEXT_LENGTH, (strlen(text3D) == 0) ? (BARRIER_3DTEXT_TEXT):(text3D));
    barrier_gates[slot][bg_3DTextDistance] = text3D_distance;
    barrier_gates[slot][bg_3DTextColor] = color;

    new Float:xoff, Float:yoff;
    switch(object_model)
    {
        case 968:
        {
            barrier_gates[slot][bg_MoveObject_ry] = ry - ((ry*95)/100);
            barrier_gates[slot][bg_ExtraObject] = CreateDynamicObject(966, x, y, z-0.8,  rx, 0.0, rz,  worldid, interiorid,  -1, BARRIER_OBJECT_DISTANCE, BARRIER_OBJECT_DISTANCE);
            barrier_gates[slot][bg_MoveObject] = CreateDynamicObject(object_model, x, y, z,  rx, ry, rz,  worldid, interiorid,  -1, BARRIER_OBJECT_DISTANCE, BARRIER_OBJECT_DISTANCE);
            
            xoff = -3.6;
            rz = 360 - rz;
            x = (floatsin(rz, degrees) * yoff + floatcos(rz, degrees) * xoff + x);
            y = (floatcos(rz, degrees) * yoff - floatsin(rz, degrees) * xoff + y);
        }
        default:
        {
            barrier_gates[slot][bg_MoveObject] = CreateDynamicObject(object_model, x, y, z,  rx, ry, rz,  worldid, interiorid,  -1, BARRIER_OBJECT_DISTANCE, BARRIER_OBJECT_DISTANCE);
        }
    }

	if(strlen(text3D) == 0) barrier_gates[slot][bg_Text3D] = CreateDynamic3DTextLabel(BARRIER_3DTEXT_TEXT, color, x, y, z+0.5, text3D_distance, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, worldid, interiorid, -1, text3D_distance);
	else barrier_gates[slot][bg_Text3D] = CreateDynamic3DTextLabel(text3D, color, x, y, z+0.5, text3D_distance, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, worldid, interiorid, -1, text3D_distance);
    
    barrier_gates[slot][bg_trigger_x] = (trigger_x == 0.0) ? (x):(trigger_x);
    barrier_gates[slot][bg_trigger_y] = (trigger_y == 0.0) ? (y):(trigger_y);
    barrier_gates[slot][bg_trigger_z] = (trigger_z == 0.0) ? (z):(trigger_z);
    
    if(slot == 0) SetTimer("_Barrier_Timer", 1000, true);
    return slot;
}

stock BarrierOpen(barrierid)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | BarrierOpen | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false || barrier_gates[barrierid][bg_Open] == true) return -1;
    
    MoveDynamicObject(barrier_gates[barrierid][bg_MoveObject], 
        barrier_gates[barrierid][bg_MoveObject_x], barrier_gates[barrierid][bg_MoveObject_y], barrier_gates[barrierid][bg_MoveObject_z]-0.1, 
        barrier_gates[barrierid][bg_MoveSpeed],
        barrier_gates[barrierid][bg_MoveObject_rx], barrier_gates[barrierid][bg_MoveObject_ry], barrier_gates[barrierid][bg_MoveObject_rz]);

    barrier_gates[barrierid][bg_Open] = true;
    return 1;
}

stock BarrierClose(barrierid)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | BarrierClose | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false || barrier_gates[barrierid][bg_Open] == false) return -1;
    
    MoveDynamicObject(barrier_gates[barrierid][bg_MoveObject],
        barrier_gates[barrierid][bg_Object_x], barrier_gates[barrierid][bg_Object_y], barrier_gates[barrierid][bg_Object_z], 
        barrier_gates[barrierid][bg_MoveSpeed], 
        barrier_gates[barrierid][bg_Object_rx], barrier_gates[barrierid][bg_Object_ry], barrier_gates[barrierid][bg_Object_rz]);

    barrier_gates[barrierid][bg_Open] = false;
	barrier_gates[barrierid][bg_ClosingTime] = 0;
    return 1;
}

stock IsBarrierOpen(barrierid)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | IsBarrierOpen | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false) return -1;
    
    return barrier_gates[barrierid][bg_Open];
}

stock SetBarrierMove(barrierid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | SetBarrierMove | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false) return -1;

    barrier_gates[barrierid][bg_MoveObject_x] =   (x != -1.0) ? (x): (barrier_gates[barrierid][bg_MoveObject_x]);
    barrier_gates[barrierid][bg_MoveObject_y] =   (y != -1.0) ? (y): (barrier_gates[barrierid][bg_MoveObject_y]);
    barrier_gates[barrierid][bg_MoveObject_z] =   (z != -1.0) ? (z): (barrier_gates[barrierid][bg_MoveObject_z]);
    barrier_gates[barrierid][bg_MoveObject_rx] = (rx != -1.0) ? (rx):(barrier_gates[barrierid][bg_MoveObject_rx]);
    barrier_gates[barrierid][bg_MoveObject_ry] = (ry != -1.0) ? (ry):(barrier_gates[barrierid][bg_MoveObject_ry]);
    barrier_gates[barrierid][bg_MoveObject_rz] = (rz != -1.0) ? (rz):(barrier_gates[barrierid][bg_MoveObject_rz]);
    return 1;
}

stock SetBarrierText(barrierid, const text[], color)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | SetBarrierText | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false || barrier_gates[barrierid][bg_Text3D] == Text3D:INVALID_3DTEXT_ID) return -1;

    format(barrier_gates[barrierid][bg_3DText_Text], BARRIER_3DTEXT_LENGTH, text);
    barrier_gates[barrierid][bg_3DTextColor] = color;

    UpdateDynamic3DTextLabelText(barrier_gates[barrierid][bg_Text3D], color, text);
    return 1;
}

stock GetBarrierText(barrierid, text[], size = sizeof(text))
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | SetBarrierText | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false || barrier_gates[barrierid][bg_Text3D] == Text3D:INVALID_3DTEXT_ID) return -1;

    format(text, size, barrier_gates[barrierid][bg_3DText_Text]);
    return 1;
}

stock GetBarrierTextColor(barrierid, &color)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | SetBarrierText | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false || barrier_gates[barrierid][bg_Text3D] == Text3D:INVALID_3DTEXT_ID) return -1;

    color = barrier_gates[barrierid][bg_3DTextColor];
    return 1;
}

stock SetBarrierSecondsClose(barrierid, seconds)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | SetBarrierSecondsClose | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false) return -1;
    if(seconds < 0 || seconds > 90000000) return -1;

    barrier_gates[barrierid][bg_ClosingTimeStatic] = seconds;
    return 1;
}

stock GetBarrierSecondsCloses(barrierid)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | GetBarrierSecondsCloses | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false) return -1;

    return barrier_gates[barrierid][bg_ClosingTimeStatic];
}

stock SetBarrierMoveSpeed(barrierid, Float:speed)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | SetBarrierMoveSpeed | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false) return -1;
    if(speed < 0.0 || speed > 90000000.0) return -1;

    barrier_gates[barrierid][bg_MoveSpeed] = speed;
    return 1;
}

stock GetBarrierMoveSpeed(barrierid, &Float:speed)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | GetBarrierMoveSpeed | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false) return -1;

    speed = barrier_gates[barrierid][bg_MoveSpeed];
    return 1;
}

stock SetBarrierTrigger(barrierid, Float:x, Float:y, Float:z)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | SetBarrierTrigger | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false) return -1;

    barrier_gates[barrierid][bg_trigger_x] = x;
    barrier_gates[barrierid][bg_trigger_y] = y;
    barrier_gates[barrierid][bg_trigger_z] = z;
    return 1;
}

stock GetBarrierTrigger(barrierid, &Float:x, &Float:y, &Float:z)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | GetBarrierTrigger | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false) return -1;

    x = barrier_gates[barrierid][bg_trigger_x];
    y = barrier_gates[barrierid][bg_trigger_y];
    z = barrier_gates[barrierid][bg_trigger_z];
    return 1;
}

stock SetBarrierTextPosition(barrierid, Float:x, Float:y, Float:z)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | SetBarrierTrigger | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false) return -1;

    if(barrier_gates[barrierid][bg_Text3D] != Text3D:INVALID_3DTEXT_ID) DestroyDynamic3DTextLabel(barrier_gates[barrierid][bg_Text3D]);
	barrier_gates[barrierid][bg_Text3D] = CreateDynamic3DTextLabel(barrier_gates[barrierid][bg_3DText_Text], barrier_gates[barrierid][bg_3DTextColor], x, y, z, barrier_gates[barrierid][bg_3DTextDistance], INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, barrier_gates[barrierid][bg_Worldid], barrier_gates[barrierid][bg_Interiorid], -1, barrier_gates[barrierid][bg_3DTextDistance]);
    return 1;
}

stock BarrierDelete(barrierid)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | BarrierDelete | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false) return -1;

    if(IsValidDynamicObject(barrier_gates[barrierid][bg_MoveObject])) DestroyDynamicObject(barrier_gates[barrierid][bg_MoveObject]);
    if(IsValidDynamicObject(barrier_gates[barrierid][bg_ExtraObject])) DestroyDynamicObject(barrier_gates[barrierid][bg_ExtraObject]);
    if(barrier_gates[barrierid][bg_Text3D] != Text3D:INVALID_3DTEXT_ID) DestroyDynamic3DTextLabel(barrier_gates[barrierid][bg_Text3D]);

    barrier_gates[barrierid][bg_Create] = false;
    barrier_gates[barrierid][bg_Function][0] = '\0';
    barrier_gates[barrierid][bg_MoveObject] = 0;
    barrier_gates[barrierid][bg_ExtraObject] = 0;
    barrier_gates[barrierid][bg_Text3D] = Text3D:INVALID_3DTEXT_ID;
    return barrierid;
}

stock GetBarrierSlotID(const function[])
{
	if(strlen(function) <= 0 || strlen(function) >= BARRIER_MAX_FUNCTION_NAME) return printf("easy-barrier --->>> | GetBarrierSlotID | error, in function name '%s' | wrong name length (length from 1 to 30)", function) & -1;
	new slot = -1;
	for(new x; x < MAX_BARRIERS; x ++)
	{
		if(barrier_gates[x][bg_Create] == false) continue;
		if(strcmp(function, barrier_gates[x][bg_Function], false)) continue;
		slot = x;
		break;
	}
	return slot;
}

stock BarrierCreateExtraObject(barrierid, object_model, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | BarrierCreateOtherObject | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false) return -1;

    if(IsValidDynamicObject(barrier_gates[barrierid][bg_ExtraObject])) DestroyDynamicObject(barrier_gates[barrierid][bg_ExtraObject]);
    barrier_gates[barrierid][bg_ExtraObject] = CreateDynamicObject(object_model, x, y, z,  rx, ry, rz,  worldid, interiorid,  -1, BARRIER_OBJECT_DISTANCE, BARRIER_OBJECT_DISTANCE);
    return 1;
}

stock SetBarrierState(barrierid, barrier_state)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | SetBarrierState | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false) return -1;
    if(barrier_state != BARRIER_STATE_PLAYER_AND_DRIVER && barrier_state != BARRIER_STATE_DRIVER_ONLY && barrier_state != BARRIER_STATE_PLAYER_ONLY) return printf("easy-barrier --->>> | SetBarrierState (ID: %d) | error, invalid 'barrier_state'", barrierid) & -1;

    barrier_gates[barrierid][bg_BarrierState] = barrier_state;
    return 1;
}

stock GetBarrierState(barrierid)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | GetBarrierState | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false) return -1;

    return barrier_gates[barrierid][bg_BarrierState];
}

stock GetBarrierObjectID(barrierid, &moveid, &extraid = 0)
{
    if(barrierid < 0 || barrierid >= MAX_BARRIERS) return printf("easy-barrier --->>> | GetBarrierObjectID | error, invalid barrierid '%d'", barrierid) & -1;
    if(barrier_gates[barrierid][bg_Create] == false) return -1;

    moveid = barrier_gates[barrierid][bg_MoveObject];
    extraid = barrier_gates[barrierid][bg_ExtraObject];
    return 1;
}

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
#else
	public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
#endif
{
	if(newkeys & BARRIER_KEY_STATE_ONFOOT && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT || newkeys & BARRIER_KEY_STATE_DRIVER && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		for(new x; x < MAX_BARRIERS; x ++)
		{
			if(barrier_gates[x][bg_Create] == false) continue;
            if(!IsPlayerInRangeOfPoint(playerid, barrier_gates[x][bg_ZoneSize], barrier_gates[x][bg_trigger_x], barrier_gates[x][bg_trigger_y], barrier_gates[x][bg_trigger_z])) continue;
            if(barrier_gates[x][bg_Worldid] != -1 && GetPlayerVirtualWorld(playerid) != barrier_gates[x][bg_Worldid] || barrier_gates[x][bg_Interiorid] != -1 && GetPlayerInterior(playerid) != barrier_gates[x][bg_Interiorid]) break; 
            if(barrier_gates[x][bg_BarrierState] != BARRIER_STATE_PLAYER_AND_DRIVER && barrier_gates[x][bg_BarrierState] != GetPlayerState(playerid)) break;
            if(barrier_gates[x][bg_ClosingTimeStatic] != 0 && barrier_gates[x][bg_Open] == true) break;

			new check = CallLocalFunction(barrier_gates[x][bg_Function], "dd", playerid, x); // BarrierResponse
            if(check == 0)
            {
                if(barrier_gates[x][bg_ClosingTimeStatic] == 0)
                {
                    if(barrier_gates[x][bg_Open] == false) BarrierOpen(x);
                    else BarrierClose(x);
                    break;
                }
                BarrierOpen(x);
                barrier_gates[x][bg_ClosingTime] = barrier_gates[x][bg_ClosingTimeStatic];
            }
			break;
		}
	}
    #if !defined _inc_y_hooks && !defined _INC_y_hooks && defined OnPKeyStateC_barrier_gates
		return OnPKeyStateC_barrier_gates(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerKeyStateChange
		#undef OnPlayerKeyStateChange
	#else
		#define _ALS_OnPlayerKeyStateChange
	#endif
	#define OnPlayerKeyStateChange OnPKeyStateC_barrier_gates
	#if defined OnPKeyStateC_barrier_gates
		forward OnPKeyStateC_barrier_gates(playerid, newkeys, oldkeys);
	#endif
#endif


forward _Barrier_Timer();
public _Barrier_Timer()
{
    for(new x; x < MAX_BARRIERS; x ++)
    {
        if(barrier_gates[x][bg_Create] == false) continue;
        if(barrier_gates[x][bg_ClosingTime] == 0) continue;
    
        barrier_gates[x][bg_ClosingTime] --;
        if(barrier_gates[x][bg_ClosingTime] <= 0 && barrier_gates[x][bg_Open] == true) BarrierClose(x);
    }
    return 1;
}
