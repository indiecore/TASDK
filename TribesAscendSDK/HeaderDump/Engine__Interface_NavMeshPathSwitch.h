#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Interface_NavMeshPathSwitch." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Interface_NavMeshPathSwitch." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Interface_NavMeshPathSwitch." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Interface_NavMeshPathSwitch : public Interface_NavMeshPathObject
	{
	public:
			bool AIActivateSwitch( class AIController* AI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Interface_NavMeshPathSwitch.AIActivateSwitch" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AIController** )params = AI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
