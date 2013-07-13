#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.InterpTrackSound." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.InterpTrackSound." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.InterpTrackSound." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InterpTrackSound : public InterpTrackVectorBase
	{
	public:
			ADD_VAR( ::BoolProperty, bTreatAsDialogue, 0x8 )
			ADD_VAR( ::BoolProperty, bSuppressSubtitles, 0x4 )
			ADD_VAR( ::BoolProperty, bContinueSoundOnMatineeEnd, 0x2 )
			ADD_VAR( ::BoolProperty, bPlayOnReverse, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
