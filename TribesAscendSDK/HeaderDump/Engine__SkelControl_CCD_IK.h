#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SkelControl_CCD_IK." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SkelControl_CCD_IK." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SkelControl_CCD_IK." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SkelControl_CCD_IK : public SkelControlBase
	{
	public:
			ADD_VAR( ::FloatProperty, MaxAngleSteps, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bNoTurnOptimization, 0x2 )
			ADD_VAR( ::BoolProperty, bStartFromTail, 0x1 )
			ADD_VAR( ::FloatProperty, Precision, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IterationsCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxPerBoneIterations, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumBones, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, EffectorTranslationFromBone, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, EffectorSpaceBoneName, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, EffectorLocationSpace, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, EffectorLocation, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
