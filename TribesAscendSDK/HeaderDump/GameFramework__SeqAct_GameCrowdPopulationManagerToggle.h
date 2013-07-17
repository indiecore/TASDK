#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.SeqAct_GameCrowdPopulationManagerToggle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.SeqAct_GameCrowdPopulationManagerToggle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.SeqAct_GameCrowdPopulationManagerToggle." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_GameCrowdPopulationManagerToggle : public SequenceAction
	{
	public:
			ADD_VAR( ::FloatProperty, WarmupPct, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bClearOldArchetypes, 0x2 )
			ADD_OBJECT( GameCrowd_ListOfAgents, CrowdAgentList )
			ADD_VAR( ::FloatProperty, MaxSimulationDistance, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCastShadows, 0x8 )
			ADD_VAR( ::BoolProperty, bEnableCrowdLightEnvironment, 0x4 )
			ADD_VAR( ::FloatProperty, SpawnRate, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxAgents, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bKillAgentsInstantly, 0x1 )
			ADD_OBJECT( ScriptClass, PopulationManagerClass )
			void FindPopMgrTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.SeqAct_GameCrowdPopulationManagerToggle.FindPopMgrTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetObjClassVersion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.SeqAct_GameCrowdPopulationManagerToggle.GetObjClassVersion" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
