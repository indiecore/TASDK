#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.LensFlare." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.LensFlare." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.LensFlare." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LensFlare : public Object
	{
	public:
			ADD_OBJECT( Texture2D, ThumbnailImage )
			ADD_VAR( ::FloatProperty, ThumbnailDistance, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, ThumbnailAngle, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ReflectionCount, 0xFFFFFFFF )
			ADD_OBJECT( InterpCurveEdSetup, CurveEdSetup )
			ADD_VAR( ::BoolProperty, ThumbnailImageOutOfDate, 0x4 )
			ADD_VAR( ::BoolProperty, bRenderDebugLines, 0x2 )
			ADD_VAR( ::BoolProperty, bUseFixedRelativeBoundingBox, 0x1 )
			ADD_VAR( ::FloatProperty, Radius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConeFudgeFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InnerCone, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OuterCone, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ReflectionsDPG, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, SourceDPG, 0xFFFFFFFF )
			ADD_OBJECT( StaticMesh, SourceMesh )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
