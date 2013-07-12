#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTSeqAct_PlayCameraAnim." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTSeqAct_PlayCameraAnim." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTSeqAct_PlayCameraAnim." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTSeqAct_PlayCameraAnim : public SequenceAction
	{
	public:
			ADD_OBJECT( CameraAnim, AnimToPlay )
			ADD_VAR( ::FloatProperty, IntensityScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Rate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendInTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendOutTime, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
