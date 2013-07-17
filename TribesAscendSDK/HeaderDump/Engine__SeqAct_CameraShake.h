#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqAct_CameraShake." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqAct_CameraShake." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqAct_CameraShake." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_CameraShake : public SequenceAction
	{
	public:
			ADD_VAR( ::BoolProperty, bRadialShake, 0x2 )
			ADD_OBJECT( Actor, LocationActor )
			ADD_OBJECT( CameraShake, Shake )
			ADD_VAR( ::FloatProperty, RadialShake_InnerRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RadialShake_OuterRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RadialShake_Falloff, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDoControllerVibration, 0x1 )
			ADD_VAR( ::BoolProperty, bOrientTowardRadialEpicenter, 0x4 )
			ADD_VAR( ::FloatProperty, ShakeScale, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, PlaySpace, 0xFFFFFFFF )
			int GetObjClassVersion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqAct_CameraShake.GetObjClassVersion" );
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
