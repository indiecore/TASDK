#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.CylinderComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.CylinderComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.CylinderComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class CylinderComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::BoolProperty, bAlwaysRenderIfSelected, 0x4 )
			ADD_VAR( ::BoolProperty, bDrawNonColliding, 0x2 )
			ADD_VAR( ::BoolProperty, bDrawBoundingBox, 0x1 )
			ADD_VAR( ::FloatProperty, CollisionRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CollisionHeight, 0xFFFFFFFF )
			void SetCylinderSize( float NewRadius, float NewHeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CylinderComponent.SetCylinderSize" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = NewRadius;
				*( float* )( params + 4 ) = NewHeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
