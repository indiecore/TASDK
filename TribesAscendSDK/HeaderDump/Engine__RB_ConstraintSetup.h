#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.RB_ConstraintSetup." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.RB_ConstraintSetup." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.RB_ConstraintSetup." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class RB_ConstraintSetup : public Object
	{
	public:
			ADD_VAR( ::NameProperty, JointName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ConstraintBone1, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ConstraintBone2, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PulleyRatio, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AngularBreakThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TwistLimitDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TwistLimitStiffness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SwingLimitDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SwingLimitStiffness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TwistLimitAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Swing2LimitAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Swing1LimitAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearBreakThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearLimitDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearLimitStiffness, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bMaintainMinDistance, 0x200 )
			ADD_VAR( ::BoolProperty, bIsPulley, 0x100 )
			ADD_VAR( ::BoolProperty, bAngularBreakable, 0x80 )
			ADD_VAR( ::BoolProperty, bTwistLimitSoft, 0x40 )
			ADD_VAR( ::BoolProperty, bSwingLimitSoft, 0x20 )
			ADD_VAR( ::BoolProperty, bTwistLimited, 0x10 )
			ADD_VAR( ::BoolProperty, bSwingLimited, 0x8 )
			ADD_VAR( ::BoolProperty, bLinearBreakable, 0x4 )
			ADD_VAR( ::BoolProperty, bLinearLimitSoft, 0x2 )
			ADD_VAR( ::BoolProperty, bEnableProjection, 0x1 )
			ADD_STRUCT( ::VectorProperty, PulleyPivot2, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PulleyPivot1, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, SecAxis2, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PriAxis2, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Pos2, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, SecAxis1, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PriAxis1, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Pos1, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
