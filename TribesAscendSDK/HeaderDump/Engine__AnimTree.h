#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.AnimTree." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.AnimTree." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.AnimTree." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimTree : public AnimNodeBlendBase
	{
	public:
			ADD_VAR( ::IntProperty, PreviewFloorYaw, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PreviewFloorPos, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, PreviewCamRot, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PreviewCamPos, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PreviewAnimSetIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PreviewAnimSetListIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PreviewSocketIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PreviewMeshIndex, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SocketName, 0xFFFFFFFF )
			ADD_OBJECT( StaticMesh, SocketStaticMesh )
			ADD_OBJECT( SkeletalMesh, SocketSkelMesh )
			ADD_OBJECT( SkeletalMesh, PreviewSkelMesh )
			ADD_VAR( ::FloatProperty, PreviewPlayRate, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MorphConnDrawY, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRebuildAnimTickArray, 0x8 )
			ADD_VAR( ::BoolProperty, bParentNodeArrayBuilt, 0x4 )
			ADD_VAR( ::BoolProperty, bBeingEdited, 0x2 )
			ADD_VAR( ::BoolProperty, bUseSavedPose, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
