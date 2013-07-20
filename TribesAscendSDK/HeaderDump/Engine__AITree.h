#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AITree." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AITree." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AITree." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AITree : public K2GraphBase
	{
	public:
			ADD_OBJECT( K2GraphBase, GatherList )
			bool SetActiveRoot( ScriptName InName, void* &Handle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AITree.SetActiveRoot" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( ScriptName* )params = InName;
				*( void** )( params + 8 ) = Handle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Handle = *( void** )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void* EvaluateTree( class AIController* InAI, void* &Handle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AITree.EvaluateTree" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( class AIController** )params = InAI;
				*( void** )( params + 4 ) = Handle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Handle = *( void** )( params + 4 );
				return *( void** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
