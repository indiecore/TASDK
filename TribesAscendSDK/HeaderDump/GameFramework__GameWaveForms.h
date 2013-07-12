#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.GameWaveForms." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.GameWaveForms." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.GameWaveForms." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameWaveForms : public Object
	{
	public:
			ADD_OBJECT( ForceFeedbackWaveform, CameraShakeBigShort )
			ADD_OBJECT( ForceFeedbackWaveform, CameraShakeBigLong )
			ADD_OBJECT( ForceFeedbackWaveform, CameraShakeMediumShort )
			ADD_OBJECT( ForceFeedbackWaveform, CameraShakeMediumLong )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
