#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ForceFieldShapeSphere." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ForceFieldShapeSphere." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ForceFieldShapeSphere." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ForceFieldShapeSphere : public ForceFieldShape
	{
	public:
			float GetRadius(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFieldShapeSphere.GetRadius" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void FillBySphere( float Radius )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFieldShapeSphere.FillBySphere" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = Radius;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillByBox( Vector Extent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFieldShapeSphere.FillByBox" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = Extent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillByCapsule( float Height, float Radius )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFieldShapeSphere.FillByCapsule" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = Height;
				*( float* )( params + 4 ) = Radius;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillByCylinder( float BottomRadius, float TopRadius, float Height, float HeightOffset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFieldShapeSphere.FillByCylinder" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = BottomRadius;
				*( float* )( params + 4 ) = TopRadius;
				*( float* )( params + 8 ) = Height;
				*( float* )( params + 12 ) = HeightOffset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetDrawComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFieldShapeSphere.GetDrawComponent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
