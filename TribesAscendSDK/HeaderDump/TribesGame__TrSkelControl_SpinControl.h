#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrSkelControl_SpinControl." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrSkelControl_SpinControl." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrSkelControl_SpinControl." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrSkelControl_SpinControl : public SkelControlSingleBone
	{
	public:
			ADD_VAR( ::FloatProperty, m_fSpinDownTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpinUpTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_TimeToInterpToTargetRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_TargetRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCurrentDegreesPerSecond, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bRotateToTargetRotation, 0x10 )
			ADD_VAR( ::BoolProperty, m_bSpinningDown, 0x8 )
			ADD_VAR( ::BoolProperty, m_bSpinningUp, 0x4 )
			ADD_VAR( ::BoolProperty, m_bIsSpinning, 0x2 )
			ADD_VAR( ::BoolProperty, m_PreviewStartStop, 0x1 )
			ADD_STRUCT( ::VectorProperty, m_vAxis, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDegreesPerSecond, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
