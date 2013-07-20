#include "TASDK.h"
//#include "Armor.h"

const char *kLogName = "SDKTest.log";

using namespace UnrealScript;

inline float MetersToUnits( float meters )
{
	return meters * 50.0f;
}

/*HookType PlayerMove( TrPlayerController *controller, void *result, float delta_time )
{
	OutputLog( "delta_time: %f\n", delta_time );

	TrPawn *pawn = ( TrPawn* )( controller->var_Pawn() );
	pawn->var_CustomGravityScaling() = 0.0f;

	pawn->var_Velocity() = ( Vector )( pawn->var_Velocity() ) + Vector( 0, 0, MetersToUnits( -22.0f ) ) * delta_time;

	if( controller->var_m_bPressingJetpack() )
	{
		Rotator rotation = controller->var_Rotation();
		rotation.pitch = 0;

		Vector forward = rotation.GetForward();
		Vector right = rotation.GetRight();

		Vector move_direction;
		move_direction += controller->var_PlayerInput()->var_aForward() * forward;
		move_direction -= controller->var_PlayerInput()->var_aStrafe() * right;
		OutputLog( "move direction: %f %f %f\n", move_direction.x, move_direction.y, move_direction.z );

		if( move_direction.Length() )
			move_direction = move_direction.GetNormal();

		OutputLog( "move direction: %f %f %f\n", move_direction.x, move_direction.y, move_direction.z );

		Vector velocity = controller->var_Pawn()->var_Velocity();
		float orientation = velocity.DotProduct( move_direction );
		
		float side_power;
		float jet_forward = MetersToUnits( 30.0f );
		if( orientation > jet_forward )
			side_power = 0.0f;
		else if( orientation < 0.0f )
			side_power = LightArmor::jet_data.jet_side_pct;
		else
			side_power = ( 1 - ( orientation / jet_forward ) );

		side_power = min( side_power, 0.6f );

		float jet_force = MetersToUnits( 37.3f );
		Vector side_force = ( side_power * jet_force ) * move_direction;
		Vector up_force = Vector( 0, 0, ( ( 1 - side_power ) * jet_force ) );

		Vector accel = up_force + side_force;
		OutputLog( "accel: %f %f %f\n", accel.x, accel.y, accel.z );

		pawn->var_Velocity() += accel * delta_time;

		return kHookBlock;
	}

	return kHookContinue;
}*/

enum ClassTypes
{
	Light_PTH = 1683,
	Light_SEN = 1686,
	Light_INF = 1682,

	Medium_SLD = 1693,
	Medium_RDR = 1699,
	Medium_TCN = 1694,

	Heavy_JUG = 1692,
	Heavy_DMB = 1691,
	Heavy_BRT = 1689,

	Class_UNK = 0
};

HookType IsClassOwned( TrEquipInterface *equip, bool &result, int class_id )
{
	OutputLog( "IsClassOwned\n" );
	result = true;
	return kHookBlock;
}

HookType IsLoadoutOwned( TrEquipInterface *equip, bool &result, int class_id, int loadout_id )
{
	OutputLog( "IsLoadoutOwned\n" );
	result = true;
	return kHookBlock;
}

HookType GetClassCount( TrEquipInterface *equip, int &result )
{
	OutputLog( "GetClassCount\n" );
	result = 9;
	return kHookBlock;
}

HookType GetFirstClassId( TrEquipInterface *equip, int &result )
{
	OutputLog( "GetFirstClassId\n" );
	result = Light_PTH;
	return kHookBlock;
}

HookType GetNextClassId( TrEquipInterface *equip, int &result, int prev_class )
{
	OutputLog( "GetNextClassId\n" );
	result = Class_UNK;

	switch( prev_class )
	{
		case Light_PTH:		result = Light_SEN;		break;
		case Light_SEN:		result = Light_INF;		break;
		case Light_INF:		result = Medium_SLD;	break;
		case Medium_SLD:	result = Medium_RDR;	break;
		case Medium_RDR:	result = Medium_TCN;	break;
		case Medium_TCN:	result = Heavy_JUG;		break;
		case Heavy_JUG:		result = Heavy_DMB;		break;
		case Heavy_DMB:		result = Heavy_BRT;		break;
		case Heavy_BRT:		result = Class_UNK;		break;
	}

	return kHookBlock;
}

HookType InTraining( TrEquipInterface *equip, bool &result )
{
	OutputLog( "InTraining\n" );
	result = true;
	return kHookBlock;
}

HookType IsEquipOwned( TrEquipInterface *equip, bool &result, int class_id, int type, int equip_id )
{
	OutputLog( "IsEquipOwned\n" );
	result = true;
	return kHookBlock;
}

/*HookType GetEquipDevice( TrEquipInterface *equip, ScriptClass* &result, ScriptClass *family_info, byte equip_slot )
{
	if( equip_slot == 2 )
	{
		ScriptClass *device_class = ScriptObject::Find< ScriptClass >( "Class TribesGame.TrDevice_ChainGun" );
		result = device_class;
		return kHookBlock;
	}
	if( equip_slot == 3 )
	{
		ScriptClass *device_class = ScriptObject::Find< ScriptClass >( "Class TribesGame.TrDevice_Spinfusor" );
		result = device_class;
		return kHookBlock;
	}
	return kHookContinue;
}

HookType ClassHotkeyPTH( TrPlayerController *controller, void *result, float delta_time )
{
	TrPawn *pawn = ( TrPawn* )( controller->var_Pawn() );

	OutputLog( "Respawn time %f\n", controller->GetRespawnDelayTotalTime() );

	return kHookContinue;
}

HookType PlayerMove( TrPlayerController *controller, void *result, float delta_time )
{
	static bool once = true;

	if( once )
	{
		static ScriptClass *CoreClass = ScriptObject::Find< ScriptClass >( "Class Core.Class" );

		TrPawn *pawn = ( TrPawn* )( controller->var_Pawn() );
		TrInventoryManager *inv_manager = ( TrInventoryManager* )( pawn->var_InvManager() );

		TrDevice *primary = inv_manager->GetDeviceByEquipPoint( 2 );
		inv_manager->RemoveFromInventory( primary );
		primary->Destroy();

		Object *chaingun = controller->DynamicLoadObject( ScriptString( L"TribesGame.TrDevice_Chaingun" ), CoreClass, false ); 
		TrDevice *device_to_swap = ( TrDevice* )( controller->Spawn( ( ScriptClass* )( chaingun ), NULL, ScriptName(), Vector( 0, 0, 0 ), Rotator( 0, 0, 0 ), NULL, false ) );

		inv_manager->AddInventory( device_to_swap, false );
		device_to_swap->var_r_eEquipAt() = 2;
		device_to_swap->var_bNetDirty() = true;

		OutputLog( "done\n" );

		once = false;
	}

	return kHookContinue;
}*/

void ModInit()
{
	//script_hooks::AddHook( "Function TribesGame.TrPlayerController.PlayerWalking.PlayerMove", PlayerMove );
	ScriptObject *png = ScriptObject::Find< ScriptObject >( "Texture2D TribesHud.01_png" );
	

	script_hooks::AddHook( "Function TribesGame.TrEquipInterface.IsClassOwned", IsClassOwned );
	script_hooks::AddHook( "Function TribesGame.TrEquipInterface.GetClassCount", GetClassCount );
	script_hooks::AddHook( "Function TribesGame.TrEquipInterface.GetFirstClassId", GetFirstClassId );
	script_hooks::AddHook( "Function TribesGame.TrEquipInterface.GetNextClassId", GetNextClassId );
	script_hooks::AddHook( "Function TribesGame.TrEquipInterface.IsLoadoutOwned", IsLoadoutOwned );
	script_hooks::AddHook( "Function TribesGame.TrPlayerController.InTraining", InTraining );

	script_hooks::AddHook( "Function TribesGame.TrEquipInterface.IsEquipOwned", IsEquipOwned );
	//script_hooks::AddHook( "Function TribesGame.TrPlayerReplicationInfo.GetCharacterEquipLocal", GetEquipDevice );

	//ScriptObject::LogAll();

	//script_hooks::AddHook( "Function TribesGame.TrPlayerController.PlayerWalking.PlayerMove", PlayerMove );

	ScriptObject::GenerateHeaders();
}