#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrSkelControl_Suspension." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrSkelControl_Suspension." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrSkelControl_Suspension." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrSkelControl_Suspension : public SkelControlSingleBone
	{
	public:
			ADD_VAR( ::IntProperty, WheelIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentRot, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxRotRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinRot, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxRot, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RotScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RotIgnore, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinTrans, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxTrans, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TransOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TransScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TransIgnore, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bApplyTranslation, 0x2 )
			ADD_VAR( ::BoolProperty, m_bApplyRotation, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
