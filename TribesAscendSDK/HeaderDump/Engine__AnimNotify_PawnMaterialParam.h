#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNotify_PawnMaterialParam." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNotify_PawnMaterialParam." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNotify_PawnMaterialParam." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNotify_PawnMaterialParam : public AnimNotify_Scripted
	{
	public:
			void Notify( class Actor* Owner, class AnimNodeSequence* AnimSeqInstigator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNotify_PawnMaterialParam.Notify" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = Owner;
				*( class AnimNodeSequence** )( params + 4 ) = AnimSeqInstigator;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
