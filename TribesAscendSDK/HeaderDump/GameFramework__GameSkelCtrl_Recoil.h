#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.GameSkelCtrl_Recoil." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.GameSkelCtrl_Recoil." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.GameSkelCtrl_Recoil." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameSkelCtrl_Recoil : public SkelControlBase
	{
	public:
			ADD_VAR( ::BoolProperty, bApplyControl, 0x8 )
			ADD_VAR( ::BoolProperty, bOldPlayRecoil, 0x4 )
			ADD_VAR( ::BoolProperty, bPlayRecoil, 0x2 )
			ADD_VAR( ::BoolProperty, bBoneSpaceRecoil, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
