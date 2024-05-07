/*
*
*
*
*   ---------------------------------------------------
*
*	Creater - @Bren828	
*									7 May 2024
*
*   Version: 1.5
*
*   ---------------------------------------------------
*
*
*	https://github.com/Bren828/easy-barrier
*
*
*/


#if defined _easy_barrier_included 
	#endinput
#endif
#define _easy_barrier_included


#if !defined MAX_BARRIERS
    #define MAX_BARRIERS 200
#endif


#if !defined BARRIER_MAX_ATTACH
    #define BARRIER_MAX_ATTACH 10
#endif


#if !defined BARRIER_MAX_FUNCTION_NAME
	#define BARRIER_MAX_FUNCTION_NAME 32
#endif


#if !defined BARRIER_KEY_STATE_ONFOOT
    #define BARRIER_KEY_STATE_ONFOOT KEY_WALK
#endif


#if !defined BARRIER_KEY_STATE_DRIVER
    #define BARRIER_KEY_STATE_DRIVER KEY_CROUCH 
#endif


#if !defined BARRIER_3DTEXT_LENGTH
	#define BARRIER_3DTEXT_LENGTH 144	
#endif


#if !defined BARRIER_OBJECT_DISTANCE
	#define BARRIER_OBJECT_DISTANCE 150.0 
#endif


#if !defined BARRIER_NOT_CREATE_EXTRA_OBJECT
    #define BARRIER_NOT_CREATE_EXTRA_OBJECT 
#endif


#define BarrierResponse:%0(%1) forward %0(%1); public %0(%1)


enum
{
    BARRIER_INVALID = -1,
    BARRIER_STATE_PLAYER_AND_DRIVER = -1,
    BARRIER_STATE_DRIVER_ONLY = 2,
    BARRIER_STATE_PLAYER_ONLY = 1,

    BARRIER_MOVEMENT_TYPE_OUTSIDE = 0,
    BARRIER_MOVEMENT_TYPE_INSIDE = 1,
    BARRIER_MOVEMENT_TYPE_RIGHT = 2,
    BARRIER_MOVEMENT_TYPE_LEFT = 3,
    BARRIER_MOVEMENT_TYPE_UP = 4,
    BARRIER_MOVEMENT_TYPE_DOWN = 5,

    BARRIER_DATA_AREA_ID = 0,
    BARRIER_DATA_ID = 1,
    BARRIER_DATA_EXTRA = 2,
}


enum BARRIER_GATES_EN
{
    bool:bg_Create,
    bg_Function[BARRIER_MAX_FUNCTION_NAME],
    Float:bg_Radius,
    
    bg_MoveObject, 
    bg_ExtraObject,
    bg_Sphere,

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

    bg_Key,
    bg_ClosingTime,
    bg_ClosingTimeStatic,
    bg_BarrierState,
    bg_3DText_Text[BARRIER_3DTEXT_LENGTH],
    bg_Attach[BARRIER_MAX_ATTACH],
    bg_AttachFrom,
    bg_MaxAttach,

    bg_extra_sphere,
    bg_extra_key,
    Float:bg_extra_trigger_radius,
    bg_extra_trigger_state,
    Float:bg_extra_trigger_x,
    Float:bg_extra_trigger_y,
    Float:bg_extra_trigger_z
}

static barrier_gates[MAX_BARRIERS][BARRIER_GATES_EN];


enum BARRIER_OBJECT_INFO_EN
{
    boi_Model,
    Float:boi_Width,
    Float:boi_Height,
    bool:boi_CoordinateX,
    boi_DefaultType,
    Float:boi_DefaultPercent,

    Float:boi_DefaultTriggerX,
    Float:boi_DefaultTriggerY,
    Float:boi_DefaultTriggerZ,
}

static const barrier_object_info[][BARRIER_OBJECT_INFO_EN] = 
{
    {977, 2.00, 3.21, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 1.0, 0.0, -0.8},
    {1493, 1.50, 2.49, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1495, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1496, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1497, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1498, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1500, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1501, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1965, 1.55, 3.00, false, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.0, 0.8, -0.5},
    {1504, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1505, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1506, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1507, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1508, 6.30, 3.36, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {1522, 1.50, 2.49, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1533, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1532, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1556, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1535, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1536, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1537, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, -0.8, 0.0, 0.8},
    {1538, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1555, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1557, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1966, 6.88, 5.53, true, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.3},
    {1967, 1.55, 3.00, false, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.0, -0.8, -0.5},
    {1560, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1561, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, -0.8, 0.0, 0.8},
    {2634, 1.52, 2.29, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.0, 0.0, -0.8},
    {1566, 1.58, 3.02, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, -0.5},
    {1567, 1.50, 2.49, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {2664, 1.48, 2.35, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, -0.5},
    {1569, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {3294, 7.23, 5.82, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.5},
    {4084, 5.90, 3.64, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {8378, 67.51, 19.44, true, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -8.5},
    {5422, 4.21, 4.03, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.8},
    {5043, 4.00, 3.00, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {5340, 7.03, 3.10, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {5779, 5.23, 3.15, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {5856, 4.21, 4.03, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.0},
    {6400, 4.51, 4.65, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.0},
    {7927, 5.30, 2.49, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {7930, 9.17, 3.00, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {7931, 5.30, 2.49, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {9093, 7.38, 3.54, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {10182, 6.51, 3.42, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {10575, 6.92, 3.96, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.8},
    {8948, 7.38, 3.54, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {9625, 7.46, 5.78, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.3},
    {10154, 5.67, 5.59, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.3},
    {5302, 4.11, 4.65, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.5},
    {9099, 5.30, 2.49, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.8},
    {10149, 4.00, 3.00, true, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.0},
    {10246, 6.78, 3.48, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.0},
    {11102, 5.86, 4.32, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.5},
    {10671, 12.10, 3.74, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.2},
    {11313, 6.92, 3.96, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.2},
    {13187, 6.78, 2.59, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {13817, 4.50, 3.04, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.8},
    {11319, 7.23, 5.82, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.7},
    {11416, 5.13, 4.19, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.0},
    {13188, 4.82, 2.59, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {13028, 4.53, 3.81, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.8},
    {13360, 1.14, 2.15, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.0, 0.0, -0.5},
    {17951, 6.17, 3.55, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.8},
    {16773, 14.64, 8.01, true, BARRIER_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -3.0},
    {17566, 3.91, 3.45, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.0},
    {16775, 14.64, 8.01, true, BARRIER_MOVEMENT_TYPE_RIGHT, 100.0, 0.0, 0.0, -3.0},
    {18553, 3.90, 2.59, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {18757, 2.00, 2.91, false, BARRIER_MOVEMENT_TYPE_LEFT, 100.0, -1.7, 1.0, -1.2},
    {18756, 2.02, 2.91, false, BARRIER_MOVEMENT_TYPE_RIGHT, 100.0, -1.7, -1.0, -1.2},
    {19302, 1.75, 2.50, true, BARRIER_MOVEMENT_TYPE_RIGHT, 100.0, 0.0, 0.0, -0.5},
    {19303, 1.75, 2.50, true, BARRIER_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -0.5},
    {19799, 2.00, 3.00, true, BARRIER_MOVEMENT_TYPE_INSIDE, 50.0, -1.0, 0.0, -0.8},
    {19802, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {19857, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, -0.5},
    {19858, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, -0.5},
    {19859, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, -0.5},
    {19860, 1.50, 2.50, true, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, -0.5},
    {19861, 5.30, 2.50, true, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.7},
    {19862, 5.30, 2.50, true, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.7},
    {19863, 5.30, 2.50, true, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.7},
    {19864, 5.30, 2.50, true, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.7},
    {19870, 4.73, 3.53, true, BARRIER_MOVEMENT_TYPE_RIGHT, 100.0, 2.4, 0.0, -1.0},
    {19910, 3.75, 2.40, true, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {19912, 11.53, 5.55, true, BARRIER_MOVEMENT_TYPE_LEFT, 100.0, -5.5, 0.0, -1.7},
    {19906, 6.17, 3.22, true, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -2.0},
    {976, 8.85, 3.34, true, BARRIER_MOVEMENT_TYPE_LEFT, 100.0, 4.3, 0.0, 0.8},
    {971, 10.85, 9.14, true, BARRIER_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -2.2},
    {2988, 4.21, 3.91, false, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.0, -2.0, 0.8},
    {985, 7.88, 7.21, true, BARRIER_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -0.5},
    {2928, 2.59, 2.50, true, BARRIER_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {2990, 10.11, 7.82, true, BARRIER_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -2.2},
    {19795, 3.25, 3.45, false, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.0, -1.6, -1.0},
    {19796, 2.51, 3.51, false, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.0, -1.2, -1.0},
    {969, 8.85, 3.34, true, BARRIER_MOVEMENT_TYPE_LEFT, 100.0, 4.5, 0.0, 0.8},
    {975, 8.85, 3.34, true, BARRIER_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -0.5},
    {980, 11.53, 5.55, true, BARRIER_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -1.5},
    {988, 5.48, 5.17, true, BARRIER_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -0.2},
    {2930, 1.72, 2.64, false, BARRIER_MOVEMENT_TYPE_LEFT, 100.0, 0.0, -0.8, -1.3},
    {3036, 4.84, 3.53, true, BARRIER_MOVEMENT_TYPE_RIGHT, 100.0, 2.5, 0.0, -0.8},
    {989, 1.65, 3.65, false, BARRIER_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -0.8},
    {19313, 13.98, 6.60, true, BARRIER_MOVEMENT_TYPE_RIGHT, 100.0, 0.0, 0.0, -2.0},
    {968, 0.58, 7.13, false, BARRIER_MOVEMENT_TYPE_UP, 100.0, 3.6, 0.0, 0.0},
    {3089, 1.50, 2.70, false, BARRIER_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.75, 0.0, -0.5}
};


static player_barrier_enter[MAX_PLAYERS];


stock BarrierCreate(const function[], Float:radius, Float:move_speed, closing_seconds, modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, barrier_state = BARRIER_STATE_PLAYER_AND_DRIVER, const text3d[] = "", color = -1, Float:text3d_distance = 3.0, Float:trigger_x = 0.0, Float:trigger_y = 0.0, Float:trigger_z = 0.0, key = 0)
{
    if(!(0 < strlen(function) < BARRIER_MAX_FUNCTION_NAME)) 
        return -1;

    new barrierid = -1;

	for(new i; i < MAX_BARRIERS; i ++)
	{
		if(barrier_gates[i][bg_Create] == true) 
            continue;

		barrierid = i;
		break;
	}

	if(barrierid == -1) 
        return printf("easy-barrier --->>> | BarrierCreate | not all barriers were created! | increase the value '#define MAX_BARRIERS'") & -1;

    barrier_gates[barrierid][bg_Create] = true;
    format(barrier_gates[barrierid][bg_Function], BARRIER_MAX_FUNCTION_NAME, function);
    barrier_gates[barrierid][bg_Radius] = radius;
    barrier_gates[barrierid][bg_MoveSpeed] = move_speed;
    barrier_gates[barrierid][bg_ClosingTimeStatic] = closing_seconds;

    barrier_gates[barrierid][bg_Object_x] = x;
    barrier_gates[barrierid][bg_Object_y] = y;
    barrier_gates[barrierid][bg_Object_z] = z;
    barrier_gates[barrierid][bg_Object_rx] = rx;
    barrier_gates[barrierid][bg_Object_ry] = ry;
    barrier_gates[barrierid][bg_Object_rz] = rz;
    barrier_gates[barrierid][bg_Worldid] = worldid;
    barrier_gates[barrierid][bg_Interiorid] = interiorid;

    barrier_gates[barrierid][bg_MoveObject_x] = x;
    barrier_gates[barrierid][bg_MoveObject_y] = y;
    barrier_gates[barrierid][bg_MoveObject_z] = z;
    barrier_gates[barrierid][bg_MoveObject_rx] = rx;
    barrier_gates[barrierid][bg_MoveObject_ry] = ry;
    barrier_gates[barrierid][bg_MoveObject_rz] = rz;

    if(key == 0) barrier_gates[barrierid][bg_Key] = (barrier_state == BARRIER_STATE_DRIVER_ONLY) ? (BARRIER_KEY_STATE_DRIVER): (BARRIER_KEY_STATE_ONFOOT);
    else barrier_gates[barrierid][bg_Key] = key;
    barrier_gates[barrierid][bg_ClosingTime] = 0;
    barrier_gates[barrierid][bg_BarrierState] = barrier_state;
    barrier_gates[barrierid][bg_Text3D] = Text3D:INVALID_3DTEXT_ID;
    for(new at; at < BARRIER_MAX_ATTACH; at ++) barrier_gates[barrierid][bg_Attach][at] = -1;
    barrier_gates[barrierid][bg_AttachFrom] = -1;
    barrier_gates[barrierid][bg_MaxAttach] = 0;
    barrier_gates[barrierid][bg_ExtraObject] = 0;

    barrier_gates[barrierid][bg_extra_key] = 0;
    barrier_gates[barrierid][bg_extra_trigger_state] = 0;
    barrier_gates[barrierid][bg_extra_trigger_radius] = 0.0;
    barrier_gates[barrierid][bg_extra_trigger_x] = 0.0;
    barrier_gates[barrierid][bg_extra_trigger_y] = 0.0;
    barrier_gates[barrierid][bg_extra_trigger_z] = 0.0;

    barrier_gates[barrierid][bg_MoveObject] = CreateDynamicObject(modelid, x, y, z,  rx, ry, rz,  worldid, interiorid,  -1, BARRIER_OBJECT_DISTANCE, BARRIER_OBJECT_DISTANCE);

    #if defined OnBarrierObjectCreated
        OnBarrierObjectCreated(barrierid, barrier_gates[barrierid][bg_MoveObject], modelid);
    #endif

    #if defined BARRIER_NOT_CREATE_EXTRA_OBJECT
        if(modelid == 968) barrier_gates[barrierid][bg_ExtraObject] = CreateDynamicObject(966, x, y, z-0.8,  rx, 0.0, rz + 180.0,  worldid, interiorid,  -1, BARRIER_OBJECT_DISTANCE, BARRIER_OBJECT_DISTANCE);
    #endif

    if(!SetBarrierTypeOpening(barrierid, -1))
    {
        barrier_gates[barrierid][bg_trigger_x] = (trigger_x != 0.0) ? (trigger_x):(x);
        barrier_gates[barrierid][bg_trigger_y] = (trigger_y != 0.0) ? (trigger_y):(y);
        barrier_gates[barrierid][bg_trigger_z] = (trigger_z != 0.0) ? (trigger_z):(z);
    }
    else 
    {
        if(trigger_x != 0.0) barrier_gates[barrierid][bg_trigger_x] = trigger_x;
        if(trigger_y != 0.0) barrier_gates[barrierid][bg_trigger_y] = trigger_y;
        if(trigger_z != 0.0) barrier_gates[barrierid][bg_trigger_z] = trigger_z;
    }

    barrier_gates[barrierid][bg_Sphere] = CreateDynamicSphere(barrier_gates[barrierid][bg_trigger_x], barrier_gates[barrierid][bg_trigger_y], barrier_gates[barrierid][bg_trigger_z], radius, worldid, interiorid);
    
    new eb_arr[3];
    eb_arr[BARRIER_DATA_AREA_ID] = barrier_gates[barrierid][bg_Sphere];
    eb_arr[BARRIER_DATA_ID] = barrierid;
    eb_arr[BARRIER_DATA_EXTRA] = 0;

    Streamer_SetArrayData(STREAMER_TYPE_AREA, barrier_gates[barrierid][bg_Sphere], E_STREAMER_EXTRA_ID, eb_arr);


	if(strlen(text3d) >= 1) 
    {
        format(barrier_gates[barrierid][bg_3DText_Text], BARRIER_3DTEXT_LENGTH, text3d);
        barrier_gates[barrierid][bg_Text3D] = CreateDynamic3DTextLabel(text3d, color, barrier_gates[barrierid][bg_trigger_x], barrier_gates[barrierid][bg_trigger_y], barrier_gates[barrierid][bg_trigger_z]+0.3, text3d_distance, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, worldid, interiorid, -1, text3d_distance);
    }
    return barrierid;
}


stock BarrierOpen(barrierid)
{
    if( !(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]|| barrier_gates[barrierid][bg_Open] == true) 
        return -1;
    
    MoveDynamicObject(barrier_gates[barrierid][bg_MoveObject], 
        barrier_gates[barrierid][bg_MoveObject_x], barrier_gates[barrierid][bg_MoveObject_y], barrier_gates[barrierid][bg_MoveObject_z]-0.020, 
        barrier_gates[barrierid][bg_MoveSpeed],
        barrier_gates[barrierid][bg_MoveObject_rx], barrier_gates[barrierid][bg_MoveObject_ry], barrier_gates[barrierid][bg_MoveObject_rz]);

    barrier_gates[barrierid][bg_Open] = true;

    if(barrier_gates[barrierid][bg_MaxAttach] >= 1)
    {
        new attachid = -1;

        for(new at; at < BARRIER_MAX_ATTACH; at ++)
        {
            if(barrier_gates[barrierid][bg_Attach][at] == -1) 
                continue;

            attachid = barrier_gates[barrierid][bg_Attach][at];

            MoveDynamicObject(barrier_gates[attachid][bg_MoveObject], 
                barrier_gates[attachid][bg_MoveObject_x], barrier_gates[attachid][bg_MoveObject_y], barrier_gates[attachid][bg_MoveObject_z]-0.020, 
                barrier_gates[attachid][bg_MoveSpeed],
                barrier_gates[attachid][bg_MoveObject_rx], barrier_gates[attachid][bg_MoveObject_ry], barrier_gates[attachid][bg_MoveObject_rz]);

            barrier_gates[attachid][bg_Open] = true;
        }
    }
    return 1;
}


forward BarrierClose(barrierid);
public BarrierClose(barrierid)
{
    if( !(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create] || barrier_gates[barrierid][bg_Open] == false) 
        return -1;

    MoveDynamicObject(barrier_gates[barrierid][bg_MoveObject],
        barrier_gates[barrierid][bg_Object_x], barrier_gates[barrierid][bg_Object_y], barrier_gates[barrierid][bg_Object_z], 
        barrier_gates[barrierid][bg_MoveSpeed], 
        barrier_gates[barrierid][bg_Object_rx], barrier_gates[barrierid][bg_Object_ry], barrier_gates[barrierid][bg_Object_rz]);

    barrier_gates[barrierid][bg_Open] = false;
	barrier_gates[barrierid][bg_ClosingTime] = 0;

    if(barrier_gates[barrierid][bg_MaxAttach] >= 1)
    {
        new attachid = -1;

        for(new at; at < BARRIER_MAX_ATTACH; at ++)
        {
            if(barrier_gates[barrierid][bg_Attach][at] == -1) 
                continue;

            attachid = barrier_gates[barrierid][bg_Attach][at];

            MoveDynamicObject(barrier_gates[attachid][bg_MoveObject],
                barrier_gates[attachid][bg_Object_x], barrier_gates[attachid][bg_Object_y], barrier_gates[attachid][bg_Object_z], 
                barrier_gates[attachid][bg_MoveSpeed], 
                barrier_gates[attachid][bg_Object_rx], barrier_gates[attachid][bg_Object_ry], barrier_gates[attachid][bg_Object_rz]);

            barrier_gates[attachid][bg_Open] = false;
            barrier_gates[attachid][bg_ClosingTime] = 0;
        }
    }
    return 1;
}


stock IsBarrierOpen(barrierid)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;
    
    return barrier_gates[barrierid][bg_Open];
}


stock SetBarrierMovementX(barrierid, Float:x)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    barrier_gates[barrierid][bg_MoveObject_x] = x;
    return 1;
}


stock SetBarrierMovementY(barrierid, Float:y)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    barrier_gates[barrierid][bg_MoveObject_y] = y;
    return 1;
}


stock SetBarrierMovementZ(barrierid, Float:z)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    barrier_gates[barrierid][bg_MoveObject_z] = z;
    return 1;
}


stock SetBarrierMovementRX(barrierid, Float:rx)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    barrier_gates[barrierid][bg_MoveObject_rx] = rx;
    return 1;
}


stock SetBarrierMovementRY(barrierid, Float:ry)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    barrier_gates[barrierid][bg_MoveObject_ry] = ry;
    return 1;
}


stock SetBarrierMovementRZ(barrierid, Float:rz)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    barrier_gates[barrierid][bg_MoveObject_rz] = rz;
    return 1;
}


stock SetBarrierTypeOpening(barrierid, type, Float:percent = 100.0)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create] || !(-1 <= type <= 5) ) 
        return -1;
    
    new eb_modelid = Streamer_GetIntData(STREAMER_TYPE_OBJECT, barrier_gates[barrierid][bg_MoveObject], E_STREAMER_MODEL_ID);
    
    for(new _object_eb; _object_eb < sizeof(barrier_object_info); _object_eb ++)
    {
        if(eb_modelid != barrier_object_info[_object_eb][boi_Model]) 
            continue;
        
        barrier_gates[barrierid][bg_MoveObject_x] = barrier_gates[barrierid][bg_Object_x];
        barrier_gates[barrierid][bg_MoveObject_y] = barrier_gates[barrierid][bg_Object_y];
        barrier_gates[barrierid][bg_MoveObject_z] = barrier_gates[barrierid][bg_Object_z];
        barrier_gates[barrierid][bg_MoveObject_rz] = barrier_gates[barrierid][bg_Object_rz];

        if(type == -1) 
        {
            type = barrier_object_info[_object_eb][boi_DefaultType];
            percent = barrier_object_info[_object_eb][boi_DefaultPercent];

            new Float:rz = 360 - barrier_gates[barrierid][bg_Object_rz];
            
            barrier_gates[barrierid][bg_trigger_x] = (floatsin(rz, degrees) * barrier_object_info[_object_eb][boi_DefaultTriggerY] + floatcos(rz, degrees) * barrier_object_info[_object_eb][boi_DefaultTriggerX] + barrier_gates[barrierid][bg_Object_x]);
            barrier_gates[barrierid][bg_trigger_y] = (floatcos(rz, degrees) * barrier_object_info[_object_eb][boi_DefaultTriggerY] - floatsin(rz, degrees) * barrier_object_info[_object_eb][boi_DefaultTriggerX] + barrier_gates[barrierid][bg_Object_y]);
            barrier_gates[barrierid][bg_trigger_z] = barrier_gates[barrierid][bg_Object_z] + barrier_object_info[_object_eb][boi_DefaultTriggerZ];
        }

        if(eb_modelid == 968)
        {
            barrier_gates[barrierid][bg_MoveObject_ry] = barrier_gates[barrierid][bg_Object_ry] - (barrier_gates[barrierid][bg_Object_ry] * percent) / 100;
            return 1;
        }

        switch(type)
        {
            case BARRIER_MOVEMENT_TYPE_RIGHT, BARRIER_MOVEMENT_TYPE_LEFT: 
            {
                new Float:x = barrier_gates[barrierid][bg_Object_x],
                    Float:y = barrier_gates[barrierid][bg_Object_y],
                    Float:rz = 360 - barrier_gates[barrierid][bg_Object_rz],
                    Float:xoff, 
                    Float:yoff,
                    Float:scale = (type == BARRIER_MOVEMENT_TYPE_LEFT) ? ((barrier_object_info[_object_eb][boi_Width] * percent) / 100) : (-(barrier_object_info[_object_eb][boi_Width] * percent) / 100);

                if(barrier_object_info[_object_eb][boi_CoordinateX] == true) xoff = scale;
                else yoff = scale;

                barrier_gates[barrierid][bg_MoveObject_x] = (floatsin(rz, degrees) * yoff + floatcos(rz, degrees) * xoff + x);
                barrier_gates[barrierid][bg_MoveObject_y] = (floatcos(rz, degrees) * yoff - floatsin(rz, degrees) * xoff + y);
            }
            case BARRIER_MOVEMENT_TYPE_UP: barrier_gates[barrierid][bg_MoveObject_z] = barrier_gates[barrierid][bg_Object_z] + ((barrier_object_info[_object_eb][boi_Height] * percent) / 100);
            case BARRIER_MOVEMENT_TYPE_DOWN: barrier_gates[barrierid][bg_MoveObject_z] = barrier_gates[barrierid][bg_Object_z] - ((barrier_object_info[_object_eb][boi_Height] * percent) / 100);
            case BARRIER_MOVEMENT_TYPE_OUTSIDE: barrier_gates[barrierid][bg_MoveObject_rz] = barrier_gates[barrierid][bg_Object_rz] + ((180.0 * percent) / 100);
            case BARRIER_MOVEMENT_TYPE_INSIDE: barrier_gates[barrierid][bg_MoveObject_rz] = barrier_gates[barrierid][bg_Object_rz] - ((180.0 * percent) / 100);
        }

        return 1;
    }

    return 0;
}


stock SetBarrierMove(barrierid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    barrier_gates[barrierid][bg_MoveObject_x] =   (x != -1.0) ? (x): (barrier_gates[barrierid][bg_MoveObject_x]);
    barrier_gates[barrierid][bg_MoveObject_y] =   (y != -1.0) ? (y): (barrier_gates[barrierid][bg_MoveObject_y]);
    barrier_gates[barrierid][bg_MoveObject_z] =   (z != -1.0) ? (z): (barrier_gates[barrierid][bg_MoveObject_z]);
    barrier_gates[barrierid][bg_MoveObject_rx] = (rx != -1.0) ? (rx):(barrier_gates[barrierid][bg_MoveObject_rx]);
    barrier_gates[barrierid][bg_MoveObject_ry] = (ry != -1.0) ? (ry):(barrier_gates[barrierid][bg_MoveObject_ry]);
    barrier_gates[barrierid][bg_MoveObject_rz] = (rz != -1.0) ? (rz):(barrier_gates[barrierid][bg_MoveObject_rz]);

    return 1;
}


stock SetBarrierText(barrierid, const text[], color = 0)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create] || barrier_gates[barrierid][bg_Text3D] == Text3D:INVALID_3DTEXT_ID) 
        return -1;

    format(barrier_gates[barrierid][bg_3DText_Text], BARRIER_3DTEXT_LENGTH, text);
    UpdateDynamic3DTextLabelText(barrier_gates[barrierid][bg_Text3D], -1, text);

    if(color != 0) Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, barrier_gates[barrierid][bg_Text3D], E_STREAMER_COLOR, color);
    return 1;
}


stock GetBarrierText(barrierid, text[], size = sizeof(text))
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create] || barrier_gates[barrierid][bg_Text3D] == Text3D:INVALID_3DTEXT_ID) 
        return -1;

    format(text, size, barrier_gates[barrierid][bg_3DText_Text]);
    return 1;
}


stock SetBarrierTextColor(barrierid, color)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create] || barrier_gates[barrierid][bg_Text3D] == Text3D:INVALID_3DTEXT_ID) 
        return -1;

    return Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, barrier_gates[barrierid][bg_Text3D], E_STREAMER_COLOR, color);
}


stock GetBarrierTextColor(barrierid)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create] || barrier_gates[barrierid][bg_Text3D] == Text3D:INVALID_3DTEXT_ID) 
        return -1;

    return Streamer_GetIntData(STREAMER_TYPE_3D_TEXT_LABEL, barrier_gates[barrierid][bg_Text3D], E_STREAMER_COLOR);
}


stock SetBarrierTextPosition(barrierid, Float:x, Float:y, Float:z)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, barrier_gates[barrierid][bg_Text3D], E_STREAMER_X, x);
    Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, barrier_gates[barrierid][bg_Text3D], E_STREAMER_Y, y);
    Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, barrier_gates[barrierid][bg_Text3D], E_STREAMER_Z, z);
    return 1;
}


stock SetBarrierClosingTime(barrierid, seconds)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !(0 <= seconds <= 90000000) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    barrier_gates[barrierid][bg_ClosingTimeStatic] = seconds;
    return 1;
}


stock GetBarrierClosingTime(barrierid)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    return barrier_gates[barrierid][bg_ClosingTimeStatic];
}


stock SetBarrierMoveSpeed(barrierid, Float:speed)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    barrier_gates[barrierid][bg_MoveSpeed] = speed;
    return 1;
}


stock Float:GetBarrierMoveSpeed(barrierid)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1.0;

    return barrier_gates[barrierid][bg_MoveSpeed];
}


stock SetBarrierTrigger(barrierid, Float:x, Float:y, Float:z)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;
   
    barrier_gates[barrierid][bg_trigger_x] = x;
    barrier_gates[barrierid][bg_trigger_y] = y;
    barrier_gates[barrierid][bg_trigger_z] = z;

    if(IsValidDynamicArea(barrier_gates[barrierid][bg_Sphere]))
    {
        Streamer_SetFloatData(STREAMER_TYPE_AREA, barrier_gates[barrierid][bg_Sphere], E_STREAMER_X, x);
        Streamer_SetFloatData(STREAMER_TYPE_AREA, barrier_gates[barrierid][bg_Sphere], E_STREAMER_Y, y);
        Streamer_SetFloatData(STREAMER_TYPE_AREA, barrier_gates[barrierid][bg_Sphere], E_STREAMER_Z, z);
    }
    return 1;
}


stock GetBarrierTrigger(barrierid, &Float:x, &Float:y, &Float:z)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    x = barrier_gates[barrierid][bg_trigger_x];
    y = barrier_gates[barrierid][bg_trigger_y];
    z = barrier_gates[barrierid][bg_trigger_z];
    return 1;
}


stock SetBarrierTriggerExtra(barrierid, Float:x, Float:y, Float:z, Float:radius, barrier_state = BARRIER_STATE_PLAYER_ONLY, key = BARRIER_KEY_STATE_ONFOOT)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    if(barrier_state != BARRIER_STATE_PLAYER_AND_DRIVER && 
        barrier_state != BARRIER_STATE_DRIVER_ONLY && 
            barrier_state != BARRIER_STATE_PLAYER_ONLY) return -1;

    if(IsValidDynamicArea(barrier_gates[barrierid][bg_extra_sphere])) 
        DestroyDynamicArea(barrier_gates[barrierid][bg_extra_sphere]);

    barrier_gates[barrierid][bg_extra_sphere] = CreateDynamicSphere(x, y, z, radius, barrier_gates[barrierid][bg_Worldid], barrier_gates[barrierid][bg_Interiorid]);

    new eb_arr[3];
    eb_arr[BARRIER_DATA_AREA_ID] = barrier_gates[barrierid][bg_extra_sphere];
    eb_arr[BARRIER_DATA_ID] = barrierid;
    eb_arr[BARRIER_DATA_EXTRA] = 1;

    Streamer_SetArrayData(STREAMER_TYPE_AREA, barrier_gates[barrierid][bg_extra_sphere], E_STREAMER_EXTRA_ID, eb_arr);

    barrier_gates[barrierid][bg_extra_key] = key; 
    barrier_gates[barrierid][bg_extra_trigger_radius] = radius;
    barrier_gates[barrierid][bg_extra_trigger_state] = barrier_state;
    barrier_gates[barrierid][bg_extra_trigger_x] = x;
    barrier_gates[barrierid][bg_extra_trigger_y] = y;
    barrier_gates[barrierid][bg_extra_trigger_z] = z;

    return 1;
}


stock GetBarrierTriggerExtra(barrierid, &Float:x, &Float:y, &Float:z, &Float:radius = 0.0, &barrier_state = 0, &key = 0)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    radius = barrier_gates[barrierid][bg_extra_trigger_radius];
    barrier_state = barrier_gates[barrierid][bg_extra_trigger_state];
    key = barrier_gates[barrierid][bg_extra_key];
    x = barrier_gates[barrierid][bg_extra_trigger_x];
    y = barrier_gates[barrierid][bg_extra_trigger_y];
    z = barrier_gates[barrierid][bg_extra_trigger_z];
    return 1;
}


stock BarrierDelete(barrierid)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    if(IsValidDynamicObject(barrier_gates[barrierid][bg_MoveObject])) 
        DestroyDynamicObject(barrier_gates[barrierid][bg_MoveObject]);
    
    if(IsValidDynamicObject(barrier_gates[barrierid][bg_ExtraObject])) 
        DestroyDynamicObject(barrier_gates[barrierid][bg_ExtraObject]);
    
    if(barrier_gates[barrierid][bg_Text3D] != Text3D:INVALID_3DTEXT_ID) 
        DestroyDynamic3DTextLabel(barrier_gates[barrierid][bg_Text3D]);

    if(IsValidDynamicArea(barrier_gates[barrierid][bg_Sphere])) 
        DestroyDynamicArea(barrier_gates[barrierid][bg_Sphere]);    

    if(IsValidDynamicArea(barrier_gates[barrierid][bg_extra_sphere])) 
        DestroyDynamicArea(barrier_gates[barrierid][bg_extra_sphere]);    

    barrier_gates[barrierid][bg_Create] = false;
    barrier_gates[barrierid][bg_Function][0] = '\0';
    barrier_gates[barrierid][bg_MoveObject] = 0;
    barrier_gates[barrierid][bg_ExtraObject] = 0;
    barrier_gates[barrierid][bg_Text3D] = Text3D:INVALID_3DTEXT_ID;

    new attachid;
    if(barrier_gates[barrierid][bg_AttachFrom] != -1)
    {
        attachid = barrier_gates[barrierid][bg_AttachFrom];
        
        barrier_gates[barrierid][bg_AttachFrom] = -1;

        for(new at; at < BARRIER_MAX_ATTACH; at ++)
        {
            if(barrier_gates[attachid][bg_Attach][at] != barrierid) 
                continue;

            barrier_gates[attachid][bg_Attach][at] = -1;
            barrier_gates[attachid][bg_MaxAttach] --;
            break;
        }
    }

    if(barrier_gates[barrierid][bg_MaxAttach] >= 1)
    {
        for(new at; at < BARRIER_MAX_ATTACH; at ++)
        {
            if(barrier_gates[barrierid][bg_Attach][at] == -1) 
                continue;

            attachid = barrier_gates[barrierid][bg_Attach][at];    

            barrier_gates[barrierid][bg_Attach][at] = -1;
            barrier_gates[barrierid][bg_MaxAttach] --;


            barrier_gates[attachid][bg_AttachFrom] = -1;

            if(IsValidDynamicArea(barrier_gates[attachid][bg_Sphere])) 
                DestroyDynamicArea(barrier_gates[attachid][bg_Sphere]);

            barrier_gates[attachid][bg_Sphere] = CreateDynamicSphere(
                barrier_gates[attachid][bg_trigger_x], 
                barrier_gates[attachid][bg_trigger_y], 
                barrier_gates[attachid][bg_trigger_z],
                barrier_gates[attachid][bg_Radius], 
                barrier_gates[attachid][bg_Worldid], 
                barrier_gates[attachid][bg_Interiorid]);
            
            
            new eb_arr[3];
            eb_arr[BARRIER_DATA_AREA_ID] = barrier_gates[attachid][bg_Sphere];
            eb_arr[BARRIER_DATA_ID] = attachid;
            eb_arr[BARRIER_DATA_EXTRA] = 0;

            Streamer_SetArrayData(STREAMER_TYPE_AREA, barrier_gates[attachid][bg_Sphere], E_STREAMER_EXTRA_ID, eb_arr);
        }
    }

    return barrierid;
}


stock GetBarrierSlotID(const function[])
{
	if( !(0 < strlen(function) < BARRIER_MAX_FUNCTION_NAME) ) 
        return -1;

	for(new barrierid; barrierid < MAX_BARRIERS; barrierid ++)
	{
		if(!barrier_gates[barrierid][bg_Create]) 
            continue;

		if(strcmp(function, barrier_gates[barrierid][bg_Function], false)) 
            continue;
		
        return barrierid;
	}
	return -1;
}


stock BarrierCreateExtraObject(barrierid, object_model, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    if(IsValidDynamicObject(barrier_gates[barrierid][bg_ExtraObject])) 
        DestroyDynamicObject(barrier_gates[barrierid][bg_ExtraObject]);
    
    barrier_gates[barrierid][bg_ExtraObject] = CreateDynamicObject(object_model, x, y, z,  rx, ry, rz,  worldid, interiorid,  -1, BARRIER_OBJECT_DISTANCE, BARRIER_OBJECT_DISTANCE);
    return 1;
}


stock DeleteBarrierExtraObject(barrierid)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    if(IsValidDynamicObject(barrier_gates[barrierid][bg_ExtraObject])) 
        DestroyDynamicObject(barrier_gates[barrierid][bg_ExtraObject]);

    barrier_gates[barrierid][bg_ExtraObject] = 0;    
    return 1;
}


stock SetBarrierState(barrierid, barrier_state)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    barrier_gates[barrierid][bg_BarrierState] = barrier_state;
    return 1;
}


stock GetBarrierState(barrierid)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    return barrier_gates[barrierid][bg_BarrierState];
}


stock GetBarrierObjectID(barrierid, &moveid, &extraid = 0)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    moveid = barrier_gates[barrierid][bg_MoveObject];
    extraid = barrier_gates[barrierid][bg_ExtraObject];

    return moveid;
}


stock AttachBarrierToBarrier(barrierid, attachid)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create] || barrierid == attachid) 
        return -1;

    if(!(0 <= attachid < MAX_BARRIERS) || !barrier_gates[attachid][bg_Create]) 
        return -1;

    if(barrier_gates[attachid][bg_AttachFrom] != -1) 
        return -1;

    for(new at; at < BARRIER_MAX_ATTACH; at ++)
    {
        if(barrier_gates[barrierid][bg_Attach][at] != -1) 
            continue;

        barrier_gates[barrierid][bg_Attach][at] = attachid;
        barrier_gates[barrierid][bg_MaxAttach] ++;

        barrier_gates[attachid][bg_AttachFrom] = barrierid;

        if(IsValidDynamicArea(barrier_gates[attachid][bg_Sphere])) 
            DestroyDynamicArea(barrier_gates[attachid][bg_Sphere]);

        return 1;
    }

    return -1;
}


stock UnAttachBarrierFromBarrier(barrierid, attachid)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create] || barrierid == attachid) 
        return -1;

    if(!(0 <= attachid < MAX_BARRIERS) || !barrier_gates[attachid][bg_Create]) 
        return -1;

    if(barrier_gates[attachid][bg_AttachFrom] == -1) 
        return -1;

    for(new at; at < BARRIER_MAX_ATTACH; at ++)
    {
        if(barrier_gates[barrierid][bg_Attach][at] != attachid) 
            continue;

        barrier_gates[barrierid][bg_Attach][at] = -1;
        barrier_gates[barrierid][bg_MaxAttach] --;


        barrier_gates[attachid][bg_AttachFrom] = -1;

        if(IsValidDynamicArea(barrier_gates[attachid][bg_Sphere])) 
            DestroyDynamicArea(barrier_gates[attachid][bg_Sphere]);

        barrier_gates[attachid][bg_Sphere] = CreateDynamicSphere(
            barrier_gates[attachid][bg_trigger_x], 
            barrier_gates[attachid][bg_trigger_y], 
            barrier_gates[attachid][bg_trigger_z],
            barrier_gates[attachid][bg_Radius], 
            barrier_gates[attachid][bg_Worldid], 
            barrier_gates[attachid][bg_Interiorid]);
        
        
        new eb_arr[3];
        eb_arr[BARRIER_DATA_AREA_ID] = barrier_gates[attachid][bg_Sphere];
        eb_arr[BARRIER_DATA_ID] = attachid;
        eb_arr[BARRIER_DATA_EXTRA] = 0;

        Streamer_SetArrayData(STREAMER_TYPE_AREA, barrier_gates[attachid][bg_Sphere], E_STREAMER_EXTRA_ID, eb_arr);

        return 1;
    }

    return -1;
}


stock GetBarrierCompare(barrierid, function[])
{
	if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

	return !strcmp(function, barrier_gates[barrierid][bg_Function], false);
}


stock GetBarrierFunctionName(barrierid, function[], size_function = sizeof(function))
{
	if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

	format(function, size_function, barrier_gates[barrierid][bg_Function]);
    return 1;
}



stock SetBarrierKey(barrierid, key)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    barrier_gates[barrierid][bg_Key] = key;
    return 1;
}


stock GetBarrierKey(barrierid)
{
    if(!(0 <= barrierid < MAX_BARRIERS) || !barrier_gates[barrierid][bg_Create]) 
        return -1;

    return barrier_gates[barrierid][bg_Key];
}



#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
#else
	public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
#endif
{
    if(player_barrier_enter[playerid] != -1)
    {
        new barrierid = player_barrier_enter[playerid];

        if(!barrier_gates[barrierid][bg_Create] || 
            !IsPlayerInDynamicArea(playerid, barrier_gates[barrierid][bg_Sphere]) && 
            !IsPlayerInDynamicArea(playerid, barrier_gates[barrierid][bg_extra_sphere])) 
        {
            player_barrier_enter[playerid] = -1;
        }

        if(player_barrier_enter[playerid] != -1)
        {
            new eb_barrier_state = barrier_gates[barrierid][bg_BarrierState],
                eb_barrier_extra_state = barrier_gates[barrierid][bg_extra_trigger_state],
                eb_player_state = GetPlayerState(playerid);


            if(IsPlayerInDynamicArea(playerid, barrier_gates[barrierid][bg_Sphere]) && newkeys & barrier_gates[barrierid][bg_Key] && (eb_barrier_state == BARRIER_STATE_PLAYER_AND_DRIVER || eb_barrier_state == eb_player_state) ||
                IsPlayerInDynamicArea(playerid, barrier_gates[barrierid][bg_extra_sphere]) && newkeys & barrier_gates[barrierid][bg_extra_key] && (eb_barrier_extra_state == BARRIER_STATE_PLAYER_AND_DRIVER || eb_barrier_extra_state == eb_player_state))
            {
                if(barrier_gates[barrierid][bg_ClosingTimeStatic] != 0 && barrier_gates[barrierid][bg_Open] == true) 
                    return 1;

                // BarrierResponse
                if(CallLocalFunction(barrier_gates[barrierid][bg_Function], "dd", playerid, barrierid) == 1) 
                    return 1;
                
                if(barrier_gates[barrierid][bg_ClosingTimeStatic] == 0)
                {
                    if(barrier_gates[barrierid][bg_Open] == false) BarrierOpen(barrierid);
                    else BarrierClose(barrierid);
                    return 1;
                }

                if(barrier_gates[barrierid][bg_ClosingTime] != 0) 
                    return 1;

                BarrierOpen(barrierid);

                barrier_gates[barrierid][bg_ClosingTime] = barrier_gates[barrierid][bg_ClosingTimeStatic];
                SetTimerEx("BarrierClose", barrier_gates[barrierid][bg_ClosingTime] * 1000, false, "d", barrierid);
                return 1;
            }
        }
    }

    #if !defined _inc_y_hooks && !defined _INC_y_hooks && defined OnPlayerKeyState_easy_barrier
		return OnPlayerKeyState_easy_barrier(playerid, newkeys, oldkeys);
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
	#define OnPlayerKeyStateChange OnPlayerKeyState_easy_barrier

	#if defined OnPlayerKeyState_easy_barrier
		forward OnPlayerKeyState_easy_barrier(playerid, newkeys, oldkeys);
	#endif
#endif



#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerEnterDynamicArea(playerid, areaid)
#else
	public OnPlayerEnterDynamicArea(playerid, areaid)
#endif
{
    new eb_arr[3];
    Streamer_GetArrayData(STREAMER_TYPE_AREA, areaid, E_STREAMER_EXTRA_ID, eb_arr);

    if(areaid == eb_arr[BARRIER_DATA_AREA_ID])
    {
        new barrierid = eb_arr[BARRIER_DATA_ID],
            barrier_extra = eb_arr[BARRIER_DATA_EXTRA];

        if( barrier_extra == 0 && (barrier_gates[barrierid][bg_BarrierState] == BARRIER_STATE_PLAYER_AND_DRIVER || barrier_gates[barrierid][bg_BarrierState] == GetPlayerState(playerid)) || 
            barrier_extra == 1 && (barrier_gates[barrierid][bg_extra_trigger_state] == BARRIER_STATE_PLAYER_AND_DRIVER || barrier_gates[barrierid][bg_extra_trigger_state] == GetPlayerState(playerid)) )
        {
            player_barrier_enter[playerid] = barrierid;

            new keys = (barrier_extra == 0) ? (barrier_gates[barrierid][bg_Key]):(barrier_gates[barrierid][bg_extra_key]);
            #if defined OnBarrierEnter
                OnBarrierEnter(playerid, barrierid, keys);
            #endif
        }
    }


    #if !defined _inc_y_hooks && !defined _INC_y_hooks && defined OnEnterDynamicArea_easy_barrier
		return OnEnterDynamicArea_easy_barrier(playerid, areaid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerEnterDynamicArea
		#undef OnPlayerEnterDynamicArea
	#else
		#define _ALS_OnPlayerEnterDynamicArea
	#endif
	#define OnPlayerEnterDynamicArea OnEnterDynamicArea_easy_barrier

	#if defined OnEnterDynamicArea_easy_barrier
		forward OnEnterDynamicArea_easy_barrier(playerid, areaid);
	#endif
#endif



#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerLeaveDynamicArea(playerid, areaid)
#else
	public OnPlayerLeaveDynamicArea(playerid, areaid)
#endif
{
    new eb_arr[3];
    Streamer_GetArrayData(STREAMER_TYPE_AREA, areaid, E_STREAMER_EXTRA_ID, eb_arr);

    if(areaid == eb_arr[BARRIER_DATA_AREA_ID])
    {
        new barrierid = eb_arr[BARRIER_DATA_ID],
            barrier_extra = eb_arr[BARRIER_DATA_EXTRA];

        if( barrier_extra == 0 && (barrier_gates[barrierid][bg_BarrierState] == BARRIER_STATE_PLAYER_AND_DRIVER || barrier_gates[barrierid][bg_BarrierState] == GetPlayerState(playerid)) || 
            barrier_extra == 1 && (barrier_gates[barrierid][bg_extra_trigger_state] == BARRIER_STATE_PLAYER_AND_DRIVER || barrier_gates[barrierid][bg_extra_trigger_state] == GetPlayerState(playerid)) )
        {
            #if defined OnBarrierLeave
                OnBarrierLeave(playerid, barrierid);
            #endif
        }
    }


    #if !defined _inc_y_hooks && !defined _INC_y_hooks && defined OnLeaveDynamicArea_easy_barrier
		return OnLeaveDynamicArea_easy_barrier(playerid, areaid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerLeaveDynamicArea
		#undef OnPlayerLeaveDynamicArea
	#else
		#define _ALS_OnPlayerLeaveDynamicArea
	#endif
	#define OnPlayerLeaveDynamicArea OnLeaveDynamicArea_easy_barrier

	#if defined OnLeaveDynamicArea_easy_barrier
		forward OnLeaveDynamicArea_easy_barrier(playerid, areaid);
	#endif
#endif
