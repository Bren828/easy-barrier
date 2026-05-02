/*
*
*
*
*   ---------------------------------------------------
*
*	Creater - @Bren828	
*									02 May 2026
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


#if !defined EB_MAX_BARRIERS
    #define EB_MAX_BARRIERS 200
#endif

#if !defined EB_MAX_ATTACH
    #define EB_MAX_ATTACH 10
#endif

#if !defined EB_LENGTH_FUNCTION_NAME
	#define EB_LENGTH_FUNCTION_NAME 32
#endif

#if !defined EB_KEY_STATE_ONFOOT
    #define EB_KEY_STATE_ONFOOT KEY_WALK
#endif

#if !defined EB_KEY_STATE_DRIVER
    #define EB_KEY_STATE_DRIVER KEY_CROUCH 
#endif

#if !defined EB_3DTEXT_LENGTH
	#define EB_3DTEXT_LENGTH 144	
#endif

#if !defined EB_DISTANCE_OBJECT
	#define EB_DISTANCE_OBJECT 150.0 
#endif

#if !defined EB_SKIP_EXTRA_OBJECT
    //#define EB_SKIP_EXTRA_OBJECT //Înly for model 968, if you want to skip creating extra object for this model, uncomment this line
#endif


#define BarrierResponse:%0(%1) \
    forward %0(%1); \
    public %0(%1)


#define EB_STREAMER_CUSTOM_TYPE 0xFF32CDFA32

enum (<<= 1) {

    EB_INVALID_ID = -1,
    EB_STATE_PLAYER_AND_DRIVER = -1,
    EB_STATE_DRIVER_ONLY = 2,
    EB_STATE_PLAYER_ONLY = 1,

    EB_MOVEMENT_TYPE_OUTSIDE = 0,
    EB_MOVEMENT_TYPE_INSIDE = 1,
    EB_MOVEMENT_TYPE_RIGHT = 2,
    EB_MOVEMENT_TYPE_LEFT = 3,
    EB_MOVEMENT_TYPE_UP = 4,
    EB_MOVEMENT_TYPE_DOWN = 5,

    EB_STREAMER_TYPE = 0,
    EB_STREAMER_AREA_ID = 1,
    EB_STREAMER_BARRIER_ID = 2,
    EB_STREAMER_EXTRA = 3
}


enum E_BARRIER {

    bool:eb_Created,
    eb_Function[EB_LENGTH_FUNCTION_NAME],
    Float:eb_Radius,
    
    eb_MoveObject, 
    eb_ExtraObject,
    eb_Sphere,

    Float:eb_X,
    Float:eb_Y,
    Float:eb_Z,
    Float:eb_RX,
    Float:eb_RY,
    Float:eb_RZ,

    eb_World,
    eb_Interior,

    Float:eb_MoveX,
    Float:eb_MoveY,
    Float:eb_MoveZ,
    Float:eb_MoveRX,
    Float:eb_MoveRY,
    Float:eb_MoveRZ,
    Float:eb_MoveSpeed,

    Float:eb_TriggerX,
    Float:eb_TriggerY,
    Float:eb_TriggerZ,

    Text3D:eb_Text3D,
    bool:eb_Open,

    eb_Key,
    eb_ClosingTime,
    eb_DefaultClosingTime,
    eb_State,
    eb_Text[EB_3DTEXT_LENGTH],
    eb_AttachedIDs[EB_MAX_ATTACH],
    eb_ParentID,
    eb_MaxAttach,

    eb_ExtraSphere,
    eb_ExtraKey,
    Float:eb_ExtraTriggerRadius,
    eb_ExtraTriggerState,
    Float:eb_ExtraTriggerX,
    Float:eb_ExtraTriggerY,
    Float:eb_ExtraTriggerZ,
    bool:eb_Disabled,
}

static barrier[EB_MAX_BARRIERS][E_BARRIER];


enum E_BARRIER_OBJECT_DATA {

    bod_ModelID,
    Float:bod_Width,
    Float:bod_Height,
    bool:bod_UseXCoordinate,
    bod_DefaultType,
    Float:bod_DefaultPercent,

    Float:bod_DefaultTriggerX,
    Float:bod_DefaultTriggerY,
    Float:bod_DefaultTriggerZ,
}

static const barrier_object_data[][E_BARRIER_OBJECT_DATA] = {

    {977, 2.00, 3.21, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 1.0, 0.0, -0.8},
    {1493, 1.50, 2.49, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1495, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1496, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1497, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1498, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1500, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1501, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1965, 1.55, 3.00, false, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.0, 0.8, -0.5},
    {1504, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1505, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1506, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1507, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1508, 6.30, 3.36, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {1522, 1.50, 2.49, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1533, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1532, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1556, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1535, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1536, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1537, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, -0.8, 0.0, 0.8},
    {1538, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1555, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1557, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1966, 6.88, 5.53, true, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.3},
    {1967, 1.55, 3.00, false, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.0, -0.8, -0.5},
    {1560, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {1561, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, -0.8, 0.0, 0.8},
    {2634, 1.52, 2.29, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.0, 0.0, -0.8},
    {1566, 1.58, 3.02, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, -0.5},
    {1567, 1.50, 2.49, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {2664, 1.48, 2.35, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, -0.5},
    {1569, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {3294, 7.23, 5.82, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.5},
    {4084, 5.90, 3.64, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {8378, 67.51, 19.44, true, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -8.5},
    {5422, 4.21, 4.03, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.8},
    {5043, 4.00, 3.00, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {5340, 7.03, 3.10, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {5779, 5.23, 3.15, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {5856, 4.21, 4.03, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.0},
    {6400, 4.51, 4.65, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.0},
    {7927, 5.30, 2.49, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {7930, 9.17, 3.00, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {7931, 5.30, 2.49, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {9093, 7.38, 3.54, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {10182, 6.51, 3.42, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {10575, 6.92, 3.96, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.8},
    {8948, 7.38, 3.54, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {9625, 7.46, 5.78, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.3},
    {10154, 5.67, 5.59, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.3},
    {5302, 4.11, 4.65, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.5},
    {9099, 5.30, 2.49, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.8},
    {10149, 4.00, 3.00, true, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.0},
    {10246, 6.78, 3.48, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.0},
    {11102, 5.86, 4.32, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.5},
    {10671, 12.10, 3.74, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.2},
    {11313, 6.92, 3.96, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.2},
    {13187, 6.78, 2.59, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {13817, 4.50, 3.04, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.8},
    {11319, 7.23, 5.82, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.7},
    {11416, 5.13, 4.19, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.0},
    {13188, 4.82, 2.59, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {13028, 4.53, 3.81, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.8},
    {13360, 1.14, 2.15, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.0, 0.0, -0.5},
    {17951, 6.17, 3.55, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.8},
    {16773, 14.64, 8.01, true, EB_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -3.0},
    {17566, 3.91, 3.45, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.0},
    {16775, 14.64, 8.01, true, EB_MOVEMENT_TYPE_RIGHT, 100.0, 0.0, 0.0, -3.0},
    {18553, 3.90, 2.59, false, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {18757, 2.00, 2.91, false, EB_MOVEMENT_TYPE_LEFT, 100.0, -1.7, 1.0, -1.2},
    {18756, 2.02, 2.91, false, EB_MOVEMENT_TYPE_RIGHT, 100.0, -1.7, -1.0, -1.2},
    {19302, 1.75, 2.50, true, EB_MOVEMENT_TYPE_RIGHT, 100.0, 0.0, 0.0, -0.5},
    {19303, 1.75, 2.50, true, EB_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -0.5},
    {19799, 2.00, 3.00, true, EB_MOVEMENT_TYPE_INSIDE, 50.0, -1.0, 0.0, -0.8},
    {19802, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, 0.8},
    {19857, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, -0.5},
    {19858, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, -0.5},
    {19859, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, -0.5},
    {19860, 1.50, 2.50, true, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.8, 0.0, -0.5},
    {19861, 5.30, 2.50, true, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.7},
    {19862, 5.30, 2.50, true, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.7},
    {19863, 5.30, 2.50, true, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.7},
    {19864, 5.30, 2.50, true, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -1.7},
    {19870, 4.73, 3.53, true, EB_MOVEMENT_TYPE_RIGHT, 100.0, 2.4, 0.0, -1.0},
    {19910, 3.75, 2.40, true, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {19912, 11.53, 5.55, true, EB_MOVEMENT_TYPE_LEFT, 100.0, -5.5, 0.0, -1.7},
    {19906, 6.17, 3.22, true, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -2.0},
    {976, 8.85, 3.34, true, EB_MOVEMENT_TYPE_LEFT, 100.0, 4.3, 0.0, 0.8},
    {971, 10.85, 9.14, true, EB_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -2.2},
    {2988, 4.21, 3.91, false, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.0, -2.0, 0.8},
    {985, 7.88, 7.21, true, EB_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -0.5},
    {2928, 2.59, 2.50, true, EB_MOVEMENT_TYPE_UP, 100.0, 0.0, 0.0, -0.5},
    {2990, 10.11, 7.82, true, EB_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -2.2},
    {19795, 3.25, 3.45, false, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.0, -1.6, -1.0},
    {19796, 2.51, 3.51, false, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.0, -1.2, -1.0},
    {969, 8.85, 3.34, true, EB_MOVEMENT_TYPE_LEFT, 100.0, 4.5, 0.0, 0.8},
    {975, 8.85, 3.34, true, EB_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -0.5},
    {980, 11.53, 5.55, true, EB_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -1.5},
    {988, 5.48, 5.17, true, EB_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -0.2},
    {2930, 1.72, 2.64, false, EB_MOVEMENT_TYPE_LEFT, 100.0, 0.0, -0.8, -1.3},
    {3036, 4.84, 3.53, true, EB_MOVEMENT_TYPE_RIGHT, 100.0, 2.5, 0.0, -0.8},
    {989, 1.65, 3.65, false, EB_MOVEMENT_TYPE_LEFT, 100.0, 0.0, 0.0, -0.8},
    {19313, 13.98, 6.60, true, EB_MOVEMENT_TYPE_RIGHT, 100.0, 0.0, 0.0, -2.0},
    {968, 0.58, 7.13, false, EB_MOVEMENT_TYPE_UP, 100.0, 3.6, 0.0, 0.0},
    {3089, 1.50, 2.70, false, EB_MOVEMENT_TYPE_OUTSIDE, 50.0, 0.75, 0.0, -0.5}
};


static PlayerBarrierID[MAX_PLAYERS];


#define BarrierCreate CreateBarrier
#define BarrierDelete DestroyBarrier


stock CreateBarrier(const function[], Float:radius, Float:moveSpeed, closingSeconds, modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, barrierState = EB_STATE_PLAYER_AND_DRIVER, const text3D[] = "", text3DColor = -1, Float:text3DDistance = 6.0, Float:triggerX = 0.0, Float:triggerY = 0.0, Float:triggerZ = 0.0, key = 0) {

    if(!(0 < strlen(function) < EB_LENGTH_FUNCTION_NAME)) {
        return EB_INVALID_ID;
    }

    new barrierid = EB_INVALID_ID;

	for(new i; i < EB_MAX_BARRIERS; i ++) {
		if(barrier[i][eb_Created]) {
            continue;
        }

		barrierid = i;
		break;
	}

	if(barrierid == EB_INVALID_ID) {
        printf("easy-barrier --->>> | The maximum number of barriers has been created");
        return EB_INVALID_ID;
    }

    barrier[barrierid][eb_Created] = true;
    format(barrier[barrierid][eb_Function], EB_LENGTH_FUNCTION_NAME, function);
    barrier[barrierid][eb_Radius] = radius;
    barrier[barrierid][eb_MoveSpeed] = moveSpeed;
    barrier[barrierid][eb_DefaultClosingTime] = closingSeconds;

    barrier[barrierid][eb_X] = x;
    barrier[barrierid][eb_Y] = y;
    barrier[barrierid][eb_Z] = z;
    barrier[barrierid][eb_RX] = rx;
    barrier[barrierid][eb_RY] = ry;
    barrier[barrierid][eb_RZ] = rz;
    barrier[barrierid][eb_World] = worldid;
    barrier[barrierid][eb_Interior] = interiorid;

    barrier[barrierid][eb_MoveX] = x;
    barrier[barrierid][eb_MoveY] = y;
    barrier[barrierid][eb_MoveZ] = z;
    barrier[barrierid][eb_MoveRX] = rx;
    barrier[barrierid][eb_MoveRY] = ry;
    barrier[barrierid][eb_MoveRZ] = rz;

    if(key == 0) {
        barrier[barrierid][eb_Key] = (barrierState == EB_STATE_DRIVER_ONLY) ? (EB_KEY_STATE_DRIVER): (EB_KEY_STATE_ONFOOT);
    }
    else {
        barrier[barrierid][eb_Key] = key;
    }

    barrier[barrierid][eb_ClosingTime] = 0;
    barrier[barrierid][eb_State] = barrierState;
    barrier[barrierid][eb_Text3D] = Text3D:INVALID_3DTEXT_ID;

    for(new at; at < EB_MAX_ATTACH; at ++) {
        barrier[barrierid][eb_AttachedIDs][at] = EB_INVALID_ID;
    }
    barrier[barrierid][eb_ParentID] = EB_INVALID_ID;
    barrier[barrierid][eb_MaxAttach] = 0;
    barrier[barrierid][eb_ExtraObject] = 0;

    barrier[barrierid][eb_ExtraKey] = 0;
    barrier[barrierid][eb_ExtraTriggerState] = 0;
    barrier[barrierid][eb_ExtraTriggerRadius] = 0.0;
    barrier[barrierid][eb_ExtraTriggerX] = 0.0;
    barrier[barrierid][eb_ExtraTriggerY] = 0.0;
    barrier[barrierid][eb_ExtraTriggerZ] = 0.0;
    barrier[barrierid][eb_Disabled] = false;

    barrier[barrierid][eb_MoveObject] = CreateDynamicObject(modelid, 
        x, y, z,  
        rx, ry, rz,  
        worldid, interiorid, 
        -1, 
        EB_DISTANCE_OBJECT, EB_DISTANCE_OBJECT);

    #if defined OnBarrierObjectCreated
        OnBarrierObjectCreated(barrierid, barrier[barrierid][eb_MoveObject], modelid);
    #endif

    #if !defined EB_SKIP_EXTRA_OBJECT
        if(modelid == 968) {
            BarrierCreateExtraObject(barrierid, 966, 
                x, y, z - 0.8,
                rx, 0.0, rz + 180.0,
                worldid, interiorid);
        }
    #endif

    if(!SetBarrierOpeningType(barrierid, -1)) {
        barrier[barrierid][eb_TriggerX] = (triggerX != 0.0) ? (triggerX) : (x);
        barrier[barrierid][eb_TriggerY] = (triggerY != 0.0) ? (triggerY) : (y);
        barrier[barrierid][eb_TriggerZ] = (triggerZ != 0.0) ? (triggerZ) : (z);
    }
    else {
        if(triggerX != 0.0) {
            barrier[barrierid][eb_TriggerX] = triggerX;
        }
        if(triggerY != 0.0) {
            barrier[barrierid][eb_TriggerY] = triggerY;
        }
        if(triggerZ != 0.0) {
            barrier[barrierid][eb_TriggerZ] = triggerZ;
        }
    }

    barrier[barrierid][eb_Sphere] = CreateDynamicSphere(
        barrier[barrierid][eb_TriggerX], 
        barrier[barrierid][eb_TriggerY], 
        barrier[barrierid][eb_TriggerZ], 
        radius, 
        worldid, 
        interiorid);
    EB_SetSphereData(barrier[barrierid][eb_Sphere], barrierid, 0);

	if(strlen(text3D) >= 1) {
        format(barrier[barrierid][eb_Text], EB_3DTEXT_LENGTH, text3D);

        barrier[barrierid][eb_Text3D] = CreateDynamic3DTextLabel(text3D, 
            text3DColor, 
            barrier[barrierid][eb_TriggerX], 
            barrier[barrierid][eb_TriggerY], 
            barrier[barrierid][eb_TriggerZ] + 0.3, 
            text3DDistance, 
            INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 
            0, 
            worldid, 
            interiorid, 
            -1, 
            text3DDistance);
    }

    return barrierid;
}


static stock EB_SetSphereData(sphereid, barrierid, extra) {
    new eb_data[4];

    eb_data[EB_STREAMER_TYPE] = EB_STREAMER_CUSTOM_TYPE;
    eb_data[EB_STREAMER_AREA_ID] = sphereid;
    eb_data[EB_STREAMER_BARRIER_ID] = barrierid;
    eb_data[EB_STREAMER_EXTRA] = extra;

    Streamer_SetArrayData(STREAMER_TYPE_AREA, sphereid, E_STREAMER_EXTRA_ID, eb_data);
    return 1;
}


stock IsValidBarrier(barrierid) {

    if(!(0 <= barrierid < EB_MAX_BARRIERS) || !barrier[barrierid][eb_Created]) {
        return false;
    }

    return true;
}


stock BarrierOpen(barrierid) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    if(IsBarrierOpen(barrierid)) {
        return EB_INVALID_ID;
    }

    MoveDynamicObject(barrier[barrierid][eb_MoveObject], 
        barrier[barrierid][eb_MoveX], 
        barrier[barrierid][eb_MoveY], 
        barrier[barrierid][eb_MoveZ] - 0.020, 

        barrier[barrierid][eb_MoveSpeed],
        barrier[barrierid][eb_MoveRX], 
        barrier[barrierid][eb_MoveRY], 
        barrier[barrierid][eb_MoveRZ]);

    barrier[barrierid][eb_Open] = true;

    if(barrier[barrierid][eb_MaxAttach]) {
        new attachid;

        for(new at; at < EB_MAX_ATTACH; at ++) {
            if(barrier[barrierid][eb_AttachedIDs][at] == EB_INVALID_ID) {
                continue;
            }

            attachid = barrier[barrierid][eb_AttachedIDs][at];

            MoveDynamicObject(barrier[attachid][eb_MoveObject], 
                barrier[attachid][eb_MoveX], 
                barrier[attachid][eb_MoveY], 
                barrier[attachid][eb_MoveZ] - 0.020, 

                barrier[attachid][eb_MoveSpeed],
                barrier[attachid][eb_MoveRX], 
                barrier[attachid][eb_MoveRY], 
                barrier[attachid][eb_MoveRZ]);

            barrier[attachid][eb_Open] = true;
        }
    }

    return 1;
}


forward BarrierClose(barrierid);
public BarrierClose(barrierid) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    if(!IsBarrierOpen(barrierid)) {
        return EB_INVALID_ID;
    }

    if(IsBarrierDisabled(barrierid)) {
        return 0;  
    }

    MoveDynamicObject(barrier[barrierid][eb_MoveObject],
        barrier[barrierid][eb_X], 
        barrier[barrierid][eb_Y], 
        barrier[barrierid][eb_Z], 

        barrier[barrierid][eb_MoveSpeed], 
        barrier[barrierid][eb_RX], 
        barrier[barrierid][eb_RY], 
        barrier[barrierid][eb_RZ]);

    barrier[barrierid][eb_Open] = false;
	barrier[barrierid][eb_ClosingTime] = 0;

    if(barrier[barrierid][eb_MaxAttach]) {
        new attachid;

        for(new at; at < EB_MAX_ATTACH; at ++) {
            if(barrier[barrierid][eb_AttachedIDs][at] == EB_INVALID_ID) {
                continue;
            }

            attachid = barrier[barrierid][eb_AttachedIDs][at];

            MoveDynamicObject(barrier[attachid][eb_MoveObject],
                barrier[attachid][eb_X], 
                barrier[attachid][eb_Y], 
                barrier[attachid][eb_Z], 

                barrier[attachid][eb_MoveSpeed], 
                barrier[attachid][eb_RX], 
                barrier[attachid][eb_RY], 
                barrier[attachid][eb_RZ]);

            barrier[attachid][eb_Open] = false;
            barrier[attachid][eb_ClosingTime] = 0;
        }
    }

    return 1;
}


stock IsBarrierOpen(barrierid) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }
    
    return barrier[barrierid][eb_Open];
}


stock SetBarrierMovementX(barrierid, Float:x) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    barrier[barrierid][eb_MoveX] = x;
    return 1;
}


stock SetBarrierMovementY(barrierid, Float:y) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    barrier[barrierid][eb_MoveY] = y;
    return 1;
}


stock SetBarrierMovementZ(barrierid, Float:z) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    barrier[barrierid][eb_MoveZ] = z;
    return 1;
}


stock SetBarrierMovementRX(barrierid, Float:rx) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    barrier[barrierid][eb_MoveRX] = rx;
    return 1;
}


stock SetBarrierMovementRY(barrierid, Float:ry) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    barrier[barrierid][eb_MoveRY] = ry;
    return 1;
}


stock SetBarrierMovementRZ(barrierid, Float:rz) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    barrier[barrierid][eb_MoveRZ] = rz;
    return 1;
}


stock SetBarrierOpeningType(barrierid, type, Float:percent = 100.0) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    if(!(-1 <= type <= 5)) {
        return EB_INVALID_ID;
    }
    
    new eb_modelid = Streamer_GetIntData(STREAMER_TYPE_OBJECT, barrier[barrierid][eb_MoveObject], E_STREAMER_MODEL_ID);
    
    for(new i; i < sizeof(barrier_object_data); i ++) {

        if(eb_modelid != barrier_object_data[i][bod_ModelID]) {
            continue;
        }
        
        barrier[barrierid][eb_MoveX] = barrier[barrierid][eb_X];
        barrier[barrierid][eb_MoveY] = barrier[barrierid][eb_Y];
        barrier[barrierid][eb_MoveZ] = barrier[barrierid][eb_Z];
        barrier[barrierid][eb_MoveRZ] = barrier[barrierid][eb_RZ];

        if(type == -1) {
            type = barrier_object_data[i][bod_DefaultType];
            percent = barrier_object_data[i][bod_DefaultPercent];

            new Float:rz = 360 - barrier[barrierid][eb_RZ];
            
            barrier[barrierid][eb_TriggerX] = (floatsin(rz, degrees) * barrier_object_data[i][bod_DefaultTriggerY] + floatcos(rz, degrees) * barrier_object_data[i][bod_DefaultTriggerX] + barrier[barrierid][eb_X]);
            barrier[barrierid][eb_TriggerY] = (floatcos(rz, degrees) * barrier_object_data[i][bod_DefaultTriggerY] - floatsin(rz, degrees) * barrier_object_data[i][bod_DefaultTriggerX] + barrier[barrierid][eb_Y]);
            barrier[barrierid][eb_TriggerZ] = barrier[barrierid][eb_Z] + barrier_object_data[i][bod_DefaultTriggerZ];
        }

        if(eb_modelid == 968) {
            barrier[barrierid][eb_MoveRY] = barrier[barrierid][eb_RY] - (barrier[barrierid][eb_RY] * percent) / 100;
            return 1;
        }

        switch(type) {

            case EB_MOVEMENT_TYPE_RIGHT, EB_MOVEMENT_TYPE_LEFT: {

                new Float:x = barrier[barrierid][eb_X],
                    Float:y = barrier[barrierid][eb_Y],
                    Float:rz = 360 - barrier[barrierid][eb_RZ];

                new Float:xoff, 
                    Float:yoff;

                new Float:scale = (type == EB_MOVEMENT_TYPE_LEFT) ? ((barrier_object_data[i][bod_Width] * percent) / 100) : (-(barrier_object_data[i][bod_Width] * percent) / 100);

                if(barrier_object_data[i][bod_UseXCoordinate]) {
                    xoff = scale;
                }
                else {
                    yoff = scale;
                }

                barrier[barrierid][eb_MoveX] = (floatsin(rz, degrees) * yoff + floatcos(rz, degrees) * xoff + x);
                barrier[barrierid][eb_MoveY] = (floatcos(rz, degrees) * yoff - floatsin(rz, degrees) * xoff + y);
            }

            case EB_MOVEMENT_TYPE_UP: { 
                barrier[barrierid][eb_MoveZ] = barrier[barrierid][eb_Z] + ((barrier_object_data[i][bod_Height] * percent) / 100);
            }

            case EB_MOVEMENT_TYPE_DOWN: { 
                barrier[barrierid][eb_MoveZ] = barrier[barrierid][eb_Z] - ((barrier_object_data[i][bod_Height] * percent) / 100);
            }
            
            case EB_MOVEMENT_TYPE_OUTSIDE: { 
                barrier[barrierid][eb_MoveRZ] = barrier[barrierid][eb_RZ] + ((180.0 * percent) / 100);
            }

            case EB_MOVEMENT_TYPE_INSIDE: { 
                barrier[barrierid][eb_MoveRZ] = barrier[barrierid][eb_RZ] - ((180.0 * percent) / 100);
            }
        }

        return 1;
    }

    return 0;
}


stock SetBarrierMove(barrierid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    barrier[barrierid][eb_MoveX] = (x != -1.0) ? (x): (barrier[barrierid][eb_MoveX]);
    barrier[barrierid][eb_MoveY] = (y != -1.0) ? (y): (barrier[barrierid][eb_MoveY]);
    barrier[barrierid][eb_MoveZ] = (z != -1.0) ? (z): (barrier[barrierid][eb_MoveZ]);

    barrier[barrierid][eb_MoveRX] = (rx != -1.0) ? (rx):(barrier[barrierid][eb_MoveRX]);
    barrier[barrierid][eb_MoveRY] = (ry != -1.0) ? (ry):(barrier[barrierid][eb_MoveRY]);
    barrier[barrierid][eb_MoveRZ] = (rz != -1.0) ? (rz):(barrier[barrierid][eb_MoveRZ]);
    return 1;
}


stock UpdateBarrierText(barrierid, const text[], color = 0) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    if(barrier[barrierid][eb_Text3D] == Text3D:INVALID_3DTEXT_ID) {
        return EB_INVALID_ID;
    }

    format(barrier[barrierid][eb_Text], EB_3DTEXT_LENGTH, text);
    UpdateDynamic3DTextLabelText(barrier[barrierid][eb_Text3D], -1, text);

    if(color != 0) {
        Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, barrier[barrierid][eb_Text3D], E_STREAMER_COLOR, color);
    }
    return 1;
}


stock GetBarrierText(barrierid, text[], size = sizeof(text)) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    if(barrier[barrierid][eb_Text3D] == Text3D:INVALID_3DTEXT_ID) {
        return EB_INVALID_ID;
    }

    format(text, size, barrier[barrierid][eb_Text]);
    return 1;
}


stock SetBarrierTextColor(barrierid, color) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    if(barrier[barrierid][eb_Text3D] == Text3D:INVALID_3DTEXT_ID) {
        return EB_INVALID_ID;
    }

    Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, barrier[barrierid][eb_Text3D], E_STREAMER_COLOR, color);
    return 1;
}


stock GetBarrierTextColor(barrierid) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    if(barrier[barrierid][eb_Text3D] == Text3D:INVALID_3DTEXT_ID) {
        return EB_INVALID_ID;
    }

    return Streamer_GetIntData(STREAMER_TYPE_3D_TEXT_LABEL, barrier[barrierid][eb_Text3D], E_STREAMER_COLOR);
}


stock SetBarrierTextPosition(barrierid, Float:x, Float:y, Float:z) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, barrier[barrierid][eb_Text3D], E_STREAMER_X, x);
    Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, barrier[barrierid][eb_Text3D], E_STREAMER_Y, y);
    Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, barrier[barrierid][eb_Text3D], E_STREAMER_Z, z);
    return 1;
}


stock SetBarrierClosingTime(barrierid, seconds) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    if(!(0 <= seconds <= 90000000)) {
        return EB_INVALID_ID;
    }

    barrier[barrierid][eb_DefaultClosingTime] = seconds;
    return 1;
}


stock GetBarrierClosingTime(barrierid) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    return barrier[barrierid][eb_DefaultClosingTime];
}


stock SetBarrierMoveSpeed(barrierid, Float:speed) {
    
    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    barrier[barrierid][eb_MoveSpeed] = speed;
    return 1;
}


stock Float:GetBarrierMoveSpeed(barrierid) {

    if(!IsValidBarrier(barrierid)) {
        return float(EB_INVALID_ID);
    }

    return barrier[barrierid][eb_MoveSpeed];
}


stock SetBarrierTrigger(barrierid, Float:x, Float:y, Float:z) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }
   
    barrier[barrierid][eb_TriggerX] = x;
    barrier[barrierid][eb_TriggerY] = y;
    barrier[barrierid][eb_TriggerZ] = z;

    if(IsValidDynamicArea(barrier[barrierid][eb_Sphere])) {
        Streamer_SetFloatData(STREAMER_TYPE_AREA, barrier[barrierid][eb_Sphere], E_STREAMER_X, x);
        Streamer_SetFloatData(STREAMER_TYPE_AREA, barrier[barrierid][eb_Sphere], E_STREAMER_Y, y);
        Streamer_SetFloatData(STREAMER_TYPE_AREA, barrier[barrierid][eb_Sphere], E_STREAMER_Z, z);
    }

    return 1;
}


stock GetBarrierTrigger(barrierid, &Float:x, &Float:y, &Float:z) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    x = barrier[barrierid][eb_TriggerX];
    y = barrier[barrierid][eb_TriggerY];
    z = barrier[barrierid][eb_TriggerZ];
    return 1;
}


stock SetBarrierTriggerExtra(barrierid, Float:x, Float:y, Float:z, Float:radius, barrierState = EB_STATE_PLAYER_ONLY, key = EB_KEY_STATE_ONFOOT) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    if(barrierState != EB_STATE_PLAYER_AND_DRIVER && barrierState != EB_STATE_DRIVER_ONLY && barrierState != EB_STATE_PLAYER_ONLY) {
        return EB_INVALID_ID;
    }

    if(IsValidDynamicArea(barrier[barrierid][eb_ExtraSphere])) {
        DestroyDynamicArea(barrier[barrierid][eb_ExtraSphere]);
    }

    barrier[barrierid][eb_ExtraSphere] = CreateDynamicSphere(x, y, z, radius, barrier[barrierid][eb_World], barrier[barrierid][eb_Interior]);

    EB_SetSphereData(barrier[barrierid][eb_ExtraSphere], barrierid, 1);

    barrier[barrierid][eb_ExtraKey] = key; 
    barrier[barrierid][eb_ExtraTriggerRadius] = radius;
    barrier[barrierid][eb_ExtraTriggerState] = barrierState;

    barrier[barrierid][eb_ExtraTriggerX] = x;
    barrier[barrierid][eb_ExtraTriggerY] = y;
    barrier[barrierid][eb_ExtraTriggerZ] = z;
    return 1;
}


stock GetBarrierTriggerExtra(barrierid, &Float:x, &Float:y, &Float:z, &Float:radius = 0.0, &barrierState = 0, &key = 0) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    radius = barrier[barrierid][eb_ExtraTriggerRadius];
    barrierState = barrier[barrierid][eb_ExtraTriggerState];
    key = barrier[barrierid][eb_ExtraKey];

    x = barrier[barrierid][eb_ExtraTriggerX];
    y = barrier[barrierid][eb_ExtraTriggerY];
    z = barrier[barrierid][eb_ExtraTriggerZ];
    return 1;
}


stock DestroyBarrier(barrierid) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    if(IsValidDynamicObject(barrier[barrierid][eb_MoveObject])) {
        DestroyDynamicObject(barrier[barrierid][eb_MoveObject]);
    }
    
    if(IsValidDynamicObject(barrier[barrierid][eb_ExtraObject])) {
        DestroyDynamicObject(barrier[barrierid][eb_ExtraObject]);
    }
    
    if(barrier[barrierid][eb_Text3D] != Text3D:INVALID_3DTEXT_ID) {
        DestroyDynamic3DTextLabel(barrier[barrierid][eb_Text3D]);
    }

    if(IsValidDynamicArea(barrier[barrierid][eb_Sphere])) {
        DestroyDynamicArea(barrier[barrierid][eb_Sphere]);
    }

    if(IsValidDynamicArea(barrier[barrierid][eb_ExtraSphere])) {
        DestroyDynamicArea(barrier[barrierid][eb_ExtraSphere]);
    }

    barrier[barrierid][eb_Created] = false;
    barrier[barrierid][eb_Function][0] = '\0';
    barrier[barrierid][eb_MoveObject] = 0;
    barrier[barrierid][eb_ExtraObject] = 0;
    barrier[barrierid][eb_Text3D] = Text3D:INVALID_3DTEXT_ID;

    new attachid;
    if(barrier[barrierid][eb_ParentID] != EB_INVALID_ID) {

        attachid = barrier[barrierid][eb_ParentID];
        barrier[barrierid][eb_ParentID] = EB_INVALID_ID;

        for(new at; at < EB_MAX_ATTACH; at ++) {

            if(barrier[attachid][eb_AttachedIDs][at] != barrierid) {
                continue;
            }

            barrier[attachid][eb_AttachedIDs][at] = EB_INVALID_ID;
            barrier[attachid][eb_MaxAttach] --;
            break;
        }
    }

    if(barrier[barrierid][eb_MaxAttach]) {

        for(new at; at < EB_MAX_ATTACH; at ++) {

            if(barrier[barrierid][eb_AttachedIDs][at] == EB_INVALID_ID) {
                continue;
            }

            attachid = barrier[barrierid][eb_AttachedIDs][at];    

            barrier[barrierid][eb_AttachedIDs][at] = EB_INVALID_ID;
            barrier[barrierid][eb_MaxAttach] --;

            barrier[attachid][eb_ParentID] = EB_INVALID_ID;

            if(IsValidDynamicArea(barrier[attachid][eb_Sphere])) {
                DestroyDynamicArea(barrier[attachid][eb_Sphere]);
            }

            barrier[attachid][eb_Sphere] = CreateDynamicSphere(
                barrier[attachid][eb_TriggerX], 
                barrier[attachid][eb_TriggerY], 
                barrier[attachid][eb_TriggerZ],
                barrier[attachid][eb_Radius], 
                barrier[attachid][eb_World], 
                barrier[attachid][eb_Interior]);
            
            EB_SetSphereData(barrier[attachid][eb_Sphere], attachid, 0);
        }
    }

    return barrierid;
}


stock GetBarrierIDByFunction(const function[]) {

	if(!(0 < strlen(function) < EB_LENGTH_FUNCTION_NAME) ) {
        return EB_INVALID_ID;
    }

	for(new barrierid; barrierid < EB_MAX_BARRIERS; barrierid ++) {

		if(!barrier[barrierid][eb_Created]) {
            continue;
        }

		if(strcmp(function, barrier[barrierid][eb_Function], false)) {
            continue;
        }
		
        return barrierid;
	}

	return EB_INVALID_ID;
}


stock BarrierCreateExtraObject(barrierid, modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    if(IsValidDynamicObject(barrier[barrierid][eb_ExtraObject])) {
        DestroyDynamicObject(barrier[barrierid][eb_ExtraObject]);
    }
    
    barrier[barrierid][eb_ExtraObject] = CreateDynamicObject(modelid, 
        x, y, z, 
        rx, ry, rz,  
        worldid, interiorid,  
        -1, 
        EB_DISTANCE_OBJECT, EB_DISTANCE_OBJECT);

    return 1;
}


stock DestroyBarrierExtraObject(barrierid) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    if(IsValidDynamicObject(barrier[barrierid][eb_ExtraObject])) {
        DestroyDynamicObject(barrier[barrierid][eb_ExtraObject]);
    }

    barrier[barrierid][eb_ExtraObject] = 0;    
    return 1;
}


stock SetBarrierState(barrierid, barrierState) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    barrier[barrierid][eb_State] = barrierState;
    return 1;
}


stock GetBarrierState(barrierid) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    return barrier[barrierid][eb_State];
}


stock GetBarrierObjectID(barrierid, &moveid, &extraid = 0) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    moveid = barrier[barrierid][eb_MoveObject];
    extraid = barrier[barrierid][eb_ExtraObject];

    return moveid;
}


stock AttachBarrierToBarrier(barrierid, attachid) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    if(!IsValidBarrier(attachid)) {
        return EB_INVALID_ID;
    }

    if(barrierid == attachid) {
        return EB_INVALID_ID;
    }

    if(barrier[attachid][eb_ParentID] != EB_INVALID_ID) {
        return EB_INVALID_ID;
    }

    for(new at; at < EB_MAX_ATTACH; at ++) {

        if(barrier[barrierid][eb_AttachedIDs][at] != EB_INVALID_ID) {
            continue;
        }

        barrier[barrierid][eb_AttachedIDs][at] = attachid;
        barrier[barrierid][eb_MaxAttach] ++;

        barrier[attachid][eb_ParentID] = barrierid;

        if(IsValidDynamicArea(barrier[attachid][eb_Sphere])) {
            DestroyDynamicArea(barrier[attachid][eb_Sphere]);
        }

        return 1;
    }

    return EB_INVALID_ID;
}


stock UnAttachBarrierFromBarrier(barrierid, attachid) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    if(!IsValidBarrier(attachid)) {
        return EB_INVALID_ID;
    }

    if(barrierid == attachid) {
        return EB_INVALID_ID;
    }

    if(barrier[attachid][eb_ParentID] == EB_INVALID_ID) {
        return EB_INVALID_ID;
    }

    for(new at; at < EB_MAX_ATTACH; at ++) {

        if(barrier[barrierid][eb_AttachedIDs][at] != attachid) {
            continue;
        }

        barrier[barrierid][eb_AttachedIDs][at] = EB_INVALID_ID;
        barrier[barrierid][eb_MaxAttach] --;

        barrier[attachid][eb_ParentID] = EB_INVALID_ID;

        if(IsValidDynamicArea(barrier[attachid][eb_Sphere])) {
            DestroyDynamicArea(barrier[attachid][eb_Sphere]);
        }

        barrier[attachid][eb_Sphere] = CreateDynamicSphere(
            barrier[attachid][eb_TriggerX], 
            barrier[attachid][eb_TriggerY], 
            barrier[attachid][eb_TriggerZ],
            barrier[attachid][eb_Radius], 
            barrier[attachid][eb_World], 
            barrier[attachid][eb_Interior]);
        
        EB_SetSphereData(barrier[attachid][eb_Sphere], attachid, 0);
        return 1;
    }

    return EB_INVALID_ID;
}


stock IsBarrierFunction(barrierid, const function[]) {

	if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

	return !strcmp(function, barrier[barrierid][eb_Function], false);
}


stock GetBarrierFunctionName(barrierid, function[], size_function = sizeof(function)) {

	if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

	format(function, size_function, barrier[barrierid][eb_Function]);
    return 1;
}


stock SetBarrierKey(barrierid, key) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    barrier[barrierid][eb_Key] = key;
    return 1;
}


stock GetBarrierKey(barrierid) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    return barrier[barrierid][eb_Key];
}


stock DisableBarrier(barrierid, bool:disable) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    barrier[barrierid][eb_Disabled] = disable; 
    return 1;
}


stock IsBarrierDisabled(barrierid) {

    if(!IsValidBarrier(barrierid)) {
        return EB_INVALID_ID;
    }

    return barrier[barrierid][eb_Disabled]; 
}



#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
#else
	public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
#endif
{
    if(PlayerBarrierID[playerid] != EB_INVALID_ID) {

        new barrierid = PlayerBarrierID[playerid];

        if(!barrier[barrierid][eb_Created] || 
           !IsPlayerInDynamicArea(playerid, barrier[barrierid][eb_Sphere]) && !IsPlayerInDynamicArea(playerid, barrier[barrierid][eb_ExtraSphere])) {
            PlayerBarrierID[playerid] = EB_INVALID_ID;
        }

        if(PlayerBarrierID[playerid] != EB_INVALID_ID) {

            new eb_state = barrier[barrierid][eb_State],
                eb_extra_state = barrier[barrierid][eb_ExtraTriggerState];

            new eb_player_state = GetPlayerState(playerid);

            if(IsPlayerInDynamicArea(playerid, barrier[barrierid][eb_Sphere]) && newkeys & barrier[barrierid][eb_Key] && (eb_state == EB_STATE_PLAYER_AND_DRIVER || eb_state == eb_player_state) ||
               IsPlayerInDynamicArea(playerid, barrier[barrierid][eb_ExtraSphere]) && newkeys & barrier[barrierid][eb_ExtraKey] && (eb_extra_state == EB_STATE_PLAYER_AND_DRIVER || eb_extra_state == eb_player_state))
            {
                if(barrier[barrierid][eb_DefaultClosingTime] != 0 && IsBarrierOpen(barrierid)) {
                    return 1;
                }

                // BarrierResponse
                if(CallLocalFunction(barrier[barrierid][eb_Function], "dd", playerid, barrierid) == 1) {
                    return 1;
                }

                if(IsBarrierDisabled(barrierid)) {
                    return 1;
                }
                
                if(barrier[barrierid][eb_DefaultClosingTime] == 0) {

                    if(!IsBarrierOpen(barrierid)) {
                        BarrierOpen(barrierid);
                    }
                    else {
                        BarrierClose(barrierid);
                    }
                    return 1;
                }

                if(barrier[barrierid][eb_ClosingTime] != 0) {
                    return 1;
                }

                BarrierOpen(barrierid);

                barrier[barrierid][eb_ClosingTime] = barrier[barrierid][eb_DefaultClosingTime];
                SetTimerEx("BarrierClose", barrier[barrierid][eb_ClosingTime] * 1000, false, "d", barrierid);
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
    new eb_data[4];
    Streamer_GetArrayData(STREAMER_TYPE_AREA, areaid, E_STREAMER_EXTRA_ID, eb_data);

    if(eb_data[EB_STREAMER_TYPE] == EB_STREAMER_CUSTOM_TYPE && areaid == eb_data[EB_STREAMER_AREA_ID]) {

        new barrierid = eb_data[EB_STREAMER_BARRIER_ID],
            eb_extra = eb_data[EB_STREAMER_EXTRA];

        if(eb_extra == 0 && (barrier[barrierid][eb_State] == EB_STATE_PLAYER_AND_DRIVER || barrier[barrierid][eb_State] == GetPlayerState(playerid)) || 
           eb_extra == 1 && (barrier[barrierid][eb_ExtraTriggerState] == EB_STATE_PLAYER_AND_DRIVER || barrier[barrierid][eb_ExtraTriggerState] == GetPlayerState(playerid)))
        {
            PlayerBarrierID[playerid] = barrierid;

            #if defined OnBarrierEnter
                new keys = barrier[barrierid][eb_Key];

                if(eb_extra != 0) {
                    keys = barrier[barrierid][eb_ExtraKey];
                }

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
    new eb_data[4];
    Streamer_GetArrayData(STREAMER_TYPE_AREA, areaid, E_STREAMER_EXTRA_ID, eb_data);

    if(eb_data[EB_STREAMER_TYPE] == EB_STREAMER_CUSTOM_TYPE && areaid == eb_data[EB_STREAMER_AREA_ID]) {

        new barrierid = eb_data[EB_STREAMER_BARRIER_ID],
            eb_extra = eb_data[EB_STREAMER_EXTRA];

        if(eb_extra == 0 && (barrier[barrierid][eb_State] == EB_STATE_PLAYER_AND_DRIVER || barrier[barrierid][eb_State] == GetPlayerState(playerid)) || 
           eb_extra == 1 && (barrier[barrierid][eb_ExtraTriggerState] == EB_STATE_PLAYER_AND_DRIVER || barrier[barrierid][eb_ExtraTriggerState] == GetPlayerState(playerid)))
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
