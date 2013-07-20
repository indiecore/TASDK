#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTCTFTeamAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTCTFTeamAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTCTFTeamAI." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTCTFTeamAI : public UTTeamAI
	{
	public:
			ADD_OBJECT( UTCTFFlag, FriendlyFlag )
			ADD_OBJECT( UTCTFFlag, EnemyFlag )
			ADD_VAR( ::FloatProperty, LastGotFlag, 0xFFFFFFFF )
			class UTSquadAI* AddSquadWithLeader( class Controller* C, class UTGameObjective* O )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCTFTeamAI.AddSquadWithLeader" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )params = C;
				*( class UTGameObjective** )( params + 4 ) = O;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTSquadAI** )( params + function->return_val_offset() );
			}

			class UTGameObjective* GetPriorityFreelanceObjectiveFor( class UTSquadAI* InFreelanceSquad )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCTFTeamAI.GetPriorityFreelanceObjectiveFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTSquadAI** )params = InFreelanceSquad;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTGameObjective** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
