#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ForceFieldShapeBox." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ForceFieldShapeBox." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ForceFieldShapeBox." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ForceFieldShapeBox : public ForceFieldShape
	{
	public:
			Vector GetRadii(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFieldShapeBox.GetRadii" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void FillBySphere( float Radius )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFieldShapeBox.FillBySphere" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = Radius;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillByBox( Vector Extent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFieldShapeBox.FillByBox" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = Extent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillByCapsule( float Height, float Radius )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFieldShapeBox.FillByCapsule" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = Height;
				*( float* )( params + 4 ) = Radius;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillByCylinder( float BottomRadius, float TopRadius, float Height, float HeightOffset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFieldShapeBox.FillByCylinder" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )params = BottomRadius;
				*( float* )( params + 4 ) = TopRadius;
				*( float* )( params + 8 ) = Height;
				*( float* )( params + 12 ) = HeightOffset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetDrawComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFieldShapeBox.GetDrawComponent" );
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
