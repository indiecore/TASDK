#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.RB_Handle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.RB_Handle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.RB_Handle." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class RB_Handle : public ActorComponent
	{
	public:
			ADD_STRUCT( ::VectorProperty, Location, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, StepSize, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Destination, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AngularStiffness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AngularDamping, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LinearDampingScale3D, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LinearStiffnessScale3D, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearStiffness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearDamping, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bInterpolating, 0x4 )
			ADD_VAR( ::BoolProperty, bRotationConstrained, 0x2 )
			ADD_VAR( ::BoolProperty, bInHardware, 0x1 )
			ADD_VAR( ::IntProperty, SceneIndex, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, GrabbedBoneName, 0xFFFFFFFF )
			void GrabComponent( ScriptName InBoneName, Vector GrabLocation, bool bConstrainRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_Handle.GrabComponent" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptName* )( params + 4 ) = InBoneName;
				*( Vector* )( params + 12 ) = GrabLocation;
				*( bool* )( params + 24 ) = bConstrainRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReleaseComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_Handle.ReleaseComponent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLocation( Vector NewLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_Handle.SetLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = NewLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSmoothLocation( Vector NewLocation, float MoveTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_Handle.SetSmoothLocation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = NewLocation;
				*( float* )( params + 12 ) = MoveTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateSmoothLocation( Vector &NewLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_Handle.UpdateSmoothLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = NewLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NewLocation = *( Vector* )params;
			}

			void SetOrientation( void* &NewOrientation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_Handle.SetOrientation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )params = NewOrientation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NewOrientation = *( void** )params;
			}

			void* GetOrientation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_Handle.GetOrientation" );
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
