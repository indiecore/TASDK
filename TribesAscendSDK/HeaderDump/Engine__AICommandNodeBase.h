#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AICommandNodeBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AICommandNodeBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AICommandNodeBase." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AICommandNodeBase : public K2NodeBase
	{
	public:
			ADD_OBJECT( DMC_Prototype, UtilityDMC )
			ADD_OBJECT( ScriptClass, CommandClass )
			class AICommandNodeBase* SelectBestChild( class AIController* InAI, void* &Handle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AICommandNodeBase.SelectBestChild" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( class AIController** )( params + 0 ) = InAI;
				*( void** )( params + 4 ) = Handle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Handle = *( void** )( params + 4 );
				return *( class AICommandNodeBase** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
