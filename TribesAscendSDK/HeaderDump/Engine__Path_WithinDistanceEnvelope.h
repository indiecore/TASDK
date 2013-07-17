#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Path_WithinDistanceEnvelope." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Path_WithinDistanceEnvelope." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Path_WithinDistanceEnvelope." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Path_WithinDistanceEnvelope : public PathConstraint
	{
	public:
			ADD_STRUCT( ::VectorProperty, EnvelopeTestPoint, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SoftStartPenalty, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bOnlyThrowOutNodesThatLeaveEnvelope, 0x2 )
			ADD_VAR( ::BoolProperty, bSoft, 0x1 )
			ADD_VAR( ::FloatProperty, MinDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxDistance, 0xFFFFFFFF )
			bool StayWithinEnvelopeToLoc( class Pawn* P, Vector InEnvelopeTestPoint, float InMaxDistance, float InMinDistance, bool bInSoft, float InSoftStartPenalty, bool bOnlyTossOutSpecsThatLeave )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Path_WithinDistanceEnvelope.StayWithinEnvelopeToLoc" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class Pawn** )( params + 0 ) = P;
				*( Vector* )( params + 4 ) = InEnvelopeTestPoint;
				*( float* )( params + 16 ) = InMaxDistance;
				*( float* )( params + 20 ) = InMinDistance;
				*( bool* )( params + 24 ) = bInSoft;
				*( float* )( params + 28 ) = InSoftStartPenalty;
				*( bool* )( params + 32 ) = bOnlyTossOutSpecsThatLeave;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Recycle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Path_WithinDistanceEnvelope.Recycle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
