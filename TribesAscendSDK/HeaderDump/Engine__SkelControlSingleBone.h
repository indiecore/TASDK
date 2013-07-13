#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SkelControlSingleBone." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SkelControlSingleBone." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SkelControlSingleBone." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SkelControlSingleBone : public SkelControlBase
	{
	public:
			ADD_VAR( ::NameProperty, RotationSpaceBoneName, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, BoneRotation, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, TranslationSpaceBoneName, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, BoneRotationSpace, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, BoneTranslationSpace, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, BoneTranslation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRemoveMeshRotation, 0x10 )
			ADD_VAR( ::BoolProperty, bAddRotation, 0x8 )
			ADD_VAR( ::BoolProperty, bAddTranslation, 0x4 )
			ADD_VAR( ::BoolProperty, bApplyRotation, 0x2 )
			ADD_VAR( ::BoolProperty, bApplyTranslation, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
