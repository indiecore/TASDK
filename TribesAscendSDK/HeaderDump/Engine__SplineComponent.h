#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SplineComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SplineComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SplineComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SplineComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::BoolProperty, bSplineDisabled, 0x1 )
			ADD_VAR( ::FloatProperty, SplineArrowSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SplineDrawRes, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SplineCurviness, 0xFFFFFFFF )
			void UpdateSplineCurviness(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineComponent.UpdateSplineCurviness" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateSplineReparamTable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineComponent.UpdateSplineReparamTable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetSplineLength(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineComponent.GetSplineLength" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			Vector GetLocationAtDistanceAlongSpline( float Distance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineComponent.GetLocationAtDistanceAlongSpline" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = Distance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector GetTangentAtDistanceAlongSpline( float Distance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineComponent.GetTangentAtDistanceAlongSpline" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = Distance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
